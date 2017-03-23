#ifndef QUICKSORT
#define QUICKSORT
#include <vector>
namespace sort {
  void Quicksort();
  void QuicksortBase(int low, int high);
  int QuicksortPartition(int low, int high);
}
#endif
