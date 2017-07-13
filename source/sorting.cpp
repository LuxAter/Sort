#include "sorting.hpp"

#include <time.h>
#include <map>
#include <string>

void Null() {}

namespace sorting {
  std::map<std::string, void (*)()> algorithms;
}

void sorting::LoadAlgorithms() { algorithms["Quick"] = Null; }

double sorting::RunSort(std::string algo) {
  double time_elapsed = 0.0;
  if (algorithms.find(algo) != algorithms.end()) {
    clock_t start = clock();
    algorithms.find(algo)->second();
    time_elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
  }
  return time_elapsed;
}
