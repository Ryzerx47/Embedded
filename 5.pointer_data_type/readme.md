<h1>📌 Pointer Type Casting, Pointer Arithmetic & Memory Interpretation in C</h1>

<h2>📖 Overview</h2>

This project demonstrates how different pointer data types interpret the same memory location differently in C, and how pointer arithmetic (address + 1) behaves based on the pointer type.

A single long long int variable is accessed using:

unsigned char*

unsigned short*

int*

long long*

Although all pointers point to the same base address, the value read and pointer movement differ due to:

Pointer data type size

Little-endian memory representation

C pointer arithmetic rules

<h2>🧠 Concepts Covered</h2>

<h3>🔹 1. Pointer Data Type Defines Memory Access Size</h3>

The data type of a pointer determines how many bytes are read from memory.

Pointer Type	Bytes Read
char* / unsigned char*	1 byte
short* / unsigned short*	2 bytes
int*	4 bytes
long long*	8 bytes

<h3>🔹 2. Pointer Arithmetic (address + 1)</h3>

When +1 is added to a pointer, C does not increment the address by 1 byte directly.
Instead, it increments by the size of the data type the pointer points to.

Pointer Type	ptr + 1 moves by
char*	1 byte
short*	2 bytes
int*	4 bytes
long long*	8 bytes

📌 Key Rule:

Pointer arithmetic is always scaled by sizeof(pointer_type).

<h3>🔹 3. Little-Endian Memory Representation</h3>

Most modern processors (x86, ARM) follow little-endian architecture, where:

The least significant byte (LSB) is stored at the lowest memory address

For the value:

0x123456789ABCDEFF


Memory layout (low → high address):

FF DE BC 9A 78 56 34 12

<h2>🧪 Source Code</h2>
  
    #include <stdio.h>
    
    long long int data = 0x123456789ABCDEFF;
    
    int main(){
    
    unsigned char *paddress_1 = (unsigned char*)&data;
    printf("Value at %p is %x\n", paddress_1, *paddress_1);
    
    int *paddress_2 = (int*)&data;
    printf("Value at %p is %x\n", paddress_2, *paddress_2);
    
    unsigned short *paddress_3 = (unsigned short*)&data;
    printf("Value at %p is %x\n", paddress_3, *paddress_3);
    
    long long *paddress_4 = &data;
    printf("Value at %p is %I64x\n", paddress_4, *paddress_4);
    
    return 0;
    }

<h3>🖥️ Output</h3>
Value at 00403008 is ff
Value at 00403008 is 9abcdeff
Value at 00403008 is deff
Value at 00403008 is 123456789abcdeff

<h3>🔍 Output Explanation</h3>
Pointer Type	Bytes Read	Value Read	Explanation
unsigned char*	1	ff	Reads only the lowest byte
unsigned short*	2	deff	Reads 2 bytes
int*	4	9abcdeff	Reads 4 bytes
long long*	8	123456789abcdeff	Reads full 8-byte value

✔ Same address
✔ Different pointer types
✔ Different interpretations

<h2>⚠️ Important Notes</h2>

Pointer type casting does not change memory

It only changes how memory is accessed

Improper pointer casting may cause:

Alignment issues

Undefined behavior

This technique is mainly used for learning and debugging

<h2>✅ Conclusion</h2>

This experiment clearly shows that:

Pointer type controls both memory access size and address movement.
