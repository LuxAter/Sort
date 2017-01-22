#ifndef _BUCKET_SORT_
#define _BUCKET_SORT_
#include "../../sort_core.hpp"
#include <ctime>
#include <iostream>
#include <vector>
namespace sort {
extern int Btotalrecursioncount;
double BucketSort(bool display = false);
void BRecursion(int bucketcount, std::vector<int> *bucket, bool display,
                bool top = false);
int BBucket(int value, int bucketsize);
bool BDupes(std::vector<int> bucket);
}
#endif
