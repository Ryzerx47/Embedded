# Bitfields Using Struct in Embedded C (STM32)

## 📘 What I Learned

Today I learned how **bitfields can be used with structures in C** to access **individual bits of hardware registers** in embedded systems.

Instead of using **bitwise operations and masks**, we can define **bitfields inside a struct** that directly represent the register layout.
This makes the code **more readable and easier to understand**.

This example demonstrates controlling an **LED connected to GPIOD Pin 12** of the STM32 using **bitfield structures**.

---

# 📌 Concept: Bitfields in C

Bitfields allow us to define the **exact number of bits** used by a variable inside a structure.

Example:

```c
uint32_t gpiod_en :1;
```

This means:

* `gpiod_en` occupies **1 bit**
* It directly maps to a **specific bit of the register**

This is very useful in **embedded systems**, where registers contain multiple control bits.

---

# 📌 Registers Used

### RCC_AHB1ENR

Used to **enable the clock for GPIO peripherals**.

Example bit:

```
gpiod_en : 1 bit
```

Setting this to **1 enables the clock for GPIOD**.

---

### GPIO_MODER

Controls the **mode of GPIO pins**.

Each pin uses **2 bits**:

| Value | Mode               |
| ----- | ------------------ |
| 00    | Input              |
| 01    | Output             |
| 10    | Alternate Function |
| 11    | Analog             |

Example:

```
pin_12 : 2 bits
```

Setting it to `01` makes **Pin 12 Output Mode**.

---

### GPIO_ODR

Used to **write output data to GPIO pins**.

Each pin uses **1 bit**.

```
pin_12 : 1 bit
```

Setting it to `1` turns **LED ON**.

Setting it to `0` turns **LED OFF**.

---

# 📂 Project Structure

```
├── main.c
└── main.h
```

---

# 📄 main.c

```c
#include "main.h"
#include <stdint.h>
#include <stdio.h>

void delay();

int main(void)
{
	RCC_AHB1ENR_t volatile *const pClkCntrlReg = (RCC_AHB1ENR_t*) 0x40023830;
	GPIO_MODER_t   volatile *const pGPIODModeReg = (GPIO_MODER_t*) 0x40020C00;
	GPIO_ODR_t  volatile *const pGPIODopReg = (GPIO_ODR_t*) 0x40020C14;

	// Enable clock for GPIOD
	pClkCntrlReg -> gpiod_en = 1;

	// Configure GPIOD Pin 12 as output
	pGPIODModeReg -> pin_12 = 1;

	while(1)
	{
		pGPIODopReg -> pin_12 = 1;
		delay();

		pGPIODopReg -> pin_12 = 0;
		delay();
	}
}

void delay()
{
	for(int i = 0; i < 300000; i++)
	{
	}
}
```

---

# 📄 main.h

```c
#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

typedef struct{
	uint32_t gpioa_en :1;
	uint32_t gpiob_en :1;
	uint32_t gpioc_en :1;
	uint32_t gpiod_en :1;
	uint32_t gpioe_en :1;
	uint32_t gpiof_en :1;
	uint32_t gpiog_en :1;
	uint32_t gpioh_en :1;
	uint32_t gpioi_en :1;
	uint32_t res_1 :3;
	uint32_t crcen :1;
	uint32_t res_2 :5;
	uint32_t bkpsramen :1;
	uint32_t res_3 :1;
	uint32_t CCMDATARAMEN :1;
	uint32_t DMA1EN :1;
	uint32_t DMA2EN :1;
	uint32_t res_4 :2;
	uint32_t ETHMACEN :1;
	uint32_t ETHMACTXEN :1;
	uint32_t ETHMACRXEN :1;
	uint32_t ETHMACPTPEN :1;
	uint32_t OTGHSEN :1;
	uint32_t OTGHSULPIEN :1;
	uint32_t res_5 :1;
} RCC_AHB1ENR_t;

typedef struct{
	uint32_t pin_0 :2;
	uint32_t pin_1 :2;
	uint32_t pin_2 :2;
	uint32_t pin_3 :2;
	uint32_t pin_4 :2;
	uint32_t pin_5 :2;
	uint32_t pin_6 :2;
	uint32_t pin_7 :2;
	uint32_t pin_8 :2;
	uint32_t pin_9 :2;
	uint32_t pin_10 :2;
	uint32_t pin_11 :2;
	uint32_t pin_12 :2;
	uint32_t pin_13 :2;
	uint32_t pin_14 :2;
	uint32_t pin_15 :2;
} GPIO_MODER_t;

typedef struct{
	uint32_t pin_0 :1;
	uint32_t pin_1 :1;
	uint32_t pin_2 :1;
	uint32_t pin_3 :1;
	uint32_t pin_4 :1;
	uint32_t pin_5 :1;
	uint32_t pin_6 :1;
	uint32_t pin_7 :1;
	uint32_t pin_8 :1;
	uint32_t pin_9 :1;
	uint32_t pin_10 :1;
	uint32_t pin_11 :1;
	uint32_t pin_12 :1;
	uint32_t pin_13 :1;
	uint32_t pin_14 :1;
	uint32_t pin_15 :1;
	uint32_t res :16;
} GPIO_ODR_t;

#endif
```

---

# ⚙️ How the Program Works

### Step 1 — Enable GPIO Clock

```
pClkCntrlReg -> gpiod_en = 1;
```

This enables the **clock for Port D**.

---

### Step 2 — Configure Pin Mode

```
pGPIODModeReg -> pin_12 = 1;
```

This sets **Pin 12 as Output Mode**.

---

### Step 3 — Toggle LED

```
pGPIODopReg -> pin_12 = 1;
```

LED ON

```
pGPIODopReg -> pin_12 = 0;
```

LED OFF

---

# 💡 Advantages of Using Bitfields

✔ Cleaner code
✔ Easier register access
✔ No need for manual bit masking
✔ Register layout becomes readable

---

# ⚠️ Important Note

Bitfields are **compiler dependent**, so they should be used carefully in embedded systems where **exact memory layout matters**.

However, they are very useful for **learning and register visualization**.

---

# 🚀 Outcome

Using **bitfields with structures**, I successfully controlled an **LED connected to STM32 GPIOD Pin 12**.

This helped me understand:

* Register mapping
* Memory-mapped peripherals
* Bit level register control
* Cleaner embedded C coding

---

⭐ This project helped me understand how **hardware registers can be represented using C structures with bitfields**.
