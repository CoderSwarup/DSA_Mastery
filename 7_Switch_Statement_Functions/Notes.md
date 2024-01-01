# Day 7: Understanding The Concepts Of Switch Case Statement And Functions

## 📅 Date: 10-11-2023

## Introduction

## Table of Contents

1. [Introduction](#introduction)
2. [What Today Learned](#📚-what-today-learned)
   - [What is Switch Case Statement](#what-is-switch-case-statement)
3. [Challenges Faced](#🦾-challenges-faced)
4. [Conclusion](#conclusion)
5. [Connect With Me](#connect-with-me)

## 📚 What Today Learned

## What is Switch Case Statement ?

The ‘Switch’ is a branching and control statement. It is just like a switchboard at home whichever thing we want to put on we have to press that switch on.

<img src="https://cdn.programiz.com/sites/tutorial2program/files/flowchart-switch-statement.jpg" width="450px">

This is the basic structure of the ‘switch-case’ statement. In the parenthesis of the switch, you can write some expression or a variable. But it can be either integer type, character type variable, or an expression. And for the different values of this expression, you can mention various cases.

## Is there any reason to use switch statement instead of if and elseif cpp

### Readability

- **Switch Statement:**

  - Provides a clear structure for comparing a variable against multiple constant values.
  - Concise when dealing with a large number of cases.

- **If-Else Statements:**
  - May become less readable as the number of conditions increases.

### Constant Expressions

- **Switch Statement:**

  - Requires constant expressions for case labels.

- **If-Else Statements:**
  - Can handle more complex conditions or dynamic expressions.

### Fallthrough

- **Switch Statement:**

  - Allows intentional fallthrough from one case to another.

- **If-Else Statements:**
  - No fallthrough by default, making behavior more predictable.

### Range Checks

- **Switch Statement:**

  - Suitable for simple conditions.

- **If-Else Statements:**
  - Better for range checks or more complex logic.

### Default Case

- **Switch Statement:**

  - Supports a default case for unmatched conditions.

- **If-Else Statements:**
  - Also allows for a default case.

### Performance

- Both constructs have similar performance, and modern compilers optimize code effectively.

# 🔄 Difference Between If-Else and Switch Statement

## Parameters 🤔 If-Else 🔄 Switch

  <table border="1">
    <tr>
      <th>Parameters</th>
      <th>🤔 If-Else</th>
      <th>🔄 Switch</th>
    </tr>
    <tr>
      <td><strong>Execution Flow</strong></td>
      <td>Conditional execution based on whether the given condition is true or false.</td>
      <td>Switches between multiple cases, executing the code block corresponding to the matched case.</td>
    </tr>
    <tr>
      <td><strong>Applicability</strong></td>
      <td>Applicable to various data types such as integers, characters, pointers, floating-point types, or Booleans.</td>
      <td>Primarily optimized for character expressions and integers.</td>
    </tr>
    <tr>
      <td><strong>Testing</strong></td>
      <td>Evaluates both logical expressions and equality.</td>
      <td>Focused on testing equality.</td>
    </tr>
    <tr>
      <td><strong>Expression Structure</strong></td>
      <td>Uses multiple statements to handle different decision scenarios.</td>
      <td>Utilizes single statements for handling multiple decision scenarios.</td>
    </tr>
    <tr>
      <td><strong>Default Execution</strong></td>
      <td>If the condition inside the if-statement is false, the code block within the else statement is executed.</td>
      <td>Executes the default statement if none of the cases match the provided condition.</td>
    </tr>
    <tr>
      <td><strong>Sequence of Execution</strong></td>
      <td>Executes the code block within the if or else statement based on the first true condition.</td>
      <td>Sequentially checks each case until a break statement is encountered or the end of the switch statement is reached.</td>
    </tr>
    <tr>
      <td><strong>Performance</strong></td>
      <td>Performance may decrease when handling multiple options due to sequential evaluation.</td>
      <td>Provides optimized performance when dealing with numerous options, executing faster than if-else statements.</td>
    </tr>
    <tr>
      <td><strong>Ease of Editing</strong></td>
      <td>May be challenging to edit when dealing with nested if-else statements.</td>
      <td>Easier to edit due to a straightforward structure.</td>
    </tr>
    <tr>
      <td><strong>Values Handling</strong></td>
      <td>Based on the constraints specified in the conditions.</td>
      <td>Relies on user inputs to match cases.</td>
    </tr>
  </table>

## Where this switch case is useful?

Mostly it is useful for writing menu-driven programs. For example, if I take the example of notepad, there are the options like ‘File’ and inside this file option ‘New’, ‘Open’, ‘Save’, ‘Save as’ etc. For each option, we can define some code i.e. ‘New – 1’, ‘Open – 2’, and so on. So, depending on the value we will define a particular case in the switch statement. One thing is that in any case, we can again define the switch statement. Below are some key points of the switch statement.

## 🦾 Challenges Faced

## Conclusion

## Connect with Me

- GitHub: [![GitHub](https://img.shields.io/badge/GitHub-CoderSwarup-blue?style=flat&logo=github)](https://github.com/CoderSwarup)
- Instagram: [![Instagram](https://img.shields.io/badge/Instagram-swarup_bhise999-pink?style=flat&logo=instagram)](https://www.instagram.com/swarup_bhise999/)

Stay tuned for more updates on my DSA learning journey!

<h3>Happy Coding 🎉</h3>
