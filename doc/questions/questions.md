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

## 自定义 Bootloader 与系统 Bootloader 的区别（含 BOOT0/BOOT1）

- **日期**：2026-02-10（更新：2026-02-13）
- **分类**：#知识盲点
- **技术**：STM32, Bootloader, BOOT0, BOOT1

### 问题描述

不清楚自己写的自定义 Bootloader 和 STM32 内置的系统 Bootloader（ROM 中的）的区别，误以为需要拉高 BOOT0 引脚或配置 BOOT1 才能进入自己的 Bootloader。

### STM32F1 完整启动模式表

| BOOT0 | BOOT1 | 启动位置 | 说明 |
|-------|-------|---------|------|
| 0 | x（任意） | **主 Flash**（0x08000000） | 正常运行模式，从 Flash 加载用户程序 |
| 1 | 0 | **System Memory**（ROM） | 进入 ST 原厂系统 Bootloader，支持串口/USB 烧录 |
| 1 | 1 | **内置 SRAM**（0x20000000） | 从 SRAM 启动，通常用于调试 |

> **BOOT1 只在 BOOT0=1 时才有意义**。当 BOOT0=0 时，无论 BOOT1 接高还是接低，MCU 都从主 Flash 启动。

### 自定义 Bootloader vs 系统 Bootloader

| 类型 | 位置 | BOOT0 | 进入方式 |
|------|------|-------|---------|
| 系统 Bootloader | ROM（出厂固化） | BOOT0=1, BOOT1=0 | 拉高 BOOT0 + 复位 |
| 自定义 Bootloader | Flash 0x08000000 | BOOT0=0 | 正常上电启动即可 |

### 实际测试接线

- **BOOT0 接 GND（或拉低）**：确保从 Flash 启动
- **BOOT1 无需关心**：BOOT0=0 时 BOOT1 被忽略
- **首次烧录**：用 ST-Link 将你的 Bootloader 烧入 Flash
- **后续更新**：上电后 Bootloader 自动运行，通过 USART1 接收应用固件

### 解决方案

自定义 Bootloader 就是一个普通 Flash 程序，MCU 上电后从 Flash 启动，先运行 Bootloader，再由 Bootloader 决定是否跳转到 APP（0x08004000）。**不需要动 BOOT0/BOOT1 引脚，保持默认从 Flash 启动即可。**

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

## 串口数据位与 Flash 半字写入对齐

- **日期**：2026-02-11
- **分类**：#知识盲点
- **技术**：STM32, USART, FLASH, 嵌入式开发

### 背景信息

- **正在实现的功能**：实现 USART Bootloader 的 Flash 写入功能
- **当前操作**：明确 `HAL_UARTEx_RxEventCallback` 参数含义及 Flash 写入限制

### 问题描述

1. **串口发送单元**：确认了 STM32 串口在标准 8 位配置下是按字节（Byte）发送的。
2. **回调参数**：`HAL_UARTEx_RxEventCallback` 中的 `Size` 参数表示本次接收到的实际字节数。
3. **Flash 写入约束**：Flash 写入前必须先擦除（恢复为 0xFF），否则无法正确写入。
4. **对齐与拼接**：STM32F1 的 Flash 编程通常要求按 16 位半字（Half-word）进行。如果接收到的字节包长度为奇数，最后一个字节无法直接写入，需要与后续数据拼接组合成半字。

### 解决方案

1. **基本原则**：始终确保目标地址在写入前已处于擦除态。
2. **字节流处理**：使用静态变量或缓存区保存未能凑成半字的“孤儿字节”。
3. **逻辑拼接**：当新字节到来时，与缓存字节组合成 `uint16_t` 后调用 `HAL_FLASH_Program`。在数据流结束时，若仍有剩余字节，使用 `0xFF` 填充高位后强制写入。

---

## 流式数据处理：枚举四分支 vs 线性逻辑

- **日期**：2026-02-11
- **分类**：#知识盲点 | #优化
- **技术**：C语言, 逻辑设计, 嵌入式开发

### 背景信息

- **正在实现的功能**：USART Bootloader 的跨包 Flash 写入（需处理 16 位对齐）
- **当前操作**：对比“枚举所有可能性”与“线性流式处理”两种实现方案

### 问题描述

在处理需要跨包拼接的数据流（如串口收到的字节流拼成 16 位写入 Flash）时，容易陷入**枚举所有组合**的误区：
- **组合状况**：(上次剩/没剩) × (本次包奇/偶) = **4 种独立情况**。
- **存在的弊端**：
    1. **代码冗余**：每个分支内都要写类似的 `for` 循环。
    2. **地址计算复杂**：接力写入（Cross-packet relay）会产生 `address + i + 1` 这种偏移，极易算错导致覆盖错误。
    3. **容易丢失数据**：在枚举逻辑中，很难保证 `last_byte` 在每一个分支都被正确提取、拼接并写入。
    4. **边界风险**：如果新包长度只有 1，多层嵌套的 `if-else` 和循环条件极易触发越界或逻辑跳空。

### 解决方案

采用**线性流式处理（Linear Processing）**，不再关注包的奇偶性，而是关注“数据对”的提取：

1. **Step 1: 处理接力（Relay）**：如果上次剩了 1 字节且本次有新数据，强行拼成第 1 对并写入，移动地址和本次数据的起点。
2. **Step 2: 批量处理（Batch）**：从新起点开始，循环提取成对的字节写入。
3. **Step 3: 存留残余（Remainder）**：处理完所有成对数据后，如果最后还剩 1 个字节，存入缓存供下次使用。

**心得**：优秀的嵌入式逻辑应该像流水线一样处理数据，而不是通过复杂的条件判断去“硬套”各种排列组合。

---

## 如何建立严谨的底层逻辑思维

- **日期**：2026-02-12
- **分类**：#经验总结 | #成长记录
- **技术**：逻辑设计, 嵌入式开发, 严谨性训练

### 背景信息

- **正在实现的功能**：USART Bootloader 的 Flash 写入逻辑
- **当前操作**：反思为什么逻辑设计容易出现“不严谨”的情况

### 核心启示：严谨性四心法

1.  **从“状态枚举”向“流式处理”转变**：
    - 避开复杂的嵌套 `if-else`。
    - 将数据看作一条流，设计一个通用的线性处理过程。
    - **逻辑准则**：代码分支越少，潜伏的 Bug 越少。

2.  **极端边界推演（0, 1, 2 法则）**：
    - 每次写完涉及下标的代码，手动模拟长度为 **0（空包）**、**1（单字节包）**、**2（刚好成对）** 的情况。
    - 如果这三个点能通，逻辑通常是稳定的。

3.  **现状优于猜测（State vs Guess）**：
    - 永远相信指针的位置（如 `i < len`），而不是推算出来的属性（如 `len % 2`）。
    - 指针停在哪里，哪里就是真实的现场。

4.  **纸上推演（Dry Run）**：
    - 涉及位偏移和下标计算时，必须先在笔纸上画出内存分布。
    - **金句**：如果你在草稿纸上都画不顺逻辑，写出的代码一定会崩。

### 总结

严谨性不是天赋，而是一种受过训练的**肌肉记忆**。在底层开发中，“慢即是快”，花时间推演逻辑能节省数倍的硬件调试时间。

---

## Flash 跨页擦除逻辑设计

- **日期**：2026-02-13
- **分类**：#已解决 | #经验总结
- **技术**：STM32, Flash, 嵌入式开发, 逻辑设计

### 背景信息

- **正在实现的功能**：USART Bootloader 的 Flash 按页擦除功能（`USART_Bootloader_EraseFlash`）
- **当前操作**：需要在写入前检查目标区域是否有脏数据，如果有则擦除对应页，并支持跨页擦除

### 问题描述

从单页擦除升级到跨页擦除时，遇到了三个关键问题：
1. **页地址计算错误**：最初用 `appStartAddress - (offset - appStartAddress) % FLASH_PAGE_SIZE` 计算页起始地址，公式逻辑不对
2. **只擦除一页**：只找到第一个脏字节就 break，擦除操作放在循环外面，导致只擦了最后一页
3. **死循环**：改成 `while` 后，如果某页全是 `0xFF`（干净页），循环变量不推进，导致无限循环

### 问题代码

```c
// 版本1：页地址计算错误 + 只擦一页
for (uint32_t i = 0; i < usart_buffer_length; i++) {
    if (flash_data != 0xFF) {
        erase_page_address =
            appStartAddress - (flash_data_offset - appStartAddress) % FLASH_PAGE_SIZE;
        break;
    }
}
// 擦除在循环外 → 只擦最后一页

// 版本2：死循环风险
while (flash_data_offset < usart_buffer_length) {
    for (; i < FLASH_PAGE_SIZE; i++) { // i 不跨页，干净页不推进 → 死循环
        ...
    }
}
```

### 解决代码

```c
uint32_t i = 0;
HAL_FLASH_Unlock();
while (i < usart_buffer_length) {
    uint32_t address = appStartAddress + i;
    uint32_t page_StartAddress = address - (address % FLASH_PAGE_SIZE);
    uint32_t page_EndAddress = page_StartAddress + FLASH_PAGE_SIZE;
    uint8_t need_erase = 0;

    for (uint32_t j = address; j < page_EndAddress && (j - appStartAddress) < usart_buffer_length; j++) {
        if (*(volatile uint8_t *)(j) != 0xFF) {
            need_erase = 1;
            break;
        }
    }
    if (need_erase) {
        // 立即擦除当前页
        HAL_FLASHEx_Erase(&EraseInit, &PageError);
    }
    i += FLASH_PAGE_SIZE; // 无论是否擦除，都跳到下一页
}
HAL_FLASH_Lock();
```

### 深度复盘 (Deep Analysis)

- **思维误区**：习惯了单次操作的思维，把"找到一个就退出"的模式直接套到了需要遍历多页的场景。擦除放在循环外是单页思维的残留。
- **模式识别**：这是"按块步进遍历"模式——处理 Flash/磁盘等按页/扇区组织的存储时，循环变量应该以块大小为步长推进，而不是逐字节 `i++`。
- **防御机制**：
  1. 循环内的操作应该是"自包含"的——每轮循环完成一个完整的"检查+操作"单元
  2. 确保每条路径（找到脏数据 / 未找到）都能推进循环变量，避免死循环
  3. `appStartAddress` 假设为页对齐地址，若不确定应加 `assert` 检查

### 解决方案

采用"按页步进 + 页内扫描 + 即时擦除"的三段式结构：每轮 `while` 处理一页，用内层 `for` 扫描该页是否有脏数据，发现即擦除，最后 `i += FLASH_PAGE_SIZE` 无条件跳到下一页。

---

## 先画后写：写函数前的三问法

- **日期**：2026-02-13
- **分类**：#经验总结 | #成长记录
- **技术**：逻辑设计, 嵌入式开发, 方法论

### 背景信息

- **正在实现的功能**：USART Bootloader 的 Flash 跨页擦除功能
- **当前操作**：擦除函数本身逻辑正确，但集成到回调时漏掉了"调用擦除"和"地址偏移"，导致整体流程不通

### 问题描述

擦除函数 `USART_Bootloader_EraseFlash` 独立来看逻辑正确，但放到整体代码中时：
1. 回调里根本没调用擦除函数（只有注释）
2. `WriteFlash` 写入地址没有加 `flash_offset`，每次都写到同一个位置
3. Flash 解锁/上锁在三层（回调、擦除、写入）中重复

**根本原因**：写函数时只关注了"这个函数内部怎么做"，没有先想清楚"这个函数在整体流程中扮演什么角色"。

### 深度复盘 (Deep Analysis)

- **思维误区**：陷入了"局部完美主义"——花大量精力打磨单个函数的内部逻辑，却忽视了它与上下游的连接关系
- **模式识别**：这是"只见树木不见森林"的错误——函数写完了，但没有检查调用链是否完整
- **防御机制**：采用"先画后写"方法论（见下方）

### 解决方案：先画后写（三问法）

**写任何函数之前，花 1 分钟回答三个问题：**

| 问题 | 含义 | 示例（擦除函数） |
|------|------|-----------------|
| ① 输入是什么？ | 谁调用我？参数从哪来？ | 回调调用，传入 `APP_START_ADDRESS + flash_offset` 和 `Size` |
| ② 输出到哪？ | 结果给谁用？影响什么状态？ | 擦除对应的 Flash 页，为后续写入做准备 |
| ③ 画调用链 | 完整的数据流是什么？ | 中断 → 擦除 → 写入 → 更新偏移 → 重新接收 |

**示例调用链草图：**

```
串口中断触发
  └→ HAL_UARTEx_RxEventCallback(Size)
       ├→ EraseFlash(APP_START_ADDRESS + flash_offset, Size)   // 先擦
       ├→ WriteFlash(APP_START_ADDRESS + flash_offset, buf, Size) // 再写
       ├→ flash_offset += Size                                    // 更新
       └→ ReceiveToIdle_IT(...)                                   // 继续收
```

### 底层开发通用思维模式速查

| 思维模式 | 何时使用 | 关键特征 |
|---------|---------|---------|
| 按块步进 | Flash 擦除/写入、DMA 传输 | 循环步长 = 块大小，不是 `i++` |
| 流式处理 | 串口数据、协议解析 | 不关心包边界，只关心"数据对"的提取 |
| 状态机 | 协议交互、多阶段流程 | 用状态变量驱动，每个状态只做一件事 |
| 先画后写 | 任何涉及地址/偏移/多函数协作的场景 | 动手前画出调用链和内存布局 |

### 核心心得

**快和严谨不矛盾**——"先画后写"看起来多花了 1 分钟画图，但能省掉后面 30 分钟的调试。速度是严谨的副产品，会随着经验自然提升。

---
