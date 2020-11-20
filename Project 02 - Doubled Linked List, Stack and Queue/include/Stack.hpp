#pragma once

#include <iostream>

template <typename T>
class Stack {
 public:
  ~Stack() {
    if (this->size() == 0) {
      return;
    }

    Node* current = this->first;

    do {
      Node* tmp = current;
      current = current->next;

      delete tmp;
    } while (current != nullptr);
  }

  void push(T value) {
    Node* newNode = new Node();
    newNode->value = value;

    Node* tmpNode = this->first;
    this->first = newNode;
    this->first->next = tmpNode;

    this->nodeCount++;
  }

  T top() {
    if (this->size() == 0) {
      throw "Empty stack";
    }

    return this->first->value;
  }

  void pop() {
    if (this->size() == 0) {
      // WARN: invalid case
      return;
    }

    Node* tmpNode = this->first;
    this->first = tmpNode->next;

    delete tmpNode;

    this->nodeCount--;
  }

  size_t size() {
    return this->nodeCount;
  }

 private:
  struct Node {
    T value;
    Node* next;
  };

  Node* first = nullptr;
  size_t nodeCount = 0;
};
