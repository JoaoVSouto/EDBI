#include <iostream>

bool is_number_on_array(int arr[], size_t size, int number) {
  for (size_t i = 0; i < size; ++i) {  // 1 + (n + 1) + n = 2n + 2
    if (number == arr[i]) {            // n + n = 2n
      return true;
    }
  }

  return false;  // 1

  // TOTAL INSTRUCTIONS: 2n + 2 + 2n + 1 = 4n + 3
}

int main() {
  int arr[] = {13, 15, 3, 44, 29, 5,
               36, 21, 6, 10, 4, 11,
               26, 42, 35, 2, 19, 18};
  size_t arrSize = sizeof(arr) / sizeof(arr[0]);

  int number{42};
  std::cout << "is " << number << " on array? " << std::boolalpha
            << is_number_on_array(arr, arrSize, number) << std::endl;

  return 0;
}
