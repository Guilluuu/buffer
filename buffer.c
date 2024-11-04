#include "buffer.h"
#include <stdio.h>

void newBuffer(buffer *B) { B->n = 0; }

int buffer_is_empty(buffer B) { return B.n == 0; }

int buffer_is_full(buffer B) { return B.n == MAX_SIZE; }


void pushchar(buffer *B, char element)
{
    if (buffer_is_full(*B))
    {
        perror("Error in <pushchar function> - Buffer is full\n");
        exit(1);
    }

    B->element[B->n].type        = CharType;
    B->element[B->n].charElement = element;
    B->n++;
}
void pushint(buffer *B, char element)
{
    if (buffer_is_full(*B))
    {
        perror("Error in <pushint function> - Buffer is full\n");
        exit(2);
    }

    B->element[B->n].type        = IntType;
    B->element[B->n].charElement = element;
    B->n++;
}
void pushfloat(buffer *B, float element)
{
    if (buffer_is_full(*B))
    {
        perror("Error in <pushfloat function> - Buffer is full\n");
        exit(3);
    }

    B->element[B->n].type        = FloatType;
    B->element[B->n].charElement = element;
    B->n++;
}

void pop(buffer *B, void *recover)
{
    if (buffer_is_empty(*B))
    {
        perror("Error in <pop function> - buffer is empty");
        exit(4);
    }

    switch (B->element[B->n - 1].type)
    {
        case InvalidType:

            perror("Error in dataType\n");
            B->n--;
            break;

        case IntType:

            *(int *) recover      = B->element[B->n - 1].intElement;
            B->element[B->n].type = IntType;
            B->n--;
            break;

        case FloatType:

            *(float *) recover    = B->element[B->n - 1].floatElement;
            B->element[B->n].type = IntType;
            B->n--;
            break;

        case CharType:

            *(char *) recover     = B->element[B->n - 1].charElement;
            B->element[B->n].type = IntType;
            B->n--;
            break;

        case StringType:
            break;
    }
}

int BufferSize(buffer B) { return B.n; }

void flush(buffer *B)
{
    while (!isBEmpty(*B))
    {
        B->element[B->n].type = InvalidType;
        B->n--;
    }
}
