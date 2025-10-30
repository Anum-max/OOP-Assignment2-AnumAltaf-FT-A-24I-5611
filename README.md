 OOP Assignment 2 — Anum Altaf (Roll No: 24I-5611) — Section FT-A

This repository contains my solutions for Object-Oriented Programming Assignment #2.  
Each question focuses on a different data structure or concept, starting from recursion and moving toward linked lists, queues, and stacks.  

Q1 (Part a & b) — Recursion
This program uses a recursive function ChangeLocation() to swap elements in an array between two given indices (b1 and b2).  
For example, if the array is `C O M P U T E R` and we swap positions 2 to 6, it reverses only that section of the array.  
It helped me understand how recursion works by repeatedly calling itself until the base condition is met.

Part (b): 24I-5611_Q1_part-b.cpp
This program prints a number pattern using recursion.  
If n = 4, it prints:
This question showed me how recursion can replace loops for repetitive tasks like printing patterns.

Q2 — Singly Linked List (NASA Features)
File: 24I-5611_Q2.cpp

This program creates a Singly Linked List to store NASA feature data.  
I used OOP principles like:
- A base class "Feature"
- Two derived classes "LandFeature" and "WaterFeature".

The program can:
- Insert features at the end  
- Delete by ID  
- Display all features  
- Reverse the list  

It helped me understand how to combine inheritance and linked liststo organize and manage related data dynamically.

---

3 — Doubly Linked List (Library System)
File: 24I-5611_Q3.cpp

This program implements a Doubly Linked List for managing books in a library.  
Each node stores book information and has two pointers — one pointing forward and one backward.

Features:
- Add book at beginning, end, or specific position  
- Delete a book by ID  
- Display the list forward and backward

This taught me how doubly linked lists make navigation easier in both directions, unlike singly linked lists.

---
Q4 — Queue (Movie Ticket Booking System)  
File: 24I-5611_Q4.cpp

This program implements a queue to simulate a movie ticket booking system.  
It follows the FIFO (First In, First Out) rule, the first person who joins gets served first.

Functions used:
- Enqueue() → Add customer  
- Dequeue() → Remove customer  
- Display() → Show all customers in line  

It showed how queues work in real-life scenarios like ticket counters or waiting lines.

Q5 — Stack (Array & Linked List) + Iterative Solutions
File: 24I-5611_Q5.cpp

This program implements two stack structures:
1. Array-based stack
2. Linked list–based stack

Then I used these stacks to perform iterative versions of Question 1’s recursion tasks.  
Finally, I compared both stacks by analyzing:
- Time complexity: Push & Pop = O(1)
- Array Stack: Faster but fixed size  
- Linked List Stack:Slower but dynamic memory

This question taught me how stacks can replace recursion and how to analyze performance differences.


