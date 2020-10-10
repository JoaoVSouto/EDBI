#include "array_util.h"

#include <iostream>

void ArrayUtil::print_array(int arr[], int size) {
  std::cout << "[";
  for (int i = 0; i < size; ++i) {
    if (i == size - 1) {
      std::cout << arr[i] << "]" << std::endl;
      continue;
    }

    std::cout << arr[i] << "," << std::endl;
  }
}
