#include "TestController.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Sort.h"

TestController::TestController(const std::string& file_path)
    : candidates(nullptr),
      candidates_size(0),
      candidates_capacity(8) {
  candidates = new Candidate[candidates_capacity];

  for (int i = 1; i <= this->QUESTIONS_AMOUNT; ++i) {
    Question question(i);

    this->questions[i - 1] = question;
  }

  std::ifstream answers_file(file_path);

  if (not answers_file or not answers_file.is_open()) {
    std::cout << "Error: Unable to open " << file_path << std::endl;
    return;
  }

  std::string line;

  while (std::getline(answers_file, line)) {
    if (line.length() == 0) continue;

    std::stringstream stream(line);
    std::string name;

    stream >> name;

    Candidate candidate;
    candidate.set_name(name);
    char* answers = candidate.get_answers();
    unsigned correct_answers = 0;

    for (int i = 0; i < this->QUESTIONS_AMOUNT; ++i) {
      char alternative;

      stream >> alternative;

      answers[i] = alternative;

      if (alternative == this->QUESTIONS_TEMPLATE[i]) {
        correct_answers += 1;
        this->questions[i].set_correct_amount(
            this->questions[i].get_correct_amount() + 1);
      } else if (alternative > 'E') {
        this->questions[i].set_blank_amount(
            this->questions[i].get_blank_amount() + 1);
      } else {
        this->questions[i].set_incorrect_amount(
            this->questions[i].get_incorrect_amount() + 1);
      }
    }

    candidate.set_correct_answers(correct_answers);
    candidate.set_wrong_answers(this->QUESTIONS_AMOUNT - correct_answers);

    this->add_candidate(candidate);
  }
}

TestController::~TestController() {
  delete[] this->candidates;
}

void TestController::add_candidate(const Candidate& candidate) {
  if (this->candidates_size >= this->candidates_capacity) {
    this->double_candidates_capacity();
  }

  this->candidates[this->candidates_size] = candidate;
  this->candidates_size += 1;
}

void TestController::double_candidates_capacity() {
  this->candidates_capacity *= 2;

  Candidate* tmp_arr = new Candidate[this->candidates_capacity];
  std::copy(this->candidates, this->candidates + this->candidates_size, tmp_arr);

  delete[] this->candidates;
  this->candidates = tmp_arr;
}

void TestController::best_candidates(unsigned long quantity) {
  Sort::best_candidates(this->candidates, 0, this->candidates_size - 1);

  unsigned long quantity_to_show = quantity > this->candidates_size
                                       ? this->candidates_size
                                       : quantity;

  for (unsigned long i = 0; i < quantity_to_show; ++i) {
    std::cout << this->candidates[i].get_name() << " - Acertos: "
              << this->candidates[i].get_correct_answers() << std::endl;
  }
}

void TestController::worst_candidates(unsigned long quantity) {
  Sort::worst_candidates(this->candidates, 0, this->candidates_size - 1);

  unsigned long quantity_to_show = quantity > this->candidates_size
                                       ? this->candidates_size
                                       : quantity;

  for (unsigned long i = 0; i < quantity_to_show; ++i) {
    std::cout << this->candidates[i].get_name() << " - Erros: "
              << this->candidates[i].get_wrong_answers() << std::endl;
  }
}
