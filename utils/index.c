#include "../push_swap.h"

static int *bubble_sort(int size, int *arr) {
  int i;
  int j;
  int temp;
  int *sorted;

  sorted = malloc(sizeof(int) * size);
  if (!sorted)
    return (NULL);

  i = 0;
  while (i < size) {
    sorted[i] = arr[i];
    i++;
  }

  i = 0;
  while (i < size - 1) {
    j = 0;
    while (j < size - i - 1) {
      if (sorted[j] > sorted[j + 1]) {
        temp = sorted[j];
        sorted[j] = sorted[j + 1];
        sorted[j + 1] = temp;
      }
      j++;
    }
    i++;
  }
  return (sorted);
}

int *index_finder(int size, int *arr) {
  int *sorted;
  int *index_arr;
  int i;
  int j;

  sorted = bubble_sort(size, arr);
  if (!sorted)
    return (NULL);
  index_arr = malloc(sizeof(int) * size);
  if (!index_arr) {
    free(sorted);
    return (NULL);
  }
  i = 0;
  while (i < size) {
    j = 0;
    while (j < size) {
      if (arr[i] == sorted[j]) {
        index_arr[i] = j;
        break;
      }
      j++;
    }
    i++;
  }
  free(sorted);
  return (index_arr);
}
