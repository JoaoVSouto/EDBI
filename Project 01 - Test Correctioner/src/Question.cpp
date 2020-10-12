#include "Question.h"

Question::Question() {}

Question::Question(unsigned number)
    : number(number),
      correct_amount(0),
      incorrect_amount(0),
      blank_amount(0) {}

void Question::set_number(unsigned number) {
  this->number = number;
}

void Question::set_correct_amount(unsigned correct_amount) {
  this->correct_amount = correct_amount;
}

void Question::set_incorrect_amount(unsigned incorrect_amount) {
  this->incorrect_amount = incorrect_amount;
}

void Question::set_blank_amount(unsigned blank_amount) {
  this->blank_amount = blank_amount;
}

unsigned Question::get_number() {
  return this->number;
}

unsigned Question::get_correct_amount() {
  return this->correct_amount;
}

unsigned Question::get_incorrect_amount() {
  return this->incorrect_amount;
}

unsigned Question::get_blank_amount() {
  return this->blank_amount;
}
