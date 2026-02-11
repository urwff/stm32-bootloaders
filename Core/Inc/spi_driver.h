#ifndef __SPI_DRIVER_H
#define __SPI_DRIVER_H

#include "stm32f103xe.h"

/*
 * SPI1 引脚定义 (Default Remap)
 * SCK  -> PA5
 * MISO -> PA6
 * MOSI -> PA7
 * NSS  -> PA4 (软件管理模式下作为普通 GPIO 控制片选)
 */
#define SPI1_GPIO_PORT GPIOA
#define SPI1_PIN_SCK GPIO_ODR_ODR5  /* PA5 */
#define SPI1_PIN_MISO GPIO_ODR_ODR6 /* PA6 */
#define SPI1_PIN_MOSI GPIO_ODR_ODR7 /* PA7 */
#define SPI1_PIN_NSS GPIO_ODR_ODR4  /* PA4 */

/*
 * 函数原型声明
 */

/**
 * @brief  初始化 SPI1
 * @note   配置为主机模式 (Master), 轮询方式, 软件片选 (SSM), 模式 0 (CPOL=0,
 * CPHA=0)
 */
void SPI1_Init(void);

/**
 * @brief  SPI1 读写一个字节 (全双工)
 * @param  TxData: 要发送的数据
 * @return 接收到的数据
 */
uint8_t SPI1_ReadWriteByte(uint8_t TxData);

/**
 * @brief  SPI1 发送缓冲区数据
 * @param  pData: 数据指针
 * @param  Size: 数据长度
 */
void SPI1_Transmit(uint8_t *pData, uint16_t Size);

/**
 * @brief  SPI1 接收数据到缓冲区
 * @param  pData: 接收缓冲区指针
 * @param  Size: 数据长度
 */
void SPI1_Receive(uint8_t *pData, uint16_t Size);

/**
 * @brief  控制 CS (NSS) 引脚电平
 * @param  State: 0 (Low/Select), 1 (High/Deselect)
 */
void SPI1_SetCS(uint8_t State);

#endif /* __SPI_DRIVER_H */
