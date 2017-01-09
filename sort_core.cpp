#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <appareo_files/appareo_headers.h>
#include "sort_headers.h"
namespace sort {
std::vector<int> values;
std::vector<int> scrambledvalues;
}

int sort::GenorateValues(int count, int min, int max, bool display) {
  double compleated = 0;
  int range = max - min;
  values.clear();
  scrambledvalues.clear();
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
  scrambledvalues = values;
  if (display == true) {
    appareo::induco::TerminateProgressBar();
    appareo::curse::out::Print("Genorated " + std::to_string(count));
    appareo::curse::out::NewLine();
    appareo::curse::out::Print(appareo::induco::DisplayTime(appareo::induco::Timer(false), true));
    appareo::curse::out::NewLine();
  }
  return (0);
}

void sort::List() {
  for (int i = 0; i < values.size(); i++) {
    std::cout << values[i] << ",";
  }
  std::cout << "\n";
}

void sort::Reset() {
  values.clear();
  values = scrambledvalues;
}
void sort::Clean() {
  values.clear();
  scrambledvalues.clear();
}

bool sort::CheckSort() {
  for (int i = 1; i < values.size(); i++) {
    if (values[i - 1] > values[i]) {
      return (false);
    }
  }
  return (true);
}

void sort::UseAll() {
  std::vector<double> times;
  std::vector<std::string> algorithms = {"Bubble",    "Bucket", "Counting",
                                         "Insertion", "Merge",  "Quick",
                                         "Selection"};
  std::cout << algorithms[0] << ":\n";
  times.push_back(BubbleSort(false));
  Reset();
  std::cout << algorithms[1] << ":\n";
  times.push_back(BucketSort(10, false));
  Reset();
  std::cout << algorithms[2] << ":\n";
  times.push_back(CountingSort(false));
  Reset();
  std::cout << algorithms[3] << ":\n";
  times.push_back(InsertionSort(false));
  Reset();
  std::cout << algorithms[4] << ":\n";
  times.push_back(MergeSort(false));
  Reset();
  std::cout << algorithms[5] << ":\n";
  times.push_back(QuickSort(false));
  Reset();
  std::cout << algorithms[6] << ":\n";
  times.push_back(SelectionSort(false));
  Reset();
  //induco::Line(51);
  //std::cout << "   ALGORITHM   | HOURS |  MIN |  SEC |  MS  |  US  \n";
  for (int i = 0; i < times.size(); i++) {
    //std::string line = "";
    //line = algorithms[i];
    //while (line.size() < 15) {
    //  line = " " + line;
    //}
    //line += "|";
    //line += induco::DisplayTime(times[i], true) + "\n";
    //std::cout << line;
  }
  //induco::Pause();
}
