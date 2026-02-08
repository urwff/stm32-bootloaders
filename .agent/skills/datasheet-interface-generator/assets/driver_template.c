#include "driver_template.h"

/**
 * @brief  初始化外设
 * @note   完全使用寄存器直接访问，不使用 HAL 库
 */
void Driver_Init(void) {
  /* ---------------- 1. 开启时钟 ---------------- */
  /*
   * 示例：开启 GPIO 和 外设时钟（使用简化宏）
   * RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;   // 开启 GPIOA 时钟
   * RCC->APB2ENR |= RCC_APB2ENR_USART1EN; // 开启 USART1 时钟
   */

  /* ---------------- 2. 配置 GPIO ---------------- */
  /*
   * 配置引脚模式（输入/输出/复用功能）
   * GPIOA->CRH &= ~GPIO_CRH_CNF9;  // 清除 CNF9 配置
   * GPIOA->CRH |= GPIO_CRH_CNF9_1; // 设置为复用推挽输出
   * GPIOA->CRH |= GPIO_CRH_MODE9;  // 设置为最高速度输出
   */

  /* ---------------- 3. 配置外设寄存器 ---------------- */
  /*
   * 根据数据手册的初始化流程配置 CR1, CR2, BRR 等寄存器
   * USART1->CR1 |= USART_CR1_UE;  // 使能 USART
   * USART1->CR1 |= USART_CR1_TE;  // 使能发送
   * USART1->CR1 |= USART_CR1_RE;  // 使能接收
   */
}

/**
 * @brief  发送/写入数据
 * @param  data: 要发送的数据
 */
void Driver_Write(uint16_t data) {
  /*
   * 1. 等待发送缓冲区为空 (TXE)
   * while (!(USART1->SR & USART_SR_TXE)); // 使用简化宏
   */

  /*
   * 2. 写入数据寄存器
   * USART1->DR = data;
   */
}

/**
 * @brief  接收/读取数据
 * @return 读取到的数据
 */
uint16_t Driver_Read(void) {
  /*
   * 1. 等待接收缓冲区非空 (RXNE)
   * while (!(USART1->SR & USART_SR_RXNE)); // 使用简化宏
   */

  /*
   * 2. 读取数据寄存器
   * return (uint16_t)(USART1->DR);
   */
  return 0;
}

/**
 * @brief  检查外设状态
 * @return 状态值
 */
uint8_t Driver_GetStatus(void) {
  /*
   * 返回状态寄存器的值，或者检查特定标志位（使用简化宏）
   * return (USART1->SR & USART_SR_TC) ? 1 : 0; // 检查发送完成标志
   */
  return 0;
}
