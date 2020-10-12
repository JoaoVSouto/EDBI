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

std::string Candidate::get_name() {
  return this->name;
}

char* Candidate::get_answers() {
  return this->answers;
}

unsigned Candidate::get_correct_answers() {
  return this->correct_answers;
}

unsigned Candidate::get_wrong_answers() {
  return this->wrong_answers;
}
