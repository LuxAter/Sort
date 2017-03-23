#ifndef SORT_SORTING_SORT_HPP
#define SORT_SORTING_SORT_HPP
#include <ostendo.h>
#include <string>
namespace sort {
  extern bool running;
  extern std::vector<std::string> help_doc;
  extern ostendo::Window win;
  void MainLoop();
  void PrintOpen();
  void Help(int page);
  void LoadHelp();
  void RunInput(std::string input);
  int IsInt(std::string str);
  std::string NormalizeInput(std::string input);
}
#endif
