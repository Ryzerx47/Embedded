### 📅 What I Learned Today

Today I implemented internal pin reading on an STM32 microcontroller using direct register programming (bare-metal approach) without using HAL libraries.

I configured:

GPIOA Pin 0 → Input pin (to read switch state)

GPIOD Pin 12 → Output pin (to control LED)

Used IDR (Input Data Register) to read pin status

Used ODR (Output Data Register) to control LED

Enabled peripheral clocks manually using RCC register

This helped me understand how microcontroller peripherals work at register level.

### 🧠 Microcontroller Used

Board: STM32F4 Discovery

MCU: STM32F407

Programming Method: Direct Register Access

IDE: STM32CubeIDE

## ⚙️ Registers Used
Register	Address	Purpose
RCC AHB1ENR	0x40023830	Enable GPIO clocks
GPIOA_MODER	0x40020000	Configure PA0 mode
GPIOD_MODER	0x40020C00	Configure PD12 mode
GPIOA_IDR	0x40020010	Read input from PA0
GPIOD_ODR	0x40020C14	Write output to PD12


### 🔍 Step-by-Step Explanation

## 1️⃣ Enable Clock for GPIOA and GPIOD

    *pClkCntrlReg = *pClkCntrlReg | (1<<0);  // Enable GPIOA clock
    *pClkCntrlReg = *pClkCntrlReg | (1<<3);  // Enable GPIOD clock


Bit 0 → GPIOA

Bit 3 → GPIOD

## 2️⃣ Configure Pin Modes

Each GPIO pin uses 2 bits in the MODER register.

➤ Set PA0 as Input (00)

    *pGPIOAModeReg = *pGPIOAModeReg & (~(1<<0));
    *pGPIOAModeReg = *pGPIOAModeReg & (~(1<<1));


➤ Set PD12 as Output (01)

Clear bits 24 & 25, then set bit 24:

    *pGPIODModeReg = *pGPIODModeReg & (~(1<<24));
    *pGPIODModeReg = *pGPIODModeReg & (~(1<<25));
    *pGPIODModeReg = *pGPIODModeReg | (1<<24);
    

## 3️⃣ Read Input and Control LED

    while(1){
        if(*pGPIOAIdReg & (1<<0)){
            *pGPIODopReg = *pGPIODopReg | (1<<12);
        }
        else{
            *pGPIODopReg = *pGPIODopReg & (~(1<<12));
        }
    }

✔ Logic:

If PA0 = HIGH → Turn ON LED (PD12)

If PA0 = LOW → Turn OFF LED

### 🔁 Working Principle

Button connected to PA0

Program continuously checks IDR register

If bit 0 is HIGH → ODR bit 12 is set

LED connected to PD12 glows

This is called internal pin read because:

The MCU reads the pin status internally using the IDR register

No external peripheral library is used

Pure register-level programming

### 💡 Key Concepts Understood

Memory mapped peripheral registers

Bitwise operations (|, &, ~, <<)

GPIO MODER configuration

IDR vs ODR difference

Infinite polling method

Bare-metal programming approach

### 🚀 What This Improved

Better understanding of microcontroller architecture

Confidence in debugging at register level

Strong foundation for Embedded Systems interviews

Understanding how HAL internally works

📂 Code Used

    #include<stdio.h>
    #include<stdint.h>
    void delay(void);
    int main(void)
    {
    	volatile uint32_t *pClkCntrlReg = (uint32_t *)0x40023830;
    	volatile uint32_t *pGPIOAModeReg  = (uint32_t*)0x40020000;
    	volatile uint32_t *pGPIODModeReg = (uint32_t *)0x40020C00;
    	volatile uint32_t *pGPIOAIdReg    = (uint32_t*)0x40020010;
    	volatile uint32_t *pGPIODopReg = (uint32_t *)0x40020C14;
    
    	*pClkCntrlReg = *pClkCntrlReg|(1<<0);
    	*pClkCntrlReg = *pClkCntrlReg|(1<<3);
    
    	*pGPIODModeReg = *pGPIODModeReg &(~(1<<24));
    	*pGPIODModeReg = *pGPIODModeReg &(~(1<<25));
    	*pGPIOAModeReg = *pGPIOAModeReg &(~(1<<0));
    	*pGPIOAModeReg = *pGPIOAModeReg &(~(1<<1));
    
    	*pGPIODModeReg = *pGPIODModeReg |(1<<24);
    
    	while(1){
    		if(*pGPIOAIdReg &(1<<0)){
    			*pGPIODopReg = *pGPIODopReg|(1<<12);
    		}
    		else{
    			*pGPIODopReg = *pGPIODopReg&(~(1<<12));
    		}
    	}
    }

### 📌 Conclusion

Today I successfully implemented GPIO input reading and output control using register-level programming on STM32.

This strengthens my foundation in:

Embedded C

GPIO configuration

Bit manipulation

Bare-metal firmware development
