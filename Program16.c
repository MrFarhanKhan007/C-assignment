#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
};
struct node *front;
struct node *rear;
void insert();
void delete ();
void display();
void main() {
  int choice = 0;
  printf("\n*********Queue operations using linked list*********\n");
  printf("\n----------------------------------------------\n");
  while (choice != 4) {
    printf("\n\nChose one from the below options...\n");
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
    printf("\n Enter your choice \n");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        insert();
        break;
      }
      case 2: {
        delete ();
        break;
      }
      case 3: {
        display();
        break;
      }
      case 4: {
        printf("Exiting....");
        break;
      }
      default: {
        printf("Please Enter valid choice ");
      }
    };
  }
}
void insert() {
  struct node *ptr;
  int item;

  ptr = (struct node *)malloc(sizeof(struct node));
  if (ptr == NULL) {
    printf("\nOVERFLOW\n");
    return;
  } else {
    printf("\nEnter value?\n");
    scanf("%d", &item);
    ptr->data = item;
    if (front == NULL) {
      front = ptr;
      rear = ptr;
      front->next = NULL;
      rear->next = NULL;
    } else {
      rear->next = ptr;
      rear = ptr;
      rear->next = NULL;
    }
  }
}
void delete () {
  struct node *ptr;
  if (front == NULL) {
    printf("\nUNDERFLOW\n");
    return;
  } else {
    ptr = front;
    front = front->next;
    free(ptr);
  }
}
void display() {
  struct node *ptr;
  ptr = front;
  if (front == NULL) {
    printf("\nEmpty queue\n");
  } else {
    printf("\nprinting values .....\n");
    while (ptr != NULL) {
      printf("\n%d\n", ptr->data);
      ptr = ptr->next;
    }
  }
}