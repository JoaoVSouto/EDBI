#include <chrono>
#include <iostream>

using namespace std::chrono;

typedef unsigned long long int ull;

int main() {
  auto start = high_resolution_clock::now();

  unsigned n{1000000000};  // 1

  ull sum{n * (n + 1ULL) / 2ULL};  // 4

  // TOTAL INSTRUCTIONS: 5

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<nanoseconds>(stop - start);

  std::cout << "total duration: " << duration.count() << "ns" << std::endl;

  std::cout << "total sum: " << sum << std::endl;

  return 0;
}
