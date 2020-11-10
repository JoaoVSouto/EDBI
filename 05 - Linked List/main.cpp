#include <cstdio>
#include <iostream>

// #include "LinkedList.hpp"
#include "LinkedListWithSortedInsert.hpp"

int main(int argc, char* argv[]) {
  LinkedListWithSortedInsert<int> list;

  list.insert(33);
  list.insert(72);
  list.insert(33);
  list.insert(72);
  list.insert(12);

  list.print();

  return 0;
}
