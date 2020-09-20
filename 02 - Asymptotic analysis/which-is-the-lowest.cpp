#include <iostream>

int lowest(int arr[], size_t size) {
  int lowest{arr[0]};  // 2

  for (size_t i = 1; i < size; ++i) {  // 1 + n + (n - 1) = 2n
    if (arr[i] < lowest) {             // n - 1 + n - 1 = 2n - 2
      lowest = arr[i];                 // n - 1 + n - 1 = 2n - 2
    }
  }

  return lowest;  // 1

  // TOTAL INSTRUCTIONS: 2 + 2n + 2n - 2 + 2n - 2 + 1 = 6n - 1
}

int main() {
  int arr[] = {13, 15, 3, 44, 29, 5,
               36, 21, 6, 10, 4, 11,
               26, 42, 35, 2, 19, 18};
  size_t arrSize = sizeof(arr) / sizeof(arr[0]);

  std::cout << "the lowest number is " << lowest(arr, arrSize) << std::endl;

  return 0;
}
