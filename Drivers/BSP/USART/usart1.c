#include "usart1.h"

/**
 * @file    usart1.c
 * @brief   USART1 驱动实现 - 基于寄存器直接访问（无 HAL）
 * @note    配置: 72MHz 时钟, PA9(TX)/PA10(RX), 115200 波特率, 8N1
 */

/* 私有宏定义 */
#define USART1_PCLK 72000000UL   /* APB2 时钟频率 */
#define USART1_BAUDRATE 115200UL /* 波特率 */

/**
 * @brief  初始化 USART1
 * @note   完全使用寄存器直接访问，不使用 HAL 库
 */
void USART1_Init(void) {
  /* ---------------- 1. 开启时钟 ---------------- */
  /* 开启 GPIOA 时钟 (APB2 总线) */
  RCC->APB2ENR |= (1UL << 2); /* RCC_APB2ENR_IOPAEN */

  /* 开启 USART1 时钟 (APB2 总线) */
  RCC->APB2ENR |= (1UL << 14); /* RCC_APB2ENR_USART1EN */

  /* ---------------- 2. 配置 GPIO 引脚 ---------------- */
  /* PA9 (TX): 复用推挽输出, 最高速度 (50MHz) */
  /* CRH 寄存器: MODE9[1:0]=11 (50MHz), CNF9[1:0]=10 (复用推挽) */
  GPIOA->CRH &= ~(0xFUL << 4); /* 清除 PA9 配置位 (位 4-7) */
  GPIOA->CRH |= (0xBUL << 4);  /* MODE9=11, CNF9=10 -> 0b1011 = 0xB */

  /* PA10 (RX): 浮空输入 */
  /* CRH 寄存器: MODE10[1:0]=00 (输入), CNF10[1:0]=01 (浮空输入) */
  GPIOA->CRH &= ~(0xFUL << 8); /* 清除 PA10 配置位 (位 8-11) */
  GPIOA->CRH |= (0x4UL << 8);  /* MODE10=00, CNF10=01 -> 0b0100 = 0x4 */

  /* ---------------- 3. 配置 USART1 寄存器 ---------------- */
  /* 先禁用 USART */
  USART1->CR1 = 0;

  /* 配置波特率寄存器 (BRR) */
  /* USARTDIV = fPCLK / (16 * 波特率) = 72000000 / (16 * 115200) = 39.0625 */
  /* 整数部分(Mantissa) = 39 = 0x27 */
  /* 小数部分(Fraction) = 0.0625 * 16 = 1 = 0x1 */
  /* BRR = (Mantissa << 4) | Fraction = (39 << 4) | 1 = 0x271 */
  USART1->BRR = (39UL << 4) | 1UL; /* 0x271 */

  /* 配置 CR1 寄存器 */
  /* M=0 (8位数据), PCE=0 (无奇偶校验), TE=1 (使能发送), RE=1 (使能接收) */
  USART1->CR1 |= USART_CR1_TE; /* 使能发送 */
  USART1->CR1 |= USART_CR1_RE; /* 使能接收 */

  /* 配置 CR2 寄存器 */
  /* STOP[1:0]=00 (1个停止位) - 默认值，无需配置 */
  USART1->CR2 = 0;

  /* 配置 CR3 寄存器 */
  /* 无硬件流控，无 DMA - 默认值 */
  USART1->CR3 = 0;

  /* 使能 USART1 */
  USART1->CR1 |= USART_CR1_UE; /* USART 使能 */
}

/**
 * @brief  发送单个字符
 * @param  ch: 要发送的字符
 */
void USART1_SendChar(uint8_t ch) {
  /* 等待发送数据寄存器为空 (TXE=1) */
  while (!(USART1->SR & USART_SR_TXE)) {
    /* 空循环等待 */
  }

  /* 写入数据到数据寄存器 */
  USART1->DR = ch;
}

/**
 * @brief  发送字符串
 * @param  str: 指向要发送的字符串的指针
 */
void USART1_SendString(const char *str) {
  while (*str != '\0') {
    USART1_SendChar((uint8_t)*str);
    str++;
  }

  /* 等待发送完成 (TC=1) */
  while (!(USART1->SR & USART_SR_TC)) {
    /* 空循环等待 */
  }
}

/**
 * @brief  发送指定长度的数据
 * @param  data: 指向数据缓冲区的指针
 * @param  len: 数据长度
 */
void USART1_SendData(const uint8_t *data, uint16_t len) {
  for (uint16_t i = 0; i < len; i++) {
    USART1_SendChar(data[i]);
  }

  /* 等待发送完成 (TC=1) */
  while (!(USART1->SR & USART_SR_TC)) {
    /* 空循环等待 */
  }
}

/**
 * @brief  接收单个字符（阻塞式）
 * @return 接收到的字符
 */
uint8_t USART1_ReceiveChar(void) {
  /* 等待接收数据寄存器非空 (RXNE=1) */
  while (!(USART1->SR & USART_SR_RXNE)) {
    /* 空循环等待 */
  }

  /* 读取并返回数据寄存器的值 */
  return (uint8_t)(USART1->DR & 0xFF);
}

/**
 * @brief  检查是否有数据可读
 * @return 1: 有数据可读, 0: 无数据
 */
uint8_t USART1_IsDataAvailable(void) {
  /* 检查 RXNE 标志位 */
  return (USART1->SR & USART_SR_RXNE) ? 1 : 0;
}

/**
 * @brief  获取 USART1 状态寄存器值
 * @return 状态寄存器值
 */
uint32_t USART1_GetStatus(void) { return USART1->SR; }
