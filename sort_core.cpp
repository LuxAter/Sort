#include "induco.h"
#include "sort_headers.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <pessum.h>
#include <string>
#include <vector>
namespace sort {
std::vector<int> values;
std::vector<int> scrambledvalues;
}

int sort::GenorateValues(int count, int min, int max, bool display) {
  if (display == true) {
    std::cout << "Genorating Values:\n";
  }
  double compleated = 0;
  int range = max - min;
  values.clear();
  scrambledvalues.clear();
  induco::Timer(true);
  while (values.size() < count) {
    int newvalue = (rand() % range);
    newvalue -= min;
    values.push_back(newvalue);
    if (display == true) {
      compleated = values.size() / (double)count;
      induco::DrawLoadingBar(compleated, 50);
    }
  }
  scrambledvalues = values;
  if (display == true) {
    induco::DrawLoadingBar(1, 50);
    std::cout << "\nGenorated " << count << "\n";
    std::cout << induco::DisplayTime(induco::Timer(false), true) << "\n";
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

void sort::UseAll() {}

void sort::MassCheck() {}

void sort::Clean() {
  values.clear();
  scrambledvalues.clear();
}
