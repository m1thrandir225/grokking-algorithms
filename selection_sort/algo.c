#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Helper function to find the current smallest index in an array
 */
int find_smallest(int *arr, int len) {
  int smallest = arr[0];
  int smallest_index = 0;

  for (int i = 0; i < len; i++) {
    if (arr[i] < smallest) {
      smallest = arr[i];
      smallest_index = i;
    }
  }
  return smallest_index;
}
/*
 *
 * Selection sort algorithm
 */
int *selection_sort(int *arr, int len) {
  int *newArr = (int *)malloc(len * sizeof(int));

  for (int i = 0; i < len; i++) {
    int smallest = find_smallest(arr, len);
    newArr[i] = arr[smallest];
    arr[smallest] = INT_MAX;
  }

  return newArr;
}

int main() {
  int arr[] = {1, 8, 12, 5, 4, 45, 18, 32, 69, 88, 102};
  int len = sizeof(arr) / sizeof(arr[0]);
  printf("Unsorted arr: \n");
  for (int i = 0; i < len; i++) {
    printf("%d\n", arr[i]);
  }

  int *sorted = selection_sort(arr, len);

  printf("Sorted array: \n");

  for (int i = 0; i < len; i++) {
    printf("%d\n", sorted[i]);
  }
  return 0;
}
