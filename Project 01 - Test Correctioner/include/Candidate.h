#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>

class Candidate {
 private:
  std::string name;
  char answers[10];
  unsigned correct_answers;
  unsigned wrong_answers;

 public:
  Candidate();

  void set_name(const std::string& name);
  void set_correct_answers(unsigned correct_answers);
  void set_wrong_answers(unsigned wrong_answers);

  char* get_answers();
};

#endif  // !CANDIDATE_H
