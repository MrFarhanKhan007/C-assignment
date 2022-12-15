#include <stdio.h>

int main() {
  int arr[100] = {0};
  int i, x, k, n = 10;

  for (i = 0; i < 10; i++) arr[i] = i + 1;

  for (i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");

  printf("Enter element to be inserted: ");
  scanf("%d", &x);

  printf("Enter position: ");
  scanf("%d", &k);

  n++;

  for (i = n - 1; i >= k; i--) {
    arr[i] = arr[i - 1];
  }
  arr[k - 1] = x;

  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
