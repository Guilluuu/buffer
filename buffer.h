#ifndef BUFFER_H
#define BUFFER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUFFER_SIZE 2048

typedef enum
{
    InvalidType = 1 << 0,
    CharType    = 1 << 1,
    IntType     = 1 << 2,
    FloatType   = 1 << 3

} DataType;

typedef struct
{
    union
    {
        int   intElement;
        float floatElement;
        char  charElement;
    };

    DataType type;

} bufferElement;

typedef struct
{
    bufferElement element[MAXBUFFER_SIZE];
    int           n;

} buffer;


// Prototipos de las funciones

void newBuffer(buffer *B);

int buffer_is_empty(buffer B);

int buffer_is_full(buffer B);

void __pushchar(buffer *B, char element);

void __pushint(buffer *B, int element);

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
