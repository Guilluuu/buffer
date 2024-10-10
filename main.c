#include "buffer.h"

int main() {
  buffer buffer;
  void *readelement;
  newBuffer(&buffer);
  readelement = malloc(MAX_SIZE);
  pushInt(&buffer, 14);
  pushFloat(&buffer, 3.3212f);
  pushChar(&buffer, 'W');
  pushString(&buffer, "Hello World");

  processTopValue(&buffer, readelement);
  printf("1st top value: %s\n", (char *)readelement);
  processTopValue(&buffer, readelement);
  printf("2nd top value: %c\n", *(char *)readelement);
  processTopValue(&buffer,readelement);
  printf("3rd top value: %f\n", *(float *)readelement);
  processTopValue(&buffer, readelement);
  printf("4th top value: %d\n", *(int *)readelement);

  destroyBuffer(&buffer);

  return 0;
}
