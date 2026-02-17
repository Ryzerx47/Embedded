# 📘 GPIO Input Using PUPDR Register & Optimization Observation

## 📅 What I Learned Today

Today I implemented GPIO pin reading using the PUPDR (Pull-Up/Pull-Down Register) in STM32 (STM32F407VGTx).

Previously, I read the pin state directly.
In this program, I properly configured the PUPDR register to control the default logic level of the input pin.

I also explored compiler optimization levels, and observed how higher optimization (-O2) affected the functionality of the program.

## 🎯 Objective

Configure GPIOA Pin 0 as input (Button)

Configure GPIOD Pin 12 as output (LED)

Use PUPDR register to enable internal pull-down

Read button state using IDR (Input Data Register)

Turn LED ON/OFF based on button press

### 🧠 Registers Used

Register	Purpose

RCC AHB1ENR	Enable clock for GPIOA & GPIOD
GPIOx_MODER	Configure pin mode
GPIOx_PUPDR	Configure pull-up / pull-down
GPIOx_IDR	Read input state
GPIOx_ODR	Control output state


### ⚙️ PUPDR Configuration

Each GPIO pin uses 2 bits in the PUPDR register:

00 → No pull-up, no pull-down

01 → Pull-up

10 → Pull-down

11 → Reserved

For GPIOA Pin 0, I configured it as Pull-Down (10):

    *pGPIOAPUPDRReg &= (~(1<<0));
    *pGPIOAPUPDRReg &= (~(1<<1));
    *pGPIOAPUPDRReg |= (1<<1);   // 10 → Pull-down enabled

### 🔎 Behavior

Button not pressed → Input reads 0

Button pressed → Input reads 1

LED turns ON when button is pressed

### 💻 Code
    
    #include<stdio.h>
    #include<stdint.h>
    
    int main(void)
    {
    	uint32_t *pClkCntrlReg = (uint32_t *)0x40023830;
    	uint32_t *pGPIOAModeReg  = (uint32_t*)0x40020000;
    	uint32_t *pGPIODModeReg = (uint32_t *)0x40020C00;
    	uint32_t *pGPIOAPUPDRReg    = (uint32_t*)0x4002000C;
    	uint32_t *pGPIOAIdReg    = (uint32_t*)0x40020010;
    	uint32_t *pGPIODopReg = (uint32_t *)0x40020C14;
    
    	// Enable clock for GPIOA and GPIOD
    	*pClkCntrlReg |= (1<<0);
    	*pClkCntrlReg |= (1<<3);
    
    	// Configure GPIOD Pin 12 as output
    	*pGPIODModeReg &= ~(1<<24);
    	*pGPIODModeReg &= ~(1<<25);
    	*pGPIODModeReg |= (1<<24);
    
    	// Configure GPIOA Pin 0 as input
    	*pGPIOAModeReg &= ~(1<<0);
    	*pGPIOAModeReg &= ~(1<<1);
    
    	// Configure Pull-Down for GPIOA Pin 0
    	*pGPIOAPUPDRReg &= ~(1<<0);
    	*pGPIOAPUPDRReg &= ~(1<<1);
    	*pGPIOAPUPDRReg |= (1<<1);
    
    	while(1)
    	{
    		if(*pGPIOAIdReg & (1<<0))
    		{
    			*pGPIODopReg |= (1<<12);
    		}
    		else
    		{
    			*pGPIODopReg &= ~(1<<12);
    		}
    	}
    }

## 🚀 Optimization Observation

I tested the program with different compiler optimization levels:

-O0 → Worked correctly

-O1 → Worked correctly

-O2 → Did NOT function as expected

## 🔎 What I Observed

At -O2 optimization:

The compiler tries to increase execution speed.

It reduces redundant operations.

It may skip repeated memory access checks.

This caused the LED behavior to change or not respond correctly.

This showed me that:

Higher optimization improves speed and reduces size, but sometimes it can affect hardware-interacting code.

## 🔥 Key Takeaways

Learned how to configure GPIO PUPDR register

Understood pull-down configuration logic

Successfully read button state using IDR

Observed real impact of compiler optimization

Learned that optimization levels must be used carefully in embedded systems

## 📌 Conclusion

Today I improved my understanding of:

Register-level GPIO configuration

Internal pull-up/pull-down behavior

Input reading logic

Effects of compiler optimization on embedded programs
