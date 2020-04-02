
# Expression / Notación
Convert infix expression to postfix and evaluate a postfix expression.

## Objective
Understand the concept of stack and use their operations to solve problems.

## Introduction
I did this implementation for my _Linear Data Structures_ course. By using a stack we can easily convert infix expression to postfix. At the same time, evaluate a postfix expression  with the help a stack is really easy. This become posible by knowing the features of a stack.


## Algorithm infix expression to postfix

 1. Create an empty stack named ***pilaops*** to keep the operators. Create an empty string for the output.
 2. Process every char on the expression, from left to right.
a. If the char is an **operand**, add it at the end of the output  string.
b. If the char is a **left parentheses**, *push* the parentheses to ***pilaops***.
c.  If the char is a **right parentheses**, *pop* items on pilaops until found a left parentheses. Add every operator at the end of the output string.
d. If the char is an **operator** , *push* it to ***pilaops***. However, all operators already in ***pilaops*** that have equal or greater precedence have to be **pop** and be added to the end of the output string.
3. When you have fully processed the infix expression, verify ***pilaops***. Any left over operator on it has to be removed and added at the end of the output string.


## Algorithm infix evaluate a postfix expression
1.  Create an empty stack called ***pilaoperandos***.
2. Process every char on the expression, from left to right.
a.  If the char is an **operand**, *push* it to ***pilaoperandos***.
b. If the char is an **operator**, *pop* the items of ***pilaoperandos*** twice. The first *pop* is the second operand and the second *pop* is the first one. Perform the arithmetic operation and *push* the result on ***pilaoperandos***.
3.  When the input expression has been fully processed, the result will be on the stack. Pop it from ***pilaoperandos*** and return it.


## About the code
I used a linked stack :arrow_right: [pila_ligada.h](https://github.com/TanZng/Notaciones/blob/master/pila_ligada.h "pila_ligada.h")

The nodes of the linked stack :arrow_right: [nodo.h](https://github.com/TanZng/Notaciones/blob/master/nodo.h "nodo.h")

The algorithms are implemented in C++ :arrow_right: [posfija.h](https://github.com/TanZng/Notaciones/blob/master/posfija.h "posfija.h")

You can found the main  :arrow_right: [posfija.cpp](https://github.com/TanZng/Notaciones/blob/master/posfija.cpp "posfija.cpp")


## Conclusion 
The stack is an important linear data structure and can be very useful in a lot of situations when we need to get the last item we saved.

:octocat:	

