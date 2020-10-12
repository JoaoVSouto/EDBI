#include "Candidate.h"

Candidate::Candidate() {}

void Candidate::set_name(const std::string& name) {
  this->name = name;
}

void Candidate::set_correct_answers(unsigned correct_answers) {
  this->correct_answers = correct_answers;
}

void Candidate::set_wrong_answers(unsigned wrong_answers) {
  this->wrong_answers = wrong_answers;
}

char* Candidate::get_answers() {
  return this->answers;
}
