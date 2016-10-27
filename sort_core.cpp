#include <pessum.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "sort_headers.h"
namespace sort {
std::vector<int> values;
std::vector<int> scrambledvalues;
int savedbarcount = -1;
bool display = false;
bool pausecheck = true;
time_t starttime = 0;
}

int sort::GenorateValues() {
  DivideLine();
  long int valuecount = 0, minimumvalue = 0, maximumvalue = 0, range;
  std::cout << "Number of values to genorate: ";
  std::cin >> valuecount;
  std::cout << "Minimum value: ";
  std::cin >> minimumvalue;
  std::cout << "Maximum value: ";
  std::cin >> maximumvalue;
  range = maximumvalue - minimumvalue;
  if (range <= 0) {
    char checkin;
    std::cout << "Minimum value must be less than Maximum "
                 "Value!\n[Y]\n";
    std::cin >> checkin;
    return (0);
  } else if (range > 0) {
    double compleated = 0;
    Timer();
    while (values.size() < valuecount) {
      int newvalue = (rand() % range);
      newvalue -= minimumvalue;
      values.push_back(newvalue);
      compleated = values.size() / (double)valuecount;
      DrawLoadingBar(compleated, 50);
    }
    DrawLoadingBar(1, 50);
    scrambledvalues = values;
    std::cout << "\n"
                 "--------------------\n"
                 "Genorated "
              << valuecount << " values in the range " << minimumvalue << " to "
              << maximumvalue << "\nIn ";
    Timer(true);
    std::cout << "[Y]";
    char checkin;
    std::cin >> checkin;
  }
}

void sort::DivideLine() {
  std::cout
      << "\n============================================================\n\n";
}

void sort::DrawLoadingBar(double percent, int size) {
  std::string bar = "%[";
  int blocks = percent * size;
  std::cout << "\r";
  if (savedbarcount != blocks) {
    for (int i = 0; i < blocks; i++) {
      bar = bar + "#";
    }
    for (int i = blocks; i < size; i++) {
      bar = bar + " ";
    }
    bar = bar + "]";
    savedbarcount = blocks;
    std::cout << bar;
  }
}

double sort::Timer(bool stop) {
  if (stop == false) {
    starttime = clock();
    return (0.0);
  } else if (stop == true) {
    clock_t endtime;
    endtime = clock();
    long double elapsed = (endtime - starttime) / (double)CLOCKS_PER_SEC;
    double returnvalue = elapsed;
    int microsec = 0, millisec = 0, sec = 0, min = 0, hour = 0;
    sec = floor(elapsed);
    elapsed -= sec;
    elapsed = elapsed * 1000;
    millisec = floor(elapsed);
    elapsed -= millisec;
    elapsed = elapsed * 1000;
    microsec = round(elapsed);
    while (sec >= 60) {
      sec -= 60;
      min++;
    }
    while (min >= 60) {
      min -= 60;
      hour++;
    }
    if (display == true) {
      std::cout << hour << "h " << min << "m " << sec << "s " << millisec
                << "ms " << microsec << "us\n";
    }
    sec = elapsed;
    return (returnvalue);
  }
}

void sort::List() {
  for (int i = 0; i < values.size(); i++) {
    std::cout << values[i] << " ";
  }
  std::cout << "\n";
}

void sort::Reset() {
  values.clear();
  values = scrambledvalues;
}

void sort::UseAll() {
  std::vector<Algorithm> algorithms;
  pausecheck = false;
  Algorithm newalgo;
  newalgo.algorithmname = "QuickSort";
  newalgo.n = values.size();
  newalgo.i = 0;
  newalgo.elapsed = QuickSort();
  algorithms.push_back(newalgo);
  Reset();
  newalgo.algorithmname = "MergeSort";
  newalgo.n = values.size();
  newalgo.i = 0;
  newalgo.elapsed = MergeSort();
  algorithms.push_back(newalgo);
  Reset();
  newalgo.algorithmname = "BubbleSort";
  newalgo.n = values.size();
  newalgo.i = 0;
  newalgo.elapsed = BubbleSort();
  algorithms.push_back(newalgo);
  Reset();
  newalgo.algorithmname = "InsertionSort";
  newalgo.n = values.size();
  newalgo.i = 0;
  newalgo.elapsed = InsertionSort();
  algorithms.push_back(newalgo);
  Reset();
  newalgo.algorithmname = "SelectionSort";
  newalgo.n = values.size();
  newalgo.i = 0;
  newalgo.elapsed = SelectionSort();
  algorithms.push_back(newalgo);
  Reset();

  for (int i = 0; i < algorithms.size() - 1; i++) {
    int smallestpointer = i;
    for (int j = i + 1; j < algorithms.size(); j++) {
      if (algorithms[j].elapsed < algorithms[smallestpointer].elapsed) {
        smallestpointer = j;
      }
    }
    if (smallestpointer != i) {
      iter_swap(algorithms.begin() + i, algorithms.begin() + smallestpointer);
    }
  }

  DivideLine();
  std::cout << "     Algorithm      | hour | min | sec | ms | us \n";
  for (int i = 0; i < algorithms.size(); i++) {
    double elapsed = algorithms[i].elapsed;
    std::string line = "", hstring, minstring, secstring, msstring, usstring;
    int microsec = 0, millisec = 0, sec = 0, min = 0, hour = 0;
    sec = floor(elapsed);
    elapsed -= sec;
    elapsed = elapsed * 1000;
    millisec = floor(elapsed);
    elapsed -= millisec;
    elapsed = elapsed * 1000;
    microsec = round(elapsed);
    while (sec >= 60) {
      sec -= 60;
      min++;
    }
    while (min >= 60) {
      min -= 60;
      hour++;
    }
    line = algorithms[i].algorithmname;
    for (int j = line.size(); j < 20; j++) {
      line = line + " ";
    }
    line = line + "|";
    hstring = std::to_string(hour);
    line = line + hstring;
    for (int j = hstring.size(); j < 6; j++) {
      line = line + " ";
    }
    line = line + "|";
    minstring = std::to_string(min);
    line = line + minstring;
    for (int j = minstring.size(); j < 5; j++) {
      line = line + " ";
    }
    line = line + "|";
    secstring = std::to_string(sec);
    line = line + secstring;
    for (int j = secstring.size(); j < 5; j++) {
      line = line + " ";
    }
    line = line + "|";
    msstring = std::to_string(millisec);
    line = line + msstring;
    for (int j = msstring.size(); j < 4; j++) {
      line = line + " ";
    }
    line = line + "|";
    usstring = std::to_string(microsec);
    line = line + usstring;
    for (int j = usstring.size(); j < 4; j++) {
      line = line + " ";
    }
    line = line + "\n";
    std::cout << line;
  }
  DivideLine();
  char checkin;
  std::cin >> checkin;
}

void sort::MassCheck() {}
