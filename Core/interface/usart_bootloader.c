#include "usart_bootloader.h"
#include "stm32f1xx_hal_flash.h"
#include "stm32f1xx_hal_flash_ex.h"
#include "stm32f1xx_hal_uart.h"
#include "usart.h"
#include <stdint.h>
#include <string.h>

#define RECEIVE_BUFFER_SIZE 512
static uint8_t usart_receive_buffer[RECEIVE_BUFFER_SIZE] = {0};
volatile uint16_t usart_buffer_length = 0; // 表示累计收到的字节长度

uint16_t buffer_receive_size = 0; // 表示当前收到的字节长度
uint32_t flash_offset = 0;

uint8_t last_byte = 0;
uint8_t last_byte_flag = 0;

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
  if (huart->Instance == USART1) {
    usart_buffer_length = Size;

    // 1. 判断a区是否需要擦除
    USART_Bootloader_EraseFlash(APP_START_ADDRESS + flash_offset,
                                usart_buffer_length);
    // 2. 写入
    USART_Bootloader_WriteFlash(APP_START_ADDRESS + flash_offset,
                                usart_receive_buffer, Size);
    // 3. 更新偏移量
    flash_offset += Size;
    // 4. 重置缓冲区并重新开始接收
    memset(usart_receive_buffer, 0, RECEIVE_BUFFER_SIZE);
    HAL_UARTEx_ReceiveToIdle_IT(&huart1, usart_receive_buffer,
                                RECEIVE_BUFFER_SIZE);
  }
}

void USART_Bootloader_Init(void) {
  // 清除标志以避免立即触发错误
  __HAL_UART_CLEAR_OREFLAG(&huart1);
  __HAL_UART_CLEAR_IDLEFLAG(&huart1);
  __HAL_UART_CLEAR_FEFLAG(&huart1);
  __HAL_UART_CLEAR_NEFLAG(&huart1);

  // 开始接收
  HAL_UARTEx_ReceiveToIdle_IT(&huart1, usart_receive_buffer,
                              RECEIVE_BUFFER_SIZE);
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
/**
 * @brief 按页擦除flash
 * @param AppAddress 应用块的起始地址
 * @param usart_buffer_length 累计收到的字节长度
 *
 * @return uint8_t
 */
uint8_t USART_Bootloader_EraseFlash(uint32_t appStartAddress,
                                    uint32_t usart_buffer_length) {
  // 1. 擦除未擦除页 如果发现到该页存在未擦除的字节，就擦除该页
  uint32_t i = 0;
  HAL_FLASH_Unlock();

  while (i < usart_buffer_length) {
    uint32_t address = appStartAddress + i;
    uint32_t page_StartAddress = address - (address % FLASH_PAGE_SIZE);
    uint32_t page_EndAddress = page_StartAddress + FLASH_PAGE_SIZE;
    uint8_t need_erase = 0;

    for (uint32_t j = address;
         j < page_EndAddress && (j - appStartAddress) < usart_buffer_length;
         j++) {
      uint8_t flash_data = *(volatile uint8_t *)(j);
      if (flash_data != 0xFF) {
        need_erase = 1;
        break;
      }
    }
    if (need_erase) {
      uint32_t PageError = 0;
      FLASH_EraseInitTypeDef EraseInit;
      EraseInit.Banks = FLASH_BANK_1;
      EraseInit.TypeErase = FLASH_TYPEERASE_PAGES;
      EraseInit.PageAddress = page_StartAddress;
      EraseInit.NbPages = 1;
      HAL_FLASHEx_Erase(&EraseInit, &PageError);
    }
    i += FLASH_PAGE_SIZE;
  }

  HAL_FLASH_Lock();
  return 0; // 成功
}

uint8_t USART_Bootloader_WriteFlash(uint32_t address,
                                    const uint8_t *buffer_data,
                                    uint32_t buffer_receive_length) {
  // 问题：
  // 1. flash写入时，只能先擦除，然后才能写入，否则会出错
  // 2. 如果遇到字节边界，需要特殊处理
  // 3. 如 发送hello world，到末尾剩余d时，需要与下次发送的字节拼接再写入
  HAL_FLASH_Unlock();
  // 拼接上次剩余的一个字节
  uint16_t i = 0;

  if (last_byte_flag != 0) {
    uint16_t receive_data = last_byte | (buffer_data[0] << 8);
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address, receive_data);
    address += 2;
    i = 1;
    last_byte_flag = 0;
  }

  for (; i + 1 < buffer_receive_length; i += 2) {
    uint16_t receive_data = buffer_data[i] | (buffer_data[i + 1] << 8);
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address, receive_data);
    address += 2;
  }

  // 0 1 2 3
  if (i < buffer_receive_length) {
    last_byte = buffer_data[buffer_receive_length - 1];
    last_byte_flag = 1;
  }

  HAL_FLASH_Lock();
  return 0;
}
