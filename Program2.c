#include <stdio.h>
int binarySearch(int size, int arr[], int item, int si, int ei) {
  if (ei >= 1) {
    int mid = (si + ei) / 2;
    if (si > ei) {
      return -1;  // or false
    } else if (item == arr[mid]) {
      return mid;
    } else if (item > arr[mid]) {
      return binarySearch(size, arr, item, mid + 1, ei);
    } else if (item < arr[mid]) {
      return binarySearch(size, arr, item, si, mid - 1);
    }
  }

  return -1;
}
int main() {
  int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
  int item=55;
  // printf("Enter value to be searched: ");
  // scanf("%d", &item);
  int size = sizeof(arr) / sizeof(arr[2]);
  printf("size is %d \n", size);
  int result = binarySearch(size, arr, item, 0, size - 1);  // si= 0 and ei=9
  for (int i = 0; i < size; i++) {
    printf(" %d ,", arr[i]);
  }
  printf("\n");

  if (result == -1) {
    printf("Element is not present!");
  } else {
    printf("Element is present at %d th index ", result);
  }

  return 0;
}