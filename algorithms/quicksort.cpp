#include <time.h>
#include <vector>
#include "algo_core.hpp"
#include "quicksort.hpp"

void sort::Quicksort(std::vector<int> Data) {
  clock_t start = clock();
  result.time_elapsed = clock() - start;
}

void sort::QuicksortBase(std::vector<int> Data, int low, int high) {}

int sort::QuicksortPartition(std::vector<int> Data, int low, int high) {
  return (0);
}
