#include "sort_headers.hpp"
#include <algorithm>
#include <appareo.h>
#include <pessum.h>

using namespace appareo::curse;

int main(int argc, char const *argv[]) {
  appareo::InitializeAppareo();
  std::vector<std::string> algorithms = {
      "Binary Tree", "Bubble",    "Bucket", "Cocktail", "Counting",
      "Heap",        "Insertion", "Merge",  "Quick",    "Radix",
      "Selection",   "Shell",     "Tim"};
  std::sort(algorithms.begin(), algorithms.end());
  std::vector<std::string> options = {"Analize All",    "Analize Select",
                                      "Run All",        "Run Select",
                                      "Set Paramaters", "Quit"};
  bool running = true;
  while (running == true) {
    std::vector<std::string> inputs =
        NewMenu(options, "Sorting Algorithms", scrwidth / 2, 3 * scrheight / 4);
    if (inputs[0] == "Run All") {
      sort::RunAlgorithms(algorithms, true);
    }
    if (inputs[0] == "Run Select") {
      std::vector<std::string> select =
          NewMenu(algorithms, "Run Select", scrwidth / 2, 3 * scrheight / 4, -1,
                  -1, true);
      sort::RunAlgorithms(select, true);
    }
    if (inputs[0] == "Set Paramaters") {
      std::vector<Field> fields;
      Field newfield;
      newfield.name = "Count";
      newfield.type = 1;
      newfield.sval = std::to_string(sort::count);
      fields.push_back(newfield);
      newfield.name = "Minimum";
      newfield.sval = std::to_string(sort::min);
      fields.push_back(newfield);
      newfield.name = "Maximum";
      newfield.sval = std::to_string(sort::max);
      fields.push_back(newfield);
      fields = NewForm(fields, "Paramaters", scrwidth / 3, 5);
      sort::count = fields[0].ival;
      sort::min = fields[1].ival;
      sort::max = fields[2].ival;
    }
    if (inputs[0] == "Quit") {
      running = false;
    }
  }
  appareo::TerminateAppareo();
  return 0;
}
