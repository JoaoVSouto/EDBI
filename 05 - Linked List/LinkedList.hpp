#pragma once

#include <iostream>
#include <limits>

template <typename T>
class LinkedList {
 public:
  LinkedList() {}

  LinkedList(const LinkedList<T>& other) {
    clone(other);
  }

  LinkedList& operator=(const LinkedList<T>& other) {
    if (&other == this) {
      return *this;
    }

    clear();
    clone(other);

    return *this;
  }

  T& operator[](size_t index) {
    if (index >= size()) {
      // TODO: throw exception
    }

    Node* current = first;
    size_t currentIndex = 0;

    while (currentIndex < index) {
      current = current->next;
      currentIndex += 1;
    }

    return current->value;
  }

  ~LinkedList() {
    clear();
  }

  void insert(T value) {
    if (first != nullptr) {
      Node* other = new Node();
      other->value = value;
      last->next = other;
      last = other;
    } else {
      first = new Node();
      first->value = value;
      last = first;
    }

    ++nodeCount;
  }

  void print() {
    if (size() == 0) {
      return;
    }

    Node* current = first;

    do {
      std::cout << current->value << std::endl;
      current = current->next;
    } while (current != nullptr);
  }

  void insertAt(size_t position, T value) {
    if (position >= size()) {
      insert(value);

      return;
    }

    size_t currentPosition = 0;
    Node* previousNode = nullptr;
    Node* currentNode = first;

    while (currentPosition < position) {
      previousNode = currentNode;
      currentNode = currentNode->next;
      currentPosition++;
    }

    Node* newNode = new Node();
    newNode->value = value;

    if (position == 0) {
      first = newNode;
    } else {
      previousNode->next = newNode;
    }

    newNode->next = currentNode;

    nodeCount++;
  }

  size_t search(T value) {
    size_t foundValuePosition = std::numeric_limits<size_t>::max();

    if (size() == 0) {
      return foundValuePosition;
    }

    Node* current = first;
    size_t currentPosition = 0;

    do {
      if (current->value == value) {
        foundValuePosition = currentPosition;
        break;
      }

      current = current->next;
      currentPosition++;
    } while (current != nullptr);

    return foundValuePosition;
  }

  void removeAt(size_t position) {
    if (position >= size()) {
      return;
    }

    size_t currentPosition = 0;
    Node* previousNode = nullptr;
    Node* currentNode = first;

    while (currentPosition < position) {
      previousNode = currentNode;
      currentNode = currentNode->next;
      currentPosition++;
    }

    if (position == 0) {
      first = currentNode->next;
    } else {
      previousNode->next = currentNode->next;
    }

    if (position == size() - 1) {
      last = size() == 1 ? nullptr : previousNode;
    }

    delete currentNode;
    --nodeCount;
  }

  size_t size() {
    return nodeCount;
  }

  void clear() {
    if (size() == 0) {
      return;
    }

    Node* current = first;

    do {
      Node* tmp = current;
      current = current->next;

      delete tmp;
    } while (current != nullptr);

    nodeCount = 0;
    first = nullptr;
    last = nullptr;
  }

 private:
  struct Node {
    T value;
    Node* next;
  };

  Node* first = nullptr;
  Node* last = nullptr;
  size_t nodeCount = 0;

  void clone(const LinkedList<T>& other) {
    if (other.nodeCount == 0) {
      return;
    }

    Node* current = other.first;

    while (current != nullptr) {
      insert(current->value);
      current = current->next;
    }
  }
};
