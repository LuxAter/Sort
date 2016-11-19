#ifndef _MERGE_SORT_
#define _MERGE_SORT_
#include "../../sort_core.h"
#include <ctime>
#include <iostream>
#include <pessum.h>
#include <vector>
namespace sort {
extern std::vector<int> workvector;
double MergeSort(bool display = false);
void Merge(int ileft, int iright, int iend);
}
#endif
