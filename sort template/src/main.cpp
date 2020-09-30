#include <iostream>
#include <string>

#include "sort_util.h"

int main(int argc, char const* argv[]) {
  int n = 100;

  if (argc <= 1) {
    std::cout << "Usage:" << std::endl;
    std::cout << argv[0] << " <array length>" << std::endl;
  } else {
    n = std::stoi(argv[1]);
  }

  int* A = SortUtil::random_array(n);

  std::cout << "[";
  for (int i = 0; i < n; ++i) {
    if (i == n - 1) {
      std::cout << A[i] << "]" << std::endl;
      continue;
    }

    std::cout << A[i] << ", ";
  }

  delete[] A;

  return 0;
}
