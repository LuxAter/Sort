#include <vector>
#include <time.h>
#include "algo_core.hpp"
#include "heap.hpp"

void sort::HeapSort(){
  clock_t start = clock();
  for(int i = data.size() / 2 - 1; i >= 0; i--){
    Heapify(i, data.size());
  }
  for(int i=data.size()-1;i>=0;i--){
    result.vec_access += 2;
    iter_swap(data.begin() + i, data.begin());
    Heapify(0, i);
  }
  result.time_elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
}

void sort::Heapify(int root, int length){
  int largest = root;
  int left = 2 * root + 1;
  int right = 2 * root + 2;
  result.comparisons += 4;
  result.vec_access += 4;
  if(left < length && data[left] > data[largest]){
    largest = left;
  }
  if(right < length && data[right] > data[largest]){
    largest = right;
  }
  if(largest != root){
    result.vec_access += 2;
    iter_swap(data.begin() + root, data.begin() + largest);
    Heapify(largest, length);
  }
}
