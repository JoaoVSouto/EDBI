#ifndef SORT_H
#define SORT_H

#include "Candidate.h"

class Sort {
 private:
  static int partition_best_candidates(Candidate* candidates, int left, int right);

 public:
  static void best_candidates(Candidate* candidates, int left, int right);
};

#endif  // !SORT_H
