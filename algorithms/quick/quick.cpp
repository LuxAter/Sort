#include "quick.hpp"
#include <time.h>
#include <vector>
#include "../algo_core.hpp"

void sort::QuickSort() {
  clock_t start = clock();
  QuickSortBase(0, data.size() - 1);
  result.time_elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
}

void sort::QuickSortBase(int low, int high) {
  if (low < high) {
    int pivot = QuickSortPartition(low, high);
    QuickSortBase(low, pivot - 1);
    QuickSortBase(pivot + 1, high);
  }
}

int sort::QuickSortPartition(int low, int high) {
  result.vec_access++;
  int pivot = data[high];
  int i = low;
  for (int j = low; j < high; j++) {
    result.vec_access += 1;
    result.comparisons++;
    if (data[j] < pivot) {
      result.vec_access += 2;
      iter_swap(data.begin() + i, data.begin() + j);
      i++;
    }
  }
  result.vec_access += 2;
  iter_swap(data.begin() + i, data.begin() + high);
  return (i);
}
