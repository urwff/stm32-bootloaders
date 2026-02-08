#ifndef __W25QXX_H
#define __W25QXX_H

/**
 * @file    w25qxx.h
 * @brief   W25Q32JV SPI NOR Flash 驱动头文件
 * @note    基于 Winbond W25Q32JVSSIQ 数据手册实现
 *          容量: 32M-bit / 4M-Byte
 *          支持标准 SPI 模式 (Mode 0/3)
 */

#include "stm32f103xe.h"

/* ========================= 硬件配置 ========================= */

/* SPI 外设选择 */
#define W25QXX_SPI SPI1

/* CS 片选引脚配置 (PC13) */
#define W25QXX_CS_GPIO GPIOC
#define W25QXX_CS_PIN (1U << 13)

/* ========================= W25Q32JV 器件信息 ========================= */

/* 制造商 ID */
#define W25QXX_MANUFACTURER_ID 0xEF /* Winbond */

/* 器件 ID */
#define W25QXX_DEVICE_ID 0x15 /* W25Q32JV */

/* JEDEC ID */
#define W25QXX_JEDEC_ID 0xEF4016 /* W25Q32JV-IQ/JQ */

/* 存储容量 */
#define W25QXX_FLASH_SIZE (4 * 1024 * 1024) /* 4 MB */
#define W25QXX_PAGE_SIZE 256                /* 256 字节/页 */
#define W25QXX_SECTOR_SIZE (4 * 1024)       /* 4 KB/扇区 */
#define W25QXX_BLOCK_SIZE (64 * 1024)       /* 64 KB/块 */

/* ========================= SPI 指令码 ========================= */

/* 设备 ID 相关指令 */
#define W25QXX_CMD_READ_JEDEC_ID 0x9F      /* 读取 JEDEC ID */
#define W25QXX_CMD_READ_DEVICE_ID 0xAB     /* 释放掉电 / 读取 Device ID */
#define W25QXX_CMD_READ_MFR_DEVICE_ID 0x90 /* 读取 Manufacturer/Device ID */

/* 读操作指令 */
#define W25QXX_CMD_READ_DATA 0x03 /* 读取数据 (最高 50MHz) */
#define W25QXX_CMD_FAST_READ                                                   \
  0x0B /* 快速读取 (最高 133MHz, 需要 dummy 字节)                    \
        */

/* 状态寄存器指令 */
#define W25QXX_CMD_READ_STATUS_REG1 0x05 /* 读取状态寄存器-1 */
#define W25QXX_CMD_READ_STATUS_REG2 0x35 /* 读取状态寄存器-2 */
#define W25QXX_CMD_READ_STATUS_REG3 0x15 /* 读取状态寄存器-3 */

/* 写使能/禁止指令 */
#define W25QXX_CMD_WRITE_ENABLE 0x06  /* 写使能 */
#define W25QXX_CMD_WRITE_DISABLE 0x04 /* 写禁止 */

/* ========================= 状态寄存器位定义 ========================= */

/* 状态寄存器-1 */
#define W25QXX_SR1_BUSY (1U << 0) /* 忙标志 (只读) */
#define W25QXX_SR1_WEL (1U << 1)  /* 写使能锁存 (只读) */

/* ========================= 函数原型声明 ========================= */

/**
 * @brief  初始化 W25QXX Flash 驱动
 * @note   配置 SPI1 和 CS 引脚 (PC13)
 */
void W25QXX_Init(void);

/**
 * @brief  读取 JEDEC ID
 * @return 24 位 JEDEC ID (制造商 ID + 存储器类型 + 容量)
 * @note   W25Q32JV 返回值: 0xEF4016
 */
uint32_t W25QXX_ReadJEDECID(void);

/**
 * @brief  读取 Manufacturer ID 和 Device ID
 * @param  pManufacturerID: 制造商 ID 输出指针 (Winbond = 0xEF)
 * @param  pDeviceID: 器件 ID 输出指针 (W25Q32JV = 0x15)
 */
void W25QXX_ReadID(uint8_t *pManufacturerID, uint8_t *pDeviceID);

/**
 * @brief  读取数据
 * @param  address: 24 位起始地址
 * @param  pBuffer: 数据缓冲区指针
 * @param  length: 读取长度 (字节)
 */
void W25QXX_ReadData(uint32_t address, uint8_t *pBuffer, uint32_t length);

/**
 * @brief  快速读取数据
 * @param  address: 24 位起始地址
 * @param  pBuffer: 数据缓冲区指针
 * @param  length: 读取长度 (字节)
 * @note   相比 ReadData 需要一个 dummy 字节, 但支持更高 SPI 时钟频率
 */
void W25QXX_FastRead(uint32_t address, uint8_t *pBuffer, uint32_t length);

/**
 * @brief  读取状态寄存器-1
 * @return 状态寄存器-1 的值
 */
uint8_t W25QXX_ReadStatusReg1(void);

/**
 * @brief  等待 BUSY 标志清除
 * @note   用于等待编程/擦除操作完成
 */
void W25QXX_WaitBusy(void);

#endif /* __W25QXX_H */
