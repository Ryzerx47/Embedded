# Understanding `volatile` Qualifier in Embedded C

## 📌 What I Learned Today

Today I learned about the **`volatile` qualifier** in C programming, especially how it affects **compiler optimization** and why it is extremely important in **Embedded Systems programming**.

As an Electronics and Communication Engineering student working with STM32 and interrupts, this concept is very critical for writing reliable firmware.

---

## 🔹 What is `volatile`?

The `volatile` keyword tells the compiler:

> "This variable can change at any time outside the current program flow. Do NOT optimize it."

Normally, the compiler optimizes code by:
- Removing redundant lines
- Storing variables in registers
- Skipping repeated memory access

But in embedded systems:
- Hardware registers change automatically
- Interrupt Service Routines (ISR) modify variables
- Peripherals update memory-mapped registers

So optimization can break the program logic.

That’s where `volatile` is required.

---

# 🧪 Case 1: Volatile and Compiler Optimization

## Code Used

    #include <stdint.h>
    #include<stdio.h>
    
    int main(void){
        uint8_t volatile data1;
        uint8_t volatile data2;
    
        data1 = 50;
    
        data2 = data1;
        data2 = data1;
    
        for(;;);
    }

## 🔍 What Happens Without volatile?
If volatile is removed:


The second data2 = data1; is redundant.


Compiler may remove it.


At higher optimization levels (-O1, -O2), even entire code may be removed if variables are unused.


Optimization Levels:
LevelBehavior-O0No optimization (everything compiled)-O1Removes redundant instructions-O2More aggressive optimization-O3Maximum optimization
Without volatile, the compiler assumes:

"These variables are not used meaningfully. I can remove them."


## 🔍 What Happens With volatile?
With volatile:


Every read and write happens exactly as written.


Compiler will NOT remove redundant assignments.


Compiler always accesses memory instead of registers.


So both lines:
data2 = data1;
data2 = data1;

will be compiled even in -O1.

### 🧪 Case 2: Volatile with Interrupts (Real Embedded Example)
This example demonstrates why volatile is mandatory when working with interrupts.
Platform Used
STM32F407VGTx

### 🔹 Shared Global Variable Between Main and ISR
uint8_t volatile g_button_pressed = 0;
uint32_t g_button_press_count = 0;

Why volatile is Required Here?
Because:


g_button_pressed is modified inside ISR


Main loop keeps checking it


Compiler does NOT know ISR will modify it


Without volatile, compiler may:


Cache variable in register


Never re-read it from memory


Result: Infinite loop, button press never detected



### 🔹 Memory Mapped Register Access
uint32_t volatile *pEXTTIPendReg = (uint32_t*) (0x40013C00 + 0x14);

Why volatile pointer?
Because:


These addresses map to hardware registers


Hardware changes them automatically


Compiler must read actual memory every time



### 🔹 Interrupt Handler
void EXTI0_IRQHandler(void)
{
    g_button_pressed = 1;
    *pEXTTIPendReg |= ( 1 << 0);
}

If g_button_pressed is NOT volatile:


Compiler may assume it never changes


Main loop may never detect button press



#### ⚙️ How volatile Affects Optimization
Without VolatileWith VolatileCompiler may cache variable in registerAlways reads from memoryRedundant lines removedAll reads/writes preservedFaster but riskySlightly slower but safeUnsafe for hardware/ISRSafe for hardware/ISR

## 📌 Where Should We Use volatile?
✅ Must Use:


ISR shared variables


Hardware register access


Peripheral status registers


Flags modified by DMA


Multi-threaded shared variables


❌ Do NOT Use:


Normal local variables


Variables used only inside one function


Performance-critical math variables (unless required)



## 🧠 Key Takeaways


volatile prevents unwanted compiler optimization.


It ensures every read/write happens exactly as written.


It is mandatory in:


Interrupt-based programming


Hardware register access


Embedded firmware development




Without it, embedded programs may behave unpredictably.



## 🚀 Conclusion
Today’s learning helped me understand one of the most important concepts in embedded firmware development.
As someone preparing for embedded systems and STM32-based interviews, understanding volatile is crucial because interviewers often ask:

"Why do we use volatile in embedded C?"

Now I can confidently explain:


Optimization behavior


ISR interaction


Hardware register mapping


Real-world consequences


