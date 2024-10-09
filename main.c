#include "buffer.h"

int main()
{
    buffer buffer;
    newBuffer(&buffer);

    pushInt(&buffer, 14);
    pushFloat(&buffer, 3.3212f);
    pushChar(&buffer, 'W');
    pushString(&buffer, "Asier Maricon");

    processTopValue(&buffer);
    processTopValue(&buffer);
    processTopValue(&buffer);
    processTopValue(&buffer);

    destroyBuffer(&buffer);

    return 0;
}
