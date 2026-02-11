#include "spi_driver.h"

/**
 * @brief  初始化 SPI1
 * @note   完全使用寄存器直接访问，不使用 HAL 库
 *         SPI1 on APB2, GPIOA
 */
void SPI1_Init(void) {
  /* ---------------- 1. 开启时钟 ---------------- */
  /* 开启 GPIOA 和 SPI1 时钟 */
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // 开启 GPIOA 时钟
  RCC->APB2ENR |= RCC_APB2ENR_SPI1EN; // 开启 SPI1 时钟

  /* ---------------- 2. 配置 GPIO ---------------- */
  /*
   * PA5 (SCK) : 复用推挽输出 (Alternate Function Push-Pull)
   * PA6 (MISO): 浮空输入 (Input Floating) 或 上拉输入
   * PA7 (MOSI): 复用推挽输出 (Alternate Function Push-Pull)
   * PA4 (NSS) : 通用推挽输出 (General Purpose Output Push-Pull) -> 软件片选
   */

  /* 清除 PA4, PA5, PA6, PA7 的配置位 (CNF & MODE) */
  GPIOA->CRL &=
      ~(GPIO_CRL_CNF4 | GPIO_CRL_MODE4 | GPIO_CRL_CNF5 | GPIO_CRL_MODE5 |
        GPIO_CRL_CNF6 | GPIO_CRL_MODE6 | GPIO_CRL_CNF7 | GPIO_CRL_MODE7);

  /* 配置 PA5 (SCK) -> 复用推挽 (CNF=10), 速度 50MHz (MODE=11) => 0xB */
  GPIOA->CRL |= (GPIO_CRL_CNF5_1 | GPIO_CRL_MODE5);

  /* 配置 PA7 (MOSI) -> 复用推挽 (CNF=10), 速度 50MHz (MODE=11) => 0xB */
  GPIOA->CRL |= (GPIO_CRL_CNF7_1 | GPIO_CRL_MODE7);

  /* 配置 PA6 (MISO) -> 浮空输入 (CNF=01), 模式输入 (MODE=00) => 0x4 */
  /* 注意：根据参考手册，全双工主模式下 MISO 应配置为浮空输入或上拉输入 */
  GPIOA->CRL |= GPIO_CRL_CNF6_0;

  /* 配置 PA4 (NSS) -> 通用推挽输出 (CNF=00), 速度 50MHz (MODE=11) => 0x3 */
  GPIOA->CRL |= GPIO_CRL_MODE4;

  /* 拉高 CS 引脚 (空闲状态) */
  GPIOA->BSRR = SPI1_PIN_NSS; // Set PA4

  /* ---------------- 3. 配置 SPI1 寄存器 ---------------- */
  /*
   * 复位 SPI1 寄存器 (可选，确保纯净状态)
   * RCC->APB2RSTR |= RCC_APB2RSTR_SPI1RST;
   * RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI1RST;
   */

  /* 配置 CR1 寄存器 */
  /*
   * BR[2:0]: 波特率预分频. fPCLK2 (72MHz) / 8 = 9MHz
   * CPOL=0, CPHA=0 (Mode 0)
   * DFF=0 (8-bit)
   * LSBFIRST=0 (MSB First)
   * SSM=1, SSI=1 (软件管理 NSS, 且内部 NSS 信号置高，避免进入 ModF 错误)
   * MSTR=1 (主模式)
   */
  SPI1->CR1 = 0; // 清除 CR1

  SPI1->CR1 |= (0x02 << SPI_CR1_BR_Pos); // BR = fPCLK/8 (010)

  SPI1->CR1 |=
      SPI_CR1_CPOL; // CPOL=1 (Idle High) - Wait, standard is often Mode 0 or 3.
                    // User said "Default". Let's stick to Mode 0 (CPOL=0,
                    // CPHA=0) as it's most common for simple Flash/Sensor.
                    // ERROR CORRECTION: I wrote CPOL=1 in comment above but
                    // code sets it. Let's use Mode 3 (CPOL=1, CPHA=1) or Mode
                    // 0? "Default" usually implies Reset state which is Mode 0.
                    // I will use Mode 0.
  SPI1->CR1 &= ~SPI_CR1_CPOL; // CPOL=0
  SPI1->CR1 &= ~SPI_CR1_CPHA; // CPHA=0

  SPI1->CR1 |= SPI_CR1_SSM;  // 软件 NSS 管理
  SPI1->CR1 |= SPI_CR1_SSI;  // Internal NSS High (Master)
  SPI1->CR1 |= SPI_CR1_MSTR; // 主模式

  /* 使能 SPI1 */
  SPI1->CR1 |= SPI_CR1_SPE;
}

/**
 * @brief  SPI1 读写一个字节 (全双工)
 * @param  TxData: 要发送的数据
 * @return 接收到的数据
 */
uint8_t SPI1_ReadWriteByte(uint8_t TxData) {
  /* 1. 等待发送缓冲区为空 (TXE) */
  while (!(SPI1->SR & SPI_SR_TXE)) {
    /* 可以添加超时处理 */
  }

  /* 2. 写入数据寄存器，开始发送 */
  SPI1->DR = TxData;

  /* 3. 等待接收缓冲区非空 (RXNE) */
  while (!(SPI1->SR & SPI_SR_RXNE)) {
    /* 可以添加超时处理 */
  }

  /* 4. 读取数据寄存器 (这会清除 RXNE 标志) */
  return (uint8_t)(SPI1->DR);
}

/**
 * @brief  SPI1 发送缓冲区数据
 * @param  pData: 数据指针
 * @param  Size: 数据长度
 */
void SPI1_Transmit(uint8_t *pData, uint16_t Size) {
  uint16_t i;
  for (i = 0; i < Size; i++) {
    SPI1_ReadWriteByte(pData[i]);
    /* 忽略接收到的数据 */
  }
}

/**
 * @brief  SPI1 接收数据到缓冲区
 * @param  pData: 接收缓冲区指针
 * @param  Size: 数据长度
 */
void SPI1_Receive(uint8_t *pData, uint16_t Size) {
  uint16_t i;
  for (i = 0; i < Size; i++) {
    /* 发送 Dummy Byte (0xFF) 以产生时钟并读取数据 */
    pData[i] = SPI1_ReadWriteByte(0xFF);
  }
}

/**
 * @brief  控制 CS (NSS) 引脚电平
 * @param  State: 0 (Low/Select), 1 (High/Deselect)
 */
void SPI1_SetCS(uint8_t State) {
  if (State) {
    /* Set PA4 High */
    GPIOA->BSRR = SPI1_PIN_NSS;
  } else {
    /* Reset PA4 Low */
    GPIOA->BRR = SPI1_PIN_NSS;
  }
}
