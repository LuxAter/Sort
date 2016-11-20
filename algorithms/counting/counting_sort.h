#ifndef _COUNTING_SORT_
#define _COUNTING_SORT_
#include "../../sort_core.h"
#include <ctime>
#include <iostream>
#include <vector>
namespace sort {
struct Counter {
  int value, count;
};
double CountingSort(bool display = false);
}
#endif
