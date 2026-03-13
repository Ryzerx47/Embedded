# Struct, Union and Bit Extraction in C

## Overview
Today I learned how **structures, unions, and bit-fields** can be used in C to **extract specific bits from a data packet**.

This concept is widely used in **embedded systems**, communication protocols, and **hardware register decoding**.

The idea is to:

1. Store the full **32-bit packet value**
2. Use a **structure with bit-fields** to define individual parts of the packet
3. Use a **union** so both representations share the **same memory**

This allows us to **write once and read multiple fields easily**.



# Structure with Bit Fields

Bit fields allow us to **extract specific numbers of bits from a variable**.

Example:
    
    struct
    {
        uint32_t crc :2;
        uint32_t status:1;
        uint32_t payload:12;
        uint32_t bat:3;
        uint32_t sensor:3;
        uint32_t long_add:8;
        uint32_t short_add:2;
        uint32_t addr_mode:1;
    };
Meaning
Field	Bits	Description
crc	2	CRC bits
status	1	Packet status
payload	12	Payload data
bat	3	Battery information
sensor	3	Sensor ID
long_add	8	Long address
short_add	2	Short address
addr_mode	1	Addressing mode

Total bits = 32 bits

## Using Union to Access Packet Data

A union allows different data types to share the same memory location.

In this example:

One member stores the entire packet

Another member interprets the packet as individual bit fields

    union packet
    {
        uint32_t packvalue;
    
        struct
        {
            uint32_t crc :2;
            uint32_t status:1;
            uint32_t payload:12;
            uint32_t bat:3;
            uint32_t sensor:3;
            uint32_t long_add:8;
            uint32_t short_add:2;
            uint32_t addr_mode:1;
        } value;
    };
## Why Union is Useful

When we write:

pack.packvalue = 0x12345678;

the same memory is automatically interpreted as:

pack.value.crc
pack.value.status
pack.value.payload
...

So the union helps us decode packet data without manually shifting bits.

Complete Program

    #include<stdio.h>
    #include<stdint.h>
    
    union packet
    {
        uint32_t packvalue;
    
        struct
        {
            uint32_t crc :2;
            uint32_t status:1;
            uint32_t payload:12;
            uint32_t bat:3;
            uint32_t sensor:3;
            uint32_t long_add:8;
            uint32_t short_add:2;
            uint32_t addr_mode:1;
        } value;
    };
    
    int main()
    {
        union packet pack;
    
        printf("Enter the packetvalue \n");
        fflush(stdout);
    
        scanf("%x",&pack.packvalue);
    
        printf("CRC = %X\n",pack.value.crc);
        printf("Status = %X\n",pack.value.status);
        printf("Payload = %X\n",pack.value.payload);
        printf("Battery = %X\n",pack.value.bat);
        printf("Sensor = %X\n",pack.value.sensor);
        printf("Long Address = %X\n",pack.value.long_add);
        printf("Short Address = %X\n",pack.value.short_add);
        printf("Address Mode = %X\n",pack.value.addr_mode);
    
        printf("Size of union = %d",sizeof(pack));
    }
### How It Works

Step 1
User enters a 32-bit hexadecimal packet

0x12345678

Step 2
Value is stored in

pack.packvalue

Step 3
Because of the union, the same memory is also accessed as:

pack.value.crc
pack.value.status
pack.value.payload
...

So the bit fields automatically extract specific bits.

Memory Representation
32-bit Packet
------------------------------------------------
|CRC|Status|Payload|Bat|Sensor|Long|Short|Mode|
------------------------------------------------
 2    1      12      3    3      8     2     1
## Advantages of This Approach

✔ No manual bit shifting
✔ Easy packet decoding
✔ Cleaner code
✔ Common in embedded systems
✔ Useful for hardware register mapping

Embedded Systems Usage

This technique is commonly used in:

Communication protocol decoding

Sensor data packets

Network packet parsing

Microcontroller register access

Low-level embedded programming

## What I Learned

Structures group multiple variables together

Unions share the same memory among members

Bit fields allow bit-level extraction

Union + Struct helps decode packets efficiently

This technique is widely used in embedded systems programming
