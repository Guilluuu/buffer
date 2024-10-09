# Generic Buffer Implementation in C
This project provides an implementation of a generic buffer (stack) in C, which can handle multiple data types. It includes functions to create, manipulate, and destroy the buffer, as well as example usage (main.c).

# Files
**buffer.h**: Header file that declares the buffer structure and the functions used to manage the buffer.

**buffer.c**: Source file that contains the implementation of the buffer functions.

**main.c**: Example program that demonstrates how to use the buffer with different data types.

**Makefile**: Makefile for compiling the project easily.

# Features
**Generic stack implementation**: Allows pushing and popping of different data types (integers, floats, chars, and strings).

**Memory management**: Handles dynamic memory allocation and deallocation to avoid memory leaks.
Type-safe operations: Differentiates between different data types during stack operations.
# Functions

**newBuffer**: Initializes a new empty buffer.

**destroyBuffer**: Frees the memory used by the buffer and its elements.

**isBempty**: Checks if the buffer is empty.

**top**: Retrieves the top element from the buffer and identifies its type.

**pushInt**: Pushes an integer value onto the buffer.

**pushFloat**: Pushes a float value onto the buffer.

**pushChar**: Pushes a character value onto the buffer.

**pushString**: Pushes a string value onto the buffer.

**processTopValue**: Processes and displays the top value from the buffer based on its type.

**flush**: Clears all elements from the buffer.
