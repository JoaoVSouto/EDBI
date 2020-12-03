#include <string>

class Word {
  std::string name;
  size_t score;

 public:
  Word(const std::string& name);

  std::string get_name();
  size_t get_score();

  void set_score(size_t score);
};