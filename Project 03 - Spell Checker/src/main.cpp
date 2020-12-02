#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

#include "Word.h"
#include "levenshtein.h"

int main(int argc, char const* argv[]) {
  if (argc <= 2) {
    std::cout << "Usage: " << argv[0]
              << " <path to dictionary file>"
              << " <path to target file>"
              << std::endl;
    return 1;
  }

  std::string dictionary_file_path(argv[1]);
  std::string target_file_path(argv[2]);

  std::ifstream dictionary_file(dictionary_file_path);

  if (not dictionary_file or not dictionary_file.is_open()) {
    std::cout << "Unable to open: " << dictionary_file_path << std::endl;
    return 1;
  }

  std::string dictionary_line;
  std::list<Word> dictionary;

  while (std::getline(dictionary_file, dictionary_line)) {
    if (dictionary_line.length() == 0) continue;

    Word word(dictionary_line);
    dictionary.push_back(word);
  }

  // std::cout << levenshtein<std::string>("casa", "carro") << std::endl;

  return 0;
}
