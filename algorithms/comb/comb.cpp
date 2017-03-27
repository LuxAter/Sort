#include <time.h>
#include <vector>
#include "../algo_core.hpp"
#include "comb.hpp"
#include <math.h>

void sort::CombSort(){
  clock_t start = clock();
  int gap = data.size();
  double step = 1.3;
  bool sorted = false;
  while(sorted == false){
    gap = floor((double)gap / step);
    if(gap > 1){
      sorted = false;
    }
    else{
      gap = 1;
      sorted = true;
    }
    for(int i = 0; i + gap < data.size(); i++){
      result.comparisons++;
      result.vec_access +=2;
      if(data[i] > data[i+gap]){
        result.vec_access +=2;
        iter_swap(data.begin() + i, data.begin() + i + gap);
        sorted = false;
      }
    }
  }
  result.time_elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
}
