#include <cstdio>
#include <iostream>

#include "LinkedList.hpp"

int main(int argc, char* argv[]) {
  LinkedList<int> list;

  list.insert(33);
  list.insert(72);
  list.insert(95);
  list.insertAt(3, 777);
  list.insertAt(12, 222);
  list.removeAt(4);
  list.removeAt(3);
  list.removeAt(2);

  // std::cout << list.last->value << std::endl;

  return 0;
}
