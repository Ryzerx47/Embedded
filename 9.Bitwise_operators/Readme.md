# Bitwise Operators in C (Embedded Systems)

## 📌 Overview
This repository documents my learning of **bitwise operators in C** and how they are used in **embedded systems programming**.  
Bitwise operations work directly at the **bit level**, making them extremely useful for **hardware control, register manipulation, flags, and memory-efficient logic**.

All programs are written and tested using standard C libraries.

---

## 🔹 Bitwise Operators Covered

| Operator | Name        | Description |
|--------|------------|-------------|
| `&`    | AND         | Sets bit to 1 only if both bits are 1 |
| `\|`   | OR          | Sets bit to 1 if at least one bit is 1 |
| `^`    | XOR         | Sets bit to 1 if bits are different |
| `~`    | NOT         | Inverts all bits (1 → 0, 0 → 1) |

---

## 🧠 Why Bitwise Operators Matter in Embedded C
- Direct control of **hardware registers**
- Efficient **flag checking**
- Setting and clearing **specific bits**
- Faster execution compared to arithmetic operations
- Reduced memory usage

---

## 🧪 Programs Implemented

---

### 1️⃣ Basic Bitwise Operations
This program performs **AND, OR, XOR, and NOT** on two user-provided integers.


    c = a & b;   // Bitwise AND
    c = a | b;   // Bitwise OR
    c = a ^ b;   // Bitwise XOR
    c = ~a;      // Bitwise NOT


#### 📌 Key Learning

Bitwise operations work on the binary representation of numbers

~ produces a 2’s complement result for signed integers

### 2️⃣ Even or Odd Using Bitwise AND

Checks whether a number is even or odd using (a & 1).

    if ((a & 1) == 0)
        // Even number
    else
        // Odd number
    

#### 📌 Why this works

The LSB (Least Significant Bit) determines even or odd

Faster and more efficient than % operator

### 3️⃣ Setting Specific Bits Using OR (|)

Sets specific bits using a bitmask (0x90).

    a | 0x90


#### 📌 What this does

0x90 = 10010000 (binary)

OR operation forces selected bits to 1

Used to enable features or flags

### 4️⃣ Clearing Bits Using AND (&) with Mask

Clears the 4th, 5th, and 6th bits using a predefined mask.

    a & 0x8F


#### 📌 Explanation

0x8F = 10001111

Bits 4, 5, 6 become 0

Common technique in register manipulation

### 5️⃣ Clearing Bits Using AND (&) with NOT (~) and Left Shift

A more flexible and readable approach using bit shifting.

    a & ~(7 << 4)


#### 📌 Step-by-step logic

7 → 111 (binary)

7 << 4 shifts to bits 4, 5, 6

~ inverts the mask

& clears only the required bits

✔️ Best practice in embedded systems

## 🧩 Key Takeaways

Bitwise operators operate at bit level

Masking is essential for safe hardware access

(a & 1) is a fast method to check even/odd

| is used to set bits

& with masks or ~ is used to clear bits

Left shift (<<) helps create dynamic masks

## 🚀 Applications in Embedded Systems

GPIO register control

Peripheral configuration

Status flag handling

Power-efficient programming

Communication protocols (SPI, I2C, UART)
