#include <stdio.h>
#include <stdlib.h>
#define bool int

struct tNode {
  int data;
  struct tNode *left;
  struct tNode *right;
};
struct sNode {
  struct tNode *t;
  struct sNode *next;
};

void push(struct sNode **top_ref, struct tNode *t);
struct tNode *pop(struct sNode **top_ref);
bool isEmpty(struct sNode *top);

void inOrder(struct tNode *root) {  // Left, Root, Right

  struct tNode *current = root;
  struct sNode *s = NULL;
  bool done = 0;

  while (!done) {
    if (current != NULL) {
      push(&s, current);
      current = current->left;
    }

    else {
      if (!isEmpty(s)) {
        current = pop(&s);
        printf("%d ", current->data);

        current = current->right;
      } else
        done = 1;
    }
  }
}
void preOrder(struct tNode *root) {  // Root, Left, Right
  struct tNode *current = root;
  struct sNode *s = NULL;
  bool done = 0;
  while (!done) {
    if (current != NULL) {
      printf("%d ", current->data);
      push(&s, current);
      current = current->left;
    } else {
      if (!isEmpty(s)) {
        current = pop(&s);
        current = current->right;
      } else
        done = 1;
    }
  }
}
void postOrder(struct tNode *node) {  // iterative
  if (node == NULL) return;
  struct tNode *stack[100];
  int top = -1;
  struct tNode *current = node;
  while (current != NULL || top != -1) {
    if (current != NULL) {
      stack[++top] = current;
      current = current->left;
    } else {
      struct tNode *temp = stack[top]->right;
      if (temp == NULL) {
        temp = stack[top--];
        printf("%d ", temp->data);
        while (top != -1 && temp == stack[top]->right) {
          temp = stack[top--];
          printf("%d ", temp->data);
        }
      } else {
        current = temp;
      }
    }
  }
}
void push(struct sNode **top_ref, struct tNode *t) {
  struct sNode *new_tNode = (struct sNode *)malloc(sizeof(struct sNode));
  if (new_tNode == NULL) {
    printf("Stack Overflow \n");
    getchar();
    exit(0);
  }
  new_tNode->t = t;
  new_tNode->next = (*top_ref);
  (*top_ref) = new_tNode;
}

bool isEmpty(struct sNode *top) { return (top == NULL) ? 1 : 0; }

struct tNode *pop(struct sNode **top_ref) {
  struct tNode *res;
  struct sNode *top;
  if (isEmpty(*top_ref)) {
    printf("Stack Underflow \n");
    getchar();
    exit(0);
  } else {
    top = *top_ref;
    res = top->t;
    *top_ref = top->next;
    free(top);
    return res;
  }
}

struct tNode *newtNode(int data) {
  struct tNode *tNode = (struct tNode *)malloc(sizeof(struct tNode));
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;

  return (tNode);
}

int main() {
  /* Constructed binary tree is
                    1
                   / \
                  2	  3
                 / \
                4   5
  */
  struct tNode *root = newtNode(1);
  root->left = newtNode(2);
  root->right = newtNode(3);
  root->left->left = newtNode(4);
  root->left->right = newtNode(5);
  printf("Preorder traversal of binary tree is \n");
  preOrder(root);

  printf("\n");
  printf("Inorder traversal of binary tree is \n");
  inOrder(root);

  printf("\n");
  printf("Postorder traversal of binary tree is \n"); 
  postOrder(root);

  getchar();
  return 0;
}
