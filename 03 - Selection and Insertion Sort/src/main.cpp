#include <iostream>
#include <string>

#include "array_util.h"
#include "sort.h"
#include "sort_util.h"

void show_usage(const std::string& program_name) {
  std::cout << "Usage:" << std::endl;
  std::cout << program_name << " <array length>";
  std::cout << " <\"selection\" | \"insertion\">" << std::endl;
}

int main(int argc, char const* argv[]) {
  int n = 100;
  std::string sort_method("");

  if (argc <= 2) {
    show_usage(argv[0]);

    return 0;
  } else {
    n = std::stoi(argv[1]);
    sort_method = argv[2];

    if (sort_method.compare("selection") != 0 and
        sort_method.compare("insertion") != 0) {
      show_usage(argv[0]);

      return 0;
    }
  }

  std::cout << "sort method: \033[1;36m" << sort_method << "\033[0m" << std::endl;

  int* A = SortUtil::random_array(n);

  if (!sort_method.compare("selection")) {
    Sort::selection(A, n);
  } else {
    Sort::insertion(A, n);
  }

  ArrayUtil::print_array(A, n);

  delete[] A;

  return 0;
}
