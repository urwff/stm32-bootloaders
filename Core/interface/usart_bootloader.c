#include "usart_bootloader.h"
#include "stm32f1xx_hal_flash.h"
#include "stm32f1xx_hal_flash_ex.h"
#include "stm32f1xx_hal_uart.h"
#include "usart.h"
#include <stdint.h>
#include <string.h>

#define RECEIVE_BUFFER_SIZE 512
static uint8_t receive_buffer[RECEIVE_BUFFER_SIZE] = {0};
volatile uint16_t receive_size = 0;
uint16_t receive_len = 0;
uint32_t flash_offset = 0;

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
  if (huart->Instance == USART1) {
    receive_size = Size;
    uint32_t current_page = 0;
    receive_len += Size;
    HAL_FLASH_Unlock();
    // 1. 判断a区是否需要擦除
    uint8_t need_erase = 0;
    for (uint16_t i = 0; i < Size; i++) {
      uint8_t data =
          *(volatile uint8_t *)(APP_START_ADDRESS + flash_offset + i);
      if (data != 0xFF) {
        need_erase = 1;
        current_page = (APP_START_ADDRESS + flash_offset + i) -
                       (APP_START_ADDRESS + flash_offset + i) % FLASH_PAGE_SIZE;
        break;
      }
    }
    // 2. 擦除
    if (need_erase == 1) {
      FLASH_EraseInitTypeDef EraseInitStruct;
      EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
      EraseInitStruct.PageAddress = current_page;
      EraseInitStruct.NbPages = 1;
      uint32_t PageError = 0;
      EraseInitStruct.Banks = FLASH_BANK_1;
      HAL_FLASHEx_Erase(&EraseInitStruct, &PageError);
    }
    // 写入
    for (uint16_t i = 0; i < Size; i++) {
      uint16_t receive_data;
      if (i + 1 < Size) {
        receive_data = receive_buffer[i] | (receive_buffer[i + 1] << 8);
        HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD,
                          APP_START_ADDRESS + flash_offset + i, receive_data);
        i++;
      } else {
        receive_data = receive_buffer[i] | (0x00ff << 8);
        HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD,
                          APP_START_ADDRESS + flash_offset + i, receive_data);
      }
    }
    // 3. 更新偏移量
    flash_offset += Size;
    HAL_FLASH_Lock();
    // 4. 重置缓冲区并重新开始接收
    memset(receive_buffer, 0, RECEIVE_BUFFER_SIZE);
    HAL_UARTEx_ReceiveToIdle_IT(&huart1, receive_buffer, RECEIVE_BUFFER_SIZE);
  }
}

void USART_Bootloader_Init(void) {
  // 清除标志以避免立即触发错误
  __HAL_UART_CLEAR_OREFLAG(&huart1);
  __HAL_UART_CLEAR_IDLEFLAG(&huart1);
  __HAL_UART_CLEAR_FEFLAG(&huart1);
  __HAL_UART_CLEAR_NEFLAG(&huart1);

  // 开始接收
  HAL_UARTEx_ReceiveToIdle_IT(&huart1, receive_buffer, RECEIVE_BUFFER_SIZE);
}

void USART_Bootloader_Process(void) {
  // 如果需要，处理逻辑（例如超时、命令）
  // 当前完全由中断驱动进行数据接收
}

bool USART_Bootloader_JumpToApplication(void) {
  typedef void (*pFunction)(void);
  pFunction JumpToApplication;
  uint32_t JumpAddress;

  // 检查应用程序地址处是否存在有效的代码
  // 应用程序地址处的第一个字（32位）是堆栈指针 (MSP)
  // 它应该在 RAM 范围内（例如 0x20000000 - 0x200xxxxx）
  uint32_t msp_value = *(__IO uint32_t *)APP_START_ADDRESS;
  if ((msp_value & 0x2FF00000) == 0x20000000) {
    // 1. 禁用所有中断
    __disable_irq();
    HAL_DeInit(); // 反初始化 HAL 以重置外设

    // 2. 获取跳转地址（复位处理程序） - 第 2 个字
    JumpAddress = *(__IO uint32_t *)(APP_START_ADDRESS + 4);
    JumpToApplication = (pFunction)JumpAddress;

    // 3. 设置主堆栈指针
    __set_MSP(msp_value);

    // 4. 跳转
    JumpToApplication();
    return true;
  }
  return false;
}

uint8_t USART_Bootloader_EraseFlash(uint32_t startAddress, uint32_t length) {
  HAL_FLASH_Unlock();

  FLASH_EraseInitTypeDef EraseInitStruct;
  uint32_t PageError = 0;

  // 计算页数
  // 注意：为了安全，此简单架构假设 startAddress 是页对齐的
  // 或者检查对齐情况。
  // 如果长度迫使跨入新页面，则应擦除该页面。
  // 但是，如果我们顺序写入小块，盲目擦除后续页面可能会很危险。
  // 安全策略：仅当处于页面*开始*位置时才擦除*当前*页面。
  // 如果数据跨越页面，我们从技术上讲
  // 也需要擦除下一个页面，但前提是我们确定是第一次进入该页面。
  // 鉴于回调逻辑：如果 (current_address % FLASH_PAGE_SIZE) == 0 -> 擦除
  // 我们假设主机发送的数据块可能对齐也可能不对齐，但通常包大小 < 页大小。
  // 让我们实现一个通用的擦除函数，擦除 [start, start+len] 触及的所有页面，
  // 但需要谨慎调用。

  uint32_t endAddress = startAddress + length - 1;
  uint32_t startPage = startAddress & ~(FLASH_PAGE_SIZE - 1);
  uint32_t endPage = endAddress & ~(FLASH_PAGE_SIZE - 1);

  // 安全性：仅当请求的 startAddress 是页面的开头时才进行擦除
  // 否则，如果我们正在向页面追加内容，可能会擦除刚刚写入的数据。
  if (startAddress != startPage) {
    // 我们处于页面的中间。假设我们在开始
    // 写入此页面时它已被擦除。除非我们跨越了页边界？
    if (startPage != endPage) {
      // 我们跨越了边界！我们必须擦除下一页。
      // 但我们不应该擦除第一页（它包含数据）。
      startPage = startPage + FLASH_PAGE_SIZE; // 从 *下一页* 开始擦除
    } else {
      // 整个范围都在一个应该已经被擦除的页面内。
      HAL_FLASH_Lock();
      return 0; // 无需擦除
    }
  }

  if (endPage < startPage) {
    HAL_FLASH_Lock();
    return 0; // 无需擦除
  }

  EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
  EraseInitStruct.PageAddress = startPage;
  EraseInitStruct.NbPages = (endPage - startPage) / FLASH_PAGE_SIZE + 1;
  EraseInitStruct.Banks = FLASH_BANK_1;

  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PageError) != HAL_OK) {
    HAL_FLASH_Lock();
    return 1; // 错误
  }

  HAL_FLASH_Lock();
  return 0; // 成功
}

uint8_t USART_Bootloader_WriteFlash(uint32_t address, const uint8_t *data,
                                    uint32_t length) {
  HAL_FLASH_Unlock();

  for (uint32_t i = 0; i < length; i += 2) {
    uint16_t halfword_data;

    // 处理奇数长度（最后一个字节）
    if (i + 1 >= length) {
      halfword_data = (uint16_t)data[i] | 0xFF00; // 用 0xFF 填充
    } else {
      halfword_data = (uint16_t)data[i] | ((uint16_t)data[i + 1] << 8);
    }

    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address + i,
                          halfword_data) != HAL_OK) {
      HAL_FLASH_Lock();
      return 1; // 错误
    }
  }

  HAL_FLASH_Lock();
  return 0;
}
