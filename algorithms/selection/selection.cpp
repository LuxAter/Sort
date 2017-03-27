#include "selection.hpp"
#include <time.h>
#include <vector>
#include "../algo_core.hpp"

void sort::SelectionSort(){
  clock_t start = clock();
  for(int i = 0; i < data.size(); i++){
    int min = i;
    for(int j = i; j < data.size(); j++){
      result.vec_access += 2;
      result.comparisons++;
      if(data[j] < data[min]){
        min = j;
      }
    }
    if(min != i){
      result.vec_access += 2;
      iter_swap(data.begin() + i, data.begin() + min);
    }
  }
  result.time_elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
}
