#include "sort.h"

void Sort::selection(int arr[], int size) {
  for (int i = 0; i < size - 1; ++i) {
    int min = i;

    for (int j = i + 1; j < size; ++j) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    int aux = arr[i];
    arr[i] = arr[min];
    arr[min] = aux;
  }
}

void Sort::insertion(int arr[], int size) {
  for (int i = 1; i < size; ++i) {
    int j = i - 1;
    int tmp = arr[i];

    while (j >= 0) {
      if (tmp >= arr[j]) {
        break;
      }

      int aux = arr[j];
      arr[j] = arr[j + 1];
      arr[j + 1] = aux;

      j -= 1;
    }
  }
}
