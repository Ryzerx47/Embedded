# STM32 LED Blinking Using Register-Level Programming

## Overview
This project demonstrates **blinking an LED on an STM32 microcontroller** using **direct register-level programming**, without using HAL or driver libraries.  
The code configures **GPIOD pin 12** as an output and toggles it continuously with a software delay.

This approach helps in understanding:
- Memory-mapped peripherals
- GPIO register configuration
- RCC clock enable mechanism
- Bitwise operations on registers

---

## Hardware Used
- **STM32 Discovery Board (STM32F4 series)**
- On-board LEDs connected to **Port D**

### LEDs on the Board
There are **8 LEDs** on the board, out of which **4 are user-accessible**:
- **PD12**
- **PD13**
- **PD14**
- **PD15**

In this project, **PD12** is used for blinking.

---

## Key Concepts Learned

### 1. Memory-Mapped I/O
STM32 peripherals like **GPIOA, GPIOB, GPIOC, GPIOD**, etc., are mapped into specific memory addresses.

By accessing these addresses directly using pointers, we can control the hardware.

Example:

    volatile uint32_t *pGPIODModeReg = (uint32_t *)0x40020C00;


### 2. RCC Clock Enable for GPIOD

Before using any GPIO peripheral, its clock must be enabled using the RCC AHB1ENR register.

RCC AHB1ENR Address: 0x40023830

GPIOD Enable Bit: Bit 3 (GPIODEN)

    *pClkCntrlReg = *pClkCntrlReg | 0x08;


This enables the clock for GPIOD.

### 3. GPIO Mode Configuration

Each GPIO pin uses 2 bits in the MODER register.

For PD12:

Bit positions: 24 and 25

01 → Output mode

Steps:

Clear bits 24 and 25

Set bit 24

    *pGPIODModeReg = *pGPIODModeReg & 0xFCFFFFFF;
    *pGPIODModeReg = *pGPIODModeReg | 0x01000000;

### 4. GPIO Output Data Register (ODR)

To control the output level of the pin:

ODR Address: 0x40020C14

PD12 Mask: 0x00001000

Set PD12 HIGH:

    *pGPIODopReg = *pGPIODopReg | 0x00001000;


Toggle PD12:

    *pGPIODopReg = *pGPIODopReg ^ 0x00001000;

### 5. Delay Using Software Loop

A simple blocking delay is created using a for loop.

    void delay(void)
    {
        for(uint32_t i = 0; i < 500000; i++);
    }


This controls the LED blinking speed.

### Complete Code
    
    #include<stdio.h>
    #include<stdint.h>
    
    void delay(void);
    
    int main(void)
    {
    volatile uint32_t *pClkCntrlReg = (uint32_t *)0x40023830;
    volatile uint32_t *pGPIODModeReg = (uint32_t *)0x40020C00;
    volatile uint32_t *pGPIODopReg   = (uint32_t *)0x40020C14;
    
    // Enable clock for GPIOD
    *pClkCntrlReg = *pClkCntrlReg | 0x08;
    
    // Configure PD12 as output
    *pGPIODModeReg = *pGPIODModeReg & 0xFCFFFFFF;
    *pGPIODModeReg = *pGPIODModeReg | 0x01000000;
    
    // Set PD12 high initially
    *pGPIODopReg = *pGPIODopReg | 0x00001000;
    
    while(1)
    {
        *pGPIODopReg = *pGPIODopReg ^ 0x00001000;
        delay();
    }
    }
    
    void delay(void)
    {
    for(uint32_t i = 0; i < 500000; i++);
    }

### Datasheet & Reference Manual Usage

The following information was obtained from the STM32 Datasheet and Reference Manual:

Memory map of peripherals

Base addresses of GPIO and RCC registers

Bit positions for GPIO mode and RCC enable registers

Using the datasheet, we:

Identified the base address of GPIOD

Located MODER and ODR offsets

Found the RCC AHB1ENR register to enable clocks

### Outcome

Successfully blinked an LED using pure register-level programming

Gained a deeper understanding of STM32 architecture and peripheral control

Learned how to read and use datasheets and reference manuals effectively

