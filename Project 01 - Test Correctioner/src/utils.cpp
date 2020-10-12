#include "utils.h"

#include <algorithm>

// Credits to https://stackoverflow.com/a/4654718/10183811
bool utils::is_number(const std::string& string) {
  return !string.empty() and
         std::find_if(string.begin(),
                      string.end(),
                      [](unsigned char c) { return !std::isdigit(c); }) == string.end();
}
