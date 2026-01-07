<h1>📘 Understanding Floating-Point Variables in C</h1>

Today, I learned about floating-point data types in C, specifically:

Single precision (float)

Double precision (double)

How floating-point numbers are stored internally using the IEEE-754 standard

The role of Sign, Exponent, and Mantissa (Fraction)

<h2>🔢 Floating-Point Data Types in C</h2>

C provides two commonly used floating-point types:

Data Type	Size	Precision	Typical Use
float	4 bytes (32-bit)	~6–7 decimal digits	Memory-efficient calculations
double	8 bytes (64-bit)	~15–16 decimal digits	High-precision calculations

<h3>📦 Single Precision (float) – 32 bits</h3>
Field	Bits
Sign	1 bit
Exponent	8 bits
Mantissa (Fraction)	23 bits

Exponent Bias = 127

Used for faster and memory-efficient operations

<h3>📦 Double Precision (double) – 64 bits</h3>
Field	Bits
Sign	1 bit
Exponent	11 bits
Mantissa (Fraction)	52 bits

Exponent Bias = 1023

Provides higher accuracy and range

</h2>🧾 Meaning of Each Field</h2>

Sign Bit

0 → Positive number

1 → Negative number

Exponent

Stores the power of 2 (biased form)

Mantissa (Fraction)

Stores the significant digits of the number


<h2>✅ Key Takeaways</h2>

float uses less memory but has lower precision

double provides higher accuracy

Floating-point values are stored using sign, exponent, and mantissa

Precision issues occur due to binary representation limitations

<h2>📌 Conclusion</h2>

Understanding how floating-point numbers work internally helps avoid:

Precision errors

Incorrect comparisons

Unexpected results in embedded systems and numerical applications
