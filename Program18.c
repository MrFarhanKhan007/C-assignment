#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void createNode(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  if (head == NULL) {
    head = newNode;
  } else {
    struct node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}
void display() {
  struct node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);

    temp = temp->next;
  }
  printf("\n");
}
void increment() {
  struct node *temp = head;
  while (temp != NULL) {
    temp->data += 10;
    temp = temp->next;
  }
}
int main() {
  int n, data;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  printf("Enter the data: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &data);
    createNode(data);
  }
  printf("The linked list is before increment is: ");
  display();
  increment();
  printf("The linked list after increment is: ");
  display();
  return 0;
}