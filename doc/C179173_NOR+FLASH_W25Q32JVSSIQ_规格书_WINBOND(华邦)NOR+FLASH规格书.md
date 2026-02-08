# spiflash

# 3V 32M-BIT SERIAL FLASH MEMORY WITH DUAL, QUAD SPI

For Industrial & Industrial Plus Grade 

# Table of Contents

1. GENERAL DESCRIPTIONS. 4 

2. FEATURES.. 4 

3. PACKAGE TYPES AND PIN CONFIGURATIONS . 5 

3.1 Pin Configuration SOIC 150/208-mil & VSOP 208-mil... ... 5 

3.2 Pad Configuration WSON 6x5-mm/ 8X6-mm, XSON 4x4-mm . 5 

3.3 Pin Description SOIC 150/208-mil, VSOP 208-mil, WSON 6x5-mm/8x6-mm, XSON 4x4- mm 5 

3.4 Pin Configuration SOIC 300-mil . . 6 

3.5 Pin Description SOIC 300-mil. . 6 

3.6 Ball Configuration TFBGA 8x6-mm (5x5 or 6x4 Ball Array) . 

3.7 Ball Description TFBGA 8x6-mm ....... ... 7 

3.8 Pin Configuration PDIP 300-mil.. . 8 

3.9 Pin Description PDIP 300-mil . . 8 

4. PIN DESCRIPTIONS.. 9 

4.1 Chip Select (/CS) .. . 9 

4.2 Serial Data Input, Output and IOs (DI, DO and IO0, IO1, IO2, IO3) ........... ... 9 

4.3 Write Protect (/WP).. . 9 

4.4 HOLD (/HOLD) ...... .. 9 

4.5 Serial Clock (CLK) .. . 9 

4.6 Reset (/RESET)(1) . . 9 

5. BLOCK DIAGRAM. .10 

6. FUNCTIONAL DESCRIPTIONS. .11 

6.1 Standard SPI Instructions. .11 

6.2 Dual SPI Instructions .. .11 

6.3 Quad SPI Instructions.. .11 

6.4 Software Reset & Hardware /RESET pin.. .11 

6.5 Write Protection . .12 

Write Protect Features. .12 

7. STATUS AND CONFIGURATION REGISTERS. . 13 

7.1 Status Registers . .13 

Erase/Write In Progress (BUSY) – Status Only ... .13 

Write Enable Latch (WEL) – Status Only... .13 

Block Protect Bits (BP2, BP1, BP0) – Volatile/Non-Volatile Writable.. .13 

Top/Bottom Block Protect (TB) – Volatile/Non-Volatile Writable. .14 

Sector/Block Protect Bit (SEC) – Volatile/Non-Volatile Writable . .14 

Complement Protect (CMP) – Volatile/Non-Volatile Writable ... ..14 

Status Register Protect (SRP, SRL) – Volatile/Non-Volatile Writable.. ..15 

Erase/Program Suspend Status (SUS) – Status Only . .16 

Security Register Lock Bits (LB3, LB2, LB1) – Volatile/Non-Volatile OTP Writable ...........16 

Quad Enable (QE) – Volatile/Non-Volatile Writable. .16 

Write Protect Selection (WPS) – Volatile/Non-Volatile Writable . .17 

# winbond

Output Driver Strength (DRV1, DRV0) – Volatile/Non-Volatile Writable .. ..17 

Reserved Bits – Non Functional . .17 

Status Register Memory Protection $N P S = 0$ , ${ \mathsf { C M P } } = 0$ ) .. .18 

Status Register Memory Protection $N P S = 0$ , CMP $= 1$ ) .... ..19 

Individual Block Memory Protection $N P S { = } 1$ ) . .20 

# 8. INSTRUCTIONS.. .. 21

8.1 Device ID and Instruction Set Tables . .21 

Manufacturer and Device Identification. .21 

Instruction Set Table 1 (Standard SPI Instructions)(1) . .22 

Instruction Set Table 2 (Dual/Quad SPI Instructions)(1). .23 

8.2 Instruction Descriptions . .. 24 

Write Enable (06h).. .24 

Write Enable for Volatile Status Register (50h).. .24 

Write Disable (04h) ... .25 

Read Status Register-1 (05h), Status Register-2 (35h) & Status Register-3 (15h) ...............25 

Write Status Register-1 (01h), Status Register-2 (31h) & Status Register-3 (11h) ...............26 

Read Data (03h) .. .28 

Fast Read (0Bh) .. .29 

Fast Read Dual Output (3Bh) ... ..30 

Fast Read Quad Output (6Bh). .31 

Fast Read Dual I/O (BBh).. .32 

Fast Read Quad I/O (EBh).. .33 

Set Burst with Wrap (77h).. .34 

Page Program (02h) .. ..35 

Quad Input Page Program (32h).. ..36 

Sector Erase (20h)... .37 

32KB Block Erase (52h).... ..38 

64KB Block Erase (D8h).. .39 

Chip Erase (C7h / 60h) ... ..40 

Erase / Program Suspend (75h) .. ..41 

Erase / Program Resume (7Ah).. .42 

Power-down (B9h) .... ..43 

Release Power-down / Device ID (ABh) .. .44 

Read Manufacturer / Device ID (90h) . .45 

Read Manufacturer / Device ID Dual I/O (92h) .. ..46 

Read Manufacturer / Device ID Quad I/O (94h). ..47 

Read Unique ID Number (4Bh).. ..48 

Read JEDEC ID (9Fh) .... ..49 

Read SFDP Register (5Ah)... ..50 

Erase Security Registers (44h) .... ..51 

Program Security Registers (42h).. .52 

Read Security Registers (48h).. .53 

Individual Block/Sector Lock (36h)... .54 

Individual Block/Sector Unlock (39h) . .55 

Read Block/Sector Lock (3Dh).. .56 

# winbond

Global Block/Sector Lock (7Eh) .. .57 

Global Block/Sector Unlock (98h) . .57 

Enable Reset (66h) and Reset Device (99h) .. .58 

# 9. ELECTRICAL CHARACTERISTICS.. .. 59

9.1 Absolute Maximum Ratings (1) . .59 

9.2 Operating Ranges . .59 

9.3 Power-Up Power-Down Timing and Requirements .. 60 

9.4 DC Electrical Characteristics-. .61 

9.5 AC Measurement Conditions . . 62 

9.6 AC Electrical Characteristics(6) . .63 

9.7 Serial Output Timing.. .. 65 

9.8 Serial Input Timing.......... .. 65 

9.9 /WP Timing .. .. 65 

# 10. PACKAGE SPECIFICATIONS .66

10.1 8-Pin SOIC 150-mil (Package Code SN) . .66 

10.2 8-Pin SOIC 208-mil (Package Code SS). .67 

10.3 8-Pin VSOP 208-mil (Package Code ST)..... .. 68 

10.4 8-Pad WSON 6x5-mm (Package Code ZP). .69 

10.5 8-Pad WSON 8x6-mm (Package Code ZE). .70 

10.6 Pad XSON 4x4x0.45-mm (Package Code XG).. .71 

10.7 16-Pin SOIC 300-mil (Package Code SF). .72 

10.8 8-Pin PDIP 300-mil (Package Code DA). .73 

10.10 24-Ball TFBGA 8x6-mm (Package Code TB, 5x5 Ball Array) .74 

10.11 24-Ball TFBGA 8x6-mm (Package Code TC, 6x4 ball array) . .75 

# 11. ORDERING INFORMATION . .. 76

11.1 Valid Part Numbers and Top Side Marking.. .77 

# 12. REVISION HISTORY.. .. 79

# 1. GENERAL DESCRIPTIONS

The W25Q32JV (32M-bit) Serial Flash memory provides a storage solution for systems with limited space, pins and power. The 25Q series offers flexibility and performance well beyond ordinary Serial Flash devices. They are ideal for code shadowing to RAM, executing code directly from Dual/Quad SPI (XIP) and storing voice, text and data. The device operates on 2.7V to 3.6V power supply with current consumption as low as $1 \mu \mathsf { A }$ for power-down. 

The W25Q32JV array is organized into 16,384 programmable pages of 256-bytes each. Up to 256 bytes can be programmed at a time. Pages can be erased in groups of 16 (4KB sector erase), groups of 128 (32KB block erase), groups of 256 (64KB block erase) or the entire chip (chip erase). The W25Q32JV has 1,024 erasable sectors and 64 erasable blocks respectively. The small 4KB sectors allow for greater flexibility in applications that require data and parameter storage. (See Figure 2.) 

The W25Q32JV supports the standard Serial Peripheral Interface (SPI), and a high performance Dual/Quad output as well as Dual/Quad I/O SPI: Serial Clock, Chip Select, Serial Data I/O0 (DI), I/O1 (DO), I/O2, and I/O3. SPI clock frequencies of up to 133MHz are supported allowing equivalent clock rates of 266MHz (133MHz x 2) for Dual I/O and 532MHz (133MHz x 4) for Quad I/O when using the Fast Read Dual/Quad I/O instructions. These transfer rates can outperform standard Asynchronous 8 and 16-bit Parallel Flash memories. 

Additionally, the device supports JEDEC standard manufacturer and device ID and SFDP Register, a 64- bit Unique Serial Number and three 256-bytes Security Registers. 

# 2. FEATURES

 New Family of SpiFlash Memories 

– W25Q32JV: 32M-bit / 4M-byte 

– Standard SPI: CLK, /CS, DI, DO 

– Dual SPI: CLK, /CS, IO0, IO1, 

– Quad SPI: CLK, /CS, IO0, IO1, IO2, IO3 

– Software & Hardware Reset(1) 

 Highest Performance Serial Flash 

– 133MHz Single, Dual/Quad SPI clocks 

– 266/532MHz equivalent Dual/Quad SPI 

– 66MB/S continuous data transfer rate 

– Min. 100K Program-Erase cycles per sector 

– More than 20-year data retention 

 Efficient “Continuous Read” 

– Continuous Read with 8/16/32/64-Byte Wrap 

– As few as 8 clocks to address memory 

– Allows true XIP (execute in place) operation 

– Outperforms X16 Parallel Flash 

 Low Power, Wide Temperature Range 

– Single 2.7V to $3 . 6 \mathsf { V }$ supply 

$- < 1 \mu \mathsf { A }$ Power-down (typ.) 

$\textstyle - 4 0 ^ { \circ } \mathsf { C }$ to $+ 8 5 ^ { \circ } \mathsf { C }$ operating range 

$\textstyle - 4 0 ^ { \circ } \mathsf { C }$ to $+ 1 0 5 ^ { \circ } \mathsf C$ operating range 

 Flexible Architecture with 4KB sectors 

– Uniform Sector/Block Erase (4K/32K/64K-Byte) 

– Program 1 to 256 byte per programmable page 

– Erase/Program Suspend & Resume 

 Advanced Security Features 

– Software and Hardware Write-Protect 

– Special OTP protection(2) 

– Top/Bottom, Complement array protection 

– Individual Block/Sector array protection 

– 64-Bit Unique ID for each device 

– Discoverable Parameters (SFDP) Register 

– 3X256-Bytes Security Registers 

– Volatile & Non-volatile Status Register Bits 

 Space Efficient Packaging 

– 8-pin SOIC/VSOP 150/208-mil 

– 16-pin SOIC 300-mil 

– 8-pin PDIP 300-mil 

– 8-pad WSON 6x5-mm/8x6-mm 

– 8-pad XSON 4x4-mm 

– 24-ball TFBGA 8x6-mm (6x4/5x5 ball array) 

– Contact Winbond for KGD and other options 

# 3. PACKAGE TYPES AND PIN CONFIGURATIONS

# 3.1 Pin Configuration SOIC 150/208-mil & VSOP 208-mil

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/1eae7700e56a99f08eaa0499865d9e676cef869f915f1be5d0e2e3157e87d200.jpg)



Figure 1a. W25Q32JV Pin Assignments, 8-pin SOIC 208-mil (Package Code SN/SS/ ST)


# 3.2 Pad Configuration WSON 6x5-mm/ 8X6-mm, XSON 4x4-mm

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/09de51dbbd2533b5c6cf6addee39548c3a88ca0a376d9a7ae8988333ffbddd28.jpg)



Figure 1b. W25Q32JV Pad Assignments, 8-pad WSON 6x5-mm (Package Code ZP/ZE, XG)


# 3.3 Pin Description SOIC 150/208-mil, VSOP 208-mil, WSON 6x5-mm/8x6-mm, XSON 4x4-mm

<table><tr><td>PAD NO.</td><td>PAD NAME</td><td>I/O</td><td>FUNCTION</td></tr><tr><td>1</td><td>/CS</td><td>I</td><td>Chip Select Input</td></tr><tr><td>2</td><td>DO (IO1)</td><td>I/O</td><td>Data Output (Data Input Output 1)(1)</td></tr><tr><td>3</td><td>/WP (IO2)</td><td>I/O</td><td>Write Protect Input ( Data Input Output 2)(2)</td></tr><tr><td>4</td><td>GND</td><td></td><td>Ground</td></tr><tr><td>5</td><td>DI (IO0)</td><td>I/O</td><td>Data Input (Data Input Output 0)(1)</td></tr><tr><td>6</td><td>CLK</td><td>I</td><td>Serial Clock Input</td></tr><tr><td>7</td><td>/HOLD or /RESET (IO3)</td><td>I/O</td><td>Hold or Reset Input (Data Input Output 3)(2)</td></tr><tr><td>8</td><td>VCC</td><td></td><td>Power Supply</td></tr></table>

# Notes:

1. IO0 and IO1 are used for Standard and Dual SPI instructions 

2. IO0 – IO3 are used for Quad SPI instructions, /HOLD (or /RESET) function is only available for Standard/Dual SPI. 

# 3.4 Pin Configuration SOIC 300-mil

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/31eb744dc2ac3a5321bab3d74b2fe816bc6d86d3ce42eedea2f9634ff24bd398.jpg)



Figure 1c. W25Q32JV Pin Assignments, 16-pin SOIC 300-mil (Package Code SF)


# 3.5 Pin Description SOIC 300-mil

<table><tr><td>PIN NO.</td><td>PIN NAME</td><td>I/O</td><td>FUNCTION</td></tr><tr><td>1</td><td>/HOLD or RESET (IO3)</td><td>I/O</td><td>Hold or Reset Input (Data Input Output 3)(2)</td></tr><tr><td>2</td><td>VCC</td><td></td><td>Power Supply</td></tr><tr><td>3</td><td>/RESET</td><td>I</td><td>Reset Input(3)</td></tr><tr><td>4</td><td>N/C</td><td></td><td>No Connect</td></tr><tr><td>5</td><td>N/C</td><td></td><td>No Connect</td></tr><tr><td>6</td><td>N/C</td><td></td><td>No Connect</td></tr><tr><td>7</td><td>/CS</td><td>I</td><td>Chip Select Input</td></tr><tr><td>8</td><td>DO (IO1)</td><td>I/O</td><td>Data Output (Data Input Output 1)(1)</td></tr><tr><td>9</td><td>/WP (IO2)</td><td>I/O</td><td>Write Protect Input (Data Input Output 2)(2)</td></tr><tr><td>10</td><td>GND</td><td></td><td>Ground</td></tr><tr><td>11</td><td>N/C</td><td></td><td>No Connect</td></tr><tr><td>12</td><td>N/C</td><td></td><td>No Connect</td></tr><tr><td>13</td><td>N/C</td><td></td><td>No Connect</td></tr><tr><td>14</td><td>N/C</td><td></td><td>No Connect</td></tr><tr><td>15</td><td>DI (IO0)</td><td>I/O</td><td>Data Input (Data Input Output 0)(1)</td></tr><tr><td>16</td><td>CLK</td><td>I</td><td>Serial Clock Input</td></tr></table>

# Notes:

1. IO0 and IO1 are used for Standard and Dual SPI instructions. 

2. IO0 – IO3 are used for Quad SPI instructions, /HOLD (or /RESET) function is only available for Standard/Dual SPI. 

3. The /RESET pin is a dedicated hardware reset pin regardless of device settings or operation states. If the hardware reset function is not used, this pin can be left floating or connected to VCC in the system. 

# 3.6 Ball Configuration TFBGA 8x6-mm (5x5 or 6x4 Ball Array)


Top View


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/047fda5233583d66317bca2ced6535084e05f891e19c84c898e99732ff18ad4c.jpg)



Package Code B



Top View


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/4f8fe472c701050146ab84cced32f9eefcb7926d9b78b8947bee0a9dd2a2a40a.jpg)



Package Code C



Figure 1d. W25Q32JV Ball Assignments, 24-ball TFBGA 8x6-mm, 5X5 and 6x4 (Package Code TB, TC)


# 3.7 Ball Description TFBGA 8x6-mm

<table><tr><td>BALL NO.</td><td>PIN NAME</td><td>I/O</td><td>FUNCTION</td></tr><tr><td>A4</td><td>/RESET</td><td>I</td><td>Reset Input(3)</td></tr><tr><td>B2</td><td>CLK</td><td>I</td><td>Serial Clock Input</td></tr><tr><td>B3</td><td>GND</td><td></td><td>Ground</td></tr><tr><td>B4</td><td>VCC</td><td></td><td>Power Supply</td></tr><tr><td>C2</td><td>/CS</td><td>I</td><td>Chip Select Input</td></tr><tr><td>C4</td><td>/WP (IO2)</td><td>I/O</td><td>Write Protect Input (Data Input Output 2)(2)</td></tr><tr><td>D2</td><td>DO (IO1)</td><td>I/O</td><td>Data Output (Data Input Output 1)(1)</td></tr><tr><td>D3</td><td>DI (IO0)</td><td>I/O</td><td>Data Input (Data Input Output 0)(1)</td></tr><tr><td>D4</td><td>/HOLD (IO3)</td><td>I/O</td><td>Hold or Reset Input (Data Input Output 3)(2)</td></tr><tr><td>Multiple</td><td>NC</td><td></td><td>No Connect</td></tr></table>

# Notes:

1. IO0 and IO1 are used for Standard and Dual SPI instructions 

2. IO0 – IO3 are used for Quad SPI instructions, /HOLD (or /RESET) function is only available for Standard/Dual SPI. 

3. The /RESET pin is a dedicated hardware reset pin regardless of device settings or operation states. 

If the hardware reset function is not used, this pin can be left floating or connected to VCC in the system 

# 3.8 Pin Configuration PDIP 300-mil

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/b211e4098a0753ca5d2ca6c965281528f65881002b008e2111b93e0989daffb0.jpg)



Figure 1e. W25Q32JV Pin Assignments, 8-pin PDIP (Package Code DA)


# 3.9 Pin Description PDIP 300-mil

<table><tr><td>PAD NO.</td><td>PAD NAME</td><td>I/O</td><td>FUNCTION</td></tr><tr><td>1</td><td>/CS</td><td>I</td><td>Chip Select Input</td></tr><tr><td>2</td><td>DO (IO1)</td><td>I/O</td><td>Data Output (Data Input Output 1)(1)</td></tr><tr><td>3</td><td>/WP (IO2)</td><td>I/O</td><td>Write Protect Input ( Data Input Output 2)*2</td></tr><tr><td>4</td><td>GND</td><td></td><td>Ground</td></tr><tr><td>5</td><td>DI (IO0)</td><td>I/O</td><td>Data Input (Data Input Output 0)(1)</td></tr><tr><td>6</td><td>CLK</td><td>I</td><td>Serial Clock Input</td></tr><tr><td>7</td><td>/HOLD (IO3) or /RESET (IO3)</td><td>I/O</td><td>Hold or Reset Input (Data Input Output 3)(2)</td></tr><tr><td>8</td><td>VCC</td><td></td><td>Power Supply</td></tr></table>

# Notes:

1. IO0 and IO1 are used for Standard and Dual SPI instructions 

2. IO0 – IO3 are used for Quad SPI instructions, /HOLD (or /RESET) function is only available for Standard/Dual SPI. 

# 4. PIN DESCRIPTIONS

# 4.1 Chip Select (/CS)

The SPI Chip Select (/CS) pin enables and disables device operation. When /CS is high the device is deselected and the Serial Data Output (DO, or IO0, IO1, IO2, IO3) pins are at high impedance. When deselected, the devices power consumption will be at standby levels unless an internal erase, program or write status register cycle is in progress. When /CS is brought low the device will be selected, power consumption will increase to active levels and instructions can be written to and data read from the device. After power-up, /CS must transition from high to low before a new instruction will be accepted. The /CS input must track the VCC supply level at power-up and power-down (see “Write Protection” and Figure 58). If needed a pull-up resister on the /CS pin can be used to accomplish this. 

# 4.2 Serial Data Input, Output and IOs (DI, DO and IO0, IO1, IO2, IO3)

The W25Q32JV supports standard SPI, Dual SPI and Quad SPI operation. Standard SPI instructions use the unidirectional DI (input) pin to serially write instructions, addresses or data to the device on the rising edge of the Serial Clock (CLK) input pin. Standard SPI also uses the unidirectional DO (output) to read data or status from the device on the falling edge of CLK. 

Dual and Quad SPI instructions use the bidirectional IO pins to serially write instructions, addresses or data to the device on the rising edge of CLK and read data or status from the device on the falling edge of CLK. Quad SPI instructions require the non-volatile Quad Enable bit (QE) in Status Register-2 to be set. When $\mathtt { Q E } = 1$ , the /WP pin becomes IO2 and the /HOLD pin becomes IO3. 

# 4.3 Write Protect (/WP)

The Write Protect (/WP) pin can be used to prevent the Status Register from being written. Used in conjunction with the Status Register’s Block Protect (CMP, SEC, TB, BP2, BP1 and BP0) bits and Status Register Protect (SRP) bits, a portion as small as a 4KB sector or the entire memory array can be hardware protected. The /WP pin is active low. 

# 4.4 HOLD (/HOLD)

The /HOLD pin allows the device to be paused while it is actively selected. When /HOLD is brought low, while /CS is low, the DO pin will be at high impedance and signals on the DI and CLK pins will be ignored (don’t care). When /HOLD is brought high, device operation can resume. The /HOLD function can be useful when multiple devices are sharing the same SPI signals. The /HOLD pin is active low. When the QE bit of Status Register-2 is set for Quad I/O, the /HOLD pin function is not available since this pin is used for IO3. See Figure 1a-c for the pin configuration of Quad I/O operation. 

# 4.5 Serial Clock (CLK)

The SPI Serial Clock Input (CLK) pin provides the timing for serial input and output operations. ("See SPI Operations") 

# 4.6 Reset (/RESET)(1)

A dedicated hardware /RESET pin is available on SOIC-16 and TFBGA packages. When it’s driven low for a minimum period of ${ \sim } 1 \mu \mathsf { S }$ , this device will terminate any external or internal operations and return to its power-on state. 

# Note:

1. Hardware /RESET pin is available on SOIC-16 or TFBGA; please contact Winbond for this package. 


5. BLOCK DIAGRAM


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/67438856a759dceea22b020d19cce4578071935d1aceca4e806b3d382c5acecd.jpg)



Figure 2. W25Q32JV Serial Flash Memory Block Diagram


# 6. FUNCTIONAL DESCRIPTIONS

# 6.1 Standard SPI Instructions

The W25Q32JV is accessed through an SPI compatible bus consisting of four signals: Serial Clock (CLK), Chip Select (/CS), Serial Data Input (DI) and Serial Data Output (DO). Standard SPI instructions use the DI input pin to serially write instructions, addresses or data to the device on the rising edge of CLK. The DO output pin is used to read data or status from the device on the falling edge of CLK. 

SPI bus operation Mode 0 (0,0) and 3 (1,1) are supported. The primary difference between Mode 0 and Mode 3 concerns the normal state of the CLK signal when the SPI bus master is in standby and data is not being transferred to the Serial Flash. For Mode 0, the CLK signal is normally low on the falling and rising edges of /CS. For Mode 3, the CLK signal is normally high on the falling and rising edges of /CS. 

# 6.2 Dual SPI Instructions

The W25Q32JV supports Dual SPI operation when using instructions such as “Fast Read Dual Output (3Bh)” and “Fast Read Dual I/O (BBh)”. These instructions allow data to be transferred to or from the device at two to three times the rate of ordinary Serial Flash devices. The Dual SPI Read instructions are ideal for quickly downloading code to RAM upon power-up (code-shadowing) or for executing non-speed-critical code directly from the SPI bus (XIP). When using Dual SPI instructions, the DI and DO pins become bidirectional I/O pins: IO0 and IO1. 

# 6.3 Quad SPI Instructions

The W25Q32JV supports Quad SPI operation when using instructions such as “Fast Read Quad Output (6Bh)”, and “Fast Read Quad I/O (EBh). These instructions allow data to be transferred to or from the device four to six times the rate of ordinary Serial Flash. When using Quad SPI instructions, the DI and DO pins become bidirectional IO0 and IO1, with the additional I/O pins: IO2, IO3. 

# 6.4 Software Reset & Hardware /RESET pin

The W25Q32JV can be reset to the initial power-on state by a software Reset sequence. This sequence must include two consecutive instructions: Enable Reset (66h) & Reset (99h). If the instruction sequence is successfully accepted, the device will take approximately $3 0 \mu \mathsf { S }$ (tRST) to reset. No instruction will be accepted during the reset period. For the SOIC-16 and TFBGA packages, W25Q32JV provides a dedicated hardware /RESET pin. Drive the /RESET pin low for a minimum period of ${ \sim } 1 \mu \mathsf { S }$ (tRESET*) will interrupt any on-going external/internal operations and reset the device to its initial power-on state. Hardware /RESET pin has higher priority than other SPI input signals (/CS, CLK, IOs). 

# Note:

1. Hardware /RESET pin is available on SOIC-16 or TFBGA; please contact Winbond for his package. 

2. While a faster /RESET pulse (as short as a few hundred nanoseconds) will often reset the device, a 1us minimum is recommended to ensure reliable operation. 

3. There is an internal pull-up resistor for the dedicated /RESET pin on the SOIC-16 package. If the reset function is not needed, this pin can be left floating in the system. 

# 6.5 Write Protection

Applications that use non-volatile memory must take into consideration the possibility of noise and other adverse system conditions that may compromise data integrity. To address this concern, the W25Q32JV provides several means to protect the data from inadvertent writes. 

# Write Protect Features

 Device resets when VCC is below threshold 

 Time delay write disable after Power-up 

Write enable/disable instructions and automatic write disable after erase or program 

 Software and Hardware (/WP pin) write protection using Status Registers 

 Additional Individual Block/Sector Locks for array protection 

Write Protection using Power-down instruction 

 Lock Down write protection for Status Register until the next power-up 

 One Time Program (OTP) write protection for array and Security Registers using Status Register* 

* Note: This feature is available upon special order. Please contact Winbond for details. 

Upon power-up or at power-down, the W25Q32JV will maintain a reset condition while VCC is below the threshold value of VWI, (See Power-up Timing and Voltage Levels and Figure 43). While reset, all operations are disabled and no instructions are recognized. During power-up and after the VCC voltage exceeds VWI, all program and erase related instructions are further disabled for a time delay of tPUW. This includes the Write Enable, Page Program, Sector Erase, Block Erase, Chip Erase and the Write Status Register instructions. Note that the chip select pin (/CS) must track the VCC supply level at power-up until the VCC-min level and tVSL time delay is reached, and it must also track the VCC supply level at powerdown to prevent adverse command sequence. If needed a pull-up resister on /CS can be used to accomplish this. 

After power-up the device is automatically placed in a write-disabled state with the Status Register Write Enable Latch (WEL) set to a 0. A Write Enable instruction must be issued before a Page Program, Sector Erase, Block Erase, Chip Erase or Write Status Register instruction will be accepted. After completing a program, erase or write instruction the Write Enable Latch (WEL) is automatically cleared to a write-disabled state of 0. 

Software controlled write protection is facilitated using the Write Status Register instruction and setting the Status Register Protect (SRP, SRL) and Block Protect (CMP, TB, BP[2:0]) bits. These settings allow a portion or the entire memory array to be configured as read only. Used in conjunction with the Write Protect (/WP) pin, changes to the Status Register can be enabled or disabled under hardware control. See Status Register section for further information. Additionally, the Power-down instruction offers an extra level of write protection as all instructions are ignored except for the Release Power-down instruction. 

The W25Q32JV also provides another Write Protect method using the Individual Block Locks. Each 64KB block (except the top and bottom blocks, total of 62 blocks) and each 4KB sector within the top/bottom blocks (total of 32 sectors) are equipped with an Individual Block Lock bit. When the lock bit is 0, the corresponding sector or block can be erased or programmed; when the lock bit is set to 1, Erase or Program commands issued to the corresponding sector or block will be ignored. When the device is powered on, all Individual Block Lock bits will be 1, so the entire memory array is protected from Erase/Program. An “Individual Block Unlock (39h)” instruction must be issued to unlock any specific sector or block. 

The WPS bit in Status Register-3 is used to decide which Write Protect scheme should be used. When ${ \sf N P S } { = } 0$ (factory default), the device will only utilize CMP, SEC, TB, BP[2:0] bits to protect specific areas of the array; when ${ \sf W P S } = 1$ , the device will utilize the Individual Block Locks for write protection. 

# 7. STATUS AND CONFIGURATION REGISTERS

Three Status and Configuration Registers are provided for W25Q32JV. The Read Status Register-1/2/3 instructions can be used to provide status on the availability of the flash memory array, whether the device is write enabled or disabled, the state of write protection, Quad SPI setting, Security Register lock status, Erase/Program Suspend status, and output driver strength. The Write Status Register instruction can be used to configure the device write protection features, Quad SPI setting, Security Register OTP locks, and output driver strength. Write access to the Status Register is controlled by the state of the nonvolatile Status Register Protect bits (SRL), the Write Enable instruction, and during Standard/Dual SPI operations. 

# 7.1 Status Registers

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/10ff5031e9633f13d028c13cdfcfed0a9cdd4f59fa674b8031b6dae808767c6b.jpg)



Figure 4a. Status Register-1


# Erase/Write In Progress (BUSY) – Status Only

BUSY is a read only bit in the status register (S0) that is set to a 1 state when the device is executing a Page Program, Quad Page Program, Sector Erase, Block Erase, Chip Erase, Write Status Register or Erase/Program Security Register instruction. During this time the device will ignore further instructions except for the Read Status Register and Erase/Program Suspend instruction (see tW, tPP, tSE, tBE, and tCE in AC Characteristics). When the program, erase or write status/security register instruction has completed, the BUSY bit will be cleared to a 0 state indicating the device is ready for further instructions. 

# Write Enable Latch (WEL) – Status Only

Write Enable Latch (WEL) is a read only bit in the status register (S1) that is set to 1 after executing a Write Enable Instruction. The WEL status bit is cleared to 0 when the device is write disabled. A write disable state occurs upon power-up or after any of the following instructions: Write Disable, Page Program, Quad Page Program, Sector Erase, Block Erase, Chip Erase, Write Status Register, Erase Security Register and Program Security Register. 

# Block Protect Bits (BP2, BP1, BP0) – Volatile/Non-Volatile Writable

The Block Protect Bits (BP2, BP1, BP0) are non-volatile read/write bits in the status register (S4, S3, and S2) that provide Write Protection control and status. Block Protect bits can be set using the Write Status Register Instruction (see tW in AC characteristics). All, none or a portion of the memory array can be protected from Program and Erase instructions (see Status Register Memory Protection table). The factory default setting for the Block Protection Bits is 0, none of the array protected. 

# Top/Bottom Block Protect (TB) – Volatile/Non-Volatile Writable

The non-volatile Top/Bottom bit (TB) controls if the Block Protect Bits (BP2, BP1, BP0) protect from the Top $( \mathsf { T B } { = } 0 )$ or the Bottom $( T B = 1$ ) of the array as shown in the Status Register Memory Protection table. The factory default setting is $\scriptstyle \mathsf { T B } = 0$ . The TB bit can be set with the Write Status Register Instruction depending on the state of the SRP/SRL and WEL bits. 

# Sector/Block Protect Bit (SEC) – Volatile/Non-Volatile Writable

The non-volatile Sector/Block Protect bit (SEC) controls if the Block Protect Bits (BP2, BP1, BP0) protect either 4KB Sectors $( { \mathsf { S E C } } { = } 1 ) ,$ ) or 64KB Blocks $( \mathsf { S E C = } 0 )$ ) in the Top $( \mathsf { T B } { = } 0 )$ or the Bottom $( \mathsf { T B } { = } 1 )$ ) of the array as shown in the Status Register Memory Protection table. The default setting is $\mathtt { S E C = 0 }$ . 

# Complement Protect (CMP) – Volatile/Non-Volatile Writable

The Complement Protect bit (CMP) is a non-volatile read/write bit in the status register (S14). It is used in conjunction with SEC, TB, BP2, BP1 and BP0 bits to provide more flexibility for the array protection. Once CMP is set to 1, previous array protection set by SEC, TB, BP2, BP1 and BP0 will be reversed. For instance, when CMP=0, a top 64KB block can be protected while the rest of the array is not; when ${ \mathsf { C M P } } { = } 1$ , the top 64KB block will become unprotected while the rest of the array become read-only. Please refer to the Status Register Memory Protection table for details. The default setting is CMP=0. 

# Status Register Protect (SRP, SRL) – Volatile/Non-Volatile Writable

Three Status and Configuration Registers are provided for W25Q32JV. The Read Status Register-1/2/3 instructions can be used to provide status on the availability of the flash memory array, whether the device is write enabled or disabled, the state of write protection, Quad SPI setting, Security Register lock status, Erase/Program Suspend status,and output driver strength, The Write Status Register instruction can be used to configure the device write protection features, Quad SPI setting, Security Register OTP locks, output driver. Write access to the Status Register is controlled by the state of the non-volatile Status Register Protect bits (SRP, SRL), the Write Enable instruction, and during Standard/Dual SPI operations, the /WP pin. 

<table><tr><td>SRL</td><td>SRP</td><td>/WP</td><td>Status Register</td><td>Description</td></tr><tr><td>0</td><td>0</td><td>X</td><td>Software Protection</td><td>/WP pin has no control. The Status register can be written to after a Write Enable instruction, WEL=1. [Factory Default]</td></tr><tr><td>0</td><td>1</td><td>0</td><td>Hardware Protected</td><td>When /WP pin is low the Status Register locked and cannot be written to.</td></tr><tr><td>0</td><td>1</td><td>1</td><td>Hardware Unprotected</td><td>When /WP pin is high the Status register is unlocked and can be written to after a Write Enable instruction, WEL=1.</td></tr><tr><td>1</td><td>X</td><td>X</td><td>Power Supply Lock-Down</td><td>Status Register is protected and cannot be written to again until the next power-down, power-up cycle.(1)</td></tr><tr><td>1</td><td>X</td><td>X</td><td>One Time Program(2)</td><td>Status Register is permanently protected and cannot be written to. (enabled by adding prefix command AAh, 55h)</td></tr></table>


1. When SRL $= 1$ , a power-down, power-up cycle will change SRL ${ } = 0$ state. 



2. Please contact Winbond for details regarding the special instruction sequence. 


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/6a020b2dffb242db8c7b9cc82bb0bc7b1caa8620299dd66d12ab9c86cc0e428f.jpg)



Figure 4b. Status Register-2


# Erase/Program Suspend Status (SUS) – Status Only

The Suspend Status bit is a read only bit in the status register (S15) that is set to 1 after executing a Erase/Program Suspend (75h) instruction. The SUS status bit is cleared to 0 by Erase/Program Resume (7Ah) instruction as well as a power-down, power-up cycle. 

# Security Register Lock Bits (LB3, LB2, LB1) – Volatile/Non-Volatile OTP Writable

The Security Register Lock Bits (LB3, LB2, LB1) are non-volatile One Time Program (OTP) bits in Status Register (S13, S12, S11) that provide the write protect control and status to the Security Registers. The default state of LB3-1 is 0, Security Registers are unlocked. LB3-1 can be set to 1 individually using the Write Status Register instruction. LB3-1 are One Time Programmable (OTP), once it’s set to 1, the corresponding 256-Byte Security Register will become read-only permanently. 

# Quad Enable (QE) – Volatile/Non-Volatile Writable

The Quad Enable (QE) bit is a non-volatile read/write bit in the status register (S9) that enables Quad SPI operation. When the QE bit is set to a 0 state (factory default for part numbers with ordering options “IM” & ”JM”), the /HOLD are enabled, the device operates in Standard/Dual SPI modes. When the QE bit is set to a 1 (factory fixed default for part numbers with ordering options “IQ” & “JQ”), the Quad IO2 and IO3 pins are enabled, and /HOLD function is disabled, the device operates in Standard/Dual/Quad SPI modes. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/a1c82a0bf05571c17591e9a59163cad4d0246b8898b47a45871f8b938432c342.jpg)



Figure 4c. Status Register-3


# Write Protect Selection (WPS) – Volatile/Non-Volatile Writable

The WPS bit is used to select which Write Protect scheme should be used. When ${ \sf N P S } { = } 0$ , the device will use the combination of CMP, SEC, TB, BP[2:0] bits to protect a specific area of the memory array. When ${ \sf W P S } = 1$ , the device will utilize the Individual Block Locks to protect any individual sector or blocks. The default value for all Individual Block Lock bits is 1 upon device power on or after reset. 

# Output Driver Strength (DRV1, DRV0) – Volatile/Non-Volatile Writable

The DRV1 & DRV0 bits are used to determine the output driver strength for the Read operations. 

<table><tr><td>DRV1, DRV0</td><td>Driver Strength</td></tr><tr><td>0, 0</td><td>100%</td></tr><tr><td>0, 1</td><td>75%</td></tr><tr><td>1, 0</td><td>50%</td></tr><tr><td>1, 1</td><td>25% (default)</td></tr></table>

# Reserved Bits – Non Functional

There are a few reserved Status Register bits that may be read out as a “0” or “1”. It is recommended to ignore the values of those bits. During a “Write Status Register” instruction, the Reserved Bits can be written as $" 0 "$ , but there will not be any effects. 

# Status Register Memory Protection (WPS = 0, CMP $\mathbf { \eta } = \mathbf { 0 } _ { \mathrm { ~ } }$ )

<table><tr><td colspan="5">STATUS REGISTER(1)</td><td colspan="4">W25Q32JV (32M-BIT) MEMORY PROTECTION(3)</td></tr><tr><td>SEC</td><td>TB</td><td>BP2</td><td>BP1</td><td>BP0</td><td>PROTECTED BLOCK(S)</td><td>PROTECTED ADDRESSES</td><td>PROTECTED DENSITY</td><td>PROTECTED PORTION(2)</td></tr><tr><td>X</td><td>X</td><td>0</td><td>0</td><td>0</td><td>NONE</td><td>NONE</td><td>NONE</td><td>NONE</td></tr><tr><td>0</td><td>0</td><td>0</td><td>0</td><td>1</td><td>63</td><td>3F0000h - 3FFFFFFh</td><td>64KB</td><td>Upper 1/64</td></tr><tr><td>0</td><td>0</td><td>0</td><td>1</td><td>0</td><td>62 and 63</td><td>3E0000h - 3FFFFFFh</td><td>128KB</td><td>Upper 1/32</td></tr><tr><td>0</td><td>0</td><td>0</td><td>1</td><td>1</td><td>60 thru 63</td><td>3C0000h - 3FFFFFFh</td><td>256KB</td><td>Upper 1/16</td></tr><tr><td>0</td><td>0</td><td>1</td><td>0</td><td>0</td><td>56 thru 63</td><td>380000h - 3FFFFFFh</td><td>512KB</td><td>Upper 1/8</td></tr><tr><td>0</td><td>0</td><td>1</td><td>0</td><td>1</td><td>48 thru 63</td><td>300000h - 3FFFFFFh</td><td>1MB</td><td>Upper 1/4</td></tr><tr><td>0</td><td>0</td><td>1</td><td>1</td><td>0</td><td>32 thru 63</td><td>200000h - 3FFFFFFh</td><td>2MB</td><td>Upper 1/2</td></tr><tr><td>0</td><td>1</td><td>0</td><td>0</td><td>1</td><td>0</td><td>000000h - 00FFFFFFh</td><td>64KB</td><td>Lower 1/64</td></tr><tr><td>0</td><td>1</td><td>0</td><td>1</td><td>0</td><td>0 and 1</td><td>000000h - 01FFFFFFh</td><td>128KB</td><td>Lower 1/32</td></tr><tr><td>0</td><td>1</td><td>0</td><td>1</td><td>1</td><td>0 thru 3</td><td>000000h - 03FFFFFFh</td><td>256KB</td><td>Lower 1/16</td></tr><tr><td>0</td><td>1</td><td>1</td><td>0</td><td>0</td><td>0 thru 7</td><td>000000h - 07FFFFFFh</td><td>512KB</td><td>Lower 1/8</td></tr><tr><td>0</td><td>1</td><td>1</td><td>0</td><td>1</td><td>0 thru 15</td><td>000000h - 0FFFFFFh</td><td>1MB</td><td>Lower 1/4</td></tr><tr><td>0</td><td>1</td><td>1</td><td>1</td><td>0</td><td>0 thru 31</td><td>000000h - 1FFFFFFh</td><td>2MB</td><td>Lower 1/2</td></tr><tr><td>X</td><td>X</td><td>1</td><td>1</td><td>1</td><td>0 thru 63</td><td>000000h - 3FFFFFFh</td><td>4MB</td><td>ALL</td></tr><tr><td>1</td><td>0</td><td>0</td><td>0</td><td>1</td><td>63</td><td>3FF000h - 3FFFFFFh</td><td>4KB</td><td>U - 1/1024</td></tr><tr><td>1</td><td>0</td><td>0</td><td>1</td><td>0</td><td>63</td><td>3FE000h - 3FFFFFFh</td><td>8KB</td><td>U - 1/512</td></tr><tr><td>1</td><td>0</td><td>0</td><td>1</td><td>1</td><td>63</td><td>3FC000h - 3FFFFFFh</td><td>16KB</td><td>U - 1/256</td></tr><tr><td>1</td><td>0</td><td>1</td><td>0</td><td>X</td><td>63</td><td>3F8000h - 3FFFFFFh</td><td>32KB</td><td>U - 1/128</td></tr><tr><td>1</td><td>1</td><td>0</td><td>0</td><td>1</td><td>0</td><td>000000h - 000FFFFh</td><td>4KB</td><td>L - 1/1024</td></tr><tr><td>1</td><td>1</td><td>0</td><td>1</td><td>0</td><td>0</td><td>000000h - 001FFFFh</td><td>8KB</td><td>L - 1/512</td></tr><tr><td>1</td><td>1</td><td>0</td><td>1</td><td>1</td><td>0</td><td>000000h - 003FFFFh</td><td>16KB</td><td>L - 1/256</td></tr><tr><td>1</td><td>1</td><td>1</td><td>0</td><td>X</td><td>0</td><td>000000h - 007FFFFh</td><td>32KB</td><td>L - 1/128</td></tr></table>

# Notes:

1. $\mathsf { X } =$ don’t care 

2. $\mathsf { L } =$ Lower; $\mathsf { U } =$ Upper 

3. If any Erase or Program command specifies a memory region that contains protected data portion, this command will be ignored. 

# Status Register Memory Protection (WPS = 0, CMP $=$ 1)

<table><tr><td colspan="5">STATUS REGISTER(1)</td><td colspan="4">W25Q32JV (32M-BIT) MEMORY PROTECTION(3)</td></tr><tr><td>SEC</td><td>TB</td><td>BP2</td><td>BP1</td><td>BP0</td><td>PROTECTED BLOCK(S)</td><td>PROTECTED ADDRESSES</td><td>PROTECTED DENSITY</td><td>PROTECTED PORTION(2)</td></tr><tr><td>X</td><td>X</td><td>0</td><td>0</td><td>0</td><td>0 thru 63</td><td>000000h – 3FFFFFFh</td><td>4MB</td><td>ALL</td></tr><tr><td>0</td><td>0</td><td>0</td><td>0</td><td>1</td><td>0 thru 62</td><td>000000h – 3FFFFFFh</td><td>4,032KB</td><td>Lower 63/64</td></tr><tr><td>0</td><td>0</td><td>0</td><td>1</td><td>0</td><td>0 and 61</td><td>000000h – 3DFFFFh</td><td>3,968KB</td><td>Lower 31/32</td></tr><tr><td>0</td><td>0</td><td>0</td><td>1</td><td>1</td><td>0 thru 59</td><td>000000h – 3BFFFFh</td><td>3,840KB</td><td>Lower 15/16</td></tr><tr><td>0</td><td>0</td><td>1</td><td>0</td><td>0</td><td>0 thru 55</td><td>000000h – 37FFFFFFh</td><td>3,584KB</td><td>Lower 7/8</td></tr><tr><td>0</td><td>0</td><td>1</td><td>0</td><td>1</td><td>0 thru 47</td><td>000000h – 2FFFFFFh</td><td>3MB</td><td>Lower 3/4</td></tr><tr><td>0</td><td>0</td><td>1</td><td>1</td><td>0</td><td>0 thru 31</td><td>000000h – 1FFFFFFh</td><td>2MB</td><td>Lower 1/2</td></tr><tr><td>0</td><td>1</td><td>0</td><td>0</td><td>1</td><td>1 thru 63</td><td>010000h – 3FFFFFFh</td><td>4,032KB</td><td>Upper 63/64</td></tr><tr><td>0</td><td>1</td><td>0</td><td>1</td><td>0</td><td>2 and 63</td><td>020000h – 3FFFFFFh</td><td>3,968KB</td><td>Upper 31/32</td></tr><tr><td>0</td><td>1</td><td>0</td><td>1</td><td>1</td><td>4 thru 63</td><td>040000h – 3FFFFFFh</td><td>3,840KB</td><td>Upper 15/16</td></tr><tr><td>0</td><td>1</td><td>1</td><td>0</td><td>0</td><td>8 thru 63</td><td>080000h – 3FFFFFFh</td><td>3,584KB</td><td>Upper 7/8</td></tr><tr><td>0</td><td>1</td><td>1</td><td>0</td><td>1</td><td>16 thru 63</td><td>100000h – 3FFFFFFh</td><td>3MB</td><td>Upper 3/4</td></tr><tr><td>0</td><td>1</td><td>1</td><td>1</td><td>0</td><td>32 thru 63</td><td>200000h – 3FFFFFFh</td><td>2MB</td><td>Upper 1/2</td></tr><tr><td>X</td><td>X</td><td>1</td><td>1</td><td>1</td><td>NONE</td><td>NONE</td><td>NONE</td><td>NONE</td></tr><tr><td>1</td><td>0</td><td>0</td><td>0</td><td>1</td><td>0 thru 63</td><td>000000h – 3FEFFFh</td><td>4,092KB</td><td>L - 1023/1024</td></tr><tr><td>1</td><td>0</td><td>0</td><td>1</td><td>0</td><td>0 thru 63</td><td>000000h – 3FDFFFh</td><td>4,088KB</td><td>L - 511/512</td></tr><tr><td>1</td><td>0</td><td>0</td><td>1</td><td>1</td><td>0 thru 63</td><td>000000h – 3FBFFFh</td><td>4,080KB</td><td>L - 255/256</td></tr><tr><td>1</td><td>0</td><td>1</td><td>0</td><td>X</td><td>0 thru 63</td><td>000000h – 3F7FFFh</td><td>4,064KB</td><td>L - 127/128</td></tr><tr><td>1</td><td>1</td><td>0</td><td>0</td><td>1</td><td>0 thru 63</td><td>001000h – 3FFFFFFh</td><td>4,092KB</td><td>U - 1023/1024</td></tr><tr><td>1</td><td>1</td><td>0</td><td>1</td><td>0</td><td>0 thru 63</td><td>002000h – 3FFFFFFh</td><td>4,088KB</td><td>U - 511/512</td></tr><tr><td>1</td><td>1</td><td>0</td><td>1</td><td>1</td><td>0 thru 63</td><td>004000h – 3FFFFFFh</td><td>4,080KB</td><td>U - 255/256</td></tr><tr><td>1</td><td>1</td><td>1</td><td>0</td><td>X</td><td>0 thru 63</td><td>008000h – 3FFFFFFh</td><td>4,064KB</td><td>U - 127/128</td></tr></table>

# Notes:

1. $\mathsf { X } =$ don’t care 

2. L $=$ Lower; $\mathsf { U } =$ Upper 

3. If any Erase or Program command specifies a memory region that contains protected data portion, this command will be ignored. 

# Individual Block Memory Protection (WPS=1)

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/0746b2884b75d7742039093810eb4f6a87d476afcc590c0c94d11a1003daa58a.jpg)



Figure 4d. Individual Block/Sector Locks


# Notes:

1. Individual Block/Sector protection is only valid when WPS=1. 

2. All individual block/sector lock bits are set to 1 by default after power up, all memory array is protected. 

# 8. INSTRUCTIONS

The Standard/Dual/Quad SPI instruction set of the W25Q32JV consists of 48 basic instructions that are fully controlled through the SPI bus (see Instruction Set Table1-2). Instructions are initiated with the falling edge of Chip Select (/CS). The first byte of data clocked into the DI input provides the instruction code. Data on the DI input is sampled on the rising edge of clock with most significant bit (MSB) first. 

Instructions vary in length from a single byte to several bytes and may be followed by address bytes, data bytes, dummy bytes (don’t care), and in some cases, a combination. Instructions are completed with the rising edge of edge /CS. Clock relative timing diagrams for each instruction are included in Figures 5 through 57. All read instructions can be completed after any clocked bit. However, all instructions that Write, Program or Erase must complete on a byte boundary (/CS driven high after a full 8-bits have been clocked) otherwise the instruction will be ignored. This feature further protects the device from inadvertent writes. Additionally, while the memory is being programmed or erased, or when the Status Register is being written, all instructions except for Read Status Register will be ignored until the program or erase cycle has completed. 

# 8.1 Device ID and Instruction Set Tables

# Manufacturer and Device Identification

<table><tr><td>MANUFACTURER ID</td><td>(MF7 - MF0)</td><td rowspan="3"></td></tr><tr><td>Winbond Serial Flash</td><td>EFh</td></tr><tr><td colspan="2"></td></tr><tr><td>Device ID</td><td>(ID7 - ID0)</td><td>(ID15 - ID0)</td></tr><tr><td>Instruction</td><td>ABh, 90h, 92h, 94h</td><td>9Fh</td></tr><tr><td>W25Q32JV-IQ/JQ</td><td>15h</td><td>4016h</td></tr><tr><td>W25Q32JV-IM*/JM*</td><td>15h</td><td>7016h</td></tr></table>


Note: For DTR, QPI supporting, please refer to W25Q32JV DTR datasheet. 



Instruction Set Table 1 (Standard SPI Instructions)(1)


<table><tr><td>Data Input Output</td><td>Byte 1</td><td>Byte 2</td><td>Byte 3</td><td>Byte 4</td><td>Byte 5</td><td>Byte 6</td><td>Byte 7</td></tr><tr><td>Number of Clock(1-1-1)</td><td>8</td><td>8</td><td>8</td><td>8</td><td>8</td><td>8</td><td>8</td></tr><tr><td>Write Enable</td><td>06h</td><td colspan="6"></td></tr><tr><td>Volatile SR Write Enable</td><td>50h</td><td colspan="6"></td></tr><tr><td>Write Disable</td><td>04h</td><td colspan="6"></td></tr><tr><td>Release Power-down / ID</td><td>ABh</td><td>Dummy</td><td>Dummy</td><td>Dummy</td><td>(ID7-ID0)(2)</td><td colspan="2"></td></tr><tr><td>Manufacturer/Device ID</td><td>90h</td><td>Dummy</td><td>Dummy</td><td>00h</td><td>(MF7-MF0)</td><td>(ID7-ID0)</td><td></td></tr><tr><td>JEDEC ID</td><td>9Fh</td><td>(MF7-MF0)</td><td>(ID15-ID8)</td><td>(ID7-ID0)</td><td colspan="3"></td></tr><tr><td>Read Unique ID</td><td>4Bh</td><td>Dummy</td><td>Dummy</td><td>Dummy</td><td>Dummy</td><td>(UID63-0)</td><td></td></tr><tr><td>Read Data</td><td>03h</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td>(D7-D0)</td><td colspan="2"></td></tr><tr><td>Fast Read</td><td>0Bh</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td>Dummy</td><td>(D7-D0)</td><td></td></tr><tr><td>Page Program</td><td>02h</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td>D7-D0</td><td>D7-D0(3)</td><td></td></tr><tr><td>Sector Erase (4KB)</td><td>20h</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td colspan="3"></td></tr><tr><td>Block Erase (32KB)</td><td>52h</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td colspan="3"></td></tr><tr><td>Block Erase (64KB)</td><td>D8h</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td colspan="3"></td></tr><tr><td>Chip Erase</td><td>C7h/60h</td><td colspan="6"></td></tr><tr><td>Read Status Register-1</td><td>05h</td><td>(S7-S0)(2)</td><td colspan="5"></td></tr><tr><td>Write Status Register-1(4)</td><td>01h</td><td>(S7-S0)(4)</td><td colspan="5"></td></tr><tr><td>Read Status Register-2</td><td>35h</td><td>(S15-S8)(2)</td><td colspan="5"></td></tr><tr><td>Write Status Register-2</td><td>31h</td><td>(S15-S8)</td><td colspan="5"></td></tr><tr><td>Read Status Register-3</td><td>15h</td><td>(S23-S16)(2)</td><td colspan="5"></td></tr><tr><td>Write Status Register-3</td><td>11h</td><td>(S23-S16)</td><td colspan="5"></td></tr><tr><td>Read SFDP Register</td><td>5Ah</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td>dummy</td><td>(D7-0)</td><td></td></tr><tr><td>Erase Security Register(5)</td><td>44h</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td colspan="3"></td></tr><tr><td>Program Security Register(5)</td><td>42h</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td>D7-D0</td><td>D7-D0(3)</td><td></td></tr><tr><td>Read Security Register(5)</td><td>48h</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td>Dummy</td><td>(D7-D0)</td><td></td></tr><tr><td>Global Block Lock</td><td>7Eh</td><td colspan="6"></td></tr><tr><td>Global Block Unlock</td><td>98h</td><td colspan="6"></td></tr><tr><td>Read Block Lock</td><td>3Dh</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td>(L7-L0)</td><td colspan="2"></td></tr><tr><td>Individual Block Lock</td><td>36h</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td colspan="3"></td></tr><tr><td>Individual Block Unlock</td><td>39h</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td colspan="3"></td></tr><tr><td>Erase / Program Suspend</td><td>75h</td><td colspan="6"></td></tr><tr><td>Erase / Program Resume</td><td>7Ah</td><td colspan="6"></td></tr><tr><td>Power-down</td><td>B9h</td><td colspan="6"></td></tr><tr><td>Enable Reset</td><td>66h</td><td colspan="6"></td></tr><tr><td>Reset Device</td><td>99h</td><td colspan="6"></td></tr></table>


Instruction Set Table 2 (Dual/Quad SPI Instructions)(1)


<table><tr><td>Data Input Output</td><td>Byte 1</td><td>Byte 2</td><td>Byte 3</td><td>Byte 4</td><td>Byte 5</td><td>Byte 6</td><td>Byte 7</td><td>Byte 8</td><td>Byte 9</td></tr><tr><td>Number of \(Clock_{(1-1-2)}\)</td><td>8</td><td>8</td><td>8</td><td>8</td><td>4</td><td>4</td><td>4</td><td>4</td><td>4</td></tr><tr><td>Fast Read Dual Output</td><td>3Bh</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td>Dummy</td><td>Dummy</td><td>\((D7-D0)^{(7)}\)</td><td colspan="2">...</td></tr><tr><td>Number of \(Clock_{(1-2-2)}\)</td><td>8</td><td>4</td><td>4</td><td>4</td><td>4</td><td>4</td><td>4</td><td>4</td><td>4</td></tr><tr><td>Fast Read Dual I/O</td><td>BBh</td><td>\(A23-A16^{(6)}\)</td><td>\(A15-A8^{(6)}\)</td><td>\(A7-A0^{(6)}\)</td><td>\(Dummy^{(11)}\)</td><td>\((D7-D0)^{(7)}\)</td><td colspan="3">...</td></tr><tr><td>Mfrr./Device ID Dual I/O</td><td>92h</td><td>\(A23-A16^{(6)}\)</td><td>\(A15-A8^{(6)}\)</td><td>\(00^{(6)}\)</td><td>\(Dummy^{(11)}\)</td><td>(MF7-MF0)</td><td>\((ID7-ID0)^{(7)}\)</td><td colspan="2"></td></tr><tr><td>Number of \(Clock_{(1-1-4)}\)</td><td>8</td><td>8</td><td>8</td><td>8</td><td>2</td><td>2</td><td>2</td><td>2</td><td>2</td></tr><tr><td>Quad Input Page Program</td><td>32h</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td>\((D7-D0)^{(9)}\)</td><td>\((D7-D0)^{(3)}\)</td><td colspan="3">...</td></tr><tr><td>Fast Read Quad Output</td><td>6Bh</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td>Dummy</td><td>Dummy</td><td>Dummy</td><td>Dummy</td><td>\((D7-D0)^{(10)}...\)</td></tr><tr><td>Number of \(Clock_{(1-4-4)}\)</td><td>8</td><td>\(2^{(8)}\)</td><td>\(2^{(8)}\)</td><td>\(2^{(8)}\)</td><td>2</td><td>2</td><td>2</td><td>2</td><td>2</td></tr><tr><td>Mfrr./Device ID Quad I/O</td><td>94h</td><td>A23-A16</td><td>A15-A8</td><td>00</td><td>\(Dummy^{(11)}\)</td><td>Dummy</td><td>Dummy</td><td>(MF7-MF0)</td><td>(ID7-ID0)</td></tr><tr><td>Fast Read Quad I/O</td><td>EBh</td><td>A23-A16</td><td>A15-A8</td><td>A7-A0</td><td>\(Dummy^{(11)}\)</td><td>Dummy</td><td>Dummy</td><td>(D7-D0)</td><td></td></tr><tr><td>Set Burst with Wrap</td><td>77h</td><td>Dummy</td><td>Dummy</td><td>Dummy</td><td>W8-W0</td><td colspan="4"></td></tr></table>


Notes: 



1. Data bytes are shifted with Most Significant Bit first. Byte fields with data in parenthesis “( )” indicate data output from the device on either 1, 2 or 4 IO pins. 



2. The Status Register contents and Device ID will repeat continuously until /CS terminates the instruction. 



3. At least one byte of data input is required for Page Program, Quad Page Program and Program Security Registers, up to 256 bytes of data input. If more than 256 bytes of data are sent to the device, the addressing will wrap to the beginning of the page and overwrite previously sent data. 



4. Write Status Register-1 (01h) can also be used to program Status Register-1&2, see section 8.2.5. 



5. Security Register Address: 


Security Register 1: ${ \mathsf { A } } 2 3 { \mathsf { - } } 1 6 = 0 0 { \mathsf { h } }$ ; $\mathsf { A } 1 5  – 8 = 1 0 \mathsf { h }$ ; A7-0 = byte address 

Security Register 2: ${ \mathsf { A } } 2 3 { \mathsf { - } } 1 6 = 0 0 { \mathsf { h } }$ ; $\mathsf { A } 1 5 8 = 2 0 \mathsf { h }$ ; $\mathsf { A } 7  – 0 =$ byte address 

Security Register 3: ${ \mathsf { A } } 2 3 { \mathsf { - } } 1 6 = 0 0 { \mathsf { h } }$ ; $\mathsf { A } 1 5  – 8 = 3 0 \mathsf { h }$ ; $\mathsf { A } 7  – 0 =$ byte address 

6. Dual SPI address input format: 

$1 0 0 = \mathsf { A } 2 2$ , A20, A18, A16, A14, A12, A10, A8 A6, A4, A2, A0, M6, M4, M2, M0 

$| \boldsymbol { \mathrm { O } } 1 = \mathsf { A } 2 3$ , A21, A19, A17, A15, A13, A11, A9 A7, A5, A3, A1, M7, M5, M3, M1 

7. Dual SPI data output format: 

IO0 = (D6, D4, D2, D0) 

IO1 = (D7, D5, D3, D1) 

8. Quad SPI address input format: 

$1 0 0 = \mathsf { A } 2 0$ , A16, A12, A8, A4, A0, M4, M0 

$| \boldsymbol { \mathrm { O } } 1 = \boldsymbol { \mathsf { A } } 2 \boldsymbol { \mathrm { 1 } }$ , A17, A13, A9, A5, A1, M5, M1 

$1 0 2 = \mathsf { A } 2 2$ , A18, A14, A10, A6, A2, M6, M2 

$| \boldsymbol { \mathrm { O 3 } } = \mathsf { A } 2 \boldsymbol { 3 }$ , A19, A15, A11, A7, A3, M7, M3 

Set Burst with Wrap input format: 

$1 0 0 = \mathsf { x }$ , x, x, x, x, x, W4, x 

$1 0 1 = \mathsf { x }$ , x, x, x, x, x, W5, x 

$1 0 2 = x$ , x, x, x, x, x, W6, x 

$1 { \bigcirc } 3 = \mathbf { x }$ , x, x, x, x, x, x, x 

9. Quad SPI data input/output format: 

IO0 = (D4, D0, …..) 

IO1 = (D5, D1, …..) 

IO2 = (D6, D2, …..) 

IO3 = (D7, D3, …..) 

10. Fast Read Quad I/O data output format: 

$1 0 0 = ( { \tt x } , { \tt x } , { \tt x } , { \tt x } , { \tt x } ,$ 

$| 0 1 = ( { \tt x } , { \tt x } , { \tt x } , { \tt x } , { \tt x } ,$ 

$1 0 2 = ( { \tt x } , { \tt x } , { \tt x } , { \tt x } , { \tt x } ,$ 

11. The first dummy is M7-M0 should be set to Fxh 

# 8.2 Instruction Descriptions

# Write Enable (06h)

The Write Enable instruction (Figure 5) sets the Write Enable Latch (WEL) bit in the Status Register to a 1. The WEL bit must be set prior to every Page Program, Quad Page Program, Sector Erase, Block Erase, Chip Erase, Write Status Register and Erase/Program Security Registers instruction. The Write Enable instruction is entered by driving /CS low, shifting the instruction code “06h” into the Data Input (DI) pin on the rising edge of CLK, and then driving /CS high. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/28f696ee2419255c602c2969c35af6240b07e13b2e0f54ce0953a23257208f16.jpg)



Figure 5. Write Enable Instruction


# Write Enable for Volatile Status Register (50h)

The non-volatile Status Register bits described in section 7.1 can also be written to as volatile bits. This gives more flexibility to change the system configuration and memory protection schemes quickly without waiting for the typical non-volatile bit write cycles or affecting the endurance of the Status Register nonvolatile bits. To write the volatile values into the Status Register bits, the Write Enable for Volatile Status Register (50h) instruction must be issued prior to a Write Status Register (01h) instruction. Write Enable for Volatile Status Register instruction (Figure 6) will not set the Write Enable Latch (WEL) bit, it is only valid for the Write Status Register instruction to change the volatile Status Register bit values. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/710dff3122286445550a8ab7d68d7bbc8eeca85aee57a78876d49d2816347448.jpg)



Figure 6. Write Enable for Volatile Status Register Instruction


# Write Disable (04h)

The Write Disable instruction (Figure 7) resets the Write Enable Latch (WEL) bit in the Status Register to a 0. The Write Disable instruction is entered by driving /CS low, shifting the instruction code “04h” into the DI pin and then driving /CS high. Note that the WEL bit is automatically reset after Power-up and upon completion of the Write Status Register, Erase/Program Security Registers, Page Program, Quad Page Program, Sector Erase, Block Erase, Chip Erase and Reset instructions. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/750d9471150bb00dfa8c411415f2dbfe457fa862fc8a48f103e6b86956a4bf8f.jpg)



Figure 7. Write Disable Instruction


# Read Status Register-1 (05h), Status Register-2 (35h) & Status Register-3 (15h)

The Read Status Register instructions allow the 8-bit Status Registers to be read. The instruction is entered by driving /CS low and shifting the instruction code “05h” for Status Register-1, “35h” for Status Register-2 or “15h” for Status Register-3 into the DI pin on the rising edge of CLK. The status register bits are then shifted out on the DO pin at the falling edge of CLK with most significant bit (MSB) first as shown in Figure 8. Refer to section 7.1 for Status Register descriptions. 

The Read Status Register instruction may be used at any time, even while a Program, Erase or Write Status Register cycle is in progress. This allows the BUSY status bit to be checked to determine when the cycle is complete and if the device can accept another instruction. The Status Register can be read continuously, as shown in Figure 8. The instruction is completed by driving /CS high. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/39b6d5c0f47f215cb05016ba8e989e0d5acea5aa2074fcf8890ff36b790d6ff1.jpg)



Figure 8. Read Status Register Instruction


# Write Status Register-1 (01h), Status Register-2 (31h) & Status Register-3 (11h)

The Write Status Register instruction allows the Status Registers to be written. The writable Status Register bits include: SEC, TB, BP[2:0] in Status Register-1; CMP, LB[3:1], QE, SRL in Status Register-2; DRV1, DRV0, WPS in Status Register-3. All other Status Register bit locations are read-only and will not be affected by the Write Status Register instruction. LB[3:1] are non-volatile OTP bits, once it is set to 1, it cannot be cleared to 0. 

To write non-volatile Status Register bits, a standard Write Enable (06h) instruction must previously have been executed for the device to accept the Write Status Register instruction (Status Register bit WEL must equal 1). Once write enabled, the instruction is entered by driving /CS low, sending the instruction code “01h/31h/11h”, and then writing the status register data byte as illustrated in Figure 9a. 

To write volatile Status Register bits, a Write Enable for Volatile Status Register (50h) instruction must have been executed prior to the Write Status Register instruction (Status Register bit WEL remains 0). However, SRL and LB[3:1] cannot be changed from “1” to $" 0 "$ because of the OTP protection for these bits. Upon power off or the execution of a Software/Hardware Reset, the volatile Status Register bit values will be lost, and the non-volatile Status Register bit values will be restored. 

During non-volatile Status Register write operation (06h combined with 01h/31h/11h), after /CS is driven high, the self-timed Write Status Register cycle will commence for a time duration of tW (See AC Characteristics). While the Write Status Register cycle is in progress, the Read Status Register instruction may still be accessed to check the status of the BUSY bit. The BUSY bit is a 1 during the Write Status Register cycle and a 0 when the cycle is finished and ready to accept other instructions again. After the Write Status Register cycle has finished, the Write Enable Latch (WEL) bit in the Status Register will be cleared to 0. 

During volatile Status Register write operation (50h combined with 01h/31h/11h), after /CS is driven high, the Status Register bits will be refreshed to the new values within the time period of tSHSL2 (See AC Characteristics). BUSY bit will remain 0 during the Status Register bit refresh period. 

Refer to section 7.1 for Status Register descriptions. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/73101c15452e6d5fea20396deb09901ecb633a2acb74439326edde677cd85bbd.jpg)



Figure 9a. Write Status Register-1/2/3 Instruction


# winbond

The W25Q32JV is also backward compatible to Winbond’s previous generations of serial flash memories, in which the Status Register-1&2 can be written using a single “Write Status Register-1 (01h)” command. To complete the Write Status Register-1&2 instruction, the /CS pin must be driven high after the sixteenth bit of data that is clocked in as shown in Figure 9b. If /CS is driven high after the eighth clock, the Write Status Register-1 (01h) instruction will only program the Status Register-1, the Status Register-2 will not be affected (Previous generations will clear CMP and QE bits). 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/9fd5f77d7cc429421436cc91ab030b6961f300a7f661533ab395a7d319632162.jpg)



Figure 9b. Write Status Register-1/2 Instruction


# Read Data (03h)

The Read Data instruction allows one or more data bytes to be sequentially read from the memory. The instruction is initiated by driving the /CS pin low and then shifting the instruction code “03h” followed by a 24-bit address (A23-A0) into the DI pin. The code and address bits are latched on the rising edge of the CLK pin. After the address is received, the data byte of the addressed memory location will be shifted out on the DO pin at the falling edge of CLK with most significant bit (MSB) first. The address is automatically incremented to the next higher address after each byte of data is shifted out allowing for a continuous stream of data. This means that the entire memory can be accessed with a single instruction as long as the clock continues. The instruction is completed by driving /CS high. 

The Read Data instruction sequence is shown in Figure 14. If a Read Data instruction is issued while an Erase, Program or Write cycle is in process $( \mathsf { B U S Y } = 1$ ) the instruction is ignored and will not have any effects on the current cycle. The Read Data instruction allows clock rates from D.C. to a maximum of fR (see AC Electrical Characteristics). 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/c7c43be565a62cec1f0b93b62706e52af34357a8ab26822bb00a9ed588a28ada.jpg)



Figure 14. Read Data Instruction


# Fast Read (0Bh)

The Fast Read instruction is similar to the Read Data instruction except that it can operate at the highest possible frequency of FR (see AC Electrical Characteristics). This is accomplished by adding eight “dummy” clocks after the 24-bit address as shown in Figure 16. The dummy clocks allow the devices internal circuits additional time for setting up the initial address. During the dummy clocks the data value on the DO pin is a “don’t care”. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/0c46dd95d365d0420eba9e1d3e4c1275a386954979364e3a9b5ae053b3af6865.jpg)



Figure 16. Fast Read Instruction


# Fast Read Dual Output (3Bh)

The Fast Read Dual Output (3Bh) instruction is similar to the standard Fast Read (0Bh) instruction except that data is output on two pins; $1 0 _ { 0 }$ and $\mathsf { I O } _ { 1 }$ . This allows data to be transferred at twice the rate of standard SPI devices. The Fast Read Dual Output instruction is ideal for quickly downloading code from Flash to RAM upon power-up or for applications that cache code-segments to RAM for execution. 

Similar to the Fast Read instruction, the Fast Read Dual Output instruction can operate at the highest possible frequency of FR (see AC Electrical Characteristics). This is accomplished by adding eight “dummy” clocks after the 24-bit address as shown in Figure 18. The dummy clocks allow the device's internal circuits additional time for setting up the initial address. The input data during the dummy clocks is “don’t care”. However, the IO0 pin should be high-impedance prior to the falling edge of the first data out clock. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/9c4cfcbf61457e6f2723ffa054729907c9c17a68714f48134b0d8270e7439e8b.jpg)



Figure 18. Fast Read Dual Output Instruction


# Fast Read Quad Output (6Bh)

The Fast Read Quad Output (6Bh) instruction is similar to the Fast Read Dual Output (3Bh) instruction except that data is output on four pins, $1 0 _ { 0 }$ , $\mathsf { I O } _ { 1 }$ , $\mathsf { I O } _ { 2 }$ , and $\mathsf { I O } _ { 3 }$ . The Quad Enable (QE) bit in Status Register-2 must be set to 1 before the device will accept the Fast Read Quad Output Instruction. The Fast Read Quad Output Instruction allows data to be transferred at four times the rate of standard SPI devices. 

The Fast Read Quad Output instruction can operate at the highest possible frequency of FR (see AC Electrical Characteristics). This is accomplished by adding eight “dummy” clocks after the 24-bit address as shown in Figure 20. The dummy clocks allow the device's internal circuits additional time for setting up the initial address. The input data during the dummy clocks is “don’t care”. However, the IO pins should be high-impedance prior to the falling edge of the first data out clock. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/aac96bc56c13fa49b9c6f8b6b5476f4842c94d7bba443b69a370a1a0e59d7d70.jpg)



Figure 20. Fast Read Quad Output Instruction


# Fast Read Dual I/O (BBh)

The Fast Read Dual I/O (BBh) instruction allows for improved random access while maintaining two IO pins, $1 0 _ { 0 }$ and $\mathsf { I O } _ { 1 }$ . It is similar to the Fast Read Dual Output (3Bh) instruction but with the capability to input the Address bits (A23-0) two bits per clock. This reduced instruction overhead may allow for code execution (XIP) directly from the Dual SPI in some applications. 

Similar to the Fast Read Dual Output (3Bh) instruction, the Fast Read Dual I/O instruction can operate at the highest possible frequency of FR (see AC Electrical Characteristics). This is accomplished by adding four “dummy” clocks after the 24-bit address as shown in Figure 22. The dummy clocks allow the device's internal circuits additional time for setting up the initial address. The input data during the dummy clocks is “don’t care”. However, the $1 0 \phantom { . 0 }$ pin should be high-impedance prior to the falling edge of the first data out clock. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/6c898c85b6232a237fba3d85e4ea2ba1729e7065e2b2ece50a321c4e98699f15.jpg)



Figure 22. Fast Read Dual I/O Instruction (M7-M0 should be set to Fxh)


# Fast Read Quad I/O (EBh)

The Fast Read Quad I/O (EBh) instruction is similar to the Fast Read Dual I/O (BBh) instruction except that address and data bits are input and output through four pins $1 0 \phantom { . 0 }$ , IO1, $1 0 _ { 2 }$ and IO3 and four Dummy clocks are required in SPI mode prior to the data output. The Quad I/O dramatically reduces instruction overhead allowing faster random access for code execution (XIP) directly from the Quad SPI. The Quad Enable bit (QE) of Status Register-2 must be set to enable the Fast Read Quad I/O Instruction. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/eda49c1a943395fd21fbd300770c0b4ff9a78e39762959bfec54d302ba7fdf39.jpg)



Figure 24. Fast Read Quad I/O Instruction (M7-M0 should be set to Fxh)


# Fast Read Quad I/O with “8/16/32/64-Byte Wrap Around”

The Fast Read Quad I/O instruction can also be used to access a specific portion within a page by issuing a “Set Burst with Wrap” (77h) command prior to EBh. The “Set Burst with Wrap” (77h) command can either enable or disable the “Wrap Around” feature for the following EBh commands. When “Wrap Around” is enabled, the data being accessed can be limited to either an 8, 16, 32 or 64-byte section of a 256-byte page. The output data starts at the initial address specified in the instruction, once it reaches the ending boundary of the 8/16/32/64-byte section, the output will wrap around to the beginning boundary automatically until /CS is pulled high to terminate the command. 

The Burst with Wrap feature allows applications that use cache to quickly fetch a critical address and then fill the cache afterwards within a fixed length (8/16/32/64-byte) of data without issuing multiple read commands. 

The “Set Burst with Wrap” instruction allows three “Wrap Bits”, W6-4 to be set. The W4 bit is used to enable or disable the “Wrap Around” operation while W6-5 are used to specify the length of the wrap around section within a page. Refer to section 8.2.37 for detail descriptions. 

# Set Burst with Wrap (77h)

The Set Burst with Wrap (77h) instruction is used in conjunction with “Fast Read Quad I/O” instruction to access a fixed length of 8/16/32/64-byte section within a 256-byte page. Certain applications can benefit from this feature and improve the overall system code execution performance. 

Similar to a Quad I/O instruction, the Set Burst with Wrap instruction is initiated by driving the /CS pin low and then shifting the instruction code “77h” followed by 24 dummy bits and 8 “Wrap Bits”, W7-0. The instruction sequence is shown in Figure 28. Wrap bit W7 and the lower nibble W3-0 are not used. 

<table><tr><td rowspan="2">W6, W5</td><td colspan="2">W4 = 0</td><td colspan="2">W4 =1 (DEFAULT)</td></tr><tr><td>Wrap Around</td><td>Wrap Length</td><td>Wrap Around</td><td>Wrap Length</td></tr><tr><td>0 0</td><td>Yes</td><td>8-byte</td><td>No</td><td>N/A</td></tr><tr><td>0 1</td><td>Yes</td><td>16-byte</td><td>No</td><td>N/A</td></tr><tr><td>1 0</td><td>Yes</td><td>32-byte</td><td>No</td><td>N/A</td></tr><tr><td>1 1</td><td>Yes</td><td>64-byte</td><td>No</td><td>N/A</td></tr></table>

Once W6-4 is set by a Set Burst with Wrap instruction, all the following “Fast Read Quad I/O” instruction will use the W6-4 setting to access the 8/16/32/64-byte section within any page. To exit the “Wrap Around” function and return to normal read operation, another Set Burst with Wrap instruction should be issued to set ${ \mathsf { W } } 4 = 1$ . The default value of W4 upon power on or after a software/hardware reset is 1. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/786da32cff1eae27f8a8481efbb8712ac9642530c255882db3775ee77de2ffde.jpg)



Figure 28. Set Burst with Wrap Instruction


# Page Program (02h)

The Page Program instruction allows from one byte to 256 bytes (a page) of data to be programmed at previously erased (FFh) memory locations. A Write Enable instruction must be executed before the device will accept the Page Program Instruction (Status Register bit ${ \mathsf { W E L } } = 1$ ). The instruction is initiated by driving the /CS pin low then shifting the instruction code $" 0 \bar { 2 } \mathsf { h } ^ { \prime \prime }$ followed by a 24-bit address (A23-A0) and at least one data byte, into the DI pin. The /CS pin must be held low for the entire length of the instruction while data is being sent to the device. The Page Program instruction sequence is shown in Figure 29. 

If an entire 256 byte page is to be programmed, the last address byte (the 8 least significant address bits) should be set to 0. If the last address byte is not zero, and the number of clocks exceeds the remaining page length, the addressing will wrap to the beginning of the page. In some cases, less than 256 bytes (a partial page) can be programmed without having any effect on other bytes within the same page. One condition to perform a partial page program is that the number of clocks cannot exceed the remaining page length. If more than 256 bytes are sent to the device the addressing will wrap to the beginning of the page and overwrite previously sent data. 

As with the write and erase instructions, the /CS pin must be driven high after the eighth bit of the last byte has been latched. If this is not done the Page Program instruction will not be executed. After /CS is driven high, the self-timed Page Program instruction will commence for a time duration of tpp (See AC Characteristics). While the Page Program cycle is in progress, the Read Status Register instruction may still be accessed for checking the status of the BUSY bit. The BUSY bit is a 1 during the Page Program cycle and becomes a 0 when the cycle is finished and the device is ready to accept other instructions again. After the Page Program cycle has finished the Write Enable Latch (WEL) bit in the Status Register is cleared to 0. The Page Program instruction will not be executed if the addressed page is protected by the Block Protect (CMP, SEC, TB, BP2, BP1, and BP0) bits or the Individual Block/Sector Locks. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/214f0b4215df4ffc9beb36e3b644882b3d2dac0ad29e93e04d726fc24a9da6f2.jpg)



Figure 29. Page Program Instruction


# Quad Input Page Program (32h)

The Quad Page Program instruction allows up to 256 bytes of data to be programmed at previously erased (FFh) memory locations using four pins: IO0, IO1, IO2, and IO3. The Quad Page Program can improve performance for PROM Programmer and applications that have slow clock speeds <5MHz. Systems with faster clock speed will not realize much benefit for the Quad Page Program instruction since the inherent page program time is much greater than the time it take to clock-in the data. 

To use Quad Page Program the Quad Enable (QE) bit in Status Register-2 must be set to 1. A Write Enable instruction must be executed before the device will accept the Quad Page Program instruction (Status Register-1, WEL=1). The instruction is initiated by driving the /CS pin low then shifting the instruction code “32h” followed by a 24-bit address (A23-A0) and at least one data byte, into the IO pins. The /CS pin must be held low for the entire length of the instruction while data is being sent to the device. All other functions of Quad Page Program are identical to standard Page Program. The Quad Page Program instruction sequence is shown in Figure 30. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/803cd770877c54e20996939892c0d9116b33fe8c736f3765b4333130de3f8c07.jpg)



Figure 30. Quad Input Page Program Instruction


# Sector Erase (20h)

The Sector Erase instruction sets all memory within a specified sector (4K-bytes) to the erased state of all 1s (FFh). A Write Enable instruction must be executed before the device will accept the Sector Erase Instruction (Status Register bit WEL must equal 1). The instruction is initiated by driving the /CS pin low and shifting the instruction code “20h” followed a 24-bit sector address (A23-A0). The Sector Erase instruction sequence is shown in Figure 31. 

The /CS pin must be driven high after the eighth bit of the last byte has been latched. If this is not done the Sector Erase instruction will not be executed. After /CS is driven high, the self-timed Sector Erase instruction will commence for a time duration of tSE (See AC Characteristics). While the Sector Erase cycle is in progress, the Read Status Register instruction may still be accessed for checking the status of the BUSY bit. The BUSY bit is a 1 during the Sector Erase cycle and becomes a 0 when the cycle is finished and the device is ready to accept other instructions again. After the Sector Erase cycle has finished the Write Enable Latch (WEL) bit in the Status Register is cleared to 0. The Sector Erase instruction will not be executed if the addressed page is protected by the Block Protect (CMP, SEC, TB, BP2, BP1, and BP0) bits or the Individual Block/Sector Locks. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/a881233d5d080b3a627bd58ab6ce13440ea5aa4083d457862b166b37a3c5cb70.jpg)



Figure 31. Sector Erase Instruction


# 32KB Block Erase (52h)

The Block Erase instruction sets all memory within a specified block (32K-bytes) to the erased state of all 1s (FFh). A Write Enable instruction must be executed before the device will accept the Block Erase Instruction (Status Register bit WEL must equal 1). The instruction is initiated by driving the /CS pin low and shifting the instruction code “52h” followed a 24-bit block address (A23-A0). The Block Erase instruction sequence is shown in Figure 32. 

The /CS pin must be driven high after the eighth bit of the last byte has been latched. If this is not done the Block Erase instruction will not be executed. After /CS is driven high, the self-timed Block Erase instruction will commence for a time duration of tBE1 (See AC Characteristics). While the Block Erase cycle is in progress, the Read Status Register instruction may still be accessed for checking the status of the BUSY bit. The BUSY bit is a 1 during the Block Erase cycle and becomes a 0 when the cycle is finished and the device is ready to accept other instructions again. After the Block Erase cycle has finished the Write Enable Latch (WEL) bit in the Status Register is cleared to 0. The Block Erase instruction will not be executed if the addressed page is protected by the Block Protect (CMP, SEC, TB, BP2, BP1, and BP0) bits or the Individual Block/Sector Locks. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/d7a54ae5e7892e97974e38c78b7ce90a30124fd6c314a59d69dfd32f40e9a918.jpg)



Figure 32. 32KB Block Erase Instruction


# 64KB Block Erase (D8h)

The Block Erase instruction sets all memory within a specified block (64K-bytes) to the erased state of all 1s (FFh). A Write Enable instruction must be executed before the device will accept the Block Erase Instruction (Status Register bit WEL must equal 1). The instruction is initiated by driving the /CS pin low and shifting the instruction code “D8h” followed a 24-bit block address (A23-A0). The Block Erase instruction sequence is shown in Figure 33. 

The /CS pin must be driven high after the eighth bit of the last byte has been latched. If this is not done the Block Erase instruction will not be executed. After /CS is driven high, the self-timed Block Erase instruction will commence for a time duration of tBE (See AC Characteristics). While the Block Erase cycle is in progress, the Read Status Register instruction may still be accessed for checking the status of the BUSY bit. The BUSY bit is a 1 during the Block Erase cycle and becomes a 0 when the cycle is finished and the device is ready to accept other instructions again. After the Block Erase cycle has finished the Write Enable Latch (WEL) bit in the Status Register is cleared to 0. The Block Erase instruction will not be executed if the addressed page is protected by the Block Protect (CMP, SEC, TB, BP2, BP1, and BP0) bits or the Individual Block/Sector Locks. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/8ae4663e57df090e546d70c4542c8fbc8bdb7583016117ee03674ad7f1aa4db5.jpg)



Figure 33. 64KB Block Erase Instruction


# Chip Erase (C7h / 60h)

The Chip Erase instruction sets all memory within the device to the erased state of all 1s (FFh). A Write Enable instruction must be executed before the device will accept the Chip Erase Instruction (Status Register bit WEL must equal 1). The instruction is initiated by driving the /CS pin low and shifting the instruction code “C7h” or “60h”. The Chip Erase instruction sequence is shown in Figure 34. 

The /CS pin must be driven high after the eighth bit has been latched. If this is not done the Chip Erase instruction will not be executed. After /CS is driven high, the self-timed Chip Erase instruction will commence for a time duration of tCE (See AC Characteristics). While the Chip Erase cycle is in progress, the Read Status Register instruction may still be accessed to check the status of the BUSY bit. The BUSY bit is a 1 during the Chip Erase cycle and becomes a 0 when finished and the device is ready to accept other instructions again. After the Chip Erase cycle has finished the Write Enable Latch (WEL) bit in the Status Register is cleared to 0. The Chip Erase instruction will not be executed if any memory region is protected by the Block Protect (CMP, SEC, TB, BP2, BP1, and BP0) bits or the Individual Block/Sector Locks. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/5c3b71f8e7da8298d80c04a2a73517558b2dd3833f7113407961b6d566656848.jpg)



Figure 34. Chip Erase Instruction Sequence Diagram


# Erase / Program Suspend (75h)

The Erase/Program Suspend instruction “75h”, allows the system to interrupt a Sector or Block Erase operation or a Page Program operation and then read from or program/erase data to, any other sectors or blocks. The Erase/Program Suspend instruction sequence is shown in Figure 35. 

The Write Status Register instruction (01h) and Erase instructions (20h, 52h, D8h, C7h, 60h, 44h) are not allowed during Erase Suspend. Erase Suspend is valid only during the Sector or Block erase operation. If written during the Chip Erase operation, the Erase Suspend instruction is ignored. The Write Status Register instruction (01h) and Program instructions (02h, 32h, 42h) are not allowed during Program Suspend. Program Suspend is valid only during the Page Program or Quad Page Program operation. 

The Erase/Program Suspend instruction “75h” will be accepted by the device only if the SUS bit in the Status Register equals to 0 and the BUSY bit equals to 1 while a Sector or Block Erase or a Page Program operation is on-going. If the SUS bit equals to 1 or the BUSY bit equals to 0, the Suspend instruction will be ignored by the device. A maximum of time of “tSUS” (See AC Characteristics) is required to suspend the erase or program operation. The BUSY bit in the Status Register will be cleared from 1 to 0 within “tSUS” and the SUS bit in the Status Register will be set from 0 to 1 immediately after Erase/Program Suspend. For a previously resumed Erase/Program operation, it is also required that the Suspend instruction “75h” is not issued earlier than a minimum of time of “tSUS” following the preceding Resume instruction “7Ah”. 

Unexpected power off during the Erase/Program suspend state will reset the device and release the suspend state. SUS bit in the Status Register will also reset to 0. The data within the page, sector or block that was being suspended may become corrupted. It is recommended for the user to implement system design techniques against the accidental power interruption and preserve data integrity during erase/program suspend state. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/5a5afffdea8352b4317ec3ee57a5b54609556508ff4d0cd1fb5a1120317ada82.jpg)



Figure 35. Erase/Program Suspend Instruction


# Erase / Program Resume (7Ah)

The Erase/Program Resume instruction “7Ah” must be written to resume the Sector or Block Erase operation or the Page Program operation after an Erase/Program Suspend. The Resume instruction “7Ah” will be accepted by the device only if the SUS bit in the Status Register equals to 1 and the BUSY bit equals to 0. After issued the SUS bit will be cleared from 1 to 0 immediately, the BUSY bit will be set from 0 to 1 within 200ns and the Sector or Block will complete the erase operation or the page will complete the program operation. If the SUS bit equals to 0 or the BUSY bit equals to 1, the Resume instruction “7Ah” will be ignored by the device. The Erase/Program Resume instruction sequence is shown in Figure 36. 

Resume instruction is ignored if the previous Erase/Program Suspend operation was interrupted by unexpected power off. It is also required that a subsequent Erase/Program Suspend instruction not to be issued within a minimum of time of “tSUS” following a previous Resume instruction. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/2ab35d6fcbe850e389ae4c6dee0b21308a5063b6ad3968d0e5365cc2f29162ae.jpg)



Figure 36. Erase/Program Resume Instruction


# Power-down (B9h)

Although the standby current during normal operation is relatively low, standby current can be further reduced with the Power-down instruction. The lower power consumption makes the Power-down instruction especially useful for battery powered applications (See ICC1 and ICC2 in AC Characteristics). The instruction is initiated by driving the /CS pin low and shifting the instruction code “B9h” as shown in Figure 37. 

The /CS pin must be driven high after the eighth bit has been latched. If this is not done the Power-down instruction will not be executed. After /CS is driven high, the power-down state will entered within the time duration of tDP (See AC Characteristics). While in the power-down state only the Release Power-down / Device ID (ABh) instruction, which restores the device to normal operation, will be recognized. All other instructions are ignored. This includes the Read Status Register instruction, which is always available during normal operation. Ignoring all but one instruction makes the Power Down state a useful condition for securing maximum write protection. The device always powers-up in the normal operation with the standby current of ICC1. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/b7c4dec3c3cc1677459c55189f979756667e68d8e00dbef11399fcd6ea327b66.jpg)



Figure 37. Deep Power-down Instruction


# Release Power-down / Device ID (ABh)

The Release from Power-down / Device ID instruction is a multi-purpose instruction. It can be used to release the device from the power-down state, or obtain the devices electronic identification (ID) number. 

To release the device from the power-down state, the instruction is issued by driving the /CS pin low, shifting the instruction code “ABh” and driving /CS high as shown in Figure 38a. Release from power-down will take the time duration of tRES1 (See AC Characteristics) before the device will resume normal operation and other instructions are accepted. The /CS pin must remain high during the tRES1 time duration. 

When used only to obtain the Device ID while not in the power-down state, the instruction is initiated by driving the /CS pin low and shifting the instruction code “ABh” followed by 3-dummy bytes. The Device ID bits are then shifted out on the falling edge of CLK with most significant bit (MSB) first. The Device ID value for the W25Q32JV is listed in Manufacturer and Device Identification table. The Device ID can be read continuously. The instruction is completed by driving /CS high. 

When used to release the device from the power-down state and obtain the Device ID, the instruction is the same as previously described, and shown in Figure 38b, except that after /CS is driven high it must remain high for a time duration of tRES2 (See AC Characteristics). After this time duration the device will resume normal operation and other instructions will be accepted. If the Release from Power-down / Device ID instruction is issued while an Erase, Program or Write cycle is in process (when BUSY equals 1) the instruction is ignored and will not have any effects on the current cycle. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/336d30673aaeb4a4cabcd73b87ef299ecd40536b7a4f6584fab8f668a58e490f.jpg)



Figure 38a. Release Power-down Instruction


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/acc7e0c54dbfe375029cf0a16afa4607a45a404156a58c5b3b50b153ff89edd6.jpg)



Figure 38b. Release Power-down / Device ID Instruction


# Read Manufacturer / Device ID (90h)

The Read Manufacturer/Device ID instruction is an alternative to the Release from Power-down / Device ID instruction that provides both the JEDEC assigned manufacturer ID and the specific device ID. 

The Read Manufacturer/Device ID instruction is very similar to the Release from Power-down / Device ID instruction. The instruction is initiated by driving the /CS pin low and shifting the instruction code “90h” followed by a 24-bit address (A23-A0) of 000000h. After which, the Manufacturer ID for Winbond (EFh) and the Device ID are shifted out on the falling edge of CLK with most significant bit (MSB) first as shown in Figure 39. The Device ID values for the W25Q32JV are listed in Manufacturer and Device Identification table. The instruction is completed by driving /CS high. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/f6954a71578ffacf8527e270219563f31f8346946f1623ecc2db365d2bbd9add.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/26974deef2959be345b6764f4f0b54e7952559671f12c15f69e9e71aba7fdea5.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/79f620a5bb4046a7db0242bb5b4de79a1765b0b3a56ba9d1691736b8d5367042.jpg)



Figure 39. Read Manufacturer / Device ID Instruction


# Read Manufacturer / Device ID Dual I/O (92h)

The Read Manufacturer / Device ID Dual I/O instruction is an alternative to the Read Manufacturer / Device ID instruction that provides both the JEDEC assigned manufacturer ID and the specific device ID at 2x speed. 

The Read Manufacturer / Device ID Dual I/O instruction is similar to the Fast Read Dual I/O instruction. The instruction is initiated by driving the /CS pin low and shifting the instruction code “92h” followed by a 24-bit address (A23-A0) of 000000h, but with the capability to input the Address bits two bits per clock. After which, the Manufacturer ID for Winbond (EFh) and the Device ID are shifted out 2 bits per clock on the falling edge of CLK with most significant bits (MSB) first as shown in Figure 40. The Device ID values for the W25Q32JV are listed in Manufacturer and Device Identification table. The Manufacturer and Device IDs can be read continuously, alternating from one to the other. The instruction is completed by driving /CS high. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/576b2625315fe034227cc3658c99813e93b666c7a20cef0317b71af7e7299d48.jpg)



Figure 40. Read Manufacturer / Device ID Dual I/O Instruction


Note: 

The bits M(7-0) must be set to Fxh to be compatible with Fast Read Dual I/O instruction. 

# Read Manufacturer / Device ID Quad I/O (94h)

The Read Manufacturer / Device ID Quad I/O instruction is an alternative to the Read Manufacturer / Device ID instruction that provides both the JEDEC assigned manufacturer ID and the specific device ID at 4x speed. 

The Read Manufacturer / Device ID Quad I/O instruction is similar to the Fast Read Quad I/O instruction. The instruction is initiated by driving the /CS pin low and shifting the instruction code “94h” followed by a four clock dummy cycles and then a 24-bit address (A23-A0) of 000000h, but with the capability to input the Address bits four bits per clock. After which, the Manufacturer ID for Winbond (EFh) and the Device ID are shifted out four bits per clock on the falling edge of CLK with most significant bit (MSB) first as shown in Figure 41. The Device ID values for the W25Q32JV are listed in Manufacturer and Device Identification table. The Manufacturer and Device IDs can be read continuously, alternating from one to the other. The instruction is completed by driving /CS high. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/5676aaf8b82ab3a455b6d0e0219b97db631bf6e24cdc5f14fc4c25a9c473ab21.jpg)



Figure 41. Read Manufacturer / Device ID Quad I/O Instruction


# Note:

The “Continuous Read Mode” bits M(7-0) must be set to Fxh to be compatible with Fast Read Quad I/O instruction. 

# Read Unique ID Number (4Bh)

The Read Unique ID Number instruction accesses a factory-set read-only 64-bit number that is unique to each W25Q32JV device. The ID number can be used in conjunction with user software methods to help prevent copying or cloning of a system. The Read Unique ID instruction is initiated by driving the /CS pin low and shifting the instruction code “4Bh” followed by a four bytes of dummy clocks. After which, the 64- bit ID is shifted out on the falling edge of CLK as shown in Figure 42. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/4666b53d38884f604c0c5dae39ee677c0f26f129151c6bc9f3c8e55e278321aa.jpg)



Figure 42. Read Unique ID Number Instruction


# Read JEDEC ID (9Fh)

For compatibility reasons, the W25Q32JV provides several instructions to electronically determine the identity of the device. The Read JEDEC ID instruction is compatible with the JEDEC standard for SPI compatible serial memories that was adopted in 2003. The instruction is initiated by driving the /CS pin low and shifting the instruction code “9Fh”. The JEDEC assigned Manufacturer ID byte for Winbond (EFh) and two Device ID bytes, Memory Type (ID15-ID8) and Capacity (ID7-ID0) are then shifted out on the falling edge of CLK with most significant bit (MSB) first as shown in Figure 43. For memory type and capacity values refer to Manufacturer and Device Identification table. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/2408314729dcef64a9d9fbb51ef070a3296a65581ea68bf48fad50fea6cb3d1e.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/67e4269881852a7d9f6eb57339a0fe5636d8d6e36b49d0568af66627dfc85061.jpg)



Figure 43. Read JEDEC ID Instruction


# Read SFDP Register (5Ah)

The W25Q32JV features a 256-Byte Serial Flash Discoverable Parameter (SFDP) register that contains information about device configurations, available instructions and other features. The SFDP parameters are stored in one or more Parameter Identification (PID) tables. Currently only one PID table is specified, but more may be added in the future. The Read SFDP Register instruction is compatible with the SFDP standard initially established in 2010 for PC and other applications, as well as the JEDEC standard JESD216-serials that is published in 2011. Most Winbond SpiFlash Memories shipped after June 2011 (date code 1124 and beyond) support the SFDP feature as specified in the applicable datasheet. 

The Read SFDP instruction is initiated by driving the /CS pin low and shifting the instruction code “5Ah” followed by a 24-bit address (A23-A0)(1) into the DI pin. Eight “dummy” clocks are also required before the SFDP register contents are shifted out on the falling edge of the $4 0 ^ { \mathrm { t h } }$ CLK with most significant bit (MSB) first as shown in Figure 34. For SFDP register values and descriptions, please refer to the Winbond Application Note for SFDP Definition Table. 

Note 1: A23-A8 = 0; A7-A0 are used to define the starting byte address for the 256-Byte SFDP Register. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/bed85c548f0eefaecc6a7eb2f02b714a90ed7d360dda6bc088bf90cb9809b68c.jpg)



Figure 34. Read SFDP Register Instruction Sequence Diagram


# Erase Security Registers (44h)

The W25Q32JV offers three 256-byte Security Registers which can be erased and programmed individually. These registers may be used by the system manufacturers to store security and other important information separately from the main memory array. 

The Erase Security Register instruction is similar to the Sector Erase instruction. A Write Enable instruction must be executed before the device will accept the Erase Security Register Instruction (Status Register bit WEL must equal 1). The instruction is initiated by driving the /CS pin low and shifting the instruction code “44h” followed by a 24-bit address (A23-A0) to erase one of the three security registers. 

<table><tr><td>ADDRESS</td><td>A23-16</td><td>A15-12</td><td>A11-8</td><td>A7-0</td></tr><tr><td>Security Register #1</td><td>00h</td><td>0 0 0 1</td><td>0 0 0 0</td><td>Don’t Care</td></tr><tr><td>Security Register #2</td><td>00h</td><td>0 0 1 0</td><td>0 0 0 0</td><td>Don’t Care</td></tr><tr><td>Security Register #3</td><td>00h</td><td>0 0 1 1</td><td>0 0 0 0</td><td>Don’t Care</td></tr></table>

The Erase Security Register instruction sequence is shown in Figure 45. The /CS pin must be driven high after the eighth bit of the last byte has been latched. If this is not done the instruction will not be executed. After /CS is driven high, the self-timed Erase Security Register operation will commence for a time duration of tSE (See AC Characteristics). While the Erase Security Register cycle is in progress, the Read Status Register instruction may still be accessed for checking the status of the BUSY bit. The BUSY bit is a 1 during the erase cycle and becomes a 0 when the cycle is finished and the device is ready to accept other instructions again. After the Erase Security Register cycle has finished the Write Enable Latch (WEL) bit in the Status Register is cleared to 0. The Security Register Lock Bits (LB3-1) in the Status Register-2 can be used to OTP protect the security registers. Once a lock bit is set to 1, the corresponding security register will be permanently locked, Erase Security Register instruction to that register will be ignored (Refer to section 7.1.9 for detail descriptions). 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/f20b1fd817018612f767513b2b9eed198267b156ef303c938e83b2a20755ca91.jpg)



Figure 45. Erase Security Registers Instruction


# Program Security Registers (42h)

The Program Security Register instruction is similar to the Page Program instruction. It allows from one byte to 256 bytes of security register data to be programmed at previously erased (FFh) memory locations. A Write Enable instruction must be executed before the device will accept the Program Security Register Instruction (Status Register bit WEL= 1). The instruction is initiated by driving the /CS pin low then shifting the instruction code “42h” followed by a 24-bit address (A23-A0) and at least one data byte, into the DI pin. The /CS pin must be held low for the entire length of the instruction while data is being sent to the device. 

<table><tr><td>ADDRESS</td><td>A23-16</td><td>A15-12</td><td>A11-8</td><td>A7-0</td></tr><tr><td>Security Register #1</td><td>00h</td><td>0 0 0 1</td><td>0 0 0 0</td><td>Byte Address</td></tr><tr><td>Security Register #2</td><td>00h</td><td>0 0 1 0</td><td>0 0 0 0</td><td>Byte Address</td></tr><tr><td>Security Register #3</td><td>00h</td><td>0 0 1 1</td><td>0 0 0 0</td><td>Byte Address</td></tr></table>

The Program Security Register instruction sequence is shown in Figure 46. The Security Register Lock Bits (LB3-1) in the Status Register-2 can be used to OTP protect the security registers. Once a lock bit is set to 1, the corresponding security register will be permanently locked, Program Security Register instruction to that register will be ignored (See 7.1.9 for detail descriptions). 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/139ea0d2cd63ccd32dff2ea25f2f61e60c2680a6a612241b3c285fb9f9e4e022.jpg)



Figure 46. Program Security Registers Instruction


# Read Security Registers (48h)

The Read Security Register instruction is similar to the Fast Read instruction and allows one or more data bytes to be sequentially read from one of the four security registers. The instruction is initiated by driving the /CS pin low and then shifting the instruction code “48h” followed by a 24-bit address (A23-A0) and eight “dummy” clocks into the DI pin. The code and address bits are latched on the rising edge of the CLK pin. After the address is received, the data byte of the addressed memory location will be shifted out on the DO pin at the falling edge of CLK with most significant bit (MSB) first. The byte address is automatically incremented to the next byte address after each byte of data is shifted out. Once the byte address reaches the last byte of the register (byte address FFh), it will reset to address 00h, the first byte of the register, and continue to increment. The instruction is completed by driving /CS high. The Read Security Register instruction sequence is shown in Figure 47. If a Read Security Register instruction is issued while an Erase, Program or Write cycle is in process $( \mathsf { B U S Y } = 1$ ) the instruction is ignored and will not have any effects on the current cycle. The Read Security Register instruction allows clock rates from D.C. to a maximum of FR (see AC Electrical Characteristics). 

<table><tr><td>ADDRESS</td><td>A23-16</td><td>A15-12</td><td>A11-8</td><td>A7-0</td></tr><tr><td>Security Register #1</td><td>00h</td><td>0 0 0 1</td><td>0 0 0 0</td><td>Byte Address</td></tr><tr><td>Security Register #2</td><td>00h</td><td>0 0 1 0</td><td>0 0 0 0</td><td>Byte Address</td></tr><tr><td>Security Register #3</td><td>00h</td><td>0 0 1 1</td><td>0 0 0 0</td><td>Byte Address</td></tr></table>

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/d1389849ee0ad27fcb92d0b3c9064cb871e03e36f0595e9c15f20a1ab94d32fe.jpg)



Figure 47. Read Security Registers Instruction


# Individual Block/Sector Lock (36h)

The Individual Block/Sector Lock provides an alternative way to protect the memory array from adverse Erase/Program. In order to use the Individual Block/Sector Locks, the WPS bit in Status Register-3 must be set to 1. If WPS=0, the write protection will be determined by the combination of CMP, SEC, TB, BP[2:0] bits in the Status Registers. The Individual Block/Sector Lock bits are volatile bits. The default values after device power up or after a Reset are 1, so the entire memory array is being protected. 

To lock a specific block or sector as illustrated in Figure 4d, an Individual Block/Sector Lock command must be issued by driving /CS low, shifting the instruction code “36h” into the Data Input (DI) pin on the rising edge of CLK, followed by a 24-bit address and then driving /CS high. A Write Enable instruction must be executed before the device will accept the Individual Block/Sector Lock Instruction (Status Register bit WEL= 1). 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/34fff827402cca4d6c8e8334a6e6d851198a5325e8f7f1a79ca4e020c333842d.jpg)



Figure 53. Individual Block/Sector Lock Instruction


# Individual Block/Sector Unlock (39h)

The Individual Block/Sector Lock provides an alternative way to protect the memory array from adverse Erase/Program. In order to use the Individual Block/Sector Locks, the WPS bit in Status Register-3 must be set to 1. If WPS=0, the write protection will be determined by the combination of CMP, SEC, TB, BP[2:0] bits in the Status Registers. The Individual Block/Sector Lock bits are volatile bits. The default values after device power up or after a Reset are 1, so the entire memory array is being protected. 

To unlock a specific block or sector as illustrated in Figure 4d, an Individual Block/Sector Unlock command must be issued by driving /CS low, shifting the instruction code “39h” into the Data Input (DI) pin on the rising edge of CLK, followed by a 24-bit address and then driving /CS high. A Write Enable instruction must be executed before the device will accept the Individual Block/Sector Unlock Instruction (Status Register bit ${ \mathsf { W E L } } = 1$ ). 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/8b12c720cb0a66f336a018bdb2f15b5cefcdf1a8a35e32809a8467f9cdf6528b.jpg)



Figure 54. Individual Block Unlock Instruction


# Read Block/Sector Lock (3Dh)

The Individual Block/Sector Lock provides an alternative way to protect the memory array from adverse Erase/Program. In order to use the Individual Block/Sector Locks, the WPS bit in Status Register-3 must be set to 1. If WPS=0, the write protection will be determined by the combination of CMP, SEC, TB, BP[2:0] bits in the Status Registers. The Individual Block/Sector Lock bits are volatile bits. The default values after device power up or after a Reset are 1, so the entire memory array is being protected. 

To read out the lock bit value of a specific block or sector as illustrated in Figure 4d, a Read Block/Sector Lock command must be issued by driving /CS low, shifting the instruction code “3Dh” into the Data Input (DI) pin on the rising edge of CLK, followed by a 24-bit address. The Block/Sector Lock bit value will be shifted out on the DO pin at the falling edge of CLK with most significant bit (MSB) first as shown in Figure 55. If the least significant bit (LSB) is 1, the corresponding block/sector is locked; if $\therefore S B = 0$ , the corresponding block/sector is unlocked, Erase/Program operation can be performed. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/693edab6841edaae73a9ee652b484f677964be7987b9a1970763a4fe9084007f.jpg)



Figure 55. Read Block Lock Instruction


# Global Block/Sector Lock (7Eh)

All Block/Sector Lock bits can be set to 1 by the Global Block/Sector Lock instruction. The command must be issued by driving /CS low, shifting the instruction code “7Eh” into the Data Input (DI) pin on the rising edge of CLK, and then driving /CS high. A Write Enable instruction must be executed before the device will accept the Global Block/Sector Lock Instruction (Status Register bit ${ \mathsf { W E L } } = 1$ ). 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/06c8ec478cd129c94017bf845562e9d6d32e0305e8821523ff2a9441014dd076.jpg)



Figure 56. Global Block Lock Instruction


# Global Block/Sector Unlock (98h)

All Block/Sector Lock bits can be set to 0 by the Global Block/Sector Unlock instruction. The command must be issued by driving /CS low, shifting the instruction code “98h” into the Data Input (DI) pin on the rising edge of CLK, and then driving /CS high. A Write Enable instruction must be executed before the device will accept the Global Block/Sector Unlock Instruction (Status Register bit ${ \mathsf { W E L } } = 1$ ). 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/50c19a7da7987d68b9f8b3abcf9c5d4f6e68044af23a685d4dbbae416ee16666.jpg)



Figure 57. Global Block Unlock Instruction


# Enable Reset (66h) and Reset Device (99h)

Because of the small package and the limitation on the number of pins, the W25Q32JV provide a software Reset instruction instead of a dedicated RESET pin. Once the Reset instruction is accepted, any on-going internal operations will be terminated and the device will return to its default power-on state and lose all the current volatile settings, such as Volatile Status Register bits, Write Enable Latch (WEL) status, Program/Erase Suspend status, Read parameter setting (P7-P0), Continuous Read Mode bit setting (M7- M0) and Wrap Bit setting (W6-W4). 

“Enable Reset (66h)” and “Reset (99h)” instructions can be issued in SPI. To avoid accidental reset, both instructions must be issued in sequence. Any other commands other than “Reset (99h)” after the “Enable Reset (66h)” command will disable the “Reset Enable” state. A new sequence of “Enable Reset (66h)” and “Reset (99h)” is needed to reset the device. Once the Reset command is accepted by the device, the device will take approximately tRST=30us to reset. During this period, no command will be accepted. 

Data corruption may happen if there is an on-going or suspended internal Erase or Program operation when Reset command sequence is accepted by the device. It is recommended to check the BUSY bit and the SUS bit in Status Register before issuing the Reset command sequence. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/147066cd9d4bd34be35093c63816e341dfef8a241b64bcf7115ab31f6a400f6d.jpg)



Figure 58. Enable Reset and Reset Instruction Sequence


# 9. ELECTRICAL CHARACTERISTICS


9.1 Absolute Maximum Ratings (1)


<table><tr><td>PARAMETERS</td><td>SYMBOL</td><td>CONDITIONS</td><td>RANGE</td><td>UNIT</td></tr><tr><td>Supply Voltage</td><td>VCC</td><td></td><td>-0.6 to 4.6</td><td>V</td></tr><tr><td>Voltage Applied to Any Pin</td><td>VIO</td><td>Relative to Ground</td><td>-0.6 to VCC+0.4</td><td>V</td></tr><tr><td>Transient Voltage on any Pin</td><td>VIOT</td><td>&lt;20nS Transient 
Relative to Ground</td><td>-2.0V to VCC+2.0V</td><td>V</td></tr><tr><td>Storage Temperature</td><td>TSTG</td><td></td><td>-65 to +150</td><td>°C</td></tr><tr><td>Lead Temperature</td><td>TLEAD</td><td></td><td>See Note (2)</td><td>°C</td></tr><tr><td>Electrostatic Discharge Voltage</td><td>VESD</td><td>Human Body Model(3)</td><td>-2000 to +2000</td><td>V</td></tr></table>

# Notes:

1. This device has been designed and tested for the specified operation ranges. Proper operation outside of these levels is not guaranteed. Exposure to absolute maximum ratings may affect device reliability. Exposure beyond absolute maximum ratings may cause permanent damage. 

2. Compliant with JEDEC Standard J-STD-20C for small body Sn-Pb or Pb-free (Green) assembly and the European directive on restrictions on hazardous substances (RoHS) 2002/95/EU. 

3. JEDEC Std JESD22-A114A $( \mathsf C 1 = 1 0 0 \mathsf p \mathsf F$ , $\mathsf { R } 1 = 1 5 0 0$ ohms, ${ \sf R } 2 \mathrm { = } 5 0 0$ ohms). 


9.2 Operating Ranges


<table><tr><td rowspan="2">PARAMETER</td><td rowspan="2">SYMBOL</td><td rowspan="2">CONDITIONS</td><td colspan="2">SPEC</td><td rowspan="2">UNIT</td></tr><tr><td>MIN</td><td>MAX</td></tr><tr><td rowspan="2">Supply Voltage(1)</td><td rowspan="2">VCC</td><td>FR=133MHz, fR=50MHz</td><td>3.0</td><td>3.6</td><td>V</td></tr><tr><td>FR=104MHz, fR=50MHz</td><td>2.7</td><td>3.0</td><td>V</td></tr><tr><td rowspan="2">Ambient Temperature, Operating</td><td rowspan="2">TA</td><td>Industrial</td><td>-40</td><td>+85</td><td>°C</td></tr><tr><td>Industrial Plus</td><td>-40</td><td>+105</td><td>°C</td></tr></table>

# Note:

1. VCC voltage during Read can operate across the min and max range but should not exceed $\pm 1 0 \%$ of the programming (erase/write) voltage. 


9.3 Power-Up Power-Down Timing and Requirements


<table><tr><td rowspan="2">PARAMETER</td><td rowspan="2">SYMBOL</td><td colspan="2">SPEC</td><td rowspan="2">UNIT</td></tr><tr><td>MIN</td><td>MAX</td></tr><tr><td>VCC (min) to /CS Low</td><td>tVSL(1)</td><td>20</td><td></td><td>μs</td></tr><tr><td>Time Delay Before Write Instruction</td><td>tPUW(1)</td><td>5</td><td></td><td>ms</td></tr><tr><td>Write Inhibit Threshold Voltage</td><td>VWI(1)</td><td>1.0</td><td>2.0</td><td>V</td></tr></table>

# Note:

1. These parameters are characterized only. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/b441bb0639b08eec16d440a680fc4de87c443fde3825bd022ec9ab38e632c00b.jpg)



Figure 58a. Power-up Timing and Voltage Levels


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/3a268dbcc2b5405a71108d1ff3b3ae435ab013d6d04688a6404242314c09083c.jpg)



Figure 58b. Power-up, Power-Down Requirement



9.4 DC Electrical Characteristics-


<table><tr><td rowspan="2">PARAMETER</td><td rowspan="2">SYMBOL</td><td rowspan="2">CONDITIONS</td><td colspan="3">SPEC</td><td rowspan="2">UNIT</td></tr><tr><td>MIN</td><td>TYP</td><td>MAX</td></tr><tr><td>Input Capacitance</td><td>CIN(1)</td><td>VIN = 0V(1)</td><td></td><td></td><td>6</td><td>pF</td></tr><tr><td>Output Capacitance</td><td>Cout(1)</td><td>VOUT = 0V(1)</td><td></td><td></td><td>8</td><td>pF</td></tr><tr><td>Input Leakage</td><td>ILI</td><td></td><td></td><td></td><td>±2</td><td>μA</td></tr><tr><td>I/O Leakage</td><td>ILO</td><td></td><td></td><td></td><td>±2</td><td>μA</td></tr><tr><td>Standby Current</td><td>ICC1</td><td>/CS = VCC, VIN = GND or VCC</td><td></td><td>10</td><td>50</td><td>μA</td></tr><tr><td>Power-down Current</td><td>ICC2</td><td>/CS = VCC, VIN = GND or VCC</td><td></td><td>1</td><td>15</td><td>μA</td></tr><tr><td>Current Read Data / Dual /Quad 50MHz(2)</td><td>ICC3</td><td>C = 0.1 VCC / 0.9 VCC DO = Open</td><td></td><td>8</td><td>15</td><td>mA</td></tr><tr><td>Current Read Data / Dual /Quad 80MHz(2)</td><td>ICC3</td><td>C = 0.1 VCC / 0.9 VCC DO = Open</td><td></td><td>10</td><td>18</td><td>mA</td></tr><tr><td>Current Read Data / Dual Output Read/Quad Output Read 104MHz(2)</td><td>ICC3</td><td>C = 0.1 VCC / 0.9 VCC DO = Open</td><td></td><td>12</td><td>20</td><td>mA</td></tr><tr><td>Current Write Status Register</td><td>ICC4</td><td>/CS = VCC</td><td></td><td>20</td><td>25</td><td>mA</td></tr><tr><td>Current Page Program</td><td>ICC5</td><td>/CS = VCC</td><td></td><td>20</td><td>25</td><td>mA</td></tr><tr><td>Current Sector/Block Erase</td><td>ICC6</td><td>/CS = VCC</td><td></td><td>20</td><td>25</td><td>mA</td></tr><tr><td>Current Chip Erase</td><td>ICC7</td><td>/CS = VCC</td><td></td><td>20</td><td>25</td><td>mA</td></tr><tr><td>Input Low Voltage</td><td>VIL</td><td></td><td>-0.5</td><td></td><td>VCC x 0.3</td><td>V</td></tr><tr><td>Input High Voltage</td><td>VIH</td><td></td><td>VCC x 0.7</td><td></td><td>VCC + 0.4</td><td>V</td></tr><tr><td>Output Low Voltage</td><td>VOL</td><td>IOL = 100 μA</td><td></td><td></td><td>0.2</td><td>V</td></tr><tr><td>Output High Voltage</td><td>VOH</td><td>IOH = -100 μA</td><td>VCC - 0.2</td><td></td><td></td><td>V</td></tr></table>

# Notes:

1. Tested on sample basis and specified through design and characterization data. ${ \mathsf { T A } } = 2 5 ^ { \circ } { \mathsf { C } }$ , $\mathsf { V C C } = 3 . 0 \mathsf { V }$ . 

2. Checker Board Pattern. 


9.5 AC Measurement Conditions


<table><tr><td rowspan="2">PARAMETER</td><td rowspan="2">SYMBOL</td><td colspan="2">SPEC</td><td rowspan="2">UNIT</td></tr><tr><td>MIN</td><td>MAX</td></tr><tr><td>Load Capacitance</td><td>CL</td><td></td><td>30</td><td>pF</td></tr><tr><td>Input Rise and Fall Times</td><td>TR, TF</td><td></td><td>5</td><td>ns</td></tr><tr><td>Input Pulse Voltages</td><td>VIN</td><td colspan="2">0.1 VCC to 0.9 VCC</td><td>V</td></tr><tr><td>Input Timing Reference Voltages</td><td>IN</td><td colspan="2">0.3 VCC to 0.7 VCC</td><td>V</td></tr><tr><td>Output Timing Reference Voltages</td><td>OUT</td><td colspan="2">0.5 VCC to 0.5 VCC</td><td>V</td></tr></table>

# Note:

1. Output Hi-Z is defined as the point where data out is no longer driven. 

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/773b5720fc3c8f3aa5aa712c41d4d1c65f175835e86a3921c07a23b4b3c90602.jpg)



Figure 59. AC Measurement I/O Waveform



9.6 AC Electrical Characteristics(6)


<table><tr><td rowspan="2">DESCRIPTION</td><td rowspan="2">SYMBOL</td><td rowspan="2">ALT</td><td colspan="3">SPEC</td><td rowspan="2">UNIT</td></tr><tr><td>MIN</td><td>TYP</td><td>MAX</td></tr><tr><td>Clock frequency except for Read Data (03h) instructions (3.0V-3.6V)</td><td>FR</td><td>fC1</td><td>D.C.</td><td></td><td>133</td><td>MHz</td></tr><tr><td>Clock frequency except for Read Data (03h) instructions( 2.7V-3.0V)</td><td>FR</td><td>fC2</td><td>D.C.</td><td></td><td>104</td><td>MHz</td></tr><tr><td>Clock frequency for Read Data instruction (03h)</td><td>fR</td><td></td><td>D.C.</td><td></td><td>50</td><td>MHz</td></tr><tr><td>Clock High, Low Time for all instructions except for Read Data (03h)</td><td>tCLH, tCLL(1)</td><td></td><td>45% PC</td><td></td><td></td><td>ns</td></tr><tr><td>Clock High, Low Time for Read Data (03h) instruction</td><td>tCRLH, tCRLL(1)</td><td></td><td>45% PC</td><td></td><td></td><td>ns</td></tr><tr><td>Clock Rise Time peak to peak</td><td>tCLCH(2)</td><td></td><td>0.1</td><td></td><td></td><td>V/ns</td></tr><tr><td>Clock Fall Time peak to peak</td><td>tCHCL(2)</td><td></td><td>0.1</td><td></td><td></td><td>V/ns</td></tr><tr><td>/CS Active Setup Time relative to CLK</td><td>tSLCH</td><td>tCSS</td><td>3</td><td></td><td></td><td>ns</td></tr><tr><td>/CS Not Active Hold Time relative to CLK</td><td>tCHSL</td><td></td><td>3</td><td></td><td></td><td>ns</td></tr><tr><td>Data In Setup Time</td><td>tDVCH</td><td>tDSU</td><td>1</td><td></td><td></td><td>ns</td></tr><tr><td>Data In Hold Time</td><td>tCHDX</td><td>tDH</td><td>2</td><td></td><td></td><td>ns</td></tr><tr><td>/CS Active Hold Time relative to CLK</td><td>tCHSH</td><td></td><td>3</td><td></td><td></td><td>ns</td></tr><tr><td>/CS Not Active Setup Time relative to CLK</td><td>tSHCH</td><td></td><td>3</td><td></td><td></td><td>ns</td></tr><tr><td>/CS Deselect Time (for Read)</td><td>tSHSL1</td><td>tCSH</td><td>10</td><td></td><td></td><td>ns</td></tr><tr><td>/CS Deselect Time (for Erase or Program or Write)</td><td>tSHSL2</td><td>tCSH</td><td>50</td><td></td><td></td><td>ns</td></tr><tr><td>Output Disable Time</td><td>tSHQZ(2)</td><td>tDIS</td><td></td><td></td><td>7</td><td>ns</td></tr><tr><td>Clock Low to Output Valid 2.7V-3.6V</td><td>tCLQV</td><td>tv</td><td></td><td></td><td>6</td><td>ns</td></tr><tr><td>Output Hold Time</td><td>tCLQX</td><td>thO</td><td>1.5</td><td></td><td></td><td>ns</td></tr></table>


Continued – next page AC Electrical Characteristics (cont’d) 


<table><tr><td rowspan="2">DESCRIPTION</td><td rowspan="2">SYMBOL</td><td rowspan="2">ALT</td><td colspan="3">SPEC</td><td rowspan="2">UNIT</td></tr><tr><td>MIN</td><td>TYP</td><td>MAX</td></tr><tr><td>Write Protect Setup Time Before /CS Low</td><td>tWHSL(3)</td><td></td><td>20</td><td></td><td></td><td>ns</td></tr><tr><td>Write Protect Hold Time After /CS High</td><td>tSHWL(3)</td><td></td><td>100</td><td></td><td></td><td>ns</td></tr><tr><td>/CS High to Power-down Mode</td><td>tDP(2)</td><td></td><td></td><td></td><td>3</td><td>μs</td></tr><tr><td>/CS High to Standby Mode without ID Read</td><td>tRES1(2)</td><td></td><td></td><td></td><td>3</td><td>μs</td></tr><tr><td>/CS High to Standby Mode with ID Read</td><td>tRES2(2)</td><td></td><td></td><td></td><td>1.8</td><td>μs</td></tr><tr><td>/CS High to next Instruction after Suspend</td><td>tsus(2)</td><td></td><td></td><td></td><td>20</td><td>μs</td></tr><tr><td>/CS High to next Instruction after Reset</td><td>tRST(2)</td><td></td><td></td><td></td><td>30</td><td>μs</td></tr><tr><td>/RESET pin Low period to reset the device</td><td>tRESET(2)</td><td></td><td>1(3)</td><td></td><td></td><td>μs</td></tr><tr><td>Write Status Register Time</td><td>tw</td><td></td><td></td><td>10</td><td>15</td><td>ms</td></tr><tr><td>Page Program Time</td><td>tPP</td><td></td><td></td><td>0.4</td><td>3</td><td>ms</td></tr><tr><td>Sector Erase Time (4KB)</td><td>tSE</td><td></td><td></td><td>45</td><td>400</td><td>ms</td></tr><tr><td>Block Erase Time (32KB)</td><td>tBE1</td><td></td><td></td><td>120</td><td>1,600</td><td>ms</td></tr><tr><td>Block Erase Time (64KB)</td><td>tBE2</td><td></td><td></td><td>150</td><td>2,000</td><td>ms</td></tr><tr><td>Chip Erase Time</td><td>tCE</td><td></td><td></td><td>10</td><td>50</td><td>s</td></tr></table>


Notes: 



1. Clock high or Clock low must be more than or equal to $45 \% \mathsf { P c }$ . $\mathsf { P c } { = } 1 / \mathsf { f c } _ { ( \mathsf { m A X } ) }$ 



2. Value guaranteed by design and/or characterization, not $100 \%$ tested in production. 



3. It’s possible to reset the device with shorter tRESET (as short as a few hundred ns), a 1us minimum is recommended to ensure reliable operation. 



4. Tested on sample basis and specified through design and characterization data. ${ \mathsf { T } } { \mathsf { A } } = 2 5 ^ { \circ } { \mathsf { C } }$ , $\mathsf { V C C } = 3 . 0 \mathsf { V }$ , $2 5 \%$ driver strength. 



5. 4-bytes address alignment for Quad Read, start address from [A1,A0]=(0,0). 



9.7 Serial Output Timing


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/29dcc285d359c92ae288665ec15aa66c8c7ec81e54d75d9c4c5d0312da62d7ec.jpg)



9.8 Serial Input Timing


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/04d3c06661db3d1369c218aceee589a5f6b5848e3e74e0069c70bca1c5645f6f.jpg)



9.9 /WP Timing


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/7ca0dcf039632465dcdfc97f8959d992cb24acaf014dea165538ba74a3f75d0f.jpg)


# 10.PACKAGE SPECIFICATIONS

# 10.1 8-Pin SOIC 150-mil (Package Code SN)

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/58c87f62a7e81e66af2e439db44f9d05a0beb2dfbadc2fa2c6bcc16e2ad2c93f.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/067739cadf29ffbea43cd11dd756d664e77b040fa93157cc7913fe822a4079d6.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/fca46a7a7377e4dfbf20b91be4e3619171343a9fae943ca92c22a5e1d88b1287.jpg)


<table><tr><td rowspan="2">SYMBOL</td><td colspan="2">MILLIMETERS</td><td colspan="2">INCHES</td></tr><tr><td>Min</td><td>Max</td><td>Min</td><td>Max</td></tr><tr><td>A</td><td>1.35</td><td>1.75</td><td>0.053</td><td>0.069</td></tr><tr><td>A1</td><td>0.10</td><td>0.25</td><td>0.004</td><td>0.010</td></tr><tr><td>b</td><td>0.33</td><td>0.51</td><td>0.013</td><td>0.020</td></tr><tr><td>c</td><td>0.19</td><td>0.25</td><td>0.008</td><td>0.010</td></tr><tr><td>E(3)</td><td>3.80</td><td>4.00</td><td>0.150</td><td>0.157</td></tr><tr><td>D(3)</td><td>4.80</td><td>5.00</td><td>0.188</td><td>0.196</td></tr><tr><td>e(2)</td><td colspan="2">1.27 BSC</td><td colspan="2">0.050 BSC</td></tr><tr><td>HE</td><td>5.80</td><td>6.20</td><td>0.228</td><td>0.244</td></tr><tr><td>Y(4)</td><td>---</td><td>0.10</td><td>---</td><td>0.004</td></tr><tr><td>L</td><td>0.40</td><td>1.27</td><td>0.016</td><td>0.050</td></tr><tr><td>θ</td><td>0°</td><td>10°</td><td>0°</td><td>10°</td></tr></table>

# Notes:

1. Controlling dimensions: millimeters, unless otherwise specified. 

2. BSC $=$ Basic lead spacing between centers. 

3. Dimensions D and E do not include mold flash protrusions and should be measured from the bottom of the package. 

4. Formed leads coplanarity with respect to seating plane shall be within 0.004 inches. 

# 10.2 8-Pin SOIC 208-mil (Package Code SS)

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/f303a9e2fe8193fbbd581483ee7ec35f1296d547956986bdee42fe171af1d981.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/1a7a01ddab74af547e3c34c65d5139f36cdbccd438351dffeca66d6be852ab3d.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/2d0e4ccf98422ed84f89644a7d62b9bc789676f1b91c6563836c588d10e51c16.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/6a45588ba44863b9c2c35bc1ef462c4df7f2c82ee665d5335c8775358066c231.jpg)


<table><tr><td rowspan="2">Symbol</td><td colspan="3">Millimeters</td><td colspan="3">Inches</td></tr><tr><td>Min</td><td>Nom</td><td>Max</td><td>Min</td><td>Nom</td><td>Max</td></tr><tr><td>A</td><td>1.75</td><td>1.95</td><td>2.16</td><td>0.069</td><td>0.077</td><td>0.085</td></tr><tr><td>A1</td><td>0.05</td><td>0.15</td><td>0.25</td><td>0.002</td><td>0.006</td><td>0.010</td></tr><tr><td>A2</td><td>1.70</td><td>1.80</td><td>1.91</td><td>0.067</td><td>0.071</td><td>0.075</td></tr><tr><td>b</td><td>0.35</td><td>0.42</td><td>0.48</td><td>0.014</td><td>0.017</td><td>0.019</td></tr><tr><td>C</td><td>0.19</td><td>0.20</td><td>0.25</td><td>0.007</td><td>0.008</td><td>0.010</td></tr><tr><td>D</td><td>5.18</td><td>5.28</td><td>5.38</td><td>0.204</td><td>0.208</td><td>0.212</td></tr><tr><td>D1</td><td>5.13</td><td>5.23</td><td>5.33</td><td>0.202</td><td>0.206</td><td>0.210</td></tr><tr><td>E</td><td>5.18</td><td>5.28</td><td>5.38</td><td>0.204</td><td>0.208</td><td>0.212</td></tr><tr><td>E1</td><td>5.13</td><td>5.23</td><td>5.33</td><td>0.202</td><td>0.206</td><td>0.210</td></tr><tr><td>e</td><td colspan="3">1.27 BSC</td><td colspan="3">0.050 BSC</td></tr><tr><td>H</td><td>7.70</td><td>7.90</td><td>8.10</td><td>0.303</td><td>0.311</td><td>0.319</td></tr><tr><td>L</td><td>0.50</td><td>0.65</td><td>0.80</td><td>0.020</td><td>0.026</td><td>0.031</td></tr><tr><td>y</td><td>---</td><td>---</td><td>0.10</td><td>---</td><td>---</td><td>0.004</td></tr><tr><td>θ</td><td>0°</td><td>---</td><td>8°</td><td>0°</td><td>---</td><td>8°</td></tr></table>

# 10.3 8-Pin VSOP 208-mil (Package Code ST)

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/82f0ba5db786311ba65935b1ef6b794aa207fb64fa5dc6aadf2a302d314c1a84.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/0b7c66919c1cb566072d4f2debeab704de4547d2f14e6bfbece0756094526b53.jpg)



DETAIL"A"


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/60aad1bb39e1122fc0b8712c40a77010da18a718a64f04372a2e51e18458794b.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/693accea7fb4573890e47fb285cc8b3069a5ebec85666098eb87feb8bda3c5e8.jpg)


<table><tr><td rowspan="2">Symbol</td><td colspan="3">Millimeters</td><td colspan="3">Inches</td></tr><tr><td>Min</td><td>Nom</td><td>Max</td><td>Min</td><td>Nom</td><td>Max</td></tr><tr><td>A</td><td>—</td><td>—</td><td>1.00</td><td>—</td><td>—</td><td>0.039</td></tr><tr><td>A1</td><td>0.05</td><td>0.10</td><td>0.15</td><td>0.002</td><td>0.004</td><td>0.006</td></tr><tr><td>A2</td><td>0.75</td><td>0.80</td><td>0.85</td><td>0.030</td><td>0.031</td><td>0.033</td></tr><tr><td>b</td><td>0.35</td><td>0.42</td><td>0.48</td><td>0.014</td><td>0.017</td><td>0.019</td></tr><tr><td>c</td><td colspan="3">0.127 REF</td><td colspan="3">0.005 REF</td></tr><tr><td>D</td><td>5.18</td><td>5.28</td><td>5.38</td><td>0.204</td><td>0.208</td><td>0.212</td></tr><tr><td>E</td><td>7.70</td><td>7.90</td><td>8.10</td><td>0.303</td><td>0.311</td><td>0.319</td></tr><tr><td>E1</td><td>5.18</td><td>5.28</td><td>5.38</td><td>0.204</td><td>0.208</td><td>0.212</td></tr><tr><td>e</td><td>—</td><td>1.27</td><td>—</td><td>—</td><td>0.050</td><td>—</td></tr><tr><td>L</td><td>0.50</td><td>0.65</td><td>0.80</td><td>0.020</td><td>0.026</td><td>0.031</td></tr><tr><td>y</td><td>—</td><td>—</td><td>0.10</td><td>—</td><td>—</td><td>0.004</td></tr><tr><td>θ</td><td>0°</td><td>—</td><td>8°</td><td>0°</td><td>—</td><td>8°</td></tr></table>

# 10.4 8-Pad WSON 6x5-mm (Package Code ZP)

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/3817bc198ae062a433e93abf2272e3f55bcd3397da7bf12017376fd284e1cc73.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/f3bceed9c8e63cefe7b0c1ef143cbabf760892c4b2ab1b08675cf44197292495.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/56703606f472a62f181b91c8438ec031caf264e5ec0f335477811c23870d5ce4.jpg)


<table><tr><td rowspan="2">Symbol</td><td colspan="3">Millimeters</td><td colspan="3">Inches</td></tr><tr><td>Min</td><td>Nom</td><td>Max</td><td>Min</td><td>Nom</td><td>Max</td></tr><tr><td>A</td><td>0.70</td><td>0.75</td><td>0.80</td><td>0.028</td><td>0.030</td><td>0.031</td></tr><tr><td>A1</td><td>0.00</td><td>0.02</td><td>0.05</td><td>0.000</td><td>0.001</td><td>0.002</td></tr><tr><td>b</td><td>0.35</td><td>0.40</td><td>0.48</td><td>0.014</td><td>0.016</td><td>0.019</td></tr><tr><td>C</td><td>---</td><td>0.20 REF</td><td>---</td><td>---</td><td>0.008 REF</td><td>---</td></tr><tr><td>D</td><td>5.90</td><td>6.00</td><td>6.10</td><td>0.232</td><td>0.236</td><td>0.240</td></tr><tr><td>D2</td><td>3.35</td><td>3.40</td><td>3.45</td><td>0.132</td><td>0.134</td><td>0.136</td></tr><tr><td>E</td><td>4.90</td><td>5.00</td><td>5.10</td><td>0.193</td><td>0.197</td><td>0.201</td></tr><tr><td>E2</td><td>4.25</td><td>4.30</td><td>4.35</td><td>0.167</td><td>0.169</td><td>0.171</td></tr><tr><td>e</td><td colspan="3">1.27 BSC</td><td colspan="3">0.050 BSC</td></tr><tr><td>L</td><td>0.55</td><td>0.60</td><td>0.65</td><td>0.022</td><td>0.024</td><td>0.026</td></tr><tr><td>y</td><td>0.00</td><td>---</td><td>0.075</td><td>0.000</td><td>---</td><td>0.003</td></tr></table>

# Note:

The metal pad area on the bottom center of the package is not connected to any internal electrical signals. It can be left floating or connected to the device ground (GND pin). Avoid placement of exposed PCB vias under the pad. 

# 10.5 8-Pad WSON 8x6-mm (Package Code ZE)

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/2518dae7e69d7528005b150dd49ae238df5befb64942bbc91ebb34ef1b67b751.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/79a3d05a17fe4852e917889f7be27967bd69332db0fade05073156742d495113.jpg)


<table><tr><td rowspan="2">Symbol</td><td colspan="3">Millimeters</td><td colspan="3">Inches</td></tr><tr><td>Min</td><td>Nom</td><td>Max</td><td>Min</td><td>Nom</td><td>Max</td></tr><tr><td>A</td><td>0.70</td><td>0.75</td><td>0.80</td><td>0.028</td><td>0.030</td><td>0.031</td></tr><tr><td>A1</td><td>0.00</td><td>0.02</td><td>0.05</td><td>0.000</td><td>0.001</td><td>0.002</td></tr><tr><td>b</td><td>0.35</td><td>0.40</td><td>0.48</td><td>0.014</td><td>0.016</td><td>0.019</td></tr><tr><td>C</td><td>---</td><td>0.20 REF</td><td>---</td><td>---</td><td>0.008 REF</td><td>---</td></tr><tr><td>D</td><td>7.90</td><td>8.00</td><td>8.10</td><td>0.311</td><td>0.315</td><td>0.319</td></tr><tr><td>D2</td><td>3.35</td><td>3.40</td><td>3.45</td><td>0.132</td><td>0.134</td><td>0.136</td></tr><tr><td>E</td><td>5.90</td><td>6.00</td><td>6.10</td><td>0.232</td><td>0.236</td><td>0.240</td></tr><tr><td>E2</td><td>4.25</td><td>4.30</td><td>4.35</td><td>0.167</td><td>0.169</td><td>0.171</td></tr><tr><td>e</td><td>---</td><td>1.27</td><td>---</td><td>---</td><td>0.050</td><td>---</td></tr><tr><td>L</td><td>0.45</td><td>0.50</td><td>0.55</td><td>0.018</td><td>0.020</td><td>0.022</td></tr><tr><td>y</td><td>0.00</td><td>---</td><td>0.050</td><td>0.000</td><td>---</td><td>0.002</td></tr></table>

# Note:

The metal pad area on the bottom center of the package is not connected to any internal electrical signals. It can be left floating or connected to the device ground (GND pin). Avoid placement of exposed PCB vias under the pad. 

# 10.6 Pad XSON 4x4x0.45-mm (Package Code XG)

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/04bfd56e015a1fd251459b40e52d77b515e412af53229ccc5a59b7cecccae23c.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/31e878609fa1be46b7f048ea76a7b54e7cc36d7e4e0f69ab00249e6e521db791.jpg)



DETAILA


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/61c65f9ff26b6e484a5ee1bcdba9dd45cdbfccc85e7e2564577d1cf88f008480.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/cf73e708f85f0746ab1dbcf55fce5cc099e4b62bdc507ae225f1538682596d90.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/923306833f0b0ef0911021b4b25f148b5bec7db56d8024219383df31c9891892.jpg)



DETAILB


<table><tr><td rowspan="2">SYMBOL</td><td colspan="3">DIMENSION
(MM)</td><td colspan="3">DIMENSION
(Inch)</td></tr><tr><td>MIN.</td><td>NOM.</td><td>MAX.</td><td>MIN.</td><td>NOM.</td><td>MAX.</td></tr><tr><td>A</td><td>0.40</td><td>0.45</td><td>0.50</td><td>0.0157</td><td>0.0177</td><td>0.0196</td></tr><tr><td>A1</td><td>0.00</td><td>0.02</td><td>0.05</td><td>0</td><td>0.0007</td><td>0.0019</td></tr><tr><td>A2</td><td>-</td><td>0.15</td><td>-</td><td>-</td><td>0.0059</td><td>-</td></tr><tr><td>A3</td><td>0.25</td><td>0.30</td><td>0.35</td><td>0.0098</td><td>0.0118</td><td>0.0137</td></tr><tr><td>b</td><td>0.25</td><td>0.30</td><td>0.35</td><td>0.0098</td><td>0.0118</td><td>0.0137</td></tr><tr><td>D</td><td>3.90</td><td>4.00</td><td>4.10</td><td>0.1535</td><td>0.1574</td><td>0.1614</td></tr><tr><td>D1</td><td>2.20</td><td>2.30</td><td>2.40</td><td>0.0866</td><td>0.0905</td><td>0.0944</td></tr><tr><td>E</td><td>3.90</td><td>4.00</td><td>4.10</td><td>0.1535</td><td>0.1574</td><td>0.1614</td></tr><tr><td>E1</td><td>2.90</td><td>3.00</td><td>3.10</td><td>0.1141</td><td>0.1181</td><td>0.1220</td></tr><tr><td>e</td><td colspan="3">0.80 BSC</td><td colspan="3">0.0314 BSC</td></tr><tr><td>L</td><td>0.35</td><td>0.40</td><td>0.45</td><td>0.0137</td><td>0.0157</td><td>0.0177</td></tr></table>

# 10.7 16-Pin SOIC 300-mil (Package Code SF)

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/fdba61075d656ee3c3a193e578e0c2abae30c0afdec2f8a4c2090c774712a72d.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/6db8579dee13fa020cec0ecc898385eb36f906608d92e2921840df81b09cff1d.jpg)



DETAILA


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/3a8fb682e74cb72636185b569ac690e3824990e795f62a517e70880c25141f39.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/177d1fca14ddce0afa57ffbb6ce7f057fd7c1c47f27a75890332a39ad3ac120f.jpg)


<table><tr><td rowspan="2">Symbol</td><td colspan="3">Millimeters</td><td colspan="3">Inches</td></tr><tr><td>Min</td><td>Nom</td><td>Max</td><td>Min</td><td>Nom</td><td>Max</td></tr><tr><td>A</td><td>2.36</td><td>2.49</td><td>2.64</td><td>0.093</td><td>0.098</td><td>0.104</td></tr><tr><td>A1</td><td>0.10</td><td>---</td><td>0.30</td><td>0.004</td><td>---</td><td>0.012</td></tr><tr><td>A2</td><td>---</td><td>2.31</td><td>---</td><td>---</td><td>0.091</td><td>---</td></tr><tr><td>b</td><td>0.33</td><td>0.41</td><td>0.51</td><td>0.013</td><td>0.016</td><td>0.020</td></tr><tr><td>C</td><td>0.18</td><td>0.23</td><td>0.28</td><td>0.007</td><td>0.009</td><td>0.011</td></tr><tr><td>D</td><td>10.08</td><td>10.31</td><td>10.49</td><td>0.397</td><td>0.406</td><td>0.413</td></tr><tr><td>E</td><td>10.01</td><td>10.31</td><td>10.64</td><td>0.394</td><td>0.406</td><td>0.419</td></tr><tr><td>E1</td><td>7.39</td><td>7.49</td><td>7.59</td><td>0.291</td><td>0.295</td><td>0.299</td></tr><tr><td>e</td><td colspan="3">1.27 BSC</td><td colspan="3">0.050 BSC</td></tr><tr><td>L</td><td>0.38</td><td>0.81</td><td>1.27</td><td>0.015</td><td>0.032</td><td>0.050</td></tr><tr><td>y</td><td>---</td><td>---</td><td>0.076</td><td>---</td><td>---</td><td>0.003</td></tr><tr><td>θ</td><td>0°</td><td>---</td><td>8°</td><td>0°</td><td>---</td><td>8°</td></tr></table>

# 10.8 8-Pin PDIP 300-mil (Package Code DA)

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/01b540ee63efa69f76ba3206bbbd351c55b79d23e998f07a863e1a45f121aaae.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/5d91c8b7c4785d4bc5a4a3e64c600e1863ca4686152dc364e73449b71579995f.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/4da262f6ba6548f7dc9cc57d23e77c5f8e4342c29ee6dd8b7f8c367da63fa4c4.jpg)



0.060typ.


<table><tr><td rowspan="2">Symbol</td><td colspan="3">Millimeters</td><td colspan="3">Inches</td></tr><tr><td>Min</td><td>Nom</td><td>Max</td><td>Min</td><td>Nom</td><td>Max</td></tr><tr><td>A</td><td>---</td><td>---</td><td>5.33</td><td>---</td><td>---</td><td>0.210</td></tr><tr><td>A1</td><td>0.38</td><td>---</td><td>---</td><td>0.015</td><td>---</td><td>---</td></tr><tr><td>A2</td><td>3.18</td><td>3.30</td><td>3.43</td><td>0.125</td><td>0.130</td><td>0.135</td></tr><tr><td>D</td><td>9.02</td><td>9.27</td><td>10.16</td><td>0.355</td><td>0.365</td><td>0.400</td></tr><tr><td>E</td><td colspan="3">7.62 BSC</td><td colspan="3">0.300 BSC</td></tr><tr><td>E1</td><td>6.22</td><td>6.35</td><td>6.48</td><td>0.245</td><td>0.250</td><td>0.255</td></tr><tr><td>L</td><td>2.92</td><td>3.30</td><td>3.81</td><td>0.115</td><td>0.130</td><td>0.150</td></tr><tr><td>eB</td><td>8.51</td><td>9.02</td><td>9.53</td><td>0.335</td><td>0.355</td><td>0.375</td></tr><tr><td>θ°</td><td>0°</td><td>7°</td><td>15°</td><td>0°</td><td>7°</td><td>15°</td></tr><tr><td>d</td><td>---</td><td>2.54</td><td>---</td><td>---</td><td>0.100</td><td>---</td></tr><tr><td>w</td><td>---</td><td>1.52</td><td>---</td><td>---</td><td>0.060</td><td>---</td></tr><tr><td>p</td><td>---</td><td>0.46</td><td>---</td><td>---</td><td>0.018</td><td>---</td></tr></table>

# 10.10 24-Ball TFBGA 8x6-mm (Package Code TB, 5x5 Ball Array)

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/536b9d7e15b156a4b0c8661828f4bc7dc021f277e435d8d1a1a214666cc50ff4.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/9a815deb0c0e4fb72f97bc5e04a126e02db1377f3b86d8c1c1b7cdd1ac10d944.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/f39f8efa7f5f5da3f4e2969e2b39e098fb4ebd11ef6652492c884797372dec48.jpg)



BALL OPENING



Note:



Ball land: $0 . 4 5 \mathsf { m m }$ . Ball Opening: 0.35mm



PCB ball land suggested $< = 0 . 3 5 \mathsf { m m }$


<table><tr><td rowspan="2">Symbol</td><td colspan="3">Millimeters</td><td colspan="3">Inches</td></tr><tr><td>Min</td><td>Nom</td><td>Max</td><td>Min</td><td>Nom</td><td>Max</td></tr><tr><td>A</td><td>---</td><td>---</td><td>1.20</td><td>---</td><td>---</td><td>0.047</td></tr><tr><td>A1</td><td>0.26</td><td>0.31</td><td>0.36</td><td>0.010</td><td>0.012</td><td>0.014</td></tr><tr><td>A2</td><td>---</td><td>0.85</td><td>---</td><td>---</td><td>0.033</td><td>---</td></tr><tr><td>b</td><td>0.35</td><td>0.40</td><td>0.45</td><td>0.014</td><td>0.016</td><td>0.018</td></tr><tr><td>D</td><td>7.90</td><td>8.00</td><td>8.10</td><td>0.311</td><td>0.315</td><td>0.319</td></tr><tr><td>D1</td><td colspan="3">4.00 BSC</td><td colspan="3">0.157 BSC</td></tr><tr><td>E</td><td>5.90</td><td>6.00</td><td>6.10</td><td>0.232</td><td>0.236</td><td>0.240</td></tr><tr><td>E1</td><td colspan="3">4.00 BSC</td><td colspan="3">0.157 BSC</td></tr><tr><td>SE</td><td colspan="3">1.00 TYP</td><td colspan="3">0.039 TYP</td></tr><tr><td>SD</td><td colspan="3">1.00 TYP</td><td colspan="3">0.039 TYP</td></tr><tr><td>e</td><td colspan="3">1.00 BSC</td><td colspan="3">0.039 BSC</td></tr><tr><td>ccc</td><td>---</td><td>---</td><td>0.10</td><td>---</td><td>---</td><td>0.0039</td></tr></table>

# 10.11 24-Ball TFBGA 8x6-mm (Package Code TC, 6x4 ball array)

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/f8f69cc3d2f717518ee8baa0191ac9b7eea781d0aa186c4227ab6b3214236b8a.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/b97de9de103b9284dd7562652e2c2fa4a1f3f8a1a1f9f41bdb295d8f4c049e53.jpg)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/360c895a16dd0384a60756691759ac67e1893a7c5d983c89949982365beaac04.jpg)


Note: 

Ball land: $0 . 4 5 \mathsf { m m }$ . Ball Opening: 0.35mm 

PCB ball land suggested $< = 0 . 3 5 \mathsf { m m }$ 

<table><tr><td rowspan="2">Symbol</td><td colspan="3">Millimeters</td><td colspan="3">Inches</td></tr><tr><td>Min</td><td>Nom</td><td>Max</td><td>Min</td><td>Nom</td><td>Max</td></tr><tr><td>A</td><td>---</td><td>---</td><td>1.20</td><td>---</td><td>---</td><td>0.047</td></tr><tr><td>A1</td><td>0.25</td><td>0.30</td><td>0.35</td><td>0.010</td><td>0.012</td><td>0.014</td></tr><tr><td>b</td><td>0.35</td><td>0.40</td><td>0.45</td><td>0.014</td><td>0.016</td><td>0.018</td></tr><tr><td>D</td><td>7.95</td><td>8.00</td><td>8.05</td><td>0.313</td><td>0.315</td><td>0.317</td></tr><tr><td>D1</td><td colspan="3">5.00 BSC</td><td colspan="3">0.197 BSC</td></tr><tr><td>E</td><td>5.95</td><td>6.00</td><td>6.05</td><td>0.234</td><td>0.236</td><td>0.238</td></tr><tr><td>E1</td><td colspan="3">3.00 BSC</td><td colspan="3">0.118 BSC</td></tr><tr><td>e</td><td colspan="3">1.00 BSC</td><td colspan="3">0.039 BSC</td></tr></table>

# 11. ORDERING INFORMATION

![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-08/61f21a44-12ae-44c6-a480-fcd32fb07667/01e6ff498a10cb461dc7cd863481efd92c151ebdc075df3ef806e4bc035afc67.jpg)


# Notes:

1. The “W” prefix is not included on the part marking. 

2. Only the $2 ^ { \mathsf { n d } }$ letter is used for the part marking; WSON package type ZP is not used for the part marking. 

3. Standard bulk shipments are in Tube (shape E). Please specify alternate packing method, such as Tape and Reel (shape T) or Tray (shape S), when placing orders. 

4. /HOLD function is disabled to support Standard, Dual and Quad I/O without user setting. 

5. For DTR, QPI supporting, please refer to W25Q32JV DTR datasheet. 

# 11.1 Valid Part Numbers and Top Side Marking

The following table provides the valid part numbers for the W25Q32JV SpiFlash Memory. Please contact Winbond for specific availability by density and package type. Winbond SpiFlash memories use a 12-digit Product Number for ordering. However, due to limited space, the Top Side Marking on all packages uses an abbreviated 10-digit number. 


W25Q32JV-IQ/JQ valid part numbers:


<table><tr><td>PACKAGE TYPE</td><td>DENSITY</td><td>PRODUCT NUMBER</td><td>TOP SIDE MARKING</td></tr><tr><td rowspan="2">SN
SOIC-8 150mil</td><td rowspan="2">32M-bit</td><td>W25Q32JVSNIQ</td><td>25Q32JVNIQ</td></tr><tr><td>W25Q32JVSNJQ</td><td>25Q32JVNJQ</td></tr><tr><td rowspan="2">SS
SOIC-8 208-mil</td><td rowspan="2">32M-bit</td><td>W25Q32JVSSIQ</td><td>25Q32JVSIQ</td></tr><tr><td>W25Q32JVSSJQ</td><td>25Q32JVSJJQ</td></tr><tr><td rowspan="2">ST(1)
VSOP-8 208-mil</td><td rowspan="2">32M-bit</td><td>W25Q32JVSTIQ</td><td>25Q32JVTIQ</td></tr><tr><td>W25Q32JVSTJJQ</td><td>25Q32JVTJJQ</td></tr><tr><td rowspan="2">SF
SOIC-16 300-mil</td><td rowspan="2">32M-bit</td><td>W25Q32JVSEFIQ</td><td>25Q32JVFIQ</td></tr><tr><td>W25Q32JVSSFJJQ</td><td>25Q32JVFFJJQ</td></tr><tr><td rowspan="2">DA
PDIP-8 300-mil</td><td rowspan="2">32M-bit</td><td>W25Q32JVDAIQ</td><td>25Q32JVAIQ</td></tr><tr><td>W25Q32JVDAJJQ</td><td>25Q32JVAJJQ</td></tr><tr><td rowspan="2">ZP(2)
WSON-8 6x5-mm</td><td rowspan="2">32M-bit</td><td>W25Q32JVZPIQ</td><td>25Q32JVIQ</td></tr><tr><td>W25Q32JVZPJQ</td><td>25Q32JVJJQ</td></tr><tr><td rowspan="2">ZE(2)
WSON-8 8x6mm</td><td rowspan="2">32M-bit</td><td>W25Q32JVZEIQ</td><td>25Q32JVIQ</td></tr><tr><td>W25Q32JVZEJJQ</td><td>25Q32JVJJQ</td></tr><tr><td rowspan="2">XG
XSON-8
4x4x0.45-mm</td><td rowspan="2">32M-bit</td><td>W25Q32JVXGIQ</td><td>Q32JVXGIQ</td></tr><tr><td>W25Q32JVXGJJQ</td><td>Q32JVXGJJQ</td></tr><tr><td rowspan="2">TB(1)
TFBGA-24 8x6-mm
(5x5 Ball Array)</td><td rowspan="2">32M-bit</td><td>W25Q32JVTBIQ</td><td>25Q32JVBIQ</td></tr><tr><td>W25Q32JVTBJQ</td><td>25Q32JVBJQ</td></tr><tr><td rowspan="2">TC(1)
TFBGA-24 8x6-mm
(6x4 Ball Array)</td><td rowspan="2">32M-bit</td><td>W25Q32JVTCIQ</td><td>25Q32JVCIQ</td></tr><tr><td>W25Q32JVTCJJQ</td><td>25Q32JVCJJQ</td></tr></table>

# Note:

1. These package types are special order, please contact Winbond for more information. 

2. For WSON packages, the package type ZP and ZE is not used in the top side marking. 


W25Q32JV-IM/JM(2) valid part numbers:


<table><tr><td>PACKAGE TYPE</td><td>DENSITY</td><td>PRODUCT NUMBER</td><td>TOP SIDE MARKING</td></tr><tr><td>SN
SOIC-8 150mil</td><td>32M-bit</td><td>W25Q32JVSNIM
W25Q32JVSNJM</td><td>25Q32JVNIM
25Q32JVNJM</td></tr><tr><td>SS
SOIC-8 208-mil</td><td>32M-bit</td><td>W25Q32JVSSIM
W25Q32JVSSJM</td><td>25Q32JVSIM
25Q32JVSJM</td></tr><tr><td>ZP(2)
WSON-8 6x5-mm</td><td>32M-bit</td><td>W25Q32JVZPIM
W25Q32JVZPJM</td><td>25Q32JVIM
25Q32JVJM</td></tr><tr><td>SF
SOIC-16 300-mil</td><td>32M-bit</td><td>W25Q32JVSFIM
W25Q32JVSFJM</td><td>25Q32JVFIM
25Q32JVFJM</td></tr><tr><td>XG
XSON-8
4x4x0.45-mm</td><td>32M-bit</td><td>W25Q32JVXGIM
W25Q32JVXGJM</td><td>Q32JVXGIM
Q32JVXGJM</td></tr><tr><td>TB(1)
TFBGA-24 8x6-mm
(5x5 Ball Array)</td><td>32M-bit</td><td>W25Q32JVTBIM
W25Q32JVTBJM</td><td>25Q32JVBIM
25Q32JVBJM</td></tr><tr><td>TC(1)
TFBGA-24 8x6-mm
(6x4 Ball Array)</td><td>32M-bit</td><td>W25Q32JVTCIM
W25Q32JVTCJM</td><td>25Q32JVCIM
25Q32JVCJM</td></tr></table>


Note: 



1. These package types are special order, please contact Winbond for more information. 



2. For DTR, QPI supporting, please refer to W25Q32JV DTR datasheet. 


# 12. REVISION HISTORY

<table><tr><td>VERSION</td><td>DATE</td><td>PAGE</td><td>DESCRIPTION</td></tr><tr><td>A</td><td>2014/06/30</td><td></td><td>New Create Datasheet</td></tr><tr><td>B</td><td>2016/03/21</td><td></td><td>Removed “preliminary”</td></tr><tr><td>C</td><td>2016/08/30</td><td>471,73,74</td><td>Added data retention descriptionAdded TFBGA 5X5</td></tr><tr><td>D</td><td>2016/11/03</td><td></td><td>Removed VSOP 208mil information</td></tr><tr><td>E</td><td>2017/01/19</td><td>134-5,66,73-744-5,68,73-74</td><td>Updated Status Register-1 tableUpdated VSOP 208mil informationUpdated WSON 8X6 package information</td></tr><tr><td>F</td><td>2017/05/11</td><td>1321,76-775,91.98-99</td><td>Updated /WP informationUpdated SR-1 tableUpdated W25Q32JV-IM order informationUpdated SOIC8 150mil information</td></tr><tr><td>G</td><td>2018/3/27</td><td>1361,63-644,76-78</td><td>Updated SR1 FigureUpdated ICC3,tPP,tSLCH,tCHSL,tDVCH,tCHDX Added industrial plus information</td></tr><tr><td></td><td></td><td></td><td></td></tr></table>

# Trademarks

Winbond and SpiFlash are trademarks of Winbond Electronics Corporation. All other marks are the property of their respective owner. 

# Important Notice

Winbond products are not designed, intended, authorized or warranted for use as components in systems or equipment intended for surgical implantation, atomic energy control instruments, airplane or spaceship instruments, transportation instruments, traffic signal instruments, combustion control instruments, or for other applications intended to support or sustain life. Furthermore, Winbond products are not intended for applications wherein failure of Winbond products could result or lead to a situation wherein personal injury, death or severe property or environmental damage could occur. Winbond customers using or selling these products for use in such applications do so at their own risk and agree to fully indemnify Winbond for any damages resulting from such improper use or sales. 

Information in this document is provided solely in connection with Winbond products. Winbond reserves the right to make changes, corrections, modifications or improvements to this document and the products and services described herein at any time, without notice. 