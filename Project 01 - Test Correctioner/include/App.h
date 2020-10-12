#ifndef APP_H
#define APP_H

class App {
 private:
  void show_usage();

 public:
  App();

  int run(int argc, char const *argv[]);
};

#endif  // !APP_H
