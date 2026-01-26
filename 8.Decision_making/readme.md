# Decision Making in Embedded C

## 📌 Overview
This repository documents my learning on **decision-making constructs in Embedded C**.  
Decision-making statements allow a program to choose different execution paths based on conditions, which is essential in embedded systems for control logic, validation, and real-time responses.

The following concepts were covered and implemented using practical C programs:

- `if`
- `if–else`
- `if–else if–else`
- `switch–case`
- Conditional (ternary) operator `?`
- Input validation using conditions

---

## 🧠 Concepts Learned

### 1️⃣ `if` Statement
- Executes a block of code only when a condition is true.
- Commonly used for **simple checks** like eligibility or threshold validation.

---

### 2️⃣ `if–else` Statement
- Provides an alternate execution path when the condition is false.
- Useful for **binary decisions**.

---

### 3️⃣ `if–else if–else` Ladder
- Used when **multiple conditions** need to be checked sequentially.
- Conditions are evaluated from top to bottom.
- The first true condition executes.

---

### 4️⃣ `switch–case`
- Used when a variable needs to be compared against **multiple constant values**.
- Improves readability and performance compared to multiple `if–else` statements.
- Common in **menu-driven programs** and state machines.

---

### 5️⃣ Conditional (Ternary) Operator `?`
- A compact form of `if–else`.
- Syntax:
  ```c
  condition ? expression1 : expression2;

## 🧪 Programs Implemented
### 🔹 1. Area Calculation Using switch–case

Concepts Used:

switch–case

User input handling

Mathematical logic

Description:
Based on the shape entered by the user (t, z, c, s, r), the program calculates the area of:

Triangle

Trapezoid

Circle

Square

Rectangle

Key Learning:

switch–case is ideal when selecting operations based on a single variable.

break prevents fall-through.

default handles invalid input.

### 🔹 2. Income Tax Calculation Using if–else if–else

Concepts Used:

if–else if–else

Type casting (double → uint64_t)

Range-based condition checks

Description:

Reads income as a floating-point value.

Casts it to an integer type.

Calculates tax based on income slabs.

Key Learning:

Order of conditions is critical.

Type conversion is important in embedded systems to avoid precision issues.

Logical operators (&&) for range checks.

### 🔹 3. Voting Eligibility Using if

Concepts Used:

Simple if condition

Description:

Checks whether the entered age is greater than or equal to 18.

Displays voting eligibility.

Key Learning:

Minimal decision logic.

Suitable for validation checks in embedded applications.

### 🔹 4. Number Comparison with Input Validation

Concepts Used:

if, if–else, else

Input validation using scanf() return value

Integer vs floating-point comparison

Description:

Accepts two floating-point numbers.

Validates input.

Converts them to integers.

Compares only the integer part and displays the result.

Key Learning:

scanf() return value can be used for error detection.

Floating-point values may behave differently when cast to integers.

Conditional logic helps handle edge cases.

## 🛠 Embedded C Practices Followed

Used fflush(stdout) to ensure prompt output (important in embedded debugging)

Explicit type casting for predictable behavior

Defensive programming with input validation

Structured and readable decision logic

## ✅ Conclusion

Through these programs, I gained hands-on experience with decision-making constructs in Embedded C, which are fundamental for:

Control flow

User interaction

Input validation

Real-time embedded logic

These concepts form the backbone of embedded firmware development and are critical for writing reliable and maintainable code.
