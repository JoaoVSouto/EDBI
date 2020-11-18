#include "DoubledLinkedList.hpp"
#include "Stack.hpp"

int main(int argc, char const *argv[]) {
  DoubledLinkedList<int> list;
  Stack<int> stack;

  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(40);
  std::cout << "top: " << stack.top() << std::endl;
  stack.pop();
  std::cout << "size: " << stack.size() << std::endl;
  std::cout << "top: " << stack.top() << std::endl;
  stack.pop();
  stack.pop();
  stack.pop();
  std::cout << "size: " << stack.size() << std::endl;
  stack.push(33);
  stack.push(21);
  std::cout << "size: " << stack.size() << std::endl;
  stack.pop();
  std::cout << "top: " << stack.top() << std::endl;

  return 0;
}
