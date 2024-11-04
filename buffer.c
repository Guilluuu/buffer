#include "buffer.h"
#include <stdio.h>

void newBuffer(buffer *B) { B->n = 0; }

int isBEmpty(buffer B) { return B.n == 0; }

void pushchar(buffer *B, char element)
{
    B->element[B->n].type        = CharType;
    B->element[B->n].charElement = element;
    B->n++;
}
void pushint(buffer *B, char element)
{
    B->element[B->n].type        = IntType;
    B->element[B->n].charElement = element;
    B->n++;
}
void pushfloat(buffer *B, float element)
{
    B->element[B->n].type        = FloatType;
    B->element[B->n].charElement = element;
    B->n++;
}

void pop(buffer *B, void *recover)
{
    switch (B->element[B->n - 1].type)
    {
        case InvalidType:

            perror("Error in dataType");
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
