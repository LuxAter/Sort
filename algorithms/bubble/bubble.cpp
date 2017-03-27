#include "bubble.hpp"
#include <time.h>
#include <vector>
#include "../algo_core.hpp"

void sort::BubbleSort() {
  clock_t start = clock();
  int length = data.size();
  while (length != 0) {
    int new_length = 0;
    for (int i = 1; i < length; i++) {
      result.comparisons++;
      result.vec_access += 2;
      if (data[i - 1] > data[i]) {
        result.vec_access += 2;
        iter_swap(data.begin() + i - 1, data.begin() + i);
        new_length = i;
      }
    }
    length = new_length;
  }
  result.time_elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
}
