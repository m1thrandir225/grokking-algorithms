#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int start, int end) {
  int pivot = arr[end];
  int i = start - 1;
  int temp = 0;
  for (int j = start; j < end; j++) {
    if (arr[j] <= pivot) {
      i++;
      temp = arr[j];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i + 1];
  arr[i + 1] = arr[end];
  arr[end] = temp;
  return i + 1;
}

void quicksort(int *arr, int start, int end) {
  if (start < end) {
    int q = partition(arr, start, end);
    quicksort(arr, start, q - 1);
    quicksort(arr, q + 1, end);
  }
}

int main() {
  int arr[10] = {1, 2, 3, 45, 234, 92, 120, 643, 23, 93};
  int len = sizeof(arr) / sizeof(arr[0]);
  printf("Unsorted array: \n");
  for (int i = 0; i < len; i++) {
    printf("%d\n", arr[i]);
  }

  printf("Sorted array: \n");

  quicksort(arr, 0, 9);
  for (int i = 0; i < len; i++) {
    printf("%d\n", arr[i]);
  }

  return 0;
}
