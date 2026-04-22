# 🧮 Arbitrary Precision Calculator (APC) in C

## 📌 Overview

This project implements an **Arbitrary Precision Calculator (APC)** in C.

An APC is used to perform arithmetic operations on **very large numbers** that cannot be handled by standard data types like `int`, `long`, or `long long`.
It achieves this by storing numbers as **linked lists** and performing operations digit by digit.

This project was developed as part of my learning program at **Emertxe** to gain hands-on experience with data structures and low-level memory handling in C.

---

## ✨ Features

The program supports the following operations:

* Addition of large numbers
* Subtraction of large numbers
* Multiplication of large numbers
* Division of large numbers (if implemented)
* Handling both positive and negative numbers
* Menu-driven interface for user interaction

---

## ⚙️ Working Principle

* Numbers are stored as **linked lists**, where each node contains a single digit
* Arithmetic operations are performed similar to **manual calculations**
* Carry and borrow are handled explicitly
* Result is stored and displayed as a linked list

---

## 🧠 Concepts Used

* Linked Lists (Single / Double)
* Dynamic Memory Allocation
* Pointers and Structures in C
* Arithmetic Algorithms (digit-by-digit operations)
* String handling

---

## 🛠️ Technologies Used

* **Programming Language:** C
* **Compiler:** GCC
* **Platform:** Linux

---

## 🎯 Learning Outcomes

Through this project, I gained a deeper understanding of:

* Handling very large numbers efficiently
* Implementing arithmetic logic without built-in operators
* Memory management using pointers
* Designing modular and structured C programs

---

## ▶️ How to Run

gcc *.c -o apc
./apc
```
