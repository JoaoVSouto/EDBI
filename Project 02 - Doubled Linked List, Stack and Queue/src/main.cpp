#include "DoubledLinkedList.hpp"

int main(int argc, char const *argv[]) {
  DoubledLinkedList<int> list;

  list.insertAtBack(1);
  list.insertAtBack(3);
  list.insertAt(2, 1);      // 1  2 3
  list.insertAtFront(22);   // 22 1 2 3
  list.removeAtBack();      // 22 1 2
  list.insertAtFront(777);  // 777 22 1 2
  list.insertAt(33, 3);     // 777 22 1 33 2
  list.removeAtFront();     // 22 1 33 2
  list.insertAtBack(777);   //  22 1 33 2 777
  list.print();

  return 0;
}
