#include "cycle.hpp"
#include <pessum.h>
#include <time.h>
#include <iostream>
#include <vector>
#include "../../sorting/sort.hpp"
#include "../algo_core.hpp"

void sort::CycleSort() {
  clock_t start = clock();
  for (int i = 0; i < data.size(); i++) {
    CycleInsert(data[i], i);
  }
  result.time_elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
}

void sort::CycleInsert(int value, int cycle_start) {
  int pos = 0;
  for (int i = 0; i < data_base.size(); i++) {
    if (data_base[i] < value) {
      pos++;
    }
  }
  if (pos != cycle_start) {
    while (data[pos] == value && pos < data.size() && pos != cycle_start) {
      pos++;
    }
    int temp = data[pos];
    data[pos] = value;
    value = temp;
  }
  while (pos != cycle_start) {
    pos = 0;
    for (int i = 0; i < data_base.size(); i++) {
      if (data_base[i] < value) {
        pos++;
      }
    }
    while (data[pos] == value && pos < data.size()) {
      pos++;
    }
    int temp = data[pos];
    data[pos] = value;
    value = temp;
  }
}
