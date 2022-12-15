#include <stdio.h>
int main() {
  int arr[] = {2, 7, 4, 1, 5, 3};
  int temp;
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("Unsorted Array : \n");
  for (int i = 0; i < size; i++) {
    printf(" %d ", arr[i]);
  }

  printf("\n");

  for (int j = size; j > 0; j--) {
    for (int i = 0; i < size; i++) {
      if (arr[i] < arr[i - 1]) {
        temp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
      }
    }
  }
  printf("Sorted Array : \n");
  for (int i = 0; i < size; i++) {
    printf(" %d ", arr[i]);
  }

  return 0;
}