#include <appareo_files/appareo_headers.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
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
    appareo::curse::out::Print(
        appareo::induco::DisplayTime(appareo::induco::Timer(false), true));
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
  appareo::induco::CreateProgressBar("Running");
  int win = appareo::curse::windows.size();
  appareo::curse::InitializeWindow();
  appareo::curse::windows[win].CreateWindow(
      "Algorithms", appareo::curse::scrwidth / 2,
      (appareo::curse::scrheight / 2) - 4, -1,
      (appareo::curse::scrheight / 2) + 3);
  appareo::curse::out::Print(algorithms[0], -1, -1, win);
  appareo::curse::out::NewLine(win);
  times.push_back(BubbleSort(false));
  appareo::induco::UpdateProgressBar(times.size() / (double)algorithms.size());
  Reset();
  appareo::curse::out::Print(algorithms[1], -1, -1, win);
  appareo::curse::out::NewLine(win);
  times.push_back(BucketSort(10, false));
  appareo::induco::UpdateProgressBar(times.size() / (double)algorithms.size());
  Reset();
  appareo::curse::out::Print(algorithms[2], -1, -1, win);
  appareo::curse::out::NewLine(win);
  times.push_back(CountingSort(false));
  appareo::induco::UpdateProgressBar(times.size() / (double)algorithms.size());
  Reset();
  appareo::curse::out::Print(algorithms[3], -1, -1, win);
  appareo::curse::out::NewLine(win);
  times.push_back(InsertionSort(false));
  appareo::induco::UpdateProgressBar(times.size() / (double)algorithms.size());
  Reset();
  appareo::curse::out::Print(algorithms[4], -1, -1, win);
  appareo::curse::out::NewLine(win);
  times.push_back(MergeSort(false));
  appareo::induco::UpdateProgressBar(times.size() / (double)algorithms.size());
  Reset();
  appareo::curse::out::Print(algorithms[5], -1, -1, win);
  appareo::curse::out::NewLine(win);
  times.push_back(QuickSort(false));
  appareo::induco::UpdateProgressBar(times.size() / (double)algorithms.size());
  Reset();
  appareo::curse::out::Print(algorithms[6], -1, -1, win);
  appareo::curse::out::NewLine(win);
  times.push_back(SelectionSort(false));
  appareo::induco::UpdateProgressBar(times.size() / (double)algorithms.size());
  Reset();

  appareo::curse::TerminateWindow(win);
  appareo::induco::TerminateProgressBar();
  win = appareo::curse::windows.size();
  appareo::curse::InitializeWindow();
  appareo::curse::win->CreateWindow("Results", appareo::curse::scrwidth / 2,
                                    3 * appareo::curse::scrheight / 4, -1, -1, true,
                                    true);
  // induco::Line(51);
  std::string line = "    ALGORITHM| HOURS |  MIN |  SEC |  MS  |  US";
  appareo::curse::out::Print(line, 1, (appareo::curse::windows[win].width - line.size()) / 2, win);
  for (int i = 0; i < times.size(); i++) {
     line = algorithms[i];
     while (line.size() < 15) {
      line = " " + line;
    }
     line += "|";
     line += appareo::induco::DisplayTime(times[i], true);
     appareo::curse::out::Print(line, i + 2, (appareo::curse::windows[win].width - line.size()) / 2, win);
  }
  getch();
  appareo::curse::TerminateWindow(win);
}
