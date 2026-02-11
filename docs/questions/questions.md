
## 为什么要重写 HAL_UARTEx_RxEventCallback 回调函数

- **日期**：2026-02-09
- **分类**：#知识盲点
- **技术**：STM32, HAL库, UART

### 问题描述

用户询问为什么需要重写 HAL_UARTEx_RxEventCallback，特别是在使用 HAL_UARTEx_ReceiveToIdle_IT 时。

### 解决方案

1.  HAL 库的 RxEventCallback 是弱定义 (__weak)，用户必须重写以实现业务逻辑。
2.  配合 HAL_UARTEx_ReceiveToIdle_IT 使用时，该回调在 IDLE（空闲）中断或半满/满中断时触发。
3.  重写目的：
    *   获取接收到的数据长度 (Size)。
    *   处理数据（如写入 Flash）。
    *   **关键**：重新调用 HAL_UARTEx_ReceiveToIdle_IT 以启动下一次接收，否则串口接收会停止。

---

## extern 关键字的作用是什么

- **日期**：2026-02-09
- **分类**：#知识盲点
- **技术**：C语言, 关键字

### 问题描述

用户询问 extern 关键字的作用。

### 解决方案

1.  **变量声明**：用于跨文件共享全局变量（如 extern UART_HandleTypeDef huart1;），告诉编译器变量定义在其他源文件中。
2.  **函数声明**：声明函数原型（虽然函数默认是 extern，但通常显式声明以便引用）。
3.  **extern "C"**：在 C++ 代码中调用 C 语言函数，避免 C++ 编译器的名字修饰（Name Mangling）。

---

## ELF 文件与 HEX 文件的区别及生成方法

- **日期**：2026-02-09
- **分类**：#知识盲点 #已解决
- **技术**：CMake, 编译原理, 烧录文件

### 问题描述

用户询问 ELF 文件和 Keil 生成的 HEX 文件的区别，以及当前 CMake 项目生成的是哪种文件。随后要求在 CMake 构建流程中添加 HEX 和 BIN 文件的自动生成。

### 解决方案

1.  **区别**：
    *   **ELF (Executable and Linkable Format)**：包含机器码、数据、**调试信息**（符号表、源代码行号引用等），用于调试和分析，体积较大。
    *   **HEX (Intel HEX)**：仅包含机器码和数据，是纯文本格式，不支持调试信息，专用于烧录器烧录，体积较小。
    *   **BIN (Binary)**：纯二进制流，无地址信息，最紧凑，常用于 IAP 升级。

2.  **CMake 生成配置**：
    在 `CMakeLists.txt` 中使用 `add_custom_command` 调用 `objcopy` 工具进行格式转换：
    ```cmake
    add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.hex
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${CMAKE_PROJECT_NAME}.bin
        COMMENT "Building ${CMAKE_PROJECT_NAME}.hex and ${CMAKE_PROJECT_NAME}.bin"
    )
    ```

---

## STM32 Flash 页起始地址计算方法

- **日期**：2026-02-10
- **分类**：#已解决 #知识盲点
- **技术**：STM32, Flash, C语言, 算法

### 问题描述

在 STM32 驱动开发中，计算 Flash 页面起始地址时，理解 `(Addr) % PAGE_SIZE` 与 `(Addr) - (Addr) % PAGE_SIZE` 的区别。

### 解决方案

1.  **`(Addr) % PAGE_SIZE`**：算出的是**余数**，即该地址在当前页面内的**偏移量 (Offset)**。
2.  **`(Addr) - (Addr) % PAGE_SIZE`**：用当前地址减去偏移量，算出的是该页的**起始地址 (Base Address)**。
3.  **更优写法（位运算）**：
    如果 `PAGE_SIZE` 是 2 的整数次幂（如 1024, 2048），使用位运算效率更高：
    ```c
    Addr & ~(PAGE_SIZE - 1)
    ```
    例如 `PAGE_SIZE` 为 1024 (0x400) 时，`PAGE_SIZE - 1` 为 `0x3FF`。按位取反后再与地址相与，会抹除地址的低 10 位，从而得到页首地址。

---

## HAL_UARTEx_RxEventCallback 回调函数存在多个逻辑错误

- **日期**：2026-02-10
- **分类**：#已解决
- **技术**：STM32, Flash, UART, Bootloader

### 问题描述

`usart_bootloader.c` 中 `HAL_UARTEx_RxEventCallback` 回调函数存在以下 6 个逻辑错误：

1. **只擦除不写入**：擦除 Flash 后没有调用 `USART_Bootloader_WriteFlash()` 将 `receive_buffer` 数据写入，导致接收的数据直接丢失。
2. **跨页擦除未处理**：只在遇到第一个非 `0xFF` 字节时计算并擦除一页，如果数据跨越两个页面，第二页不会被擦除，后续写入会失败。
3. **`HAL_FLASHEx_Erase` 第二个参数传了 `NULL`**：`PageError` 参数应传 `uint32_t` 变量指针，传 `NULL` 可能导致 HardFault。
4. **`for` 循环变量 `i` 为 `uint8_t`，最大 255**：`Size` 为 `uint16_t`（最大 512），当 `Size > 255` 时 `i` 溢出导致无限循环。
5. **缺少 `HAL_FLASH_Lock()`**：`HAL_FLASH_Unlock()` 后无论走哪个分支都没有重新加锁，Flash 保持解锁状态存在安全隐患。
6. **逐字节检查擦除条件低效**：应直接根据 `flash_offset` 是否对齐到页边界来决定擦除，或在烧录前一次性擦除整个 APP 区域。

### 解决方案

正确的回调逻辑应为：
1. 计算写入地址和涉及的页面范围，按需擦除。
2. 调用 `USART_Bootloader_WriteFlash()` 写入数据。
3. 更新 `flash_offset`。
4. 调用 `HAL_FLASH_Lock()` 重新加锁。
5. 循环变量改为 `uint16_t`，`HAL_FLASHEx_Erase` 传入有效的 `&PageError`。

---

## HAL_UARTEx_RxEventCallback 的 Size 参数含义

- **日期**：2026-02-11
- **分类**：#知识盲点
- **技术**：STM32, HAL库, UART

### 问题描述

混淆了 `HAL_UARTEx_RxEventCallback(huart, Size)` 中 `Size` 参数的含义，误以为它是缓冲区大小。

### 解决方案

`Size` 是**本次实际接收到的字节数**，不是缓冲区容量。例如调用 `HAL_UARTEx_ReceiveToIdle_IT(&huart1, buf, 512)` 时 512 是最大容量，但对方只发了 100 字节后线路空闲，则回调中 `Size = 100`。触发回调的三种情况：
1. **IDLE 空闲中断** — 对方发完数据后线路空闲
2. **半满中断** — 接收到缓冲区一半（DMA 模式）
3. **接收完成** — 缓冲区被填满

---

## 写入循环和偏移量更新中误用 receive_len 替代 Size

- **日期**：2026-02-11
- **分类**：#已解决
- **技术**：STM32, Flash, UART, Bootloader

### 问题描述

在 `HAL_UARTEx_RxEventCallback` 中，写入循环和偏移量更新错误地使用了累加的 `receive_len` 而非当前接收的 `Size`：
- `for (uint16_t i = 0; i < receive_len; i++)` — 应为 `Size`
- `flash_offset += receive_len` — 应为 `Size`

导致第二次接收时写入长度翻倍（如：第一次 100，第二次写 200），Flash 写入越界且数据错误。同时还出现了两行重复的 `HAL_FLASH_Lock()` 调用。

### 解决方案

- 写入循环条件改为 `i < Size`
- 偏移量更新改为 `flash_offset += Size`
- 删除重复的 `HAL_FLASH_Lock()`
- 牢记：`receive_buffer` 每次回调后被 `memset` 清零，其中只有 `Size` 字节是本次有效数据

---

## printf 重定向在 GCC 工具链下不生效

- **日期**：2026-02-11
- **分类**：#已解决
- **技术**：STM32, GCC, printf, UART

### 问题描述

在 `usart.c` 中通过重写 `fputc()` 重定向 `printf` 到 USART1，但实际打印无输出。原因有二：
1. **GCC/Newlib 不走 `fputc`**：GCC 工具链的 `printf` 底层调用的是 `_write()` 而非 `fputc()`，`fputc` 重定向仅适用于 Keil/ARMCC。
2. **收发共用 USART1 冲突**：`HAL_UART_Transmit`（阻塞发送）和 `HAL_UARTEx_ReceiveToIdle_IT`（中断接收）共用同一个 UART 句柄，UART 内部状态可能返回 `HAL_BUSY`。

### 解决方案

- **GCC 下**：重写 `syscalls.c` 中的 `_write()` 函数，或者绕过 `printf`，直接用 `sprintf` + `HAL_UART_Transmit` 发送。
- **冲突问题**：条件允许时用不同串口分别做调试输出和数据接收；单串口场景下注意 UART 状态管理。

---
