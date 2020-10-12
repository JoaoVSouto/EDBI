#include "App.h"

#include <iostream>
#include <string>

#include "TestController.h"
#include "utils.h"

App::App() {}

void App::show_usage() {
  std::cout
      << "Usage: <answers file path> <\"best\" | \"worst\" | \"best-questions\" | \"worst-questions\" | \"blank-questions\"> <number>"
      << std::endl;
}

int App::run(int argc, char const *argv[]) {
  if (argc < 4) {
    this->show_usage();
    return 1;
  }

  std::string file_path(argv[1]);
  std::string action_type(argv[2]);

  bool is_invalid_action = action_type.compare("best") != 0 and
                           action_type.compare("worst") != 0 and
                           action_type.compare("best-questions") != 0 and
                           action_type.compare("worst-questions") != 0 and
                           action_type.compare("blank-questions") != 0;

  if (is_invalid_action) {
    this->show_usage();
    return 1;
  }

  std::string quantity_str(argv[3]);

  if (not utils::is_number(quantity_str)) {
    this->show_usage();
    return 1;
  }

  unsigned long quantity{std::stoul(quantity_str)};

  TestController test_controller(file_path);

  if (!action_type.compare("best")) {
    test_controller.best_candidates(quantity);
  } else if (!action_type.compare("worst")) {
    test_controller.worst_candidates(quantity);
  } else if (!action_type.compare("best-questions")) {
    test_controller.best_questions(quantity);
  } else if (!action_type.compare("worst-questions")) {
    test_controller.worst_questions(quantity);
  } else if (!action_type.compare("blank-questions")) {
    test_controller.blank_questions(quantity);
  }

  return 0;
}
