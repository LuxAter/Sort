#ifndef _QUICK_SORT_
#define _QUICK_SORT_
#include "../sort_core.h"
#include <ctime>
#include <iostream>
#include <pessum.h>
#include <vector>
namespace sort {
extern int totalrecursioncount;
double QuickSort();
void Recursive(int low, int high);
int Partition(int low, int high);
}
#endif
