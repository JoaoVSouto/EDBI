#pragma once

#include <iostream>
#include <limits>

template <typename T>
class DoubledLinkedList {
 public:
  ~DoubledLinkedList() {
    if (size() == 0) {
      return;
    }

    Node* current = first;

    do {
      Node* tmp = current;
      current = current->next;

      delete tmp;
    } while (current != nullptr);
  }

  void print() {
    if (size() == 0) {
      std::cout << "A lista não possui nenhum elemento para ser mostrado!" << std::endl;
      return;
    }

    std::cout << "Imprimindo lista:" << std::endl;

    Node* current = first;

    do {
      std::cout << current->value << std::endl;
      current = current->next;
    } while (current != nullptr);
  }

  void insertAtFront(T value) {
    std::cout << "Inserindo elemento no início da lista: " << value << std::endl;

    Node* newNode = new Node();
    newNode->value = value;

    if (this->size() == 0) {
      this->first = newNode;
      this->last = newNode;

      this->nodeCount++;
      return;
    }

    Node* tmpNode = this->first;
    this->first = newNode;
    this->first->next = tmpNode;
    tmpNode->prev = this->first;

    this->nodeCount++;
  }

  void insertAtBack(T value) {
    std::cout << "Inserindo elemento no final da lista: " << value << std::endl;

    Node* newNode = new Node();
    newNode->value = value;

    if (this->size() == 0) {
      this->first = newNode;
      this->last = newNode;

      this->nodeCount++;
      return;
    }

    Node* tmpNode = this->last;
    this->last = newNode;
    this->last->prev = tmpNode;
    tmpNode->next = this->last;

    this->nodeCount++;
  }

  void insertAt(T value, size_t position) {
    if (position == 0) {
      this->insertAtFront(value);
      return;
    }

    if (position >= this->size()) {
      this->insertAtBack(value);
      return;
    }

    std::cout << "Inserindo elemento na posição "
              << position << " da lista: " << value << std::endl;

    size_t currentPosition = 0;
    Node* currentNode = this->first;

    while (currentPosition < position) {
      currentNode = currentNode->next;
      currentPosition++;
    }

    Node* newNode = new Node();
    newNode->value = value;

    currentNode->prev->next = newNode;
    newNode->prev = currentNode->prev;
    currentNode->prev = newNode;
    newNode->next = currentNode;

    this->nodeCount++;
  }

  void removeAtFront() {
    if (this->size() == 0) {
      std::cout << "A lista não possui nenhum elemento para ser removido!" << std::endl;
      return;
    }

    std::cout << "Removendo elemento do início da lista" << std::endl;

    if (this->size() == 1) {
      delete this->first;

      this->first = nullptr;
      this->last = nullptr;

      this->nodeCount--;

      return;
    }

    Node* tmpNode = this->first;
    this->first = tmpNode->next;
    this->first->prev = nullptr;

    delete tmpNode;

    this->nodeCount--;
  }

  void removeAtBack() {
    if (this->size() == 0) {
      std::cout << "A lista não possui nenhum elemento para ser removido!" << std::endl;
      return;
    }

    std::cout << "Removendo elemento do final da lista" << std::endl;

    if (this->size() == 1) {
      delete this->last;

      this->first = nullptr;
      this->last = nullptr;

      this->nodeCount--;

      return;
    }

    Node* tmpNode = this->last;
    this->last = tmpNode->prev;
    this->last->next = nullptr;

    delete tmpNode;

    this->nodeCount--;
  }

  void removeAt(size_t position) {
    if (position == 0) {
      this->removeAtFront();
      return;
    }

    if (position >= this->size() - 1) {
      this->removeAtBack();
      return;
    }

    std::cout << "Removendo elemento da posição "
              << position << " da lista" << std::endl;

    size_t currentPosition = 0;
    Node* currentNode = this->first;

    while (currentPosition < position) {
      currentNode = currentNode->next;
      currentPosition++;
    }

    currentNode->prev->next = currentNode->next;

    delete currentNode;

    this->nodeCount--;
  }

  size_t size() {
    return this->nodeCount;
  }

  void print_size() {
    std::cout << "Tamanho da lista: " << this->size() << std::endl;
  }

 private:
  struct Node {
    T value;
    Node* prev;
    Node* next;
  };

  Node* first = nullptr;
  Node* last = nullptr;
  size_t nodeCount = 0;
};