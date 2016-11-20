#ifndef _MERGE_SORT_
#define _MERGE_SORT_
#include "../../sort_core.h"
#include <ctime>
#include <iostream>
#include <vector>
namespace sort {
extern std::vector<int> Mworkvector;
double MergeSort(bool display = false);
void MMerge(int ileft, int iright, int iend);
}
#endif
