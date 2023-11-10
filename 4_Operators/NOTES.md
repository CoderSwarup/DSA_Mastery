# Day 4: Conditional Statements, Looping Statements, and Patterns

## 📅 Date: 06-11-2023

## Introduction

Welcome to Day 3 of my Data Structures and Algorithms (DSA) learning journey. Today, I dived into the essential concepts of Operators Logical Operators , Bitwise Operator Operator Precedence & Varialbles.

## Table of Contents

1. [Introduction](#introduction)
2. [What Today Learned](#📚-what-today-learned)
   - [Bitwise Operators](#bitwise-operators)
     - [List of Bitwise Operators](#list-of-bitwise-operators)
     - [Usage](#usage)
   - [C++ `break` and `continue` Keywords](#c-break-and-continue-keywords)
     - [`break` Keyword](#break-keyword)
     - [`continue` Keyword](#continue-keyword)
   - [Scope of Variables in C++](#scope-of-variables-in-c)
   - [Operator Precedence](#operator-precedence)
     - [C++ Operator Precedence](#c-operator-precedence)
     - [Example of Working](#example-of-working)
3. [Connect With Me](#connect-with-me)

## 📚 What Today Learned

## Bitwise Operators

Bitwise operators are used in computer programming to manipulate individual bits within binary representations of data. These operators work at the binary level and are commonly used in low-level programming, such as when working with hardware or optimizing code for performance. There are several bitwise operators commonly used in programming:

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/Operators-In-C.png" width="400px">

# Bitwise Operators

Bitwise operators are used in computer programming to manipulate individual bits within binary representations of data. These operators work at the binary level and are commonly used in low-level programming, such as when working with hardware or optimizing code for performance.

## List of Bitwise Operators

1. **AND (&):** The bitwise AND operator compares each pair of corresponding bits from two values and produces a new value where each bit is set to 1 only if both of the original bits were 1.

```
5 (binary: 101)
& 3 (binary: 011)
---------------
Result: 1 (binary: 001)
```

2. **OR (|):** The bitwise OR operator compares each pair of corresponding bits and produces a new value where each bit is set to 1 if at least one of the original bits was 1.

```
5 (binary: 101)
| 3 (binary: 011)
---------------
Result: 7 (binary: 111)
```

3. **XOR (^):** The bitwise XOR (exclusive OR) operator compares each pair of corresponding bits and produces a new value where each bit is set to 1 if the original bits are different (one is 0, and the other is 1).

```
5 (binary: 101)
^ 3 (binary: 011)
---------------
Result: 6 (binary: 110)
```

4. **NOT (~):** The bitwise NOT operator (also called bitwise complement) inverts the bits of a single value, changing 1s to 0s and 0s to 1s.

```
~5 (binary: 101)
Result: -6 (binary: 11111111111111111111111111111010)
```

5. **Left Shift (<<) and Right Shift (>>):** These operators shift the bits of a value to the left or right by a specified number of positions. Left shifting effectively multiplies the value by 2 raised to the power of the shift count, while right shifting divides the value by 2 raised to the power of the shift count.

   1. its in the left shift Operator Majority Cases The bit Shift Left Its Multiply by 2

   ```
   Exmaple 5 << 1
           5 = 000000000101
       After Left Shift  000001010 = 10


   Exmaple 3 << 2
           3 = 000000000011
       After Left Shift  000000001100 = 12
   ```

   Example 👍

    <img src="https://cdn1.byjus.com/wp-content/uploads/2021/10/word-image8.png" width="300px" >

   2. Right Shift Operator :=
      In the Right Shift Operator its divide by 2

   ```

       Example 5 >> 1
       5 = 000000000101
       After Right Shift 000000000001 = 1


       Ex 12 >> 2
       12 = 000000001100
       After Right Shift 000000000000 = 4
   ```

   Example 👍

    <img src="https://cdn1.byjus.com/wp-content/uploads/2021/12/word-image.png" width="300px" >

## Usage

You can use these bitwise operators in your code to perform various bit-level operations, such as setting or clearing specific bits within a value, extracting or combining bit flags, and optimizing algorithms for performance.

## What is a C++ increment Operator?

The C++ increment operator is a unary operator. The symbol used to represent the increment operator is (++). The increment operator increases the value stored by the variable by 1. This operator is used for Numeric values only.

There are two types of C++ increment Operator:

1. Post-Increment operator (a++)
   The postfix operator says that first use the value and then increment it. This means the value is first used up for the operation then the value is updated by 1.

2. Pre-increment operator(++a)
   The postfix operator says that first increment the value then use it. This means the value is increased by 1 for the operation then the value is used by the variable

<div width="100%"  align="center">
    <img src="https://2.bp.blogspot.com/-H6aijgm-52o/Wwg-PqwUm8I/AAAAAAAAAsE/sbSZ52OC82wioG-wIEKHJ7BI8CwKu89JQCLcBGAs/s1600/INC_DEC%2BOPR_IN_C.png" width="400px" >
</div>

# C++ `break` and `continue` Keywords

In C++, the `break` and `continue` keywords are used in loops to control the flow of the program. They are often used in `for`, `while`, and `do-while` loops to change the behavior of the loop.

## `break` Keyword

The `break` keyword is used to exit a loop prematurely when a certain condition is met. It is commonly used to terminate a loop's execution before it reaches its normal exit condition.

## `continue` Keyword

The continue keyword is used to skip the remaining code within a loop iteration and move to the next iteration. It is typically used to bypass certain iterations of a loop based on a condition.

<div width="100%"  align="center">
    <img src="https://i.ytimg.com/vi/UUaObrE-Ypw/maxresdefault.jpg" width="400px" >
</div>

## Scope of Variables in C++

In general, the scope is defined as the extent up to which something can be worked with. In programming also the scope of a variable is defined as the extent of the program code within which the variable can be accessed or declared or worked with. There are mainly two types of variable scopes:

1. Local Variables
   Variables defined within a function or block are said to be local to those functions.

   - Anything between ‘{‘ and ‘}’ is said to inside a block.
   - Local variables do not exist outside the block in which they are declared, i.e. they can not be accessed or used outside that block.
   - Declaring local variables: Local variables are declared inside a block.

2. Global Variables
   As the name suggests, Global Variables can be accessed from any part of the program.

   - They are available through out the life time of a program.
   - They are declared at the top of the program outside all of the functions or blocks.
   - Declaring global variables: Global variables are usually declared outside of all of the functions and blocks, at the top of the program. They can be accessed from any portion of the program.

## Operator Precedence

The concept of operator precedence and associativity in C++ helps in determining which operators will be given priority when there are multiple operators in the expression. It is very common to have multiple operators in C++ language and the compiler first evaluates the operater with higher precedence. It helps to maintain the ambiguity of the expression and helps us in avoiding unnecessary use of parenthesis.

<h2> C++ Operator Precedence </h2>
<div width="100%"  align="center">
    <img src="https://i.stack.imgur.com/XgKf8.png" width="400px" >
</div>

<h2> Example of Working  </h2>
<div width="100%"  align="center">
    <img src="https://media.geeksforgeeks.org/wp-content/uploads/20230516162457/Operator-Precedence-in-C-01.webp" width="400px" >
</div>

## Connect with Me

- GitHub: [![GitHub](https://img.shields.io/badge/GitHub-CoderSwarup-blue?style=flat&logo=github)](https://github.com/CoderSwarup)
- Instagram: [![Instagram](https://img.shields.io/badge/Instagram-swarup_bhise999-pink?style=flat&logo=instagram)](https://www.instagram.com/swarup_bhise999/)

Stay tuned for more updates on my DSA learning journey!

<h3>Happy Coding 🎉</h3>
