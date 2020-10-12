#ifndef SORT_H
#define SORT_H

#include "Candidate.h"
#include "Question.h"

class Sort {
 private:
  static int partition_best_candidates(Candidate* candidates, int left, int right);
  static int partition_worst_candidates(Candidate* candidates, int left, int right);
  static int partition_questions(Question* questions, int left, int right);
  static int partition_best_questions(Question* questions, int left, int right);
  static int partition_worst_questions(Question* questions, int left, int right);

 public:
  static void best_candidates(Candidate* candidates, int left, int right);
  static void worst_candidates(Candidate* candidates, int left, int right);
  static void questions(Question* questions, int left, int right);
  static void best_questions(Question* questions, int left, int right);
  static void worst_questions(Question* questions, int left, int right);
};

#endif  // !SORT_H
