#include "Word.h"

#include <algorithm>

Word::Word(const std::string& name) : name(name), lowercased_name(name), score(0) {
  std::transform(this->lowercased_name.begin(),
                 this->lowercased_name.end(),
                 this->lowercased_name.begin(),
                 ::tolower);
}

bool Word::operator<(Word& word) const {
  return this->score < word.get_score();
}

std::string Word::get_name() {
  return this->name;
}

std::string Word::get_lowercased_name() {
  return this->lowercased_name;
}

size_t Word::get_score() {
  return this->score;
}

void Word::set_score(size_t score) {
  this->score = score;
}
