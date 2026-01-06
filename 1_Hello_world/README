#📡 ITM Debug Output & Serial Monitor Usage
##📌 Overview

This repository documents my learning and experimentation with ITM (Instrumentation Trace Macrocell) for debugging in embedded systems.
The project demonstrates how printf() output can be redirected through ITM and observed using a Serial Monitor / SWV viewer, along with an important detail about buffer flushing.
 🔍 What is ITM?

ITM (Instrumentation Trace Macrocell) is a debugging feature available in ARM Cortex-M cores.
It allows developers to send debug messages (like printf) through the SWD interface without using UART pins, making it extremely useful during development.

##🖥️ Using printf() with ITM

In this project, printf() is redirected to the ITM stimulus port so that messages appear in the Serial Monitor / SWV console.

However, an important behavior was observed:

printf() output does not appear immediately unless the output buffer is flushed.

###⚠️ Important Note on Buffer Flushing

When using ITM for printf() debugging, the output is buffered.
To ensure messages appear in the Serial Monitor, the buffer must be flushed using one of the following methods:

✔ Method 1: Newline Character

Adding a newline character \n at the end of the printf() statement forces the buffer to flush:

printf("Hello from ITM\n");

✔ Method 2: Manual Buffer Flush

Explicitly flushing the standard output buffer:

printf("Hello from ITM");
fflush(stdout);


Without either of these, the Serial Monitor may not display the output.

##🧠 Key Learnings

ITM is a powerful alternative to UART-based debugging

printf() output through ITM is buffered

Buffer flushing is mandatory for real-time visibility

\n or fflush(stdout); ensures immediate output
