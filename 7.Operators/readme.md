#Operators in C
##📘 Overview

In C programming, operators are special symbols used to perform operations on variables and values.
Today, I learned about the following types of operators:

Unary Operators

Binary Operators

Ternary Operator

Logical Operators

Relational Operators

Operator Precedence and Associativity

Understanding precedence and associativity is crucial to avoid logical errors in expressions.

###🔹 1. Unary Operators

Unary operators operate on a single operand.

Common Unary Operators
Operator	Description
+	Unary plus
-	Unary minus
++	Increment
--	Decrement
!	Logical NOT
~	Bitwise NOT
&	Address-of
*	Dereference
Example

        #include <stdio.h>
        
          int main() {
          int a = 5;
          printf("a = %d\n", a);
          printf("++a = %d\n", ++a);
          printf("--a = %d\n", --a);
          return 0;
          }

###🔹 2. Binary Operators

Binary operators operate on two operands.

Common Binary Operators
Operator	Description
+	Addition
-	Subtraction
*	Multiplication
/	Division
%	Modulus
=	Assignment
Example

        #include <stdio.h>
        
        int main() {
            int x = 10, y = 3;
            printf("x + y = %d\n", x + y);
            printf("x * y = %d\n", x * y);
            return 0;
        }

###🔹 3. Ternary Operator

The ternary operator is the only operator in C that works with three operands.

Syntax
(condition) ? expression1 : expression2;

Example

    #include <stdio.h>
    
    int main() {
        int a = 10, b = 20;
        int max = (a > b) ? a : b;
        printf("Maximum value = %d\n", max);
        return 0;
    }

###🔹 4. Logical Operators

Logical operators are used to combine or invert conditions.

Logical Operators Table
Operator	Meaning
&&	Logical AND
`	
!	Logical NOT
Example

    #include <stdio.h>
    
    int main() {
        int a = 5, b = 10;
    
        if (a > 0 && b > 0) {
            printf("Both numbers are positive\n");
        }
    
        if (a > 10 || b > 5) {
            printf("At least one condition is true\n");
        }
    
        return 0;
    }

###🔹 5. Relational Operators

Relational operators compare two values and return 1 (true) or 0 (false).

Relational Operators Table
Operator	Description
==	Equal to
!=	Not equal to
>	Greater than
<	Less than
>=	Greater than or equal to
<=	Less than or equal to
Example
    
    #include <stdio.h>
    
    int main() {
        int a = 10, b = 20;
    
        printf("a == b : %d\n", a == b);
        printf("a < b  : %d\n", a < b);
        printf("a != b : %d\n", a != b);
    
        return 0;
    }

###🔹 6. Operator Precedence and Associativity
📌 Operator Precedence

Precedence determines which operator is evaluated first when multiple operators appear in an expression.

📌 Associativity

Associativity determines the direction of evaluation when operators of the same precedence appear together.

🔢 Precedence & Associativity Table (High → Low)
Precedence	Operators	Associativity
Highest	++ -- ! ~	Right to Left
	* / %	Left to Right
	+ -	Left to Right
	< <= > >=	Left to Right
	== !=	Left to Right
	&&	Left to Right
	`	
	?:	Right to Left
Lowest	=	Right to Left
🧪 Example: Precedence
#include <stdio.h>

int main() {
    int result = 10 + 5 * 2;
    printf("Result = %d\n", result);
    return 0;
}


✔ Output: 20
👉 * has higher precedence than +

🧪 Example: Associativity

    #include <stdio.h>
    
    int main() {
        int a, b, c;
        a = b = c = 5;
        printf("a = %d, b = %d, c = %d\n", a, b, c);
        return 0;
    }


✔ Assignment operator (=) has right-to-left associativity

##📌 Tip

To avoid confusion:

result = (a + b) * c;


✔ Parentheses always override precedence

##🧠 Key Learnings

Operator precedence controls evaluation order.

Operator associativity controls evaluation direction.

Misunderstanding these can lead to logical bugs.

Using parentheses improves readability and safety.
