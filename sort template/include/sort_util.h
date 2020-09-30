#ifndef SORT_UTIL_H
#define SORT_UTIL_H

// int get_random_int(int min, int max);
// int* random_array(int n);

class SortUtil {
 public:
  static int* random_array(int n);

 private:
  static int get_random_int(int min, int max);
};

#endif  // !SORT_UTIL_H
