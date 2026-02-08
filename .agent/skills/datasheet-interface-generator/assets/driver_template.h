#ifndef __DRIVER_TEMPLATE_H
#define __DRIVER_TEMPLATE_H

/*
 * 包含用户的寄存器定义头文件
 * 请根据实际情况修改，例如 "stm32f10x.h" 或 "stm32f4xx.h"
 */
#include "stm32f10x.h"

/*
 * 定义外设结构体指针
 * 请根据实际外设基地址定义，例如 USART1, SPI1 等
 */
// #define MY_PERIPH ((MyPeriph_TypeDef *)MY_PERIPH_BASE)

/* 函数原型声明 */

/**
 * @brief  初始化外设
 * @note   配置时钟，GPIO引脚，以及外设控制寄存器
 */
void Driver_Init(void);

/**
 * @brief  发送/写入数据
 * @param  data: 要发送的数据
 */
void Driver_Write(uint16_t data);

/**
 * @brief  接收/读取数据
 * @return 读取到的数据
 */
uint16_t Driver_Read(void);

/**
 * @brief  检查外设状态
 * @return 状态寄存器值或特定标志位状态
 */
uint8_t Driver_GetStatus(void);

#endif /* __DRIVER_TEMPLATE_H */
