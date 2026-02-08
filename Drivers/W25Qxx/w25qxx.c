#include "w25qxx.h"
#include <stddef.h>

/* ========================= 内部函数声明 ========================= */

static void W25QXX_CS_Low(void);
static void W25QXX_CS_High(void);
static uint8_t W25QXX_SPI_TransferByte(uint8_t data);
static void W25QXX_SendAddress(uint32_t address);

/* ========================= CS 片选控制 ========================= */

/**
 * @brief  拉低 CS 片选引脚 (选中芯片)
 */
static void W25QXX_CS_Low(void) {
  /* 使用 BRR 寄存器快速清零引脚 */
  W25QXX_CS_GPIO->BRR = W25QXX_CS_PIN;
}

/**
 * @brief  拉高 CS 片选引脚 (取消选中)
 */
static void W25QXX_CS_High(void) {
  /* 使用 BSRR 寄存器快速置位引脚 */
  W25QXX_CS_GPIO->BSRR = W25QXX_CS_PIN;
}

/* ========================= SPI 底层操作 ========================= */

/**
 * @brief  SPI 单字节收发
 * @param  data: 要发送的数据
 * @return 接收到的数据
 */
static uint8_t W25QXX_SPI_TransferByte(uint8_t data) {
  /* 等待发送缓冲区为空 (TXE) */
  while (!(W25QXX_SPI->SR & SPI_SR_TXE))
    ;

  /* 发送数据 */
  W25QXX_SPI->DR = data;

  /* 等待接收缓冲区非空 (RXNE) */
  while (!(W25QXX_SPI->SR & SPI_SR_RXNE))
    ;

  /* 返回接收到的数据 */
  return (uint8_t)W25QXX_SPI->DR;
}

/**
 * @brief  发送 24 位地址
 * @param  address: 24 位地址
 */
static void W25QXX_SendAddress(uint32_t address) {
  /* 发送地址高字节 (A23-A16) */
  W25QXX_SPI_TransferByte((uint8_t)(address >> 16));

  /* 发送地址中字节 (A15-A8) */
  W25QXX_SPI_TransferByte((uint8_t)(address >> 8));

  /* 发送地址低字节 (A7-A0) */
  W25QXX_SPI_TransferByte((uint8_t)address);
}

/* ========================= 初始化 ========================= */

/**
 * @brief  初始化 W25QXX Flash 驱动
 * @note   配置顺序: 时钟使能 -> GPIO 配置 -> SPI 配置
 */
void W25QXX_Init(void) {
  /* ---------------- 1. 开启时钟 ---------------- */

  /* 开启 GPIOA 时钟 (SPI1 引脚: PA5=SCK, PA6=MISO, PA7=MOSI) */
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

  /* 开启 GPIOC 时钟 (CS 引脚: PC13) */
  RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

  /* 开启 SPI1 时钟 */
  RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

  /* ---------------- 2. 配置 CS 引脚 (PC13) ---------------- */

  /* PC13 配置为推挽输出, 最高速度 50MHz */
  /* CRH 控制 Pin8-15, PC13 对应 CRH[23:20] */
  /* MODE13 = 11 (50MHz), CNF13 = 00 (推挽输出) */
  W25QXX_CS_GPIO->CRH &= ~(0xFU << 20); /* 清除 PC13 配置 */
  W25QXX_CS_GPIO->CRH |= (0x3U << 20);  /* MODE13 = 11 (输出 50MHz) */

  /* 默认拉高 CS (取消选中) */
  W25QXX_CS_High();

  /* ---------------- 3. 配置 SPI1 引脚 ---------------- */

  /* PA5 (SCK): 复用推挽输出, 50MHz */
  /* CRL[23:20] = MODE5[1:0] + CNF5[1:0] = 0b1011 */
  GPIOA->CRL &= ~(0xFU << 20);
  GPIOA->CRL |= (0xBU << 20); /* CNF5 = 10 (复用推挽), MODE5 = 11 (50MHz) */

  /* PA6 (MISO): 浮空输入 */
  /* CRL[27:24] = MODE6[1:0] + CNF6[1:0] = 0b0100 */
  GPIOA->CRL &= ~(0xFU << 24);
  GPIOA->CRL |= (0x4U << 24); /* CNF6 = 01 (浮空输入), MODE6 = 00 (输入) */

  /* PA7 (MOSI): 复用推挽输出, 50MHz */
  /* CRL[31:28] = MODE7[1:0] + CNF7[1:0] = 0b1011 */
  GPIOA->CRL &= ~(0xFU << 28);
  GPIOA->CRL |= (0xBU << 28); /* CNF7 = 10 (复用推挽), MODE7 = 11 (50MHz) */

  /* ---------------- 4. 配置 SPI1 ---------------- */

  /* 先禁用 SPI */
  W25QXX_SPI->CR1 &= ~SPI_CR1_SPE;

  /* 配置 CR1 寄存器:
   * - BIDIMODE = 0: 双线单向模式
   * - DFF = 0: 8 位数据帧
   * - SSM = 1: 软件从机管理
   * - SSI = 1: 内部从机选择 (主模式下需置 1)
   * - LSBFIRST = 0: MSB 先发
   * - BR[2:0] = 001: fPCLK/4 (假设 PCLK2=72MHz, 则 SPI=18MHz)
   * - MSTR = 1: 主模式
   * - CPOL = 0, CPHA = 0: SPI Mode 0
   */
  W25QXX_SPI->CR1 = SPI_CR1_SSM     /* 软件从机管理 */
                    | SPI_CR1_SSI   /* 内部从机选择 */
                    | (0x1U << 3)   /* BR = 001, fPCLK/4 */
                    | SPI_CR1_MSTR; /* 主模式 */

  /* CR2 寄存器保持默认值 */
  W25QXX_SPI->CR2 = 0;

  /* 使能 SPI */
  W25QXX_SPI->CR1 |= SPI_CR1_SPE;
}

/* ========================= 设备识别 ========================= */

/**
 * @brief  读取 JEDEC ID
 * @return 24 位 JEDEC ID
 * @note   指令格式: [9Fh] -> [MF7-0] [ID15-8] [ID7-0]
 */
uint32_t W25QXX_ReadJEDECID(void) {
  uint32_t jedecID = 0;

  /* 片选使能 */
  W25QXX_CS_Low();

  /* 发送 Read JEDEC ID 指令 (9Fh) */
  W25QXX_SPI_TransferByte(W25QXX_CMD_READ_JEDEC_ID);

  /* 读取 Manufacturer ID (MF7-0) */
  jedecID = W25QXX_SPI_TransferByte(0xFF);
  jedecID <<= 8;

  /* 读取 Memory Type (ID15-8) */
  jedecID |= W25QXX_SPI_TransferByte(0xFF);
  jedecID <<= 8;

  /* 读取 Capacity (ID7-0) */
  jedecID |= W25QXX_SPI_TransferByte(0xFF);

  /* 片选禁用 */
  W25QXX_CS_High();

  return jedecID;
}

/**
 * @brief  读取 Manufacturer ID 和 Device ID
 * @param  pManufacturerID: 制造商 ID 输出指针
 * @param  pDeviceID: 器件 ID 输出指针
 * @note   指令格式: [90h] [00h] [00h] [00h] -> [MF7-0] [ID7-0]
 */
void W25QXX_ReadID(uint8_t *pManufacturerID, uint8_t *pDeviceID) {
  /* 片选使能 */
  W25QXX_CS_Low();

  /* 发送 Read Manufacturer/Device ID 指令 (90h) */
  W25QXX_SPI_TransferByte(W25QXX_CMD_READ_MFR_DEVICE_ID);

  /* 发送 24 位地址 000000h */
  W25QXX_SPI_TransferByte(0x00);
  W25QXX_SPI_TransferByte(0x00);
  W25QXX_SPI_TransferByte(0x00);

  /* 读取 Manufacturer ID */
  if (pManufacturerID) {
    *pManufacturerID = W25QXX_SPI_TransferByte(0xFF);
  } else {
    W25QXX_SPI_TransferByte(0xFF);
  }

  /* 读取 Device ID */
  if (pDeviceID) {
    *pDeviceID = W25QXX_SPI_TransferByte(0xFF);
  }

  /* 片选禁用 */
  W25QXX_CS_High();
}

/* ========================= 数据读取 ========================= */

/**
 * @brief  读取数据
 * @param  address: 24 位起始地址
 * @param  pBuffer: 数据缓冲区指针
 * @param  length: 读取长度 (字节)
 * @note   指令格式: [03h] [A23-16] [A15-8] [A7-0] -> [D7-0]...
 */
void W25QXX_ReadData(uint32_t address, uint8_t *pBuffer, uint32_t length) {
  if (pBuffer == NULL || length == 0) {
    return;
  }

  /* 片选使能 */
  W25QXX_CS_Low();

  /* 发送 Read Data 指令 (03h) */
  W25QXX_SPI_TransferByte(W25QXX_CMD_READ_DATA);

  /* 发送 24 位地址 */
  W25QXX_SendAddress(address);

  /* 连续读取数据 */
  while (length--) {
    *pBuffer++ = W25QXX_SPI_TransferByte(0xFF);
  }

  /* 片选禁用 */
  W25QXX_CS_High();
}

/**
 * @brief  快速读取数据
 * @param  address: 24 位起始地址
 * @param  pBuffer: 数据缓冲区指针
 * @param  length: 读取长度 (字节)
 * @note   指令格式: [0Bh] [A23-16] [A15-8] [A7-0] [Dummy] -> [D7-0]...
 */
void W25QXX_FastRead(uint32_t address, uint8_t *pBuffer, uint32_t length) {
  if (pBuffer == NULL || length == 0) {
    return;
  }

  /* 片选使能 */
  W25QXX_CS_Low();

  /* 发送 Fast Read 指令 (0Bh) */
  W25QXX_SPI_TransferByte(W25QXX_CMD_FAST_READ);

  /* 发送 24 位地址 */
  W25QXX_SendAddress(address);

  /* 发送 Dummy 字节 */
  W25QXX_SPI_TransferByte(0xFF);

  /* 连续读取数据 */
  while (length--) {
    *pBuffer++ = W25QXX_SPI_TransferByte(0xFF);
  }

  /* 片选禁用 */
  W25QXX_CS_High();
}

/* ========================= 状态寄存器 ========================= */

/**
 * @brief  读取状态寄存器-1
 * @return 状态寄存器-1 的值
 * @note   指令格式: [05h] -> [S7-0]
 */
uint8_t W25QXX_ReadStatusReg1(void) {
  uint8_t status;

  /* 片选使能 */
  W25QXX_CS_Low();

  /* 发送 Read Status Register-1 指令 (05h) */
  W25QXX_SPI_TransferByte(W25QXX_CMD_READ_STATUS_REG1);

  /* 读取状态寄存器 */
  status = W25QXX_SPI_TransferByte(0xFF);

  /* 片选禁用 */
  W25QXX_CS_High();

  return status;
}

/**
 * @brief  等待 BUSY 标志清除
 * @note   用于等待编程/擦除操作完成
 */
void W25QXX_WaitBusy(void) {
  /* 轮询状态寄存器直到 BUSY 位清零 */
  while (W25QXX_ReadStatusReg1() & W25QXX_SR1_BUSY)
    ;
}
