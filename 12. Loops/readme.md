# 🔁 Understanding Loops in Embedded C
## 📅 What I Learned Today

Today I learned about loops in Embedded C and how they are used to execute a block of code repeatedly based on a condition.

Loops are very important in embedded systems because they are used for:

Continuous monitoring of sensors

Generating delays

LED blinking

Polling hardware registers

Running infinite super loops (while(1)) in microcontrollers

I explored three types of loops:

while loop

do-while loop

for loop

### 🔹 1️⃣ While Loop

📌 Syntax:

      while(condition)
      {
      // code to execute
      }

✅ Key Points:

Condition is checked before executing the loop.

If condition is false initially, the loop will not execute.

Commonly used in embedded systems as while(1) for infinite loop.

💻 Example (LED Blink Simulation):

    #include <stdio.h>
    
    int main()
    {
        int count = 0;
    
        while(count < 5)
        {
            printf("LED ON\n");
            printf("LED OFF\n");
            count++;
        }
    
        return 0;
    }

### 🔹 2️⃣ Do-While Loop
📌 Syntax:

    do
    {
        // code to execute
    }
    while(condition);


✅ Key Points:

Condition is checked after execution.

Loop runs at least one time, even if condition is false.

💻 Example:

    #include <stdio.h>
    
    int main()
    {
        int count = 0;
    
        do
        {
            printf("System Running...\n");
            count++;
        }
        while(count < 3);
    
        return 0;
    }

### 🔹 3️⃣ For Loop
📌 Syntax:

    for(initialization; condition; increment/decrement)
    {
        // code to execute
    }

✅ Key Points:

Best when the number of iterations is known.

Initialization, condition, and update are written in one line.

Frequently used for delay loops in embedded programming.

💻 Example:

    #include <stdio.h>
    
    int main()
    {
        for(int i = 0; i < 5; i++)
        {
            printf("Blink %d\n", i);
        }
    
        return 0;
    }

### 🔁 Infinite Loop in Embedded Systems

In microcontrollers like STM32, Arduino, etc., programs usually run inside an infinite loop:

    int main(void)
    {
        while(1)
        {
            // Main super loop
            // Read sensor
            // Process data
            // Control output
        }
    }
    

This is called the Super Loop Architecture.

🧠 Difference Between Loops
Feature	while	do-while	for
Condition Check	Before execution	After execution	Before execution
Runs at least once?	❌ No	✅ Yes	❌ No
Best Used When	Condition-based loops	At least one execution needed	Fixed iteration count

## 🎯 Conclusion

Today I understood:

How loops control repetitive execution

The difference between while, do-while, and for

Why infinite loops are important in embedded systems

How loops are used in LED blinking and delays

Loops are fundamental in Embedded C because almost every microcontroller program depends on repetitive execution.
