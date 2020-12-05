#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
  std::unordered_map<std::string, Word> dictionary_map;

  while (std::getline(dictionary_file, dictionary_line)) {
    if (dictionary_line.length() == 0) continue;

    Word word(dictionary_line);
    dictionary_map.insert({word.get_lowercased_name(), word});  // Avg.: O(1)
  }

  std::ifstream target_file(target_file_path);

  if (not target_file or not target_file.is_open()) {
    std::cout << "Unable to open: " << target_file_path << std::endl;
    return 1;
  }

  std::unordered_set<std::string> checked_words;

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
        auto dic_it = dictionary_map.find(current_lowercased_word);

        bool does_word_exist_on_dictionary = dic_it != dictionary_map.end();

        if (does_word_exist_on_dictionary) {
          continue;
        }

        // Avg.: O(1)
        // Worst: O(N)
        auto checked_words_it = checked_words.find(current_lowercased_word);

        bool was_word_already_checked = checked_words_it != checked_words.end();

        if (was_word_already_checked) {
          continue;
        }

        // Avg.: O(1)
        // Worst: O(N)
        checked_words.insert(current_lowercased_word);

        std::vector<Word> word_suggestions;

        // O(N)
        for (auto& i : dictionary_map) {
          size_t score = levenshtein<std::string>(current_lowercased_word,
                                                  i.first);
          i.second.set_score(score);

          if (score < SUGGESTIONS_THRESHOLD) {
            if (word_suggestions.size() < SUGGESTIONS_LIMIT) {
              // O(1)
              word_suggestions.push_back(i.second);
              continue;
            }

            // O(n)
            auto iter = std::find_if(word_suggestions.begin(),
                                     word_suggestions.end(),
                                     [&score](Word& word) {
                                       return word.get_score() > score;
                                     });

            bool found_word_with_bigger_score = iter != word_suggestions.end();

            if (found_word_with_bigger_score) {
              // O(1)
              word_suggestions.push_back(i.second);
              // O(n)
              word_suggestions.erase(iter);
            }

            // O(n)
            iter = std::find_if(word_suggestions.begin(),
                                word_suggestions.end(),
                                [](Word& word) {
                                  return word.get_score() > 1;
                                });

            bool is_suggestions_full_with_good_ones = iter == word_suggestions.end();

            if (is_suggestions_full_with_good_ones) {
              break;
            }
          }
        }

        // O(N * log N)
        std::sort(word_suggestions.begin(), word_suggestions.end());

        std::cout << current_word << ":" << std::endl;

        for (auto& i : word_suggestions) {
          std::cout << "\t- " << i.get_name() << std::endl;
        }

        std::cout << std::endl;
      }

      ++iter;
    }
  }

  return 0;
}
