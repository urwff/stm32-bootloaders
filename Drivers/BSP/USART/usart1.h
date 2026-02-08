#ifndef __USART1_H
#define __USART1_H

/**
 * @file    usart1.h
 * @brief   USART1 驱动接口 - 基于寄存器直接访问（无 HAL）
 * @note    配置: 72MHz 时钟, PA9(TX)/PA10(RX), 115200 波特率, 8N1
 */

#include "stm32f103xe.h"

/* 函数原型声明 */

/**
 * @brief  初始化 USART1
 * @note   配置时钟、GPIO引脚(PA9/PA10)、波特率(115200)、8N1格式
 */
void USART1_Init(void);

/**
 * @brief  发送单个字符
 * @param  ch: 要发送的字符
 */
void USART1_SendChar(uint8_t ch);

/**
 * @brief  发送字符串
 * @param  str: 指向要发送的字符串的指针
 */
void USART1_SendString(const char *str);

/**
 * @brief  发送指定长度的数据
 * @param  data: 指向数据缓冲区的指针
 * @param  len: 数据长度
 */
void USART1_SendData(const uint8_t *data, uint16_t len);

/**
 * @brief  接收单个字符（阻塞式）
 * @return 接收到的字符
 */
uint8_t USART1_ReceiveChar(void);

/**
 * @brief  检查是否有数据可读
 * @return 1: 有数据可读, 0: 无数据
 */
uint8_t USART1_IsDataAvailable(void);

/**
 * @brief  获取 USART1 状态寄存器值
 * @return 状态寄存器值
 */
uint32_t USART1_GetStatus(void);

#endif /* __USART1_H */
