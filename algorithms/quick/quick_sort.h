#ifndef _QUICK_SORT_
#define _QUICK_SORT_
#include "../../sort_core.h"
#include <ctime>
#include <iostream>
#include <pessum.h>
#include <vector>
namespace sort {
extern int totalrecursioncount;
double QuickSort(bool display = false);
void Recursive(int low, int high, bool display);
int Partition(int low, int high);
}
#endif
