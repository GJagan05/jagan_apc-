# 🧮 Arbitrary Precision Calculator (APC) 

## 📌 Overview

The **Arbitrary Precision Calculator (APC)** is a C-based application designed to perform arithmetic operations on **very large integers** that exceed the limits of built-in data types such as `int`, `long`, and `long long`.

To overcome these limitations, numbers are represented using **linked lists**, enabling precise computation regardless of input size.

This project was developed as part of training at **Emertxe**, focusing on **data structures, memory management, and low-level programming in C**.

---

## ✨ Features

* ✅ Addition of large numbers
* ✅ Subtraction with proper borrow handling
* ✅ Multiplication using digit-by-digit logic
* ✅ Division support *(if implemented)*
* ✅ Handles both positive and negative numbers
* ✅ Menu-driven CLI interface
* ✅ Supports arbitrarily large inputs

---

## ⚙️ Working Principle

* Each number is stored as a **linked list**, where:

  * Each node contains a **single digit**
* Arithmetic operations are performed similar to **manual calculations**
* Key implementations:

  * **Carry propagation** for addition and multiplication
  * **Borrow handling** for subtraction
* Results are stored in a new linked list and displayed to the user

---

## 🧠 Core Concepts Used

* Linked Lists (Singly / Doubly Linked List)
* Dynamic Memory Allocation (`malloc`, `free`)
* Pointers and Structures
* Manual Arithmetic Algorithms
* String to Linked List Conversion

---

## 🛠️ Technologies Used

* **Language:** C
* **Compiler:** GCC
* **Platform:** Linux

---

## 🎯 Key Learnings

* Implemented arithmetic operations beyond native data type limits
* Strengthened understanding of **pointer manipulation and memory management**
* Learned to handle **edge cases** (sign handling, leading zeros, large inputs)
* Improved modular design and code reusability

---

## ⚡ Time Complexity

* Addition / Subtraction → **O(n)**
* Multiplication → **O(n²)**
* Division → Depends on implementation (typically **O(n²)**)

---

## 🚀 How to Run

```bash id="runapc22"
gcc *.c -o apc
./apc
```

