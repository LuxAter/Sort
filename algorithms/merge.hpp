#ifndef MERGESORT
#define MERGESORT
#include <vector>
namespace sort{
  void MergeSort();
  std::vector<int> MergeSortBase(std::vector<int> list);
  std::vector<int> Merge(std::vector<int> left, std::vector<int>right);
}
#endif
