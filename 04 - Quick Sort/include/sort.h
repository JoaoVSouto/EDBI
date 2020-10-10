#ifndef SORT_H
#define SORT_H

class Sort {
 private:
  static int partition(int arr[], int start, int end);

 public:
  static void quick(int arr[], int left, int right);
};

#endif  // !SORT_H
