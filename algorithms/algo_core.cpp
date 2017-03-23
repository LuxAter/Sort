#include <math.h>
#include <map>
#include <string>
#include <vector>
#include "../sorting/sort.hpp"
#include "algo_core.hpp"
#include "algorithm_headers.hpp"

namespace sort {
  AlgoResult result;
  std::map<std::string, double (*)(std::vector<int>)> algorithms;
  std::vector<int> data_base;
}

void sort::LoadAlgos() { algorithms["quicksort"] = Quicksort; }

bool sort::RunAlgo(std::string algo) {
  std::map<std::string, double (*)(std::vector<int>)>::iterator it;
  it = algorithms.find(algo);
  bool good = false;
  if (it != algorithms.end()) {
    win.Print("Running %s...\n", algo.c_str());
    it->second(data_base);
    win.Print("Compleated %s\n", algo.c_str());
    result.time_elapsed = 192.072152;
    PrintResults();
    good = true;
  } else {
    win.Print("%s is not a valid sorting algorithm\n", algo.c_str());
    good = false;
  }
  return (good);
}

void sort::PrintResults() {
  double min, sec, milli_sec, micro_sec;
  double remaining_time;
  remaining_time = result.time_elapsed / 60.0;
  win.Print("%f\n", remaining_time);
  min = floor(remaining_time);
  remaining_time = modf(remaining_time, &sec);
  win.Print("%f\n", remaining_time);
  remaining_time *= pow(10, 3);
  win.Print("%f\n", remaining_time);
  remaining_time = modf(remaining_time, &milli_sec);
  win.Print("%f\n", remaining_time);
  remaining_time *= pow(10, 3);
  win.Print("%f\n", remaining_time);
  micro_sec = ceil(remaining_time);
  win.Print(
      "[RESULTS]\nSort Time: %fs\nFormated Time: "
      "%.2im:%.2is:%.3ims:%.3iµs\nCompairsons: "
      "%li\nArray "
      "Access: "
      "%li\nArray Writes: %li\n",
      result.time_elapsed, min, sec, milli_sec, micro_sec, result.comparisons,
      result.vec_access, result.vec_writes);
}
