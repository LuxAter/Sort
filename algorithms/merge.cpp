#include <time.h>
#include <vector>
#include "algo_core.hpp"
#include "merge.hpp"

void sort::MergeSort(){
  clock_t start = clock();
  data = MergeSortBase(data);
  result.time_elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
}

std::vector<int> sort::MergeSortBase(std::vector<int> list){
  if(list.size() <= 1){
    return(list);
  }
  result.vec_access += list.size();
  std::vector<int> right(list.begin(), list.begin() + (list.size() / 2)), left(list.begin() + (list.size() / 2) + 1, list.end());
  return(Merge(MergeSortBase(left),MergeSortBase(right)));
}

std::vector<int> sort::Merge(std::vector<int> left, std::vector<int> right){
  std::vector<int> list;
  while(left.size() != 0 && right.size() != 0){
    result.vec_access += 3;
    result.comparisons++;
    if(left[0] < right[0]){
      list.push_back(left[0]);
      left.erase(left.begin());
    }else{
      list.push_back(right[0]);
      right.erase(right.begin());
    }
  }
  if(left.size() != 0){
    result.vec_access += left.size();
    list.insert(list.end(), left.begin(), left.end());
  }else if(right.size() != 0){
    result.vec_access += right.size();
    list.insert(list.end(), right.begin(), right.end());
  }
  return(list);
}
