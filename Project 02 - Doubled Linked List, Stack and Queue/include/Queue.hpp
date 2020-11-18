#pragma once

#include <iostream>

template <typename T>
class Queue {
 public:
  ~Queue() {
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

  void pushBack(T value) {
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
    tmpNode->next = this->last;

    this->nodeCount++;
  }

  void popFront() {
    if (this->size() == 0) {
      return;
    }

    if (this->size() == 1) {
      delete this->first;

      this->first = nullptr;
      this->last = nullptr;

      this->nodeCount--;

      return;
    }

    Node* tmpNode = this->first;
    this->first = tmpNode->next;

    delete tmpNode;

    this->nodeCount--;
  }

  T front() {
    if (this->size() == 0) {
      // TODO: ???
    }

    return this->first->value;
  }

  T back() {
    if (this->size() == 0) {
      // TODO: ???
    }

    return this->last->value;
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
  Node* last = nullptr;
  size_t nodeCount = 0;
};
