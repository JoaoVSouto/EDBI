#include "sort.h"

#include <iostream>

int Sort::partition(int arr[], int left, int right) {
  int pivot_pos = left;
  int pivot = arr[pivot_pos];

  while (left < right) {
    while (arr[left] <= pivot) {
      left += 1;
    }

    while (arr[right] > pivot) {
      right -= 1;
    }

    if (left < right) {
      int aux = arr[left];
      arr[left] = arr[right];
      arr[right] = aux;
    }
  }

  arr[pivot_pos] = arr[right];
  arr[right] = pivot;

  return right;
}

void Sort::quick(int arr[], int left, int right) {
  if (left < right) {
    int pivot_position = Sort::partition(arr, left, right);
    Sort::quick(arr, left, pivot_position - 1);
    Sort::quick(arr, pivot_position + 1, right);
  }
}
