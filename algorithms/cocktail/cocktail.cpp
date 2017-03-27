#include "cocktail.hpp"
#include <time.h>
#include <vector>
#include "../algo_core.hpp"

void sort::CocktailSort() {
  clock_t start = clock();
  bool swap = true;
  int istart = 0, iend = data.size() - 1;
  while (swap == true) {
    swap = false;
    int new_end, new_start;
    for (int i = istart; i <= iend; i++) {
      result.comparisons++;
      result.vec_access += 2;
      if (data[i] > data[i + 1]) {
        result.vec_access += 2;
        iter_swap(data.begin() + i, data.begin() + i + 1);
        swap = true;
        new_end = i;
      }
    }
    iend = new_end;
    for (int i = iend; i >= istart && swap == true; i--) {
      result.comparisons++;
      result.vec_access += 2;
      if (data[i] > data[i + 1]) {
        result.vec_access += 2;
        iter_swap(data.begin() + i, data.begin() + i + 1);
        swap = true;
        new_start = i;
      }
    }
    istart = new_start;
  }
  result.time_elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
}
