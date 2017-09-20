#include "algo/merge.hpp"

#include <array>
#include <vector>

#include "sort.hpp"

#include <iostream>

std::array<int, 2> merge::Run() {
  std::array<int, 2> trace = {{0, 0}};
  Base(0, data.size(), &trace);
  return trace;
}

void merge::Base(int low, int high, std::array<int, 2>* trace) {
  if (high - low == 2) {
    if (data[low] > data[high - 1]) {
      iter_swap(data.begin() + low, data.begin() + high - 1);
    }
    return;
  } else if (high - low <= 1) {
    return;
  }
  int low1 = low, high1 = ((high - low) / 2) + low;
  int low2 = ((high - low) / 2) + low, high2 = high;
  Base(low1, high1, trace);
  Base(low2, high2, trace);
  Merge(low1, high1, low2, high2, trace);
}

void merge::Merge(int low1, int high1, int low2, int high2,
                  std::array<int, 2>* trace) {
  while ((high1 - low1) != 0 && (high2 - low2) != 0) {
    if (data[low1] >= data[low2]) {
      int tmp = data[low2];
      data.erase(data.begin() + low2);
      data.insert(data.begin() + low1, tmp);
      low2++;
      high1++;
    }
    low1++;
  }
}
