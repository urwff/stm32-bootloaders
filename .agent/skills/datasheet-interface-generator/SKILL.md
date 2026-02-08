---
name: datasheet-interface-generator
description: Generate peripheral driver interfaces based on user-provided register definition headers and datasheet knowledge. Use this skill when the user wants to create a bare-metal driver (NO HAL) for a specific hardware peripheral referencing existing headers.
---

# Datasheet Interface Generator

This skill helps you generate C driver code for hardware peripherals by analyzing existing register definition header files provided by the user. It strictly avoids HAL libraries, prioritizing direct register access and Chinese comments consistent with datasheet terminology.

## Core Philosophy

1.  **No HAL**: Do not use `HAL_Init`, `HAL_GPIO_WritePin`, etc. Use direct pointer access (e.g., `GPIOA->ODR`).
2.  **Respect User Definitions**: Use the `typedef struct` and `#define` macros from the user's header file. Do not invent new structures.
3.  **Datasheet Fidelity**: Logic must follow the standard hardware flow.
4.  **Chinese Comments**: All comments, especially those explaining register operations, MUST be in Simplified Chinese.
5.  **Use Simplified Macros**: Prefer simplified bit-definition macros (e.g., `RCC_APB2ENR_USART1EN`, `USART_SR_TXE`) over magic numbers. Use `_Pos`/`_Msk` macros only when necessary for multi-bit fields.

## Detailed Process

### 1. Preparation & Assets

**First**, load the template assets to understand the expected structure:
-   `assets/driver_template.h`
-   `assets/driver_template.c`

**Next**, identify the target:
-   **Target Peripheral**: (e.g., `USART1`, `SPI2`, `I2C1`).
-   **Header File**: The file defining the registers (e.g., `stm32f10x.h`).

If the user hasn't provided the header file path, ask for it or search for it in standard locations like `Drivers/CMSIS/...`.

### 2. Analysis Step

**Phase A: Search for Datasheets**
1.  Check for a `doc` directory in the current workspace or project root.
2.  If found, list its contents to see if there are relevant PDF datasheets (e.g., `STM32F103_ReferenceManual.pdf`).
3.  **If a relevant PDF is found**, YOU MUST use the `pdf` skill (to extract text) or `read_resource` (if it's a small text file) to consult it for specific register details, especially if the user asks for complex features.

**Phase B: Read Header File**
**READ** the user's header file using `view_file` or `grep_search`. Look for:
1.  **Peripheral Struct**: `typedef struct { ... } USART_TypeDef;`
2.  **Base Address**: `#define USART1 ((USART_TypeDef *)USART1_BASE)`
3.  **Simplified Bit Macros**: Search for macros like `RCC_APB2ENR_USART1EN`, `USART_SR_TXE`, `USART_CR1_UE` that can be used directly in bit operations. These avoid magic numbers and improve readability.
4.  **Multi-bit Field Macros** (use sparingly): If configuring multi-bit fields (e.g., baud rate divider, prescaler), look for `_Pos` and `_Msk` macros.

### 3. Interaction Step

Before generating code, **YOU MUST** clarify the hardware configuration. Ask the user:

1.  **Clock Source**: Which APB/AHB bus is this peripheral on? (Crucial for `RCC` setup).
2.  **Pin Mapping**: Which GPIO pins are used? (Remap needed?).
3.  **Mode**: Polling, Interrupt, or DMA?
4.  **Functional Requirements**: What specific features are needed? (e.g., "Just basic TX/RX" or "Hardware flow control").

**Wait for the user's response.**

### 4. Generation Step

Generate `driver.h` and `driver.c` based on the **Assets** you read in Step 1.

#### Header (`.h`)
-   Adapt `assets/driver_template.h`.
-   Include the *correct* user header.
-   Define configuration structs if necessary.

#### Source (`.c`)
-   Adapt `assets/driver_template.c`.
-   Implement `Init` following the sequence: **Clock Enable -> GPIO Config -> Peripheral Config**.
-   **CRITICAL**: Add comments in Chinese explaining *every* register manipulation step.
    -   *Good*: `// 等待发送寄存器为空 (TXE)`
    -   *Bad*: `// Wait for TXE`

## Quality Checklist

-   [ ] Did I check the `doc` folder for datasheets?
-   [ ] Did I include the correct user header?
-   [ ] Did I avoid `#include "stm32f1xx_hal.h"`?
-   [ ] Are register names exactly as they appear in the user's header?
-   [ ] Did I use simplified bit macros (e.g., `USART_SR_TXE`) instead of magic numbers?
-   [ ] Are comments in Chinese and descriptive?
-   [ ] Did I use the templates from `assets/` as a base?
