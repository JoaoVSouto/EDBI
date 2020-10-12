#ifndef TEST_CONTROLLER_H
#define TEST_CONTROLLER_H

#include <string>

#include "Candidate.h"
#include "Question.h"

class TestController {
 private:
  Question questions[10];
  Candidate* candidates;
  size_t candidates_size;
  size_t candidates_capacity;
  const unsigned QUESTIONS_AMOUNT = 10;
  const char QUESTIONS_TEMPLATE[10] = {'A', 'B', 'C', 'D', 'E', 'E', 'D', 'C', 'B', 'A'};

  void add_candidate(const Candidate& candidate);
  void double_candidates_capacity();

 public:
  TestController(const std::string& file_path);
  ~TestController();

  void best_candidates(unsigned long quantity);
  void worst_candidates(unsigned long quantity);
  void best_questions(unsigned long quantity);
};

#endif  // !TEST_CONTROLLER_H
