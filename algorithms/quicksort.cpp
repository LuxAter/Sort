#include <time.h>
#include <vector>
#include "algo_core.hpp"
#include "quicksort.hpp"

void sort::Quicksort() {
  clock_t start = clock();
  QuicksortBase(0, data.size() - 1);
  result.time_elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
}

void sort::QuicksortBase(int low, int high) {
  if (low < high) {
    int pivot = QuicksortPartition(low, high);
    QuicksortBase(low, pivot - 1);
    QuicksortBase(pivot + 1, high);
  }
}

int sort::QuicksortPartition(int low, int high) {
  result.vec_access++;
  int pivot = data[high];
  int i = low;
  for (int j = low; j < high; j++) {
    result.vec_access += 2;
    result.comparisons++;
    if (data[j] < pivot) {
      iter_swap(data.begin() + i, data.begin() + j);
      i++;
    }
  }
  result.vec_access += 2;
  iter_swap(data.begin() + i, data.begin() + high);
  return (i);
}
