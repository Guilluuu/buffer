#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

typedef enum { INT_TYPE, FLOAT_TYPE, CHAR_TYPE, STRING_TYPE } DataType;

typedef struct {
    DataType type;    // Tipo de dato almacenado
    union {           // Unión para almacenar diferentes tipos de valores
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


void newBuffer(buffer *B) { *B = NULL; }

void destroyBuffer(buffer *B) {
  buffer aux;
  aux = *B;
  while (aux != NULL) {
    aux = aux->sig;
    free(*B);
    *B = aux;
  }
}


unsigned isBempty(buffer B) { return B == NULL; }

void top(buffer B, void *E, DataType *type) {
    if (!isBempty(B)) {
        *type = B->elemento.type;  // Guardar el tipo del elemento actual

        // Según el tipo de dato, devolver el valor correcto
        switch (B->elemento.type) {
            case INT_TYPE:
                *(int *)E = B->elemento.data.iVal;
                break;
            case FLOAT_TYPE:
                *(float *)E = B->elemento.data.fVal;
                break;
            case CHAR_TYPE:
                *(char *)E = B->elemento.data.cVal;
                break;
            case STRING_TYPE:
                strcpy((char *)E, B->elemento.data.sVal);
                break;
            default:
                return;
        }
    } else {
        perror("Buffer is empty\n");
        exit(1);
    }
}

void pushInt(buffer *B, int value) {
    buffer aux = (buffer)malloc(sizeof(struct cell));
    aux->elemento.type = INT_TYPE;
    aux->elemento.data.iVal = value;
    aux->sig = *B;
    *B = aux;
}

// Función para insertar un valor flotante en el buffer
void pushFloat(buffer *B, float value) {
    buffer aux = (buffer)malloc(sizeof(struct cell));
    aux->elemento.type = FLOAT_TYPE;
    aux->elemento.data.fVal = value;
    aux->sig = *B;
    *B = aux;
}

// Función para insertar un carácter en el buffer
void pushChar(buffer *B, char value) {
    buffer aux = (buffer)malloc(sizeof(struct cell));
    aux->elemento.type = CHAR_TYPE;
    aux->elemento.data.cVal = value;
    aux->sig = *B;
    *B = aux;
}

// Función para insertar una cadena en el buffer
void pushString(buffer *B, char *value) {
    buffer aux = (buffer)malloc(sizeof(struct cell));
    aux->elemento.type = STRING_TYPE;
    strcpy(aux->elemento.data.sVal, value);  // Copiamos la cadena
    aux->sig = *B;
    *B = aux;
}

void pop(buffer *B) {
  buffer aux;
  if (!isBempty(*B)) /*si pila no vacía*/
  {
    aux = *B;
    *B = (*B)->sig;
    free(aux);
  }
}

void processTopValue(buffer *B) {
    void *result = malloc(MAX_SIZE);  // Almacenar cualquier tipo de valor
    DataType type;

    // Obtener el valor en la parte superior y el tipo
    top(*B, result, &type);

    // Procesar el valor según su tipo
    switch (type) {
        case STRING_TYPE:
            printf("Top value (string): %s\n", (char *)result);
            break;
        case CHAR_TYPE:
            printf("Top value (char): %c\n", *(char *)result);
            break;
        case FLOAT_TYPE:
            printf("Top value (float): %.2f\n", *(float *)result);
            break;
        case INT_TYPE:
            printf("Top value (int): %d\n", *(int *)result);
            break;
        default:
            printf("Unknown type\n");
    }
        // Hacer pop después de procesar el valor
    pop(B);

    // Liberar memoria utilizada
    free(result);
}

void flush(buffer *b) {
  while (!isBempty(*b)) {
    pop(b);
  }
}
