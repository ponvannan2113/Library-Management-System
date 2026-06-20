# Library Management System

A comprehensive console-based Library Management System developed in C, designed to streamline library operations through efficient book record management, issue tracking, return processing, and persistent data storage.

The application demonstrates practical implementation of core programming concepts including modular design, linked lists, file handling, dynamic memory management, and structured data organization.

---

## Overview

Managing library records manually can be time-consuming and error-prone. This system provides a centralized solution for maintaining book inventories and monitoring book circulation within a library environment.

The application allows administrators to add, update, search, issue, and return books while ensuring that all records are securely stored and retrieved using file handling mechanisms.

---

## Key Features

### Book Inventory Management
- Add new books to the library collection
- View complete library inventory
- Search books using different criteria
- Modify existing book information
- Remove outdated or unavailable books

### Book Issue Management
- Issue books to users
- Return issued books
- Maintain issued book records
- Track book availability status

### Data Storage
- Persistent storage using files
- Automatic loading of records during startup
- Save book and issue records before exit
- Maintain data consistency across executions

### Search and Retrieval
- Fast access to book information
- Book identification using unique IDs
- Simplified record lookup

---

## Technical Highlights

- Written entirely in C Programming
- Modular architecture with separate source files
- Dynamic memory allocation for record management
- Linked list implementation for flexible data storage
- File handling for permanent data retention
- Menu-driven user interface

---

## Project Structure

```text
Library-Management-System-LMS
│
├── main.c
├── lms.h
├── add_newbook.c
├── update_book.c
├── remove_book.c
├── search.c
├── view_all.c
├── print_books.c
├── issue.c
├── ret_book.c
├── list_iss.c
├── iss_save.c
├── isload.c
├── save.c
├── load.c
├── exit.c
└── Makefile
```

---

## Build Instructions

### Compile Manually

```bash
gcc main.c add_newbook.c ret_book.c load.c view_all.c \
isload.c save.c exit.c search.c print_books.c \
remove_book.c issue.c iss_save.c list_iss.c \
update_book.c -o library
```

### Compile Using Makefile

```bash
make
```

### Run the Application

```bash
./library
```

---

## Workflow

1. Load existing library records.
2. Manage book inventory.
3. Issue books to users.
4. Process returned books.
5. Save updated records.
6. Exit safely with data preservation.

---

## Concepts Implemented

This project demonstrates practical application of:

- Structures
- Linked Lists
- Dynamic Memory Allocation
- File Handling
- Modular Programming
- Data Management Techniques
- Menu Driven Application Design

---

## Applications

This system can be adapted for:

- School Libraries
- College Libraries
- Training Institutes
- Book Rental Services
- Personal Book Collections

The modular design allows easy customization for different record-management requirements.

---

## Future Improvements

- User Authentication
- Fine Calculation Module
- Due Date Management
- Book Reservation System
- Report Generation
- Database Integration
- Graphical User Interface
- Multi-User Support

---

## Author

### Gopi M

Passionate Software Developer with interests in:

- Embedded Systems
- Linux System Programming
- Data Structures
- Application Development in C

GitHub:
https://github.com/mgopi6013

---

## Project Objective

The primary objective of this project is to provide a practical and efficient solution for managing library operations while showcasing the use of fundamental and advanced C programming concepts in a real-world application.

---

© 2026 Gopi M. All Rights Reserved.
