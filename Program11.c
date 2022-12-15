#include <stdio.h>
void push(char element, char stack[], int *top, int SIZE) {
  if (*top == -1) {
    stack[SIZE - 1] = element;
    *top = SIZE - 1;
  } else if (*top == 0) {
    printf("Stack Overflow \n");
  } else {
    stack[(*top) - 1] = element;
    (*top)--;
  }
}
void pop(char stack[], int *top, int SIZE) {
  if (*top == -1) {
    printf("Stack Underflow \n");
  } else {
    printf("Element popped: %c \n", stack[(*top)]);
    
    if ((*top) == SIZE - 1) {
      (*top) = -1;
    } else {
      (*top)++;
    }
  }
}
int main() {
  int SIZE = 4;
  char stack[4];
  int top = -1;
  push('a', stack, &top, SIZE);
  printf("Element on top: %c\n", stack[top]);
  push('b', stack, &top, SIZE);
  printf("Element on top: %c\n", stack[top]);
  pop(stack, &top, SIZE);
  printf("Element on top: %c\n", stack[top]);
  pop(stack, &top, SIZE);
  printf("Top: %d\n", top);
  pop(stack, &top, SIZE);
  return 0;
}