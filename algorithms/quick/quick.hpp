#ifndef QUICKSORT
#define QUICKSORT
#include <vector>
namespace sort {
  void QuickSort();
  void QuickSortBase(int low, int high);
  int QuickSortPartition(int low, int high);
}
#endif
