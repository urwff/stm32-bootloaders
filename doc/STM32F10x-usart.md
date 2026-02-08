# 27 Universal synchronous asynchronous receiver transmitter (USART)

Low-density devices are STM32F101xx, STM32F102xx and STM32F103xx microcontrollers where the Flash memory density ranges between 16 and 32 Kbytes. 

Medium-density devices are STM32F101xx, STM32F102xx and STM32F103xx microcontrollers where the Flash memory density ranges between 64 and 128 Kbytes. 

High-density devices are STM32F101xx and STM32F103xx microcontrollers where the Flash memory density ranges between 256 and 512 Kbytes. 

XL-density devices are STM32F101xx and STM32F103xx microcontrollers where the Flash memory density ranges between 768 Kbytes and 1 Mbyte. 

Connectivity line devices are STM32F105xx and STM32F107xx microcontrollers. 

This section applies to the whole STM32F10xxx family, unless otherwise specified. 

# 27.1 USART introduction

The universal synchronous asynchronous receiver transmitter (USART) offers a flexible means of full-duplex data exchange with external equipment requiring an industry standard NRZ asynchronous serial data format. The USART offers a very wide range of baud rates using a fractional baud rate generator. 

It supports synchronous one-way communication and half-duplex single wire communication. It also supports the LIN (local interconnection network), Smartcard Protocol and IrDA (infrared data association) SIR ENDEC specifications, and modem operations (CTS/RTS). It allows multiprocessor communication. 

High speed data communication is possible by using the DMA for multibuffer configuration. 

# 27.2 USART main features

Full duplex, asynchronous communications 

 NRZ standard format (Mark/Space) 

 Fractional baud rate generator systems 

– A common programmable transmit and receive baud rates up to 4.5 MBits/s 

Programmable data word length (8 or 9 bits) 

Configurable stop bits - support for 1 or 2 stop bits 

LIN Master Synchronous Break send capability and LIN slave break detection capability 

13-bit break generation and 10/11 bit break detection when USART is hardware configured for LIN 

 Transmitter clock output for synchronous transmission 

 IrDA SIR Encoder Decoder 

Support for 3/16 bit duration for normal mode 

 Smartcard Emulation Capability 

The Smartcard interface supports the asynchronous protocol Smartcards as defined in ISO 7816-3 standards 

– 0.5, 1.5 Stop Bits for Smartcard operation 

Single wire half duplex communication 

 Configurable multibuffer communication using DMA (direct memory access) 

– Buffering of received/transmitted bytes in reserved SRAM using centralized DMA 

 Separate enable bits for Transmitter and Receiver 

Transfer detection flags: 

一 Receive buffer full

Transmit buffer empty 

End of Transmission flags 

Parity control: 

Transmits parity bit 

– Checks parity of received data byte 

 Four error detection flags: 

Overrun error 

Noise error 

Frame error 

– Parity error 

 Ten interrupt sources with flags: 

– CTS changes 

LIN break detection 

Transmit data register empty 

Transmission complete 

Receive data register full 

– Idle line received 

Overrun error 

Framing error 

Noise error 

– Parity error 

Multiprocessor communication - enter into mute mode if address match does not occur 

Wake up from mute mode (by idle line detection or address mark detection) 

 Two receiver wakeup modes: Address bit (MSB, ${ \mathfrak { g } } ^ { { \mathfrak { t h } } }$ bit), Idle line 

# 27.3 USART functional description

The interface is externally connected to another device by three pins (see Figure 279). Any USART bidirectional communication requires a minimum of two pins: Receive Data In (RX) and Transmit Data Out (TX): 

RX: Receive Data Input is the serial data input. Oversampling techniques are used for data recovery by discriminating between valid incoming data and noise. 

TX: Transmit Data Output. When the transmitter is disabled, the output pin returns to its IO port configuration. When the transmitter is enabled and nothing is to be transmitted, the TX pin is at high level. In single-wire and smartcard modes, this IO is used to transmit and receive the data (at USART level, data are then received on SW_RX). 

Through these pins, serial data is transmitted and received in normal USART mode as frames comprising: 

 An Idle Line prior to transmission or reception 

A start bit 

A data word (8 or 9 bits) least significant bit first 

0.5,1, 1.5, 2 Stop bits indicating that the frame is complete 

This interface uses a fractional baud rate generator - with a 12-bit mantissa and 4-bit fraction 

A status register (USART_SR) 

Data register (USART_DR) 

 A baud rate register (USART_BRR) - 12-bit mantissa and 4-bit fraction. 

A guard-time register (USART_GTPR) in case of Smartcard mode. 

Refer to Section 27.6: USART registers for the definition of each bit. 

The following pin is required to interface in synchronous mode: 

CK: Transmitter clock output. This pin outputs the transmitter data clock for synchronous transmission corresponding to SPI master mode (no clock pulses on start bit and stop bit, and a software option to send a clock pulse on the last data bit). In parallel data can be received synchronously on RX. This can be used to control peripherals that have shift registers (e.g. LCD drivers). The clock phase and polarity are software programmable. In Smartcard mode, CK can provide the clock to the smartcard. 

The following pins are required in Hardware flow control mode: 

CTS: Clear To Send blocks the data transmission at the end of the current transfer when high 

 RTS: Request to send indicates that the USART is ready to receive a data (when low). 


Figure 279. USART block diagram


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/fb9a8c32af59e10c5fd677178d32cbaed6070ac03e249a91f9510639af1f8d5d.jpg)


# 27.3.1 USART character description

Word length may be selected as being either 8 or 9 bits by programming the M bit in the USART_CR1 register (see Figure 280). 

The TX pin is in low state during the start bit. It is in high state during the stop bit. 

An Idle character is interpreted as an entire frame of “1”s followed by the start bit of the next frame which contains data (The number of “1” ‘s will include the number of stop bits). 

A Break character is interpreted on receiving “0”s for a frame period. At the end of the break frame the transmitter inserts either 1 or 2 stop bits (logic “1” bit) to acknowledge the start bit. 

Transmission and reception are driven by a common baud rate generator, the clock for each is generated when the enable bit is set respectively for the transmitter and receiver. 

The details of each block is given below. 


Figure 280. Word length programming


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/067e4281962cee3c62010b9fc8de1b9134180a9bdb7f6f238e45080ba764a3aa.jpg)



** LBCL bit controls last data clock pulse



8-bit word length (M bit is reset), 1 stop bit


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/c14daa7691a1c47ba8a86a8a6729cea4257f71431aa212cbc8fd973e21664203.jpg)



** LBCL bit controls last data clock pulse


# 27.3.2 Transmitter

The transmitter can send data words of either 8 or 9 bits depending on the M bit status. When the transmit enable bit (TE) is set, the data in the transmit shift register is output on the TX pin and the corresponding clock pulses are output on the CK pin. 

# Character transmission

During a USART transmission, data shifts out least significant bit first on the TX pin. In this mode, the USART_DR register consists of a buffer (TDR) between the internal bus and the transmit shift register (see Figure 279). 

Every character is preceded by a start bit, which is a logic level low for one bit period. The character is terminated by a configurable number of stop bits. 

The following stop bits are supported by USART: 0.5, 1, 1.5 and 2 stop bits. 

Note: The TE bit should not be reset during transmission of data. Resetting the TE bit during the transmission will corrupt the data on the TX pin as the baud rate counters will get frozen. The current data being transmitted will be lost. 

An idle frame will be sent after the TE bit is enabled. 

# Configurable stop bits

The number of stop bits to be transmitted with every character can be programmed in Control register 2, bits 13,12. 

1. 1 stop bit: This is the default value. 

2. 2 stop bits: This is supported by normal USART, single-wire and modem modes. 

3. 0.5 stop bit: To be used when receiving data in Smartcard mode. 

4. 1.5 stop bits: To be used when transmitting and receiving data in Smartcard mode. 

An idle frame transmission will include the stop bits. 

A break transmission will be 10 low bits followed by the configured number of stop bits (when $\mathsf m = 0$ ) and 11 low bits followed by the configured number of stop bits (when $\mathsf m = 1$ ). It is not possible to transmit long breaks (break of length greater than 10/11 low bits). 


Figure 281. Configurable stop bits


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/30180eb8c1b947e7a1c003f511106ae240712bf835684e8a48fdc72a0bd64df3.jpg)


# Procedure:

1. Enable the USART by writing the UE bit in USART_CR1 register to 1. 

2. Program the M bit in USART_CR1 to define the word length. 

3. Program the number of stop bits in USART_CR2. 

4. Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take place. Configure the DMA register as explained in multibuffer communication. 

5. Select the desired baud rate using the USART_BRR register. 

6. Set the TE bit in USART_CR1 to send an idle frame as first transmission. 

7. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this for each data to be transmitted in case of single buffer. 

8. After writing the last data into the USART_DR register, wait until $\mathsf { T C } = 1$ . This indicates that the transmission of the last frame is complete. This is required for instance when the USART is disabled or enters the Halt mode to avoid corrupting the last transmission. 

# Single byte communication

The TXE bit is always cleared by a write to the data register. 

The TXE bit is set by hardware and it indicates: 

The data has been moved from TDR to the shift register and the data transmission has started. 

The TDR register is empty. 

The next data can be written in the USART_DR register without overwriting the previous data. 

This flag generates an interrupt if the TXEIE bit is set. 

When a transmission is taking place, a write instruction to the USART_DR register stores the data in the TDR register and which is copied in the shift register at the end of the current transmission. 

When no transmission is taking place, a write instruction to the USART_DR register places the data directly in the shift register, the data transmission starts, and the TXE bit is immediately set. 

If a frame is transmitted (after the stop bit) and the TXE bit is set, the TC bit goes high. An interrupt is generated if the TCIE bit is set in the USART_CR1 register. 

After writing the last data into the USART_DR register, it is mandatory to wait for $\mathsf { T C } = 1$ before disabling the USART or causing the microcontroller to enter the low-power mode (see Figure 282). 

The TC bit is cleared by the following software sequence: 

1. A read from the USART_SR register 

2. A write to the USART_DR register 

Note: The TC bit can also be cleared by writing a ‘0’ to it. This clearing sequence is recommended only for Multibuffer communication. 


Figure 282. TC/TXE behavior when transmitting


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/932db0366edcad9abb15fa4eb550779ce5e677052f6477e4eb6a7e4cfec51e09.jpg)


# Break characters

Setting the SBK bit transmits a break character. The break frame length depends on the M bit (see Figure 280). 

If the SBK bit is set to ‘1’ a break character is sent on the TX line after completing the current character transmission. This bit is reset by hardware when the break character is completed (during the stop bit of the break character). The USART inserts a logic 1 bit at the end of the last break frame to guarantee the recognition of the start bit of the next frame. 

Note: If the software resets the SBK bit before the commencement of break transmission, the break character will not be transmitted. For two consecutive breaks, the SBK bit should be set after the stop bit of the previous break. 

# Idle characters

Setting the TE bit drives the USART to send an idle frame before the first data frame. 

# 27.3.3 Receiver

The USART can receive data words of either 8 or 9 bits depending on the M bit in the USART_CR1 register. 

# Start bit detection

In the USART, the start bit is detected when a specific sequence of samples is recognized. This sequence is: $1 \ 1 \ 1 \ 0 \times 0 \times 0 \times 0 \ 0 \ 0 \ 0$ . 


Figure 283. Start bit detection


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/4a78bab548033fab58e959fe4395b7cc06d0629f6b2ec39dd93dea647c9159f9.jpg)


Note: If the sequence is not complete, the start bit detection aborts and the receiver returns to the idle state (no flag is set) where it waits for a falling edge. 

The start bit is confirmed (RXNE flag set, interrupt generated if RXNEIE=1) if the 3 sampled bits are at 0 (first sampling on the 3rd, 5th and 7th bits finds the 3 bits at 0 and second sampling on the 8th, 9th and 10th bits also finds the 3 bits at 0). 

The start bit is validated (RXNE flag set, interrupt generated if RXNEIE=1) but the NE noise flag is set if, for both samplings, at least 2 out of the 3 sampled bits are at 0 (sampling on the 3rd, 5th and 7th bits and sampling on the 8th, 9th and 10th bits). If this condition is not met, the start detection aborts and the receiver returns to the idle state (no flag is set). 

If, for one of the samplings (sampling on the 3rd, 5th and 7th bits or sampling on the 8th, 9th and 10th bits), 2 out of the 3 bits are found at 0, the start bit is validated but the NE noise flag bit is set. 

# Character reception

During a USART reception, data shifts in least significant bit first through the RX pin. In this mode, the USART_DR register consists of a buffer (RDR) between the internal bus and the received shift register. 

# Procedure:

1. Enable the USART by writing the UE bit in USART_CR1 register to 1. 

2. Program the M bit in USART_CR1 to define the word length. 

3. Program the number of stop bits in USART_CR2. 

4. Select DMA enable (DMAR) in USART_CR3 if multibuffer communication is to take place. Configure the DMA register as explained in multibuffer communication. STEP 3 

5. Select the desired baud rate using the baud rate register USART_BRR 

6. Set the RE bit USART_CR1. This enables the receiver which begins searching for a start bit. 

When a character is received 

The RXNE bit is set. It indicates that the content of the shift register is transferred to the RDR. In other words, data has been received and can be read (as well as its associated error flags). 

An interrupt is generated if the RXNEIE bit is set. 

The error flags can be set if a frame error, noise or an overrun error has been detected during reception. 

In multibuffer, RXNE is set after every byte received and is cleared by the DMA read to the Data register. 

In single buffer mode, clearing the RXNE bit is performed by a software read to the USART_DR register. The RXNE flag can also be cleared by writing a zero to it. The RXNE bit must be cleared before the end of the reception of the next character to avoid an overrun error. 

Note: The RE bit should not be reset while receiving data. If the RE bit is disabled during reception, the reception of the current byte will be aborted. 

# Break character

When a break character is received, the USART handles it as a framing error. 

# Idle character

When an idle frame is detected, there is the same procedure as a data received character plus an interrupt if the IDLEIE bit is set. 

# Overrun error

An overrun error occurs when a character is received when RXNE has not been reset. Data can not be transferred from the shift register to the RDR register until the RXNE bit is cleared. 

The RXNE flag is set after every byte received. An overrun error occurs if RXNE flag is set when the next data is received or the previous DMA request has not been serviced. When an overrun error occurs: 

The ORE bit is set. 

The RDR content will not be lost. The previous data is available when a read to USART_DR is performed. 

The shift register will be overwritten. After that point, any data received during overrun is lost. 

An interrupt is generated if either the RXNEIE bit is set or both the EIE and DMAR bits are set. 

The ORE bit is reset by a read to the USART_SR register followed by a USART_DR register read operation. 

Note: The ORE bit, when set, indicates that at least 1 data has been lost. There are two possibilities: 

if RXNE=1, then the last valid data is stored in the receive register RDR and can be read, 

if $\mathsf { R X N E } { = } 0$ , then it means that the last valid data has already been read and thus there is nothing to be read in the RDR. This case can occur when the last valid data is read in the RDR at the same time as the new (and lost) data is received. It may also occur when the new data is received during the reading sequence (between the USART_SR register read access and the USART_DR read access). 

# Noise error

Over-sampling techniques are used (except in synchronous mode) for data recovery by discriminating between valid incoming data and noise. 


Figure 284. Data sampling for noise detection


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/fb01d53e0bc8fea9777b08e26fdccd46d2d7dbf9098be835218dae924a7cd1de.jpg)



Table 191. Noise detection from sampled data


<table><tr><td>Sampled value</td><td>NE status</td><td>Received bit value</td><td>Data validity</td></tr><tr><td>000</td><td>0</td><td>0</td><td>Valid</td></tr><tr><td>001</td><td>1</td><td>0</td><td>Not Valid</td></tr><tr><td>010</td><td>1</td><td>0</td><td>Not Valid</td></tr><tr><td>011</td><td>1</td><td>1</td><td>Not Valid</td></tr><tr><td>100</td><td>1</td><td>0</td><td>Not Valid</td></tr><tr><td>101</td><td>1</td><td>1</td><td>Not Valid</td></tr><tr><td>110</td><td>1</td><td>1</td><td>Not Valid</td></tr><tr><td>111</td><td>0</td><td>1</td><td>Valid</td></tr></table>

When noise is detected in a frame: 

The NE is set at the rising edge of the RXNE bit. 

 The invalid data is transferred from the Shift register to the USART_DR register. 

No interrupt is generated in case of single byte communication. However this bit rises at the same time as the RXNE bit which itself generates an interrupt. In case of multibuffer communication an interrupt will be issued if the EIE bit is set in the USART_CR3 register. 

The NE bit is reset by a USART_SR register read operation followed by a USART_DR register read operation. 

# Framing error

A framing error is detected when: 

The stop bit is not recognized on reception at the expected time, following either a desynchronization or excessive noise. 

When the framing error is detected: 

The FE bit is set by hardware 

 The invalid data is transferred from the Shift register to the USART_DR register. 

No interrupt is generated in case of single byte communication. However this bit rises at the same time as the RXNE bit which itself generates an interrupt. In case of multibuffer communication an interrupt will be issued if the EIE bit is set in the USART_CR3 register. 

The FE bit is reset by a USART_SR register read operation followed by a USART_DR register read operation. 

# Configurable stop bits during reception

The number of stop bits to be received can be configured through the control bits of Control register 2 - it can be either 1 or 2 in normal mode and 0.5 or 1.5 in Smartcard mode. 

1. 0.5 stop bit (reception in Smartcard mode): No sampling is done for 0.5 stop bit. As a consequence, no framing error and no break frame can be detected when 0.5 stop bit is selected. 

2. 1 stop bit: Sampling for 1 stop Bit is done on the 8th, 9th and 10th samples. 

3. 1.5 stop bits (Smartcard mode): When transmitting in Smartcard mode, the device must check that the data is correctly sent. Thus the receiver block must be enabled (RE $= 1$ in the USART_CR1 register) and the stop bit is checked to test if the smartcard has detected a parity error. In the event of a parity error, the smartcard forces the data signal low during the sampling - NACK signal-, which is flagged as a framing error. Then, the FE flag is set with the RXNE at the end of the 1.5 stop bit. Sampling for 1.5 stop bits is done on the 16th, 17th and 18th samples (1 baud clock period after the beginning of the stop bit). The 1.5 stop bit can be decomposed into 2 parts: one 0.5 baud clock period during which nothing happens, followed by 1 normal stop bit period during which sampling occurs halfway through. Refer to Section 27.3.11 for more details. 

4. 2 stop bits: Sampling for 2 stop bits is done on the 8th, 9th and 10th samples of the first stop bit. If a framing error is detected during the first stop bit the framing error flag will be set. The second stop bit is not checked for framing error. The RXNE flag will be set at the end of the first stop bit. 

# 27.3.4 Fractional baud rate generation

The baud rate for the receiver and transmitter (Rx and Tx) are both set to the same value as programmed in the Mantissa and Fraction values of USARTDIV. 

$$
\mathrm {T x} / \mathrm {R x} \text {b a u d} = \frac {\mathrm {f} _ {\mathrm {C K}}}{(1 6 ^ {*} \mathrm {U S A R T D I V})}
$$

legend: fCK - Input clock to the peripheral (PCLK1 for USART2, 3, 4, 5 or PCLK2 for USART1) 

USARTDIV is an unsigned fixed point number that is coded on the USART_BRR register. 

Note: 

The baud counters are updated with the new value of the Baud registers after a write to USART_BRR. Hence the Baud rate register value should not be changed during communication. 

# How to derive USARTDIV from USART_BRR register values

Example 1: 

If DIV_Mantissa $= 0 0 2 7$ and DIV_Fraction = 0d12 (USART_BRR = 0x1BC), then 

Mantissa (USARTDIV) = 0d27 

Fraction (USARTDIV) $= 1 2 / 1 6 = 0 0 0 . 7 5$ 

Therefore USARTDIV $=$ 0d27.75 

# Example 2:

To program USARTDIV = 0d25.62 

This leads to: 

DIV_Fraction $= 1 6 ^ { \star } 0 0 0 . 6 2 = 0 0 9 . 9 2$ 

The nearest real number is ${ 0 } { \mathsf { d } } 1 0 = 0 { \mathsf { x } } { \mathsf { A } }$ 

DIV_Mantissa $=$ mantissa $( 0 { \mathsf { d } } 2 5 . 6 2 0 ) = 0 { \mathsf { d } } 2 5 = 0 { \mathsf { x } } 1 9$ 

Then, USART_BRR = 0x19A hence USARTDIV $=$ 0d25.625 

# Example 3:

To program USARTDIV $=$ 0d50.99 

This leads to: 

DIV_Fraction $= 1 6 ^ { \star } 0 0 0 . 9 9 = 0 0 1 5 . 8 4$ 

The nearest real number is $0 { \mathsf { d } } 1 { \mathsf { 6 } } = 0 \times 1 0 = >$ overflow of DIV_frac[3:0] $= >$ carry must be added up to the mantissa 

DIV_Mantissa $=$ mantissa $( 0 \mathsf { d } 5 0 . 9 9 0 + \mathsf { c a r r y } ) = 0 \mathsf { d } 5 1 = 0 \times 3 3$ 

Then, USART_BRR $= 0 { \times } 3 3 0$ hence USARTDIV $=$ 0d51.000 


Table 192. Error calculation for programmed baud rates


<table><tr><td colspan="2">Baud rate</td><td colspan="3">\(f_{\text{PCLK}}=36 MHz\)</td><td colspan="3">\(f_{\text{PCLK}}=72 MHz\)</td></tr><tr><td>S.No</td><td>in Kbps</td><td>Actual</td><td>Value programmed in the Baud Rate register</td><td>% Error(1)</td><td>Actual</td><td>Value programmed in the Baud Rate register</td><td>% Error(1)</td></tr><tr><td>1.</td><td>2.4</td><td>2.400</td><td>937.5</td><td>0%</td><td>2.4</td><td>1875</td><td>0%</td></tr><tr><td>2.</td><td>9.6</td><td>9.600</td><td>234.375</td><td>0%</td><td>9.6</td><td>468.75</td><td>0%</td></tr><tr><td>3.</td><td>19.2</td><td>19.2</td><td>117.1875</td><td>0%</td><td>19.2</td><td>234.375</td><td>0%</td></tr><tr><td>4.</td><td>57.6</td><td>57.6</td><td>39.0625</td><td>0%</td><td>57.6</td><td>78.125</td><td>0%</td></tr><tr><td>5.</td><td>115.2</td><td>115.384</td><td>19.5</td><td>0.15%</td><td>115.2</td><td>39.0625</td><td>0%</td></tr><tr><td>6.</td><td>230.4</td><td>230.769</td><td>9.75</td><td>0.16%</td><td>230.769</td><td>19.5</td><td>0.16%</td></tr><tr><td>7.</td><td>460.8</td><td>461.538</td><td>4.875</td><td>0.16%</td><td>461.538</td><td>9.75</td><td>0.16%</td></tr><tr><td>8.</td><td>921.6</td><td>923.076</td><td>2.4375</td><td>0.16%</td><td>923.076</td><td>4.875</td><td>0.16%</td></tr><tr><td>9.</td><td>2250</td><td>2250</td><td>1</td><td>0%</td><td>2250</td><td>2</td><td>0%</td></tr><tr><td>10.</td><td>4500</td><td>NA</td><td>NA</td><td>NA</td><td>4500</td><td>1</td><td>0%</td></tr></table>


1. Defined as (Calculated Baud Rate - Desired Baud Rate) / Desired Baud Rate. 


Note: The lower the CPU clock the lower will be the accuracy for a particular Baud rate. The upper limit of the achievable baud rate can be fixed with this data. 

Only USART1 is clocked with PCLK2 (72 MHz max). Other USARTs are clocked with PCLK1 (36 MHz max). 

# 27.3.5 USART receiver’s tolerance to clock deviation

The USART’s asynchronous receiver works correctly only if the total clock system deviation is smaller than the USART receiver tolerance. The causes that contribute to the total deviation are: 

DTRA: Deviation due to the transmitter error (which also includes the deviation of the transmitter local oscillator) 

DQUANT: Error due to the baud rate quantization of the receiver 

DREC: Deviation of the receiver’s local oscillator 

DTCL: Deviation due to the transmission line (generally due to the transceivers that can introduce an asymmetry between the low-to-high transition timing and the high-to-low transition timing) 

DTRA $^ +$ DQUANT $^ +$ DREC $^ +$ DTCL $<$ USART receiver tolerance 

The USART receiver tolerance to properly receive data is equal to the maximum tolerated deviation and depends on the following choices: 

 10- or 11-bit character length defined by the M bit in the USART_CR1 register 

use of fractional baud rate or not 


Table 193. USART receiver tolerance when DIV_Fraction is 0


<table><tr><td>M bit</td><td>NF is an error</td><td>NF is don’t care</td></tr><tr><td>0</td><td>3.75%</td><td>4.375%</td></tr><tr><td>1</td><td>3.41%</td><td>3.97%</td></tr></table>


Table 194. USART receiver tolerance when DIV_Fraction is different from 0


<table><tr><td>M bit</td><td>NF is an error</td><td>NF is don’t care</td></tr><tr><td>0</td><td>3.33%</td><td>3.88%</td></tr><tr><td>1</td><td>3.03%</td><td>3.53%</td></tr></table>

Note: The figures specified in Table 193 and Table 194 may slightly differ in the special case when the received frames contain some Idle frames of exactly 10-bit times when $\scriptstyle { M = O }$ (11-bit times when $\scriptstyle { M = 1 }$ ). 

# 27.3.6 Multiprocessor communication

There is a possibility of performing multiprocessor communication with the USART (several USARTs connected in a network). For instance, one of the USARTs can be the master, its TX output is connected to the RX input of the other USART. The others are slaves, their respective TX outputs are logically ANDed together and connected to the RX input of the master. 

In multiprocessor configurations it is often desirable that only the intended message recipient should actively receive the full message contents, thus reducing redundant USART service overhead for all non addressed receivers. 

The non addressed devices may be placed in mute mode by means of the muting function. In mute mode: 

 None of the reception status bits can be set. 

All the receive interrupts are inhibited. 

The RWU bit in USART_CR1 register is set to 1. RWU can be controlled automatically by hardware or written by the software under certain conditions. 

The USART can enter or exit from mute mode using one of two methods, depending on the WAKE bit in the USART_CR1 register: 

Idle Line detection if the WAKE bit is reset, 

Address Mark detection if the WAKE bit is set. 

# Idle line detection $( \mathsf { W A K E { = } } \mathsf { 0 } )$ )

The USART enters mute mode when the RWU bit is written to 1. 

It wakes up when an Idle frame is detected. Then the RWU bit is cleared by hardware but the IDLE bit is not set in the USART_SR register. RWU can also be written to 0 by software. 

An example of mute mode behavior using idle line detection is given in Figure 285. 


Figure 285. Mute mode using Idle line detection


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/ee029234225f2ad2ad1dace11836b0c01ae0ecaae4635ddb21016d4a945a494a.jpg)


# Address mark detection (WAKE=1)

In this mode, bytes are recognized as addresses if their MSB is a ‘1’ else they are considered as data. In an address byte, the address of the targeted receiver is put on the 4 LSB. This 4-bit word is compared by the receiver with its own address which is programmed in the ADD bits in the USART_CR2 register. 

The USART enters mute mode when an address character is received which does not match its programmed address. In this case, the RWU bit is set by hardware. The RXNE flag is not set for this address byte and no interrupt nor DMA request is issued as the USART would have entered mute mode. 

It exits from mute mode when an address character is received which matches the programmed address. Then the RWU bit is cleared and subsequent bytes are received normally. The RXNE bit is set for the address character since the RWU bit has been cleared. 

The RWU bit can be written to as 0 or 1 when the receiver buffer contains no data (RXNE $\mathtt { = 0 }$ in the USART_SR register). Otherwise the write attempt is ignored. 

An example of mute mode behavior using address mark detection is given in Figure 286. 


Figure 286. Mute mode using address mark detection


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/0d65dca3e43825c1ac9ee1086aed253790957e1f52c47fcbf692b1f413912a8c.jpg)


# 27.3.7 Parity control

Parity control (generation of parity bit in transmission and parity checking in reception) can be enabled by setting the PCE bit in the USART_CR1 register. Depending on the frame length defined by the M bit, the possible USART frame formats are as listed in Table 195. 


Table 195. Frame formats(1)


<table><tr><td>M bit</td><td>PCE bit</td><td>USART frame</td></tr><tr><td>0</td><td>0</td><td>| SB | 8 bit data | STB |</td></tr><tr><td>0</td><td>1</td><td>| SB | 7-bit data | PB | STB |</td></tr><tr><td>1</td><td>0</td><td>| SB | 9-bit data | STB |</td></tr><tr><td>1</td><td>1</td><td>| SB | 8-bit data PB | STB |</td></tr></table>


1. Legends: SB: Start Bit, STB: Stop Bit, PB: Parity Bit 


Note: In case of wake up by an address mark, the MSB bit of the data is taken into account and not the parity bit 

Even parity: the parity bit is calculated to obtain an even number of “1s” inside the frame made of the 7 or 8 LSB bits (depending on whether M is equal to 0 or 1) and the parity bit. 

Ex: data=00110101; 4 bits set $= >$ parity bit will be 0 if even parity is selected (PS bit in USART_ $\mathsf { C R 1 } = 0$ ). 

Odd parity: the parity bit is calculated to obtain an odd number of “1s” inside the frame made of the 7 or 8 LSB bits (depending on whether M is equal to 0 or 1) and the parity bit. 

Ex: data=00110101; 4 bits set $= >$ parity bit will be 1 if odd parity is selected (PS bit in USART_ $\mathsf { C R 1 } = 1$ ). 

Transmission mode: If the PCE bit is set in USART_CR1, then the MSB bit of the data written in the data register is transmitted but is changed by the parity bit (even number of “1s” if even parity is selected $( P S = 0 )$ or an odd number of “1s” if odd parity is selected $( P S = 1 )$ ). If the parity check fails, the PE flag is set in the USART_SR register and an interrupt is generated if PEIE is set in the USART_CR1 register. 

# 27.3.8 LIN (local interconnection network) mode

The LIN mode is selected by setting the LINEN bit in the USART_CR2 register. In LIN mode, the following bits must be kept cleared: 

STOP[1:0], CLKEN in the USART_CR2 register 

SCEN, HDSEL and IREN in the USART_CR3 register. 

# LIN transmission

The same procedure explained in Section 27.3.2 has to be applied for LIN Master transmission than for normal USART transmission with the following differences: 

Clear the M bit to configure 8-bit word length. 

Set the LINEN bit to enter LIN mode. In this case, setting the SBK bit sends $1 3 ~ { } ^ { \cdot } 0 ^ { \cdot }$ bits as a break character. Then a bit of value ‘1’ is sent to allow the next start detection. 

# LIN reception

A break detection circuit is implemented in the USART. The detection is totally independent from the normal USART receiver. A break can be detected whenever it occurs, during idle state or during a frame. 

When the receiver is enabled $\mathrm { \Delta } ^ { \prime } \mathrm { R E } { = } 1$ in USART_CR1), the circuit looks at the RX input for a start signal. The method for detecting start bits is the same when searching break characters or data. After a start bit has been detected, the circuit samples the next bits exactly like for the data (on the 8th, 9th and 10th samples). If 10 (when the LBDL $= 0$ in USART_CR2) or 11 (when LBDL $\ O = 1$ in USART_CR2) consecutive bits are detected as $\prime 0 ^ { \prime }$ , and are followed by a delimiter character, the LBD flag is set in USART_SR. If the LBDIE bit=1, an interrupt is generated. Before validating the break, the delimiter is checked for as it signifies that the RX line has returned to a high level. 

If a ‘1’ is sampled before the 10 or 11 have occurred, the break detection circuit cancels the current detection and searches for a start bit again. 

If the LIN mode is disabled (LINEN=0), the receiver continues working as normal USART, without taking into account the break detection. 

If the LIN mode is enabled $( L \mathsf { I N E N } { = } 1$ ), as soon as a framing error occurs (i.e. stop bit detected at $\mathbf { \vec { \nabla } } ^ { \mathfrak { q } }$ , which will be the case for any break frame), the receiver stops until the break detection circuit receives either a ‘1’, if the break word was not complete, or a delimiter character if a break has been detected. 

The behavior of the break detector state machine and the break flag is shown on the Figure 287. Examples of break frames are given on Figure 288. 


Figure 287. Break detection in LIN mode (11-bit break length - LBDL bit is set)


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/0eefd334e15ce15128ff816844bc34cb91d2502892af74d171693d8538486f33.jpg)



Figure 288. Break detection in LIN mode vs. Framing error detection


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/aa5f70b65d757002043c8ad2761443eca92c0c14a65b5219b4c5dbd3949a3678.jpg)


# 27.3.9 USART synchronous mode

The synchronous mode is selected by writing the CLKEN bit in the USART_CR2 register to 1. In synchronous mode, the following bits must be kept cleared: 

LINEN bit in the USART_CR2 register, 

SCEN, HDSEL and IREN bits in the USART_CR3 register. 

The USART allows the user to control a bidirectional synchronous serial communications in master mode. The CK pin is the output of the USART transmitter clock. No clock pulses are sent to the CK pin during start bit and stop bit. Depending on the state of the LBCL bit in the USART_CR2 register clock pulses will or will not be generated during the last valid data bit (address mark). The CPOL bit in the USART_CR2 register allows the user to select the clock polarity, and the CPHA bit in the USART_CR2 register allows the user to select the phase of the external clock (see Figure 289, Figure 290 and Figure 291). 

During idle, preamble and send break, the external CK clock is not activated. 

In synchronous mode the USART transmitter works exactly like in asynchronous mode. But as CK is synchronized with TX (according to CPOL and CPHA), the data on TX is synchronous. 

In this mode the USART receiver works in a different manner compared to the asynchronous mode. If $\mathsf { R E } { = } 1$ , the data is sampled on CK (rising or falling edge, depending on CPOL and CPHA), without any oversampling. A setup and a hold time must be respected (which depends on the baud rate: 1/16 bit time). 

Note: The CK pin works in conjunction with the TX pin. Thus, the clock is provided only if the transmitter is enabled $( T E = 1 )$ ) and a data is being transmitted (the data register USART_DR 

has been written). This means that it is not possible to receive a synchronous data without transmitting data. 

The LBCL, CPOL and CPHA bits have to be selected when both the transmitter and the receiver are disabled ${ \mathit { T E } } { = } { \mathit { R E } } { = } { 0 } { ) }$ to ensure that the clock pulses function correctly. These bits should not be changed while the transmitter or the receiver is enabled. 

It is advised that TE and RE are set in the same instruction to minimize the setup and the hold time of the receiver. 

The USART supports master mode only: it cannot receive or send data related to an input clock (CK is always an output). 


Figure 289. USART example of synchronous transmission


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/0cd034060385c1e4ac20a4c35cbc6e828f2fa58ede9b0efb324c002b0fe503ad.jpg)



Figure 290. USART data clock timing diagram $( M = 0 )$


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/752fdafecbd88d6acba2f72b9de6fc77071ea28c69b63b09f697b3add2402648.jpg)



Figure 291. USART data clock timing diagram $( M = 1 )$


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/54fd71b87c18fdef207ca2c1399fbc728e87260f59d68efe79e4becfc2497262.jpg)



Figure 292. RX data setup/hold time


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/2e223704e0fd0b50ebf038f1428238527339e98e8682bccafde5d482870d8055.jpg)



Note: The function of CK is different in Smartcard mode. Refer to the Smartcard mode section for more details.


# 27.3.10 Single-wire half-duplex communication

The single-wire half-duplex mode is selected by setting the HDSEL bit in the USART_CR3 register. In this mode, the following bits must be kept cleared: 

 LINEN and CLKEN bits in the USART_CR2 register, 

SCEN and IREN bits in the USART_CR3 register. 

The USART can be configured to follow a single-wire half-duplex protocol. In single-wire half-duplex mode, the TX and RX pins are connected internally. The selection between halfand full-duplex communication is made with a control bit ‘HALF DUPLEX SEL’ (HDSEL in USART_CR3). 

As soon as HDSEL is written to 1: 

RX is no longer used, 

TX is always released when no data is transmitted. Thus, it acts as a standard IO in idle or in reception. It means that the IO must be configured so that TX is configured as floating input (or output high open-drain) when not driven by the USART. 

Apart from this, the communications are similar to what is done in normal USART mode. The conflicts on the line must be managed by the software (by the use of a centralized arbiter, for instance). In particular, the transmission is never blocked by hardware and continue to occur as soon as a data is written in the data register while the TE bit is set. 

# 27.3.11 Smartcard

The Smartcard mode is selected by setting the SCEN bit in the USART_CR3 register. In Smartcard mode, the following bits must be kept cleared: 

 LINEN bit in the USART_CR2 register, 

 HDSEL and IREN bits in the USART_CR3 register. 

Moreover, the CLKEN bit may be set in order to provide a clock to the smartcard. 

The Smartcard interface is designed to support asynchronous protocol Smartcards as defined in the ISO 7816-3 standard. The USART should be configured as: 

8 bits plus parity: where $\mathsf { M } = 1$ and $\mathsf { P C E } = 1$ in the USART_CR1 register 

1.5 stop bits when transmitting and receiving $\boldsymbol { : }$ where STOP=’11’ in the USART_CR2 register. 

Note: It is also possible to choose 0.5 stop bit for receiving but it is recommended to use 1.5 stop bits for both transmitting and receiving to avoid switching between the two configurations. 

Figure 293 shows examples of what can be seen on the data line with and without parity error. 


Figure 293. ISO 7816-3 asynchronous protocol


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/c66b7654c922db781c595cd71acc889c70ed2d5ffb899b126b9de645e3f4e314.jpg)


When connected to a smartcard, the USART TX output drives a bidirectional line that is also driven by the smartcard. The TX pin must be configured as open drain. 

Smartcard is a single wire half duplex communication protocol. 

Transmission of data from the transmit shift register is guaranteed to be delayed by a minimum of 1/2 baud clock. In normal operation a full transmit shift register will start shifting on the next baud clock edge. In Smartcard mode this transmission is further delayed by a guaranteed 1/2 baud clock. 

If a parity error is detected during reception of a frame programmed with a 0.5 or 1.5 stop bit period, the transmit line is pulled low for a baud clock period after the completion of the receive frame. This is to indicate to the Smartcard that the data transmitted to USART has not been correctly received. This NACK signal (pulling transmit line low for 1 baud clock) will cause a framing error on the transmitter side (configured with 1.5 stop bits). The application can handle re-sending of data according to the protocol. A parity error is ‘NACK’ed by the receiver if the NACK control bit is set, otherwise a NACK is not transmitted. 

The assertion of the TC flag can be delayed by programming the Guard Time register. In normal operation, TC is asserted when the transmit shift register is empty and no further transmit requests are outstanding. In Smartcard mode an empty transmit shift register triggers the guard time counter to count up to the programmed value in the Guard Time register. TC is forced low during this time. When the guard time counter reaches the programmed value TC is asserted high. 

The de-assertion of TC flag is unaffected by Smartcard mode. 

If a framing error is detected on the transmitter end (due to a NACK from the receiver), the NACK will not be detected as a start bit by the receive block of the transmitter. According to the ISO protocol, the duration of the received NACK can be 1 or 2 baud clock periods. 

On the receiver side, if a parity error is detected and a NACK is transmitted the receiver will not detect the NACK as a start bit. 

Note: A break character is not significant in Smartcard mode. A 0x00 data with a framing error will be treated as data and not as a break. 

No IDLE frame is transmitted when toggling the TE bit. The IDLE frame (as defined for the other configurations) is not defined by the ISO protocol. 

Figure 294 details how the NACK signal is sampled by the USART. In this example, the USART transmits a data and is configured with 1.5 stop bits. The receiver part of the USART is enabled in order to check the integrity of the data and the NACK signal. 


Figure 294. Parity error detection using the 1.5 stop bits


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/b4ff09e3ca16f5476d1d63e519cbb28697982657a766507a9f0a00f6bcb5284d.jpg)


The USART can provide a clock to the smartcard through the CK output. In Smartcard mode, CK is not associated to the communication but is simply derived from the internal peripheral input clock through a 5-bit prescaler. The division ratio is configured in the prescaler register USART_GTPR. CK frequency can be programmed from $\mathsf { f } _ { \mathsf { C K } } / 2$ to $\mathsf { f } _ { \mathsf { C K } } / 6 2$ , where $\mathsf { f } _ { \mathsf { C K } }$ is the peripheral input clock. 

# 27.3.12 IrDA SIR ENDEC block

The IrDA mode is selected by setting the IREN bit in the USART_CR3 register. In IrDA mode, the following bits must be kept cleared: 

 LINEN, STOP and CLKEN bits in the USART_CR2 register, 

SCEN and HDSEL bits in the USART_CR3 register. 

The IrDA SIR physical layer specifies use of a Return to Zero, Inverted (RZI) modulation scheme that represents logic 0 as an infrared light pulse (see Figure 295). 

The SIR Transmit encoder modulates the Non Return to Zero (NRZ) transmit bit stream output from USART. The output pulse stream is transmitted to an external output driver and infrared LED. USART supports only bit rates up to 115.2Kbps for the SIR ENDEC. In normal mode the transmitted pulse width is specified as 3/16 of a bit period. 

The SIR receive decoder demodulates the return-to-zero bit stream from the infrared detector and outputs the received NRZ serial bit stream to USART. The decoder input is normally HIGH (marking state) in the idle state. The transmit encoder output has the opposite polarity to the decoder input. A start bit is detected when the decoder input is low. 

IrDA is a half duplex communication protocol. If the Transmitter is busy (i.e. the USARTsends data to the IrDA encoder), any data on the IrDA receive line is ignored by the IrDA decoder and if the Receiver is busy (USART receives decoded data from the USART), data on the TX from the USART to IrDA is not encoded by IrDA. While receiving data, transmission should be avoided as the data to be transmitted could be corrupted. 

A ‘0’ is transmitted as a high pulse and a ‘1’ is transmitted as a $\mathbf { \vec { \nabla } } 0 ^ { \prime }$ . The width of the pulse is specified as 3/16th of the selected bit period in normal mode (see Figure 296). 

The SIR decoder converts the IrDA compliant receive signal into a bit stream for USART. 

The SIR receive logic interprets a high state as a logic one and low pulses as logic zeros. 

The transmit encoder output has the opposite polarity to the decoder input. The SIR output is in low state when idle. 

The IrDA specification requires the acceptance of pulses greater than 1.41 us. The acceptable pulse width is programmable. Glitch detection logic on the receiver end filters out pulses of width less than 2 PSC periods (PSC is the prescaler value programmed in the IrDA low-power Baud register, USART_GTPR). Pulses of width less than 1 PSC period are always rejected, but those of width greater than one and less than two periods may be accepted or rejected, those greater than 2 periods will be accepted as a pulse. The IrDA encoder/decoder doesn’t work when $\mathsf { P S C = } 0$ . 

 The receiver can communicate with a low-power transmitter. 

In IrDA mode, the STOP bits in the USART_CR2 register must be configured to “1 stop bit”. 

# IrDA low-power mode

# Transmitter

In low-power mode the pulse width is not maintained at 3/16 of the bit period. Instead, the width of the pulse is 3 times the low-power baud rate which can be a minimum of 1.42 MHz. Generally this value is 1.8432 MHz (1.42 MHz < PSC< 2.12 MHz). A low-power mode programmable divisor divides the system clock to achieve this value. 

# Receiver

Receiving in low-power mode is similar to receiving in normal mode. For glitch detection, the USART should discard pulses of duration shorter than 1/PSC. A valid low is accepted only if its duration is greater than 2 periods of the IrDA low-power Baud clock (PSC value in USART_GTPR). 

Note: A pulse of width less than two and greater than one PSC period(s) may or may not be rejected. 

The receiver set up time should be managed by software. The IrDA physical layer specification specifies a minimum of 10 ms delay between transmission and reception (IrDA is a half duplex protocol). 


Figure 295. IrDA SIR ENDEC- block diagram


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/d58ff84a1e4ce9b305c966b4f831dc950cef9f26fb62d3b724d7044445b55c70.jpg)



Figure 296. IrDA data modulation (3/16) -normal mode


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/e93d36795563fd0041314fe400f8e68e7b6538e30ce64df7a7c4dd5fd4075e9e.jpg)


# 27.3.13 Continuous communication using DMA

The USART is capable of continuing communication using the DMA. The DMA requests for Rx buffer and Tx buffer are generated independently. 

Note: User should refer to product specs for availability of the DMA controller. If DMA is not available in the product, you should use the USART as explained in Section 27.3.2 or 27.3.3. In the USART_SR register, user can clear the TXE/ RXNE flags to achieve continuous communication. 

# Transmission using DMA

DMA mode can be enabled for transmission by setting DMAT bit in the USART_CR3 register. Data is loaded from a SRAM area configured using the DMA peripheral (refer to the DMA specification) to the USART_DR register whenever the TXE bit is set. To map a DMA channel for USART transmission, use the following procedure (x denotes the channel number): 

1. Write the USART_DR register address in the DMA control register to configure it as the destination of the transfer. The data will be moved to this address from memory after each TXE event. 

2. Write the memory address in the DMA control register to configure it as the source of the transfer. The data will be loaded into the USART_DR register from this memory area after each TXE event. 

3. Configure the total number of bytes to be transferred to the DMA control register. 

4. Configure the channel priority in the DMA register 

5. Configure DMA interrupt generation after half/ full transfer as required by the application. 

6. Clear the TC bit in the SR register by writing 0 to it. 

7. Activate the channel in the DMA register. 

When the number of data transfers programmed in the DMA Controller is reached, the DMA controller generates an interrupt on the DMA channel interrupt vector. 

In transmission mode, once the DMA has written all the data to be transmitted (the TCIF flag is set in the DMA_ISR register), the TC flag can be monitored to make sure that the USART communication is complete. This is required to avoid corrupting the last transmission before disabling the USART or entering the Stop mode. The software must wait until $\mathsf { T C } = 1$ . The TC flag remains cleared during all data transfers and it is set by hardware at the last frame’s end of transmission. 


Figure 297. Transmission using DMA


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/a5d7fc971f36545d2b26ba15eb22ccf21aaa91f8d699452d099c2a811071b182.jpg)


# Reception using DMA

DMA mode can be enabled for reception by setting the DMAR bit in USART_CR3 register. Data is loaded from the USART_DR register to a SRAM area configured using the DMA peripheral (refer to the DMA specification) whenever a data byte is received. To map a DMA channel for USART reception, use the following procedure: 

1. Write the USART_DR register address in the DMA control register to configure it as the source of the transfer. The data will be moved from this address to the memory after each RXNE event. 

2. Write the memory address in the DMA control register to configure it as the destination of the transfer. The data will be loaded from USART_DR to this memory area after each RXNE event. 

3. Configure the total number of bytes to be transferred in the DMA control register. 

4. Configure the channel priority in the DMA control register 

5. Configure interrupt generation after half/ full transfer as required by the application. 

6. Activate the channel in the DMA control register. 

When the number of data transfers programmed in the DMA Controller is reached, the DMA controller generates an interrupt on the DMA channel interrupt vector. 


Figure 298. Reception using DMA


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/702341e86497c4978db328d90586ee72976d68007ecdd5c86bc69c5f18aec561.jpg)


# Error flagging and interrupt generation in multibuffer communication

In case of multibuffer communication if any error occurs during the transaction the error flag will be asserted after the current byte. An interrupt will be generated if the interrupt enable flag is set. For framing error, overrun error and noise flag which are asserted with RXNE in case of single byte reception, there will be separate error flag interrupt enable bit (EIE bit in the USART_CR3 register), which if set will issue an interrupt after the current byte with either of these errors. 

# 27.3.14 Hardware flow control

It is possible to control the serial data flow between two devices by using the CTS input and the RTS output. Figure 299 shows how to connect two devices in this mode: 


Figure 299. Hardware flow control between two USARTs


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/ecaa759f839546f39c72f135c6faccbfa63ebd575c0357e451bc47ab2dec5f40.jpg)


RTS and CTS flow control can be enabled independently by writing respectively RTSE and CTSE bits to 1 (in the USART_CR3 register). 

# RTS flow control

If the RTS flow control is enabled $( \mathsf { R T S E } = 1$ ), then RTS is asserted (tied low) as long as the USART receiver is ready to receive new data. When the receive register is full, RTS is deasserted, indicating that the transmission is expected to stop at the end of the current frame. Figure 300 shows an example of communication with RTS flow control enabled. 


Figure 300. RTS flow control


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/c2361edb38d456c22b1c770a6ffbeb8a21298bb4cfbc768d3bdebca56b096943.jpg)


# CTS flow control

If the CTS flow control is enabled $( \mathsf { C T S E } 3 7 \mathsf { c m }$ ), then the transmitter checks the CTS input before transmitting the next frame. If CTS is asserted (tied low), then the next data is transmitted (assuming that a data is to be transmitted, in other words, if $\mathrm { T X E } { = } 0 .$ ), else the transmission does not occur. When CTS is deasserted during a transmission, the current transmission is completed before the transmitter stops. 

When CTSE=1, the CTSIF status bit is automatically set by hardware as soon as the CTS input toggles. It indicates when the receiver becomes ready or not ready for communication. An interrupt is generated if the CTSIE bit in the USART_CR3 register is set. The figure below shows an example of communication with CTS flow control enabled. 


Figure 301. CTS flow control


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/7e3ee5a93fdb4d9e02484eb4b8210c87ecb32b2b125a1a2d2a7d8d89e9e1ee15.jpg)


# 27.4 USART interrupts


Table 196. USART interrupt requests


<table><tr><td>Interrupt event</td><td>Event flag</td><td>Enable Control bit</td></tr><tr><td>Transmit data register empty</td><td>TXE</td><td>TXEIE</td></tr><tr><td>CTS flag</td><td>CTS</td><td>CTSIE</td></tr><tr><td>Transmission complete</td><td>TC</td><td>TCIE</td></tr><tr><td>Received data ready to be read</td><td>RXNE</td><td rowspan="2">RXNEIE</td></tr><tr><td>Overrun error detected</td><td>ORE</td></tr><tr><td>Idle line detected</td><td>IDLE</td><td>IDLEIE</td></tr><tr><td>Parity error</td><td>PE</td><td>PEIE</td></tr><tr><td>Break flag</td><td>LBD</td><td>LBDIE</td></tr><tr><td>Noise flag, Overrun error and Framing error in multibuffer communication</td><td>NE or ORE or FE</td><td>EIE(1)</td></tr></table>


1. This bit is used only when data reception is performed by DMA. 


The USART interrupt events are connected to the same interrupt vector (see Figure 302). 

During transmission: Transmission Complete, Clear to Send or Transmit Data register empty interrupt. 

While receiving: Idle Line detection, Overrun error, Receive Data register not empty, Parity error, LIN break detection, Noise Flag (only in multi buffer communication) and Framing Error (only in multi buffer communication). 

These events generate an interrupt if the corresponding Enable Control Bit is set. 


Figure 302. USART interrupt mapping diagram


![image](https://cdn-mineru.openxlab.org.cn/result/2026-02-07/43c5798b-d3e4-4cc5-9e92-d809edc79f53/e7af40e2263bdc41ed8e97ad1d03981527670b51da613ae1b9ed5a9d4f674073.jpg)


# 27.5 USART mode configuration


Table 197. USART mode configuration(1)


<table><tr><td>USART modes</td><td>USART1</td><td>USART2</td><td>USART3</td><td>UART4</td><td>UART5</td></tr><tr><td>Asynchronous mode</td><td>X</td><td>X</td><td>X</td><td>X</td><td>X</td></tr><tr><td>Hardware Flow Control</td><td>X</td><td>X</td><td>X</td><td>NA</td><td>NA</td></tr><tr><td>Multibuffer Communication (DMA)</td><td>X</td><td>X</td><td>X</td><td>X</td><td>NA</td></tr><tr><td>Multiprocessor Communication</td><td>X</td><td>X</td><td>X</td><td>X</td><td>X</td></tr><tr><td>Synchronous</td><td>X</td><td>X</td><td>X</td><td>NA</td><td>NA</td></tr><tr><td>Smartcard</td><td>X</td><td>X</td><td>X</td><td>NA</td><td>NA</td></tr><tr><td>Half-Duplex (Single-Wire mode)</td><td>X</td><td>X</td><td>X</td><td>X</td><td>X</td></tr><tr><td>IrDA</td><td>X</td><td>X</td><td>X</td><td>X</td><td>X</td></tr><tr><td>LIN</td><td>X</td><td>X</td><td>X</td><td>X</td><td>X</td></tr></table>


1. X = supported; NA $=$ not applicable. 


# 27.6 USART registers

Refer to Section 2.2 on page 45 for a list of abbreviations used in register descriptions. 

The peripheral registers can be accessed by half-words (16-bit) or words (32-bit). 

# 27.6.1 Status register (USART_SR)

Address offset: 0x00 

Reset value: 0x00C0 

<table><tr><td colspan="15">Reserved</td><td></td></tr><tr><td>15</td><td>14</td><td>13</td><td>12</td><td>11</td><td>10</td><td>9</td><td>8</td><td>7</td><td>6</td><td>5</td><td>4</td><td>3</td><td>2</td><td>1</td><td>0</td></tr><tr><td rowspan="2" colspan="5">Reserved</td><td>CTS</td><td>LBD</td><td>TXE</td><td>TC</td><td>RXNE</td><td>IDLE</td><td>ORE</td><td>NE</td><td>FE</td><td>PE</td><td></td></tr><tr><td>rc_w0</td><td>rc_w0</td><td>r</td><td>rc_w0</td><td>rc_w0</td><td>r</td><td>r</td><td>r</td><td>r</td><td>r</td><td></td></tr></table>

Bits 31:10 Reserved, forced by hardware to 0. 

# Bit 9 CTS: CTS flag

This bit is set by hardware when the CTS input toggles, if the CTSE bit is set. It is cleared by software (by writing it to 0). An interrupt is generated if CTSIE $^ { = 1 }$ in the USART_CR3 register. 

0: No change occurred on the CTS status line 

1: A change occurred on the CTS status line 

This bit is not available for UART4 & UART5. 

# Bit 8 LBD: LIN break detection flag

This bit is set by hardware when the LIN break is detected. It is cleared by software (by writing it to 0). An interrupt is generated if LBDIE = 1 in the USART_CR2 register. 

0: LIN Break not detected 

1: LIN break detected 

Note: An interrupt is generated when LBD=1 if LBDIE=1 

# Bit 7 TXE: Transmit data register empty

This bit is set by hardware when the content of the TDR register has been transferred into the shift register. An interrupt is generated if the TXEIE bit $= 1$ in the USART_CR1 register. It is cleared by a write to the USART_DR register. 

0: Data is not transferred to the shift register 

1: Data is transferred to the shift register) 

Note: This bit is used during single buffer transmission. 

# Bit 6 TC: Transmission complete

This bit is set by hardware if the transmission of a frame containing data is complete and if TXE is set. An interrupt is generated if ${ \mathsf { T C l E } } = 1$ in the USART_CR1 register. It is cleared by a software sequence (a read from the USART_SR register followed by a write to the USART_DR register). The TC bit can also be cleared by writing a $" 0 "$ to it. This clearing sequence is recommended only for multibuffer communication. 

0: Transmission is not complete 

1: Transmission is complete 

# Bit 5 RXNE: Read data register not empty

This bit is set by hardware when the content of the RDR shift register has been transferred to the USART_DR register. An interrupt is generated if RXNEIE $= 1$ in the USART_CR1 register. It is cleared by a read to the USART_DR register. The RXNE flag can also be cleared by writing a zero to it. This clearing sequence is recommended only for multibuffer communication. 

0: Data is not received 

1: Received data is ready to be read. 

# Bit 4 IDLE: IDLE line detected

This bit is set by hardware when an Idle Line is detected. An interrupt is generated if the IDLEIE $= 1$ in the USART_CR1 register. It is cleared by a software sequence (an read to the USART_SR register followed by a read to the USART_DR register). 

0: No Idle Line is detected 

1: Idle Line is detected 

Note: The IDLE bit will not be set again until the RXNE bit has been set itself (i.e. a new idle line occurs). 

# Bit 3 ORE: Overrun error

This bit is set by hardware when the word currently being received in the shift register is ready to be transferred into the RDR register while RXNE $= 1$ . An interrupt is generated if RXNEIE=1 in the USART_CR1 register. It is cleared by a software sequence (an read to the USART_SR register followed by a read to the USART_DR register). 

0: No Overrun error 

1: Overrun error is detected 

Note: When this bit is set, the RDR register content will not be lost but the shift register will be overwritten. An interrupt is generated on ORE flag in case of Multi Buffer communication if the EIE bit is set. 

# Bit 2 NE: Noise error flag

This bit is set by hardware when noise is detected on a received frame. It is cleared by a software sequence (an read to the USART_SR register followed by a read to the USART_DR register). 

0: No noise is detected 

1: Noise is detected 

Note: This bit does not generate interrupt as it appears at the same time as the RXNE bit which itself generates an interrupting interrupt is generated on NE flag in case of Multi Buffer communication if the EIE bit is set. 

# Bit 1 FE: Framing error

This bit is set by hardware when a de-synchronization, excessive noise or a break character is detected. It is cleared by a software sequence (an read to the USART_SR register followed by a read to the USART_DR register). 

0: No Framing error is detected 

1: Framing error or break character is detected 

Note: This bit does not generate interrupt as it appears at the same time as the RXNE bit which itself generates an interrupt. If the word currently being transferred causes both frame error and overrun error, it will be transferred and only the ORE bit will be set. An interrupt is generated on FE flag in case of Multi Buffer communication if the EIE bit is set. 

# Bit 0 PE: Parity error

This bit is set by hardware when a parity error occurs in receiver mode. It is cleared by a software sequence (a read to the status register followed by a read to the USART_DR data register). The software must wait for the RXNE flag to be set before clearing the PE bit. An interrupt is generated if PEIE $= 1$ in the USART_CR1 register. 

0: No parity error 

1: Parity error 

# 27.6.2 Data register (USART_DR)

Address offset: 0x04 

Reset value: Undefined 

<table><tr><td colspan="15">Reserved</td><td></td></tr><tr><td>15</td><td>14</td><td>13</td><td>12</td><td>11</td><td>10</td><td>9</td><td>8</td><td>7</td><td>6</td><td>5</td><td>4</td><td>3</td><td>2</td><td>1</td><td>0</td></tr><tr><td rowspan="2" colspan="7">Reserved</td><td colspan="9">DR[8:0]</td></tr><tr><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td></tr></table>

Bits 31:9 Reserved, forced by hardware to 0. 

Bits 8:0 DR[8:0]: Data value 

Contains the Received or Transmitted data character, depending on whether it is read from or written to. 

The Data register performs a double function (read and write) since it is composed of two registers, one for transmission (TDR) and one for reception (RDR) 

The TDR register provides the parallel interface between the internal bus and the output shift register (see Figure 1). 

The RDR register provides the parallel interface between the input shift register and the internal bus. 

When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register), the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect because it is replaced by the parity. 

When receiving with the parity enabled, the value read in the MSB bit is the received parity bit. 

# 27.6.3 Baud rate register (USART_BRR)

Note: The baud counters stop counting if the TE or RE bits are disabled respectively. 

Address offset: 0x08 

Reset value: 0x0000 

<table><tr><td>31</td><td>30</td><td>29</td><td>28</td><td>27</td><td>26</td><td>25</td><td>24</td><td>23</td><td>22</td><td>21</td><td>20</td><td>19</td><td>18</td><td>17</td><td>16</td></tr><tr><td colspan="16">Reserved</td></tr><tr><td>15</td><td>14</td><td>13</td><td>12</td><td>11</td><td>10</td><td>9</td><td>8</td><td>7</td><td>6</td><td>5</td><td>4</td><td>3</td><td>2</td><td>1</td><td>0</td></tr><tr><td colspan="12">DIV_Mantissa[11:0]</td><td colspan="4">DIV_Fraction[3:0]</td></tr><tr><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td></tr></table>

Bits 31:16 Reserved, forced by hardware to 0. 

Bits 15:4 DIV_Mantissa[11:0]: mantissa of USARTDIV 

These 12 bits define the mantissa of the USART Divider (USARTDIV) 

Bits 3:0 DIV_Fraction[3:0]: fraction of USARTDIV 

These 4 bits define the fraction of the USART Divider (USARTDIV) 

# 27.6.4 Control register 1 (USART_CR1)

Address offset: 0x0C 

Reset value: 0x0000 

<table><tr><td colspan="16">Reserved</td></tr><tr><td>15</td><td>14</td><td>13</td><td>12</td><td>11</td><td>10</td><td>9</td><td>8</td><td>7</td><td>6</td><td>5</td><td>4</td><td>3</td><td>2</td><td>1</td><td>0</td></tr><tr><td rowspan="2">Reserved</td><td>UE</td><td>M</td><td>WAKE</td><td>PCE</td><td>PS</td><td>PEIE</td><td>TXEIE</td><td>TCIE</td><td>RXNEIE</td><td>IDLEIE</td><td>TE</td><td>RE</td><td>RWU</td><td>SBK</td><td></td></tr><tr><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td></tr></table>

Bits 31:14 Reserved, forced by hardware to 0. 

Bit 13 UE: USART enable 

When this bit is cleared the USART prescalers and outputs are stopped and the end of the current 

byte transfer in order to reduce power consumption. This bit is set and cleared by software. 

0: USART prescaler and outputs disabled 

1: USART enabled 

Bit 12 M: Word length 

This bit determines the word length. It is set or cleared by software. 

0: 1 Start bit, 8 Data bits, n Stop bit 

1: 1 Start bit, 9 Data bits, n Stop bit 

Note: The M bit must not be modified during a data transfer (both transmission and reception) 

Bit 11 WAKE: Wakeup method 

This bit determines the USART wakeup method, it is set or cleared by software. 

0: Idle Line 

1: Address Mark 

Bit 10 PCE: Parity control enable 

This bit selects the hardware parity control (generation and detection). When the parity control is enabled, the computed parity is inserted at the MSB position (9th bit if $\mathsf { M } = 1$ ; 8th bit if $\scriptstyle { \mathsf { M } } = 0$ ) and parity is checked on the received data. This bit is set and cleared by software. Once it is set, PCE is active after the current byte (in reception and in transmission). 

0: Parity control disabled 

1: Parity control enabled 

Bit 9 PS: Parity selection 

This bit selects the odd or even parity when the parity generation/detection is enabled (PCE bit set). It is set and cleared by software. The parity will be selected after the current byte. 

0: Even parity 

1: Odd parity 

Bit 8 PEIE: PE interrupt enable 

This bit is set and cleared by software. 

0: Interrupt is inhibited 

1: A USART interrupt is generated whenever $\mathsf { P E } { = } 1$ in the USART_SR register 

Bit 7 TXEIE: TXE interrupt enable 

This bit is set and cleared by software. 

0: Interrupt is inhibited 

1: A USART interrupt is generated whenever $\mathsf { T X E } = 1$ in the USART_SR register 

Bit 6 TCIE: Transmission complete interrupt enable 

This bit is set and cleared by software. 

0: Interrupt is inhibited 

1: A USART interrupt is generated whenever $\mathsf { T C } = 1$ in the USART_SR register 

Bit 5 RXNEIE: RXNE interrupt enable 

This bit is set and cleared by software. 

0: Interrupt is inhibited 

1: A USART interrupt is generated whenever ORE=1 or RXNE $= 1$ in the USART_SR register 

Bit 4 IDLEIE: IDLE interrupt enable 

This bit is set and cleared by software. 

0: Interrupt is inhibited 

1: A USART interrupt is generated whenever IDLE $= 1$ in the USART_SR register 

Bit 3 TE: Transmitter enable 

This bit enables the transmitter. It is set and cleared by software. 

0: Transmitter is disabled 

1: Transmitter is enabled 

Note: 1: During transmission, a “0” pulse on the TE bit (“0” followed by “1”) sends a preamble (idle line) after the current word, except in Smartcard mode. 

2: When TE is set there is a 1 bit-time delay before the transmission starts. 

Bit 2 RE: Receiver enable 

This bit enables the receiver. It is set and cleared by software. 

0: Receiver is disabled 

1: Receiver is enabled and begins searching for a start bit 

Bit 1 RWU: Receiver wakeup 

This bit determines if the USART is in mute mode or not. It is set and cleared by software and can be cleared by hardware when a wakeup sequence is recognized. 

0: Receiver in active mode 

1: Receiver in mute mode 

Note: 1: Before selecting Mute mode (by setting the RWU bit) the USART must first receive a data byte, otherwise it cannot function in Mute mode with wakeup by Idle line detection. 

2: In Address Mark Detection wakeup configuration (WAKE bit=1) the RWU bit cannot be modified by software while the RXNE bit is set. 

Bit 0 SBK: Send break 

This bit set is used to send break characters. It can be set and cleared by software. It should be set by software, and will be reset by hardware during the stop bit of break. 

0: No break character is transmitted 

1: Break character will be transmitted 

# 27.6.5 Control register 2 (USART_CR2)

Address offset: 0x10 

Reset value: 0x0000 

<table><tr><td colspan="16">Reserved</td></tr><tr><td>15</td><td>14</td><td>13</td><td>12</td><td>11</td><td>10</td><td>9</td><td>8</td><td>7</td><td>6</td><td>5</td><td>4</td><td>3</td><td>2</td><td>1</td><td>0</td></tr><tr><td rowspan="2">Res.</td><td>LINEN</td><td colspan="2">STOP[1:0]</td><td>CLK EN</td><td>CPOL</td><td>CPHA</td><td>LBCL</td><td>Res.</td><td>LBDIE</td><td>LBDL</td><td>Res.</td><td colspan="4">ADD[3:0]</td></tr><tr><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td></td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td></tr></table>

Bits 31:15 Reserved, forced by hardware to 0. 

Bit 14 LINEN: LIN mode enable 

This bit is set and cleared by software. 

0: LIN mode disabled 

1: LIN mode enabled 

The LIN mode enables the capability to send LIN Synch Breaks (13 low bits) using the SBK bit in the USART_CR1 register, and to detect LIN Sync breaks. 

Bits 13:12 STOP: STOP bits 

These bits are used for programming the stop bits. 

00: 1 Stop bit 

01: 0.5 Stop bit 

10: 2 Stop bits 

11: 1.5 Stop bit 

The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5. 

Bit 11 CLKEN: Clock enable 

This bit allows the user to enable the CK pin. 

0: CK pin disabled 

1: CK pin enabled 

This bit is not available for UART4 & UART5. 

Bit 10 CPOL: Clock polarity 

This bit allows the user to select the polarity of the clock output on the CK pin in synchronous mode. It works in conjunction with the CPHA bit to produce the desired clock/data relationship 

0: Steady low value on CK pin outside transmission window. 

1: Steady high value on CK pin outside transmission window. 

This bit is not available for UART4 & UART5. 

Bit 9 CPHA: Clock phase 

This bit allows the user to select the phase of the clock output on the CK pin in synchronous mode. It works in conjunction with the CPOL bit to produce the desired clock/data relationship (see figures 290 to 291) 

0: The first clock transition is the first data capture edge. 

1: The second clock transition is the first data capture edge. 

This bit is not available for UART4 & UART5. 

Bit 8 LBCL: Last bit clock pulse 

This bit allows the user to select whether the clock pulse associated with the last data bit transmitted (MSB) has to be output on the CK pin in synchronous mode. 

0: The clock pulse of the last data bit is not output to the CK pin 

1: The clock pulse of the last data bit is output to the CK pin 

The last bit is the 8th or 9th data bit transmitted depending on the 8 or 9 bit format selected by the M bit in the USART_CR1 register. 

This bit is not available for UART4 & UART5. 

Bit 7 Reserved, forced by hardware to 0. 

Bit 6 LBDIE: LIN break detection interrupt enable 

Break interrupt mask (break detection using break delimiter). 

0: Interrupt is inhibited 

1: An interrupt is generated whenever LBD=1 in the USART_SR register 

Bit 5 LBDL: lin break detection length 

This bit is for selection between 11 bit or 10 bit break detection. 

0: 10 bit break detection 

1: 11 bit break detection 

Bit 4 Reserved, forced by hardware to 0. 

Bits 3:0 ADD[3:0]: Address of the USART node 

This bit-field gives the address of the USART node. 

This is used in multiprocessor communication during mute mode, for wake up with address mark detection. 

Note: These 3 bits (CPOL, CPHA, LBCL) should not be written while the transmitter is enabled. 

# 27.6.6 Control register 3 (USART_CR3)

Address offset: 0x14 

Reset value: 0x0000 

<table><tr><td colspan="15">Reserved</td><td></td></tr><tr><td>15</td><td>14</td><td>13</td><td>12</td><td>11</td><td>10</td><td>9</td><td>8</td><td>7</td><td>6</td><td>5</td><td>4</td><td>3</td><td>2</td><td>1</td><td>0</td></tr><tr><td rowspan="2" colspan="4">Reserved</td><td>CTSIE</td><td>CTSE</td><td>RTSE</td><td>DMAT</td><td>DMAR</td><td>SCEN</td><td>NACK</td><td>HDSEL</td><td>IRLP</td><td>IREN</td><td>EIE</td><td></td></tr><tr><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td></td></tr></table>

Bits 31:11 Reserved, forced by hardware to 0. 

Bit 10 CTSIE: CTS interrupt enable 

0: Interrupt is inhibited 

1: An interrupt is generated whenever $\mathrm { C T S } { = } 1$ in the USART_SR register This bit is not available for UART4 & UART5. 

Bit 9 CTSE: CTS enable 

0: CTS hardware flow control disabled 

1: CTS mode enabled, data is only transmitted when the CTS input is asserted (tied to 0). If the CTS input is deasserted while a data is being transmitted, then the transmission is completed before stopping. If a data is written into the data register while CTS is deasserted, the transmission is postponed until CTS is asserted. 

This bit is not available for UART4 & UART5. 

# Bit 8 RTSE: RTS enable

0: RTS hardware flow control disabled 

1: RTS interrupt enabled, data is only requested when there is space in the receive buffer. 

The transmission of data is expected to cease after the current character has been 

transmitted. The RTS output is asserted (tied to 0) when a data can be received. 

This bit is not available for UART4 & UART5. 

# Bit 7 DMAT: DMA enable transmitter

This bit is set/reset by software 

1: DMA mode is enabled for transmission 

0: DMA mode is disabled for transmission 

This bit is not available for UART5. 

# Bit 6 DMAR: DMA enable receiver

This bit is set/reset by software 

1: DMA mode is enabled for reception 

0: DMA mode is disabled for reception 

This bit is not available for UART5. 

# Bit 5 SCEN: Smartcard mode enable

This bit is used for enabling Smartcard mode. 

0: Smartcard Mode disabled 

1: Smartcard Mode enabled 

This bit is not available for UART4 & UART5. 

# Bit 4 NACK: Smartcard NACK enable

0: NACK transmission in case of parity error is disabled 

1: NACK transmission during parity error is enabled 

This bit is not available for UART4 & UART5. 

# Bit 3 HDSEL: Half-duplex selection

Selection of Single-wire Half-duplex mode 

0: Half duplex mode is not selected 

1: Half duplex mode is selected 

# Bit 2 IRLP: IrDA low-power

This bit is used for selecting between normal and low-power IrDA modes 

0: Normal mode 

1: Low-power mode 

# Bit 1 IREN: IrDA mode enable

This bit is set and cleared by software. 

0: IrDA disabled 

1: IrDA enabled 

# Bit 0 EIE: Error interrupt enable

Error Interrupt Enable Bit is required to enable interrupt generation in case of a framing error, overrun error or noise error $\mathrm { F E } = 1$ or ORE=1 or $\mathsf { N E } { = } 1$ in the USART_SR register) in case of Multi Buffer Communication (DMAR $^ { = 1 }$ in the USART_CR3 register). 

0: Interrupt is inhibited 

1: An interrupt is generated whenever DMAR $^ { * 1 }$ in the USART_CR3 register and $F E = 1$ or ORE=1 or $N E { = } 1$ in the USART_SR register. 

# 27.6.7 Guard time and prescaler register (USART_GTPR)

Address offset: 0x18 

Reset value: 0x0000 

<table><tr><td>31</td><td>30</td><td>29</td><td>28</td><td>27</td><td>26</td><td>25</td><td>24</td><td>23</td><td>22</td><td>21</td><td>20</td><td>19</td><td>18</td><td>17</td><td>16</td></tr><tr><td colspan="16">Reserved</td></tr><tr><td>15</td><td>14</td><td>13</td><td>12</td><td>11</td><td>10</td><td>9</td><td>8</td><td>7</td><td>6</td><td>5</td><td>4</td><td>3</td><td>2</td><td>1</td><td>0</td></tr><tr><td colspan="8">GT[7:0]</td><td colspan="8">PSC[7:0]</td></tr><tr><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td></tr></table>

Bits 31:16 Reserved, forced by hardware to 0. 

Bits 15:8 GT[7:0]: Guard time value 

This bit-field gives the Guard time value in terms of number of baud clocks. 

This is used in Smartcard mode. The Transmission Complete flag is set after this guard time value. 

This bit is not available for UART4 & UART5. 

Bits 7:0 PSC[7:0]: Prescaler value 

– In IrDA Low-power mode: 

PSC[7:0] $=$ IrDA Low-Power Baud Rate 

Used for programming the prescaler for dividing the system clock to achieve the low-power frequency: 

The source clock is divided by the value given in the register (8 significant bits): 

00000000: Reserved - do not program this value 

00000001: divides the source clock by 1 

00000010: divides the source clock by 2 

– In normal IrDA mode: PSC must be set to 00000001. 

– In Smartcard mode: 

PSC[4:0]: Prescaler value 

Used for programming the prescaler for dividing the system clock to provide the smartcard clock. 

The value given in the register (5 significant bits) is multiplied by 2 to give the division factor of the source clock frequency: 

00000: Reserved - do not program this value 

00001: divides the source clock by 2 

00010: divides the source clock by 4 

00011: divides the source clock by 6 

Note: Bits [7:5] have no effect if Smartcard mode is used. 

This bit is not available for UART4 & UART5. 

# 27.6.8 USART register map

The table below gives the USART register map and reset values. 


Table 198. USART register map and reset values


<table><tr><td>Offset</td><td>Register</td><td>31</td><td>30</td><td>29</td><td>28</td><td>27</td><td>26</td><td>25</td><td>24</td><td>23</td><td>22</td><td>21</td><td>20</td><td>19</td><td>18</td><td>17</td><td>16</td><td>15</td><td>14</td><td>13</td><td>12</td><td>11</td><td>10</td><td>9</td><td>8</td><td>7</td><td>6</td><td>5</td><td>4</td><td>3</td><td>2</td><td>1</td><td>0</td></tr><tr><td rowspan="2">0x00</td><td>USART_SR</td><td rowspan="2" colspan="32">Reserved</td></tr><tr><td>Reset value</td></tr><tr><td rowspan="2">0x04</td><td>USART_DR</td><td rowspan="2" colspan="32">Reserved</td></tr><tr><td>Reset value</td></tr><tr><td rowspan="2">0x08</td><td>USART_BRR</td><td rowspan="2" colspan="7">Reserved</td><td colspan="25">DIV_Mantissa[15:4]</td></tr><tr><td>Reset value</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td></tr><tr><td rowspan="2">0x0C</td><td>USART_CR1</td><td rowspan="2" colspan="10">Reserved</td><td>UE</td><td>M</td><td>WAKE</td><td>PCE</td><td>PS</td><td>PEIE</td><td>TXEIE</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td></tr><tr><td>Reset value</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td></tr><tr><td rowspan="2">0x10</td><td>USART_CR2</td><td rowspan="2" colspan="10">Reserved</td><td>STOP[1:0]</td><td>CLKEN</td><td>CPOL</td><td>CPFA</td><td>LPCL</td><td>LBCL</td><td>RESERVED</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td></tr><tr><td>Reset value</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td></tr><tr><td rowspan="2">0x14</td><td>USART_CR3</td><td rowspan="2" colspan="32">Reserved</td></tr><tr><td>Reset value</td></tr><tr><td rowspan="2">0x18</td><td>USART_GTPR</td><td rowspan="2" colspan="10">Reserved</td><td colspan="22">GT[7:0]</td></tr><tr><td>Reset value</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td></tr></table>


Refer to Table 3 on page 50 for the register boundary addresses. 
