# Surfboard Inventory Management Application

## Overview
This application allows users to manage a surfboard inventory system. It includes functionality to add, edit, delete, and view surfboards. Each surfboard has properties like brand, model, size dimensions, quantity, and price. 

## Files
- `item.h` – Defines the `Item` class (surfboard).
- `item.cpp` – Implements the `Item` class methods and operator overloads.
- `main.cpp` – Contains the menu-driven program to manage inventory.
- `readme.md` – This file.

## Functionalities
- Add new surfboard
- Edit existing surfboard by ID
- Delete surfboard by ID
- View all inventory

## Operator Overloads
- `operator==` for comparing IDs
- `operator<<` for formatted printing

## Resources Used
- ChatGPT (OpenAI) for code guidance and clarification
- StackOverflow for syntax references
- C++ documentation (cplusplus.com)

## Reflection
This project helped reinforce my understanding of classes, file separation, vectors, and operator overloading. A challenge was managing vector deletion and ensuring objects were found by ID. Now that it's working, the menu is clean and intuitive.
