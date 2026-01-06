<h1>📘 Understanding the Build Process (C → ELF / BIN)</h1>

<h2>📅 What I Learned Today</h2>

Today, I learned how a C source file (.c) is transformed into an executable file (.elf or .bin) through the build process used in embedded systems and software development.

This process is handled by the compiler toolchain and happens in multiple stages.

<h2>🔄 Overview of the Build Flow</h2>
.c  →  Preprocessor  →  Compiler  →  Assembler  →  Linker  →  .elf  →  .bin


Each stage has a specific responsibility.

<h3>1️⃣ Preprocessing (.c → .i)</h3>

Handles all preprocessor directives

#include

#define

#if / #ifdef

Removes comments

Expands macros

📄 Output file: .i (expanded C code)

<h3>2️⃣ Compilation (.i → .s)</h3>

Converts high-level C code into assembly code

Performs:

Syntax checking

Type checking

Basic optimizations

📄 Output file: .s (assembly instructions)

<h3>3️⃣ Assembly (.s → .o)</h3>

Converts assembly instructions into machine code

Generates relocatable object file

📄 Output file: .o (object file)

<h3>4️⃣ Linking (.o → .elf)</h3>

Combines multiple object files

Resolves:

Function calls

Global variables

Links startup code and libraries

Assigns memory addresses using a linker script

📄 Output file: .elf (Executable and Linkable Format)

<h3>✅ The .elf file contains:</h3>

Code

Data

Debug symbols (very useful for debugging)

<h3>5️⃣ Binary Generation (.elf → .bin / .hex)</h3>

Extracts raw machine code from the .elf

Removes debug information

Produces a file suitable for flashing to hardware

📄 Output files:

.bin → Raw binary

.hex → Intel HEX format

<h2>🧠 Why This Is Important (Embedded Perspective)</h2>

Helps understand memory layout

Useful for debugging linker errors

Explains why .elf is used for debugging and .bin for flashing

Essential knowledge for STM32 / ARM / Embedded C development

🛠️ Common Tools Involved

GCC / ARM-GCC

Linker Script (.ld)

Objcopy (for .bin / .hex generation)

<h2>✅ Summary</h2>

.c → Human-readable source code

.elf → Debug-ready executable

.bin → Flash-ready firmware

Understanding this pipeline makes embedded development less magical and more logical 🚀
