#include "insertion.hpp"
#include <time.h>
#include <vector>
#include "../algo_core.hpp"

void sort::InsertionSort() {
  clock_t start = clock();
  for (int i = 1; i < data.size(); i++) {
    int j = i;
    result.vec_access += 2;
    result.comparisons++;
    while (j > 0 && data[j - 1] > data[j]) {
      result.vec_access += 2;
      iter_swap(data.begin() + j, data.begin() + j - 1);
      j--;
    }
  }
  result.time_elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
}
