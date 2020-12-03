#include <fstream>
#include <iostream>
#include <list>
#include <regex>
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

  std::ifstream target_file(target_file_path);

  if (not target_file or not target_file.is_open()) {
    std::cout << "Unable to open: " << target_file_path << std::endl;
    return 1;
  }

  std::string target_line;

  while (std::getline(target_file, target_line)) {
    if (target_line.length() == 0) continue;

    std::regex word_regex("[a-zA-Z\u00C0-\u00D6\u00D8-\u00F6\u00F8-\u024F]+");

    std::sregex_iterator iter(target_line.begin(), target_line.end(), word_regex);
    std::sregex_iterator end;

    while (iter != end) {
      for (unsigned i = 0; i < iter->size(); ++i) {
        std::string word((*iter)[i]);
        std::string word_without_double_angle(word);

        if (word.find("«") != std::string::npos or
            word.find("»") != std::string::npos) {
          std::regex double_angle_regex("[«»]+");

          word_without_double_angle =
              std::regex_replace(word, double_angle_regex, "");

          if (word_without_double_angle.length() == 0) {
            continue;
          }
        }

        std::transform(word_without_double_angle.begin(),
                       word_without_double_angle.end(),
                       word_without_double_angle.begin(),
                       ::tolower);

        bool found_equal = false;

        // O(N)
        for (auto& i : dictionary) {
          std::string lowercased_name(i.get_name());

          std::transform(lowercased_name.begin(),
                         lowercased_name.end(),
                         lowercased_name.begin(),
                         ::tolower);

          size_t score = levenshtein<std::string>(word_without_double_angle,
                                                  lowercased_name);
          i.set_score(score);

          if (score == 0) {
            found_equal = true;
            break;
          }
        }

        if (found_equal) {
          continue;
        }

        // O(N * log N)
        dictionary.sort([word_without_double_angle](Word& a, Word& b) -> bool {
          return a.get_score() < b.get_score();
        });

        std::cout << word_without_double_angle << ":" << std::endl;

        size_t counter = 0;
        for (auto& i : dictionary) {
          if (counter >= 5 or i.get_score() >= 3) {
            break;
          }

          std::cout << "\t - " << i.get_name() << std::endl;

          ++counter;
        }

        std::cout << std::endl;
      }

      ++iter;
    }
  }

  return 0;
}
