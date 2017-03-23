#include <map>
#include <string>
#include <vector>
#include "../sorting/sort.hpp"
#include "algo_core.hpp"
#include "algorithm_headers.hpp"

namespace sort {
  AlgoResult Result;
  std::map<std::string, double (*)(std::vector<int>)> algorithms;
  std::vector<int> data_base;
}

void sort::LoadAlgos() { algorithms["quicksort"] = Quicksort; }

void sort::RunAlgo(std::string algo) {
  std::map<std::string, double (*)(std::vector<int>)>::iterator it;
  it = algorithms.find(algo);
  if (it != algorithms.end()) {
    it->second(data_base);
  } else {
    win.Print("%s is not a valid sorting algorithm", algo.c_str());
  }
}
