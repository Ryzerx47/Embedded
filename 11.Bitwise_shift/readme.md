# Bitwise Operations in Embedded C (STM32)

## Overview
Today I learned and practiced **bitwise operations** in Embedded C, focusing on:

- Bitwise shift operations
- Bitwise masking and extraction
- Using bitwise operators to control GPIO registers
- LED blinking using register-level programming on STM32
- Extracting specific bits from a data word using shift and mask techniques

All examples are written in **C** and tested in an **STM32 (bare-metal)** environment.

---

## Topics Covered

### 1. Bitwise Shift Operations
Bitwise shift operators (`<<`, `>>`) move bits left or right by a specified number of positions.

- Left shift (`<<`) is commonly used to **set specific bits**
- Right shift (`>>`) is useful for **bit extraction**

Example:

    (1 << 3)   // sets the 3rd bit
### 2. LED Blinking Using Bitwise Operations (STM32)

This program controls LEDs connected to GPIOD pins 12–15 by directly accessing memory-mapped registers.

Key Concepts Used

Register address casting using pointers

Bitwise OR (|) to set bits

Bitwise AND (&) with NOT (~) to clear bits

Bitwise XOR (^) to toggle bits

Delay using a simple loop

#### LED Blink Code
    
    #include<stdio.h>
    #include<stdint.h>
    
    void delay(void);
    
    int main(void)
    {
    	volatile uint32_t *pClkCntrlReg   = (uint32_t *)0x40023830;
    	volatile uint32_t *pGPIODModeReg = (uint32_t *)0x40020C00;
    	volatile uint32_t *pGPIODopReg   = (uint32_t *)0x40020C14;
    
    	// 1. Enable clock for GPIOD (bit 3 in AHB1ENR)
    	*pClkCntrlReg |= (1 << 3);
    
    	// 2. Configure pins 12–15 as output
    	*pGPIODModeReg &= ~(1 << 24);
    	*pGPIODModeReg &= ~(1 << 25);
    	*pGPIODModeReg &= ~(1 << 26);
    	*pGPIODModeReg &= ~(1 << 27);
    	*pGPIODModeReg &= ~(1 << 28);
    	*pGPIODModeReg &= ~(1 << 29);
    	*pGPIODModeReg &= ~(1 << 30);
    	*pGPIODModeReg &= ~(1 << 31);
    
    	*pGPIODModeReg |= (1 << 24);
    	*pGPIODModeReg |= (1 << 26);
    	*pGPIODModeReg |= (1 << 28);
    	*pGPIODModeReg |= (1 << 30);
    
    	while(1)
    	{
    		*pGPIODopReg ^= (1 << 12);
    		delay();
    		*pGPIODopReg ^= (1 << 13);
    		delay();
    		*pGPIODopReg ^= (1 << 14);
    		delay();
    		*pGPIODopReg ^= (1 << 15);
    		delay();
    	}
    }
    
    void delay(void)
    {
    	for(uint32_t i = 0; i < 500000; i++);
    }

Why XOR (^)?

XOR toggles a bit

If bit = 1 → becomes 0

If bit = 0 → becomes 1
Perfect for LED blinking without affecting other bits.

### 3. Bit Extraction Using Bitwise Operations

This program demonstrates how to extract specific bits from a data word using:

Right shift (>>)

Bitwise AND (&) masking

Goal

Extract bits 9 to 14 from a 16-bit value.

#### Bit Extraction Code
    
    #include<stdio.h>
    #include<stdint.h>
    
    int main()
    {
    	uint16_t data = 0xB410;
    
    	// Shift right by 9 to align required bits to LSB
    	uint8_t temp = data >> 9;
    
    	// Mask to extract only 6 bits (bits 0–5)
    	uint8_t output = temp & 0x3F;
    
    	printf("The extracted part is %u\n", output);
    	fflush(stdout);
    
    	printf("The extracted part in hex 0x%X\n", output);
    	fflush(stdout);
    }

#### Explanation

Right shift aligns the target bits to the least significant position

Mask 0x3F (0011 1111) ensures only 6 bits are extracted

This method is widely used in:

Protocol parsing

Sensor data decoding

Register field extraction

Key Learnings

Bitwise operations give precise control over hardware

Shift + mask is the safest way to extract data from registers

XOR is ideal for toggling outputs

Register-level programming improves understanding of microcontroller internals

## Conclusion

This exercise strengthened my understanding of low-level embedded programming, especially how microcontrollers interact with hardware using bitwise logic and memory-mapped registers.
