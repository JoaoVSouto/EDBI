#ifndef QUESTION_H
#define QUESTION_H

class Question {
 private:
  unsigned number;
  unsigned correct_amount;
  unsigned incorrect_amount;
  unsigned blank_amount;

 public:
  Question();
  Question(unsigned number);

  void set_number(unsigned number);
  void set_correct_amount(unsigned correct_amount);
  void set_incorrect_amount(unsigned incorrect_amount);
  void set_blank_amount(unsigned blank_amount);

  unsigned get_number();
  unsigned get_correct_amount();
  unsigned get_incorrect_amount();
  unsigned get_blank_amount();
};

#endif  // !QUESTION_H
