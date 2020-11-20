#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "DoubledLinkedList.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

int main(int argc, char const* argv[]) {
  if (argc == 1) {
    std::cout << "Usage: " << argv[0] << " <path to instructions file>" << std::endl;
    return 1;
  }

  DoubledLinkedList<int> list;
  Stack<int> stack;
  Queue<int> queue;

  std::string file_path(argv[1]);

  std::ifstream instructions_file(file_path);

  if (not instructions_file or not instructions_file.is_open()) {
    std::cout << "Unable to open: " << file_path << std::endl;
    return 1;
  }

  std::string line;

  while (std::getline(instructions_file, line)) {
    if (line.length() == 0) continue;

    std::stringstream stream(line);
    std::string structure;
    std::string operation;

    stream >> structure;
    stream >> operation;

    if (!structure.compare("list")) {
      if (!operation.compare("print")) {
        std::cout << "Imprimindo lista:" << std::endl;
        list.print();
      } else if (!operation.compare("insertAtFront")) {
        int value;
        stream >> value;

        std::cout << "Inserindo elemento no início da lista: " << value << std::endl;
        list.insertAtFront(value);
      } else if (!operation.compare("insertAtBack")) {
        int value;
        stream >> value;

        std::cout << "Inserindo elemento no final da lista: " << value << std::endl;
        list.insertAtBack(value);
      } else if (!operation.compare("insertAt")) {
        int value;
        size_t position;

        stream >> value;
        stream >> position;

        std::cout << "Inserindo elemento na posição " << position
                  << " da lista: " << value << std::endl;
        list.insertAt(value, position);
      } else if (!operation.compare("removeAtFront")) {
        std::cout << "Removendo elemento do início da lista" << std::endl;
        list.removeAtFront();
      } else if (!operation.compare("removeAtBack")) {
        std::cout << "Removendo elemento do final da lista" << std::endl;
        list.removeAtBack();
      } else if (!operation.compare("removeAt")) {
        size_t position;
        stream >> position;

        std::cout << "Removendo elemento da posição " << position << " da lista" << std::endl;
        list.removeAt(position);
      } else if (!operation.compare("size")) {
        std::cout << "Tamanho da lista: " << list.size() << std::endl;
      }
    }

    if (!structure.compare("stack")) {
      if (!operation.compare("push")) {
        int value;
        stream >> value;

        std::cout << "Inserindo elemento na pilha: " << value << std::endl;
        stack.push(value);
      } else if (!operation.compare("top")) {
        try {
          int top = stack.top();
          std::cout << "Elemento do topo da pilha: " << top << std::endl;
        } catch (char const* error) {
          std::cout << "Não foi possível acessar o elemento do topo da pilha: "
                    << error << std::endl;
        }
      } else if (!operation.compare("pop")) {
        std::cout << "Removendo elemento da pilha" << std::endl;
        stack.pop();
      } else if (!operation.compare("size")) {
        std::cout << "Tamanho da pilha: " << stack.size() << std::endl;
      }
    }

    if (!structure.compare("queue")) {
      if (!operation.compare("pushBack")) {
        int value;
        stream >> value;

        std::cout << "Inserindo elemento na fila: " << value << std::endl;
        queue.pushBack(value);
      } else if (!operation.compare("popFront")) {
        std::cout << "Removendo elemento da fila" << std::endl;
        queue.popFront();
      } else if (!operation.compare("front")) {
        try {
          int front = queue.front();
          std::cout << "Primeiro elemento da fila: " << front << std::endl;
        } catch (char const* error) {
          std::cout << "Não foi possível acessar o primeiro elemento da fila: "
                    << error << std::endl;
        }
      } else if (!operation.compare("back")) {
        try {
          int back = queue.back();
          std::cout << "Último elemento da fila: " << back << std::endl;
        } catch (char const* error) {
          std::cout << "Não foi possível acessar o último elemento da fila: "
                    << error << std::endl;
        }
      } else if (!operation.compare("size")) {
        std::cout << "Tamanho da fila: " << queue.size() << std::endl;
      }
    }
  }

  return 0;
}
