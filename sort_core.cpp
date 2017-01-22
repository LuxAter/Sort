#include "sort_core.hpp"
#include "sort_headers.hpp"
#include <appareo.h>
#include <map>
#include <pessum.h>
#include <string>
#include <vector>

using namespace appareo::curse;

namespace sort {
std::vector<int> values, scramble;
bool display;
int count = 1000, min = 0, max = 1000;
}

double sort::GenorateValues() {
  double compleated = 0;
  int range = max - min;
  values.clear();
  scramble.clear();
  appareo::induco::Timer(true);
  appareo::induco::CreateProgressBar("Genorating Values");
  while (values.size() < count) {
    int newvalue = (rand() % range);
    newvalue -= min;
    values.push_back(newvalue);
    if (display == true) {
      compleated = values.size() / (double)count;
      appareo::induco::UpdateProgressBar(compleated);
    }
  }
  scramble = values;
  double elapsedtime = appareo::induco::Timer(false);
  if (display == true) {
    appareo::induco::TerminateProgressBar();
  }
  return (elapsedtime);
}

void sort::Reset() {
  values.clear();
  values = scramble;
}

void sort::Clean() {
  values.clear();
  scramble.clear();
}

void sort::RunAlgorithms(std::vector<std::string> algos, bool display) {
  mappedalgos mapping;

  // mapping["Binary Tree"] = &BinaryTreeSort;
  mapping["Bubble"] = &BubbleSort;
  mapping["Bucket"] = &BucketSort;
  mapping["Cocktail"] = &CocktailSort;
  mapping["Counting"] = &CountingSort;
  // mapping["Heap"] = &HeapSort;
  mapping["Insertion"] = &InsertionSort;
  mapping["Merge"] = &MergeSort;
  mapping["Quick"] = &QuickSort;
  // mapping["Radix"] = &RadixSort;
  mapping["Selection"] = &SelectionSort;
  // mapping["Shell"] = &ShellSort;
  // mapping["Tim"] = &TimSort;
  std::vector<double> times;
  times.push_back(GenorateValues());
  for (int i = 0; i < algos.size(); i++) {
    Reset();
    mappedalgos::iterator x = mapping.find(algos[i]);
    if (x != mapping.end()) {
      times.push_back((x->second)(display));
    }
  }
  algos.insert(algos.begin(), "GenVals");
  int wind = windows.size();
  InitializeWindow();
  win->CreateWindow("Results", scrwidth / 2, 3 * scrheight / 4, -1, -1, true,
                    true);
  std::string line = "    ALGORITHM| HOURS |  MIN |  SEC |  MS  |  US";
  out::Print(line, 1, (windows[wind].width - line.size()) / 2, wind);
  for (int i = 0; i < times.size(); i++) {
    line = algos[i];
    while (line.size() < 15) {
      line = " " + line;
    }
    line += "|";
    line += appareo::induco::DisplayTime(times[i], true);
    appareo::curse::out::Print(line, i + 2,
                               (windows[wind].width - line.size()) / 2, wind);
  }
  getch();
  appareo::curse::TerminateWindow(wind);
}
