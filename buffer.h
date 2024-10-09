#ifndef BUFFER_H
#define BUFFER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

typedef enum { INT_TYPE, FLOAT_TYPE, CHAR_TYPE, STRING_TYPE } DataType;

typedef struct {
    DataType type;    
    union {
        int iVal;
        float fVal;
        char cVal;
        char sVal[MAX_SIZE];
    } data;
} bufferType;

struct cell {
    bufferType elemento;
    struct cell *sig;
};

typedef struct cell *buffer;

// Prototipos de las funciones
void newBuffer(buffer *B);
void destroyBuffer(buffer *B);
unsigned isBempty(buffer B);
void top(buffer B, void *E, DataType *type);
void pushInt(buffer *B, int value);
void pushFloat(buffer *B, float value);
void pushChar(buffer *B, char value);
void pushString(buffer *B, char *value);
void processTopValue(buffer *B);
void flush(buffer *b);

#endif // BUFFER_H
