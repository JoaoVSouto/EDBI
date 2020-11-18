#include "DoubledLinkedList.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

int main(int argc, char const *argv[]) {
  DoubledLinkedList<int> list;
  Stack<int> stack;
  Queue<int> queue;

  queue.pushBack(10);
  queue.pushBack(20);
  queue.popFront();
  queue.pushBack(30);
  queue.pushBack(40);
  queue.pushBack(50);
  queue.popFront();

  std::cout << "front: " << queue.front() << std::endl;
  std::cout << "back: " << queue.back() << std::endl;

  return 0;
}
