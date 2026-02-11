# 问题记录

---

## CMake 添加源文件和头文件的正确用法

- **日期**：2026-02-09
- **分类**：#理解错误
- **技术**：CMake, STM32, 嵌入式开发

### 问题描述

在 CMakeLists.txt 中添加源文件和头文件时，混淆了两个命令的参数类型：

1. **`target_sources` 错误**：传入了目录路径 `Core/Src`，但该命令需要的是**具体的源文件路径**（如 `Core/Src/main.c`）

2. **`target_include_directories` 错误**：传入了头文件路径 `Core/interface/usart_bootloader.h`，但该命令需要的是**目录路径**（如 `Core/interface`）

### 解决方案

| 命令 | 用途 | 参数类型 |
|------|------|----------|
| `target_sources` | 添加源文件（.c/.cpp） | **具体文件路径**（不能是目录） |
| `target_include_directories` | 添加头文件搜索路径 | **目录路径**（不能是文件） |

正确示例：
```cmake
# 添加源文件 - 需要具体文件
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/interface/usart_bootloader.c
)

# 添加头文件目录 - 需要目录路径
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/interface
)
```

---

## 自定义 Bootloader 与系统 Bootloader 的区别

- **日期**：2026-02-10
- **分类**：#知识盲点
- **技术**：STM32, Bootloader, BOOT0

### 问题描述

不清楚自己写的自定义 Bootloader 和 STM32 内置的系统 Bootloader（ROM 中的）的区别，误以为需要拉高 BOOT0 引脚才能进入自己的 Bootloader。

### 解决方案

| 类型 | 位置 | BOOT0 | 进入方式 |
|------|------|-------|---------|
| 系统 Bootloader | ROM（出厂固化） | BOOT0=1 | 拉高 BOOT0 + 复位 |
| 自定义 Bootloader | Flash 0x08000000 | BOOT0=0 | 正常上电启动即可 |

自定义 Bootloader 就是一个普通 Flash 程序，MCU 上电后从 Flash 启动，先运行 Bootloader，再由 Bootloader 决定是否跳转到 APP（0x08004000）。**不需要动 BOOT0 引脚。**

---

## STM32F103xE Flash 页地址计算

- **日期**：2026-02-10
- **分类**：#知识盲点
- **技术**：STM32, Flash, 嵌入式开发

### 问题描述

不清楚 STM32F103xE 每页 2KB 的 Flash 地址是如何排布和计算的。

### 解决方案

每页大小 2KB = `0x800` 字节，从 `0x08000000` 开始连续排列：

- **页起始地址** = `0x08000000 + 页号 × 0x800`
- **已知任意地址求页起始** = `addr & 0xFFFFF800`
- **已知长度求页数** = `(length + 0x7FF) / 0x800`（向上取整）

关键页地址：第 0 页 `0x08000000`，第 8 页 `0x08004000`（APP 起始），第 32 页 `0x08010000`（测试区域）。

---
