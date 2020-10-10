#include "sort_util.h"

#include <random>

int SortUtil::get_random_int(int min, int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distribution(min, max);

  return distribution(gen);
}

int* SortUtil::random_array(int n) {
  int* A = new int[n];

  for (int i = 0; i < n; ++i) {
    A[i] = SortUtil::get_random_int(-n, n);
  }

  return A;
}
