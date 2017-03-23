#ifndef QUICKSORT
#define QUICKSORT
#include <vector>
namespace sort {
  double Quicksort(std::vector<int> Data);
  void QuicksortBase(std::vector<int> Data, int low, int high);
  int QuicksortPartition(std::vector<int> Data, int low, int high);
}
#endif
