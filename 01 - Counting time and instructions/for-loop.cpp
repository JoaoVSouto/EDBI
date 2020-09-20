#include <chrono>
#include <iostream>

using namespace std::chrono;

typedef unsigned long long int ull;

int main() {
  auto start = high_resolution_clock::now();

  unsigned n{1000000000};  // 1
  ull sum{0};              // 1

  for (size_t i = 1; i <= n; ++i) {  // 1 + (n + 1) + n = 2n + 2
    sum += i;                        // 2n
  }

  // TOTAL INSTRUCTIONS: 4n + 4

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<nanoseconds>(stop - start);

  std::cout << "total duration: " << duration.count() << "ns" << std::endl;

  std::cout << "total sum: " << sum << std::endl;

  return 0;
}
