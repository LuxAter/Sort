#ifndef _QUICK_SORT_
#define _QUICK_SORT_
#include "../../sort_core.hpp"
#include <ctime>
#include <iostream>
#include <vector>
namespace sort {
extern int Qtotalrecursioncount;
double QuickSort(bool display = false);
void QRecursive(int low, int high, bool display);
int QPartition(int low, int high);
}
#endif
