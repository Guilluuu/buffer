#include "buffer.h"


int main() // Do a generic push "__Generic"
{
    buffer buffer;
    newBuffer(&buffer);

    push(&buffer, 14);
    push(&buffer, 'W');


    char readelement;
    int  readelement2;
    pop(&buffer, &readelement);
    printf("1st top value: %c\n", readelement);
    pop(&buffer, &readelement2);
    printf("2nd top value: %d\n", readelement2);

    return 0;
}
