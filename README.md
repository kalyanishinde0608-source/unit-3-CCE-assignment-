# unit-3-CCE-assignment-
# Campus Shuttle Route and Stop Management System

## 1. Problem Statement

Develop a Campus Shuttle Route and Stop Management System using a Doubly Linked List in C++. The system should allow users to add new shuttle stops, display the route in forward and backward directions, search for a specific stop, and delete an existing stop. The system helps manage shuttle routes efficiently using dynamic memory allocation.

## 2. Objectives

- To manage campus shuttle stops efficiently.
- To add and delete shuttle stops dynamically.
- To display the shuttle route in both directions.
- To search for a particular shuttle stop.
- To understand the implementation of a Doubly Linked List in C++.

## 3. Features

1. Add Shuttle Stop
2. Display Route Forward
3. Display Route Backward
4. Search Shuttle Stop
5. Delete Shuttle Stop
6. Exit the Program

## 4. Data Structure Used

Doubly Linked List

Each node contains:
- Stop Name: Stores the name of the shuttle stop.
- Previous Pointer: Points to the previous node.
- Next Pointer: Points to the next node.

## 5. Algorithm

1. Start the program.
2. Initialize the head and tail pointers to NULL.
3. Display the menu of operations.
4. Accept the user's choice.
5. Perform the selected operation:
   - Add a new shuttle stop.
   - Display stops in forward order.
   - Display stops in backward order.
   - Search for a shuttle stop.
   - Delete a shuttle stop.
6. Repeat until the user selects Exit.
7. Free the allocated memory.
8. Stop the program.

## 6. Requirements

- Programming Language: C++
- Data Structure: Doubly Linked List
- Compiler: GCC / G++ or any standard C++ compiler
- Editor: Visual Studio Code or any C++ IDE

## 7. How to Compile and Run

### Compile

```bash
g++ shuttle.cpp -o shuttle


