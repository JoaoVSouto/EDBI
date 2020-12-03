#include <fstream>
#include <iostream>
#include <list>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_map>

#include "Word.h"
#include "levenshtein.h"

const int SUGGESTIONS_THRESHOLD = 3;
const int SUGGESTIONS_LIMIT = 5;

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
  std::unordered_map<std::string, bool> dictionary_map;

  while (std::getline(dictionary_file, dictionary_line)) {
    if (dictionary_line.length() == 0) continue;

    Word word(dictionary_line);
    dictionary.push_back(word);                                 // O(1)
    dictionary_map.insert({word.get_lowercased_name(), true});  // O(1)
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

        std::string current_word(word_without_double_angle);
        std::string current_lowercased_word(word_without_double_angle);

        std::transform(current_lowercased_word.begin(),
                       current_lowercased_word.end(),
                       current_lowercased_word.begin(),
                       ::tolower);

        // Avg.: O(1)
        // Worst: O(N)
        auto it = dictionary_map.find(current_lowercased_word);

        if (it != dictionary_map.end()) {
          continue;
        }

        // TODO: tentar jogar isso pra dentro do sort
        // O(N)
        for (auto& i : dictionary) {
          size_t score = levenshtein<std::string>(current_lowercased_word,
                                                  i.get_lowercased_name());
          i.set_score(score);
        }

        // O(N * log N)
        dictionary.sort([](Word& a, Word& b) -> bool {
          return a.get_score() < b.get_score();
        });

        std::cout << current_word << ":" << std::endl;

        size_t counter = 0;
        for (auto& i : dictionary) {
          if (counter >= SUGGESTIONS_LIMIT or
              i.get_score() >= SUGGESTIONS_THRESHOLD) {
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
