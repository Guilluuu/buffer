#ifndef BUFFER_H
#define BUFFER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE        2048
#define MAX_STRING_SIZE 32

typedef enum
{
    InvalidType = 1 << 0,
    CharType    = 1 << 1,
    StringType  = 1 << 2,
    IntType     = 1 << 3,
    FloatType   = 1 << 4

} DataType;

typedef struct
{
    union
    {
        int   intElement;
        float floatElement;
        char  charElement;
        char  StringElement[MAX_STRING_SIZE];
    };

    DataType type;

} bufferElement;

typedef struct
{
    bufferElement element[MAX_SIZE];
    int           n;

} buffer;


// Prototipos de las funciones

void newBuffer(buffer *B);

int buffer_is_empty(buffer B);

int buffer_is_full(buffer B);

void __pushchar(buffer *B, char element);

void __pushint(buffer *B, char element);

void __pushfloat(buffer *B, float element);

void pop(buffer *B, void *recover);

int BufferSize(buffer B);

#define push(Bptr, T)            \
    _Generic((T),                \
    int: __pushint(Bptr, T),     \
    float: __pushfloat(Bptr, T), \
    char: __pushchar(Bptr, T),   \
    default: __pushint(Bptr, T))


#endif // BUFFER_H
