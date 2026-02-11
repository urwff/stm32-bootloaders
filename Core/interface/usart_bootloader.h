
#ifndef USART_BOOTLOADER_H
#define USART_BOOTLOADER_H

#include "stdlib.h"
#include "usart.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define APP_START_ADDRESS 0x08004000

/**
 * @brief 初始化 USART Bootloader 相关外设（GPIO, USART, Flash 等）
 */
void USART_Bootloader_Init(void);

/**
 * @brief 运行 Bootloader 主处理逻辑，轮询或中断处理通信协议
 */
void USART_Bootloader_Process(void);

/**
 * @brief 跳转至用户应用程序区域
 * @return 如果跳转失败返回 false
 */
bool USART_Bootloader_JumpToApplication(void);

/**
 * @brief 擦除指定的 Flash 扇区或块
 * @param startAddress 起始地址
 * @param length 擦除长度
 * @return 状态码（0 为成功，非 0 为错误）
 */
uint8_t USART_Bootloader_EraseFlash(uint32_t startAddress, uint32_t length);

/**
 * @brief 将数据缓冲区写入 Flash
 * @param address 目标 Flash 地址
 * @param data 待写入的数据指针
 * @param length 数据长度
 * @return 状态码（0 为成功，非 0 为错误）
 */
uint8_t USART_Bootloader_WriteFlash(uint32_t address, const uint8_t *data,
                                    uint32_t length);

#endif /* USART_BOOTLOADER_H */
