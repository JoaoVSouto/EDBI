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

  std::string get_name();
  char* get_answers();
  unsigned get_correct_answers();
  unsigned get_wrong_answers();
};

#endif  // !CANDIDATE_H
