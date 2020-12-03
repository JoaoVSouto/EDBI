#include "Word.h"

Word::Word(const std::string& name) : name(name), score(0) {
}

std::string Word::get_name() {
  return this->name;
}

size_t Word::get_score() {
  return this->score;
}

void Word::set_score(size_t score) {
  this->score = score;
}
