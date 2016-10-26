#include "sort_core.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <pessum.h>
#include <vector>
namespace sort {
std::vector<int> values;
std::vector<int> scrambledvalues;
int savedbarcount = -1;
bool display = false;
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
