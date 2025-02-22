#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int item, int len) {
  int low, high, mid = 0, guess = 0;
  low = 0;
  high = len;

  while (low <= high) {
    mid = (low + high) / 2;
    guess = arr[mid];
    if (guess == item) {
      return mid;
    }
    if (guess > item) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

int main() {

  int arr[] = {1, 2, 3, 4, 5, 7, 10, 20};
  int len = sizeof(arr) / sizeof(arr[0]);
  int result = binary_search(arr, 10, len);

  printf("Index of element: %d", result);
  return 0;
}
