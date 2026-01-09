<h1>📌 Understanding Pointers, Addresses, and Memory Access in C</h1>

<h2>🧠 Objective</h2>

This program documents my learning journey in C programming, focusing on:

How variables are stored in memory

How to print a variable’s address correctly

How pointers work internally

How to read and write values using pointers

The goal was to remove confusion between values, addresses, and pointers and understand how C interacts with memory at a low level.

<h2>📂 Code Overview</h2>
#include <stdio.h>

int main(void){
    char x = 100;

    printf("Value of x = %d \n", x);
    printf("Address of x %p \n", (void*)&x);

    char* p_address = &x;
    char data = *p_address;
    printf("read value from pointer address %d \n", data);

    *p_address = 65;
    printf("Written value %d", x);

    return 0;
}

<h2>🔍 Key Concepts Learned</h2>

<h3>1️⃣ Difference Between Value and Address</h3>

x holds the value 100

&x gives the memory address where x is stored

C does not expose addresses automatically — we must explicitly use &

printf("Value of x = %d \n", x);
printf("Address of x %p \n", (void*)&x);

<h3>2️⃣ Why %p Needs (void *)</h3>

%p is designed to print a generic pointer

printf is a variadic function → no type checking

Casting to (void *) makes the code standard-compliant and portable

printf("%p\n", (void*)&x);

<h3>3️⃣ Pointer Declaration and Initialization</h3>
char* p_address = &x;


p_address stores the address of x

Pointer type (char*) tells the compiler:

How many bytes to read/write

How dereferencing should behave

<h3>4️⃣ Dereferencing a Pointer (Reading Data)</h3>
char data = *p_address;


*p_address accesses the value stored at that address

This reads the same value as x

Output:

read value from pointer address 100

<h3>5️⃣ Writing Data Using a Pointer</h3>
*p_address = 65;


Modifies the memory where x is stored

65 corresponds to ASCII 'A'

Since p_address points to x, modifying *p_address updates x

printf("Written value %d", x);


Output:

Written value 65

<h2>🧩 Important Observations</h2>

&x is not a pointer variable, it is an address expression

A pointer exists only when the address is stored in a pointer variable

Pointer type does not change the address, it changes how memory is interpreted

Reading and writing through pointers directly affects the original variable

<h2>🚫 Common Mistakes I Avoided</h2>

Using %d to print addresses (incorrect)

Assigning multi-character constants like '100' to char

Printing pointers without casting to void *

<h2>📚 Summary</h2>

This exercise helped me clearly understand:

How memory addressing works in C

Why pointers are necessary for indirect memory access

How dereferencing enables both reading and writing data

The importance of correct format specifiers in printf
