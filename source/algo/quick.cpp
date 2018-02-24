// Copyright 2017 Arden Rasmussen

#include "algo/quick.hpp"

#include <array>
#include <vector>

#include "sort.hpp"

std::array<int, 2> quick::Run() {
  std::array<int, 2> trace = {{0, 0}};
  Base(0, data.size() - 1, &trace);
  return trace;
}

void quick::Base(int low, int high, std::array<int, 2>* trace) {
  if (low < high) {
    int pivot = Partition(low, high, trace);
    Base(low, pivot - 1, trace);
    Base(pivot + 1, high, trace);
  }
}

int quick::Partition(int low, int high, std::array<int, 2>* trace) {
  (*trace)[0]++;
  int pivot = data[high];
  int i = low;
  for (int j = low; j < high; j++) {
    (*trace)[0]++;
    if (data[j] < pivot) {
      (*trace)[1]++;
      iter_swap(data.begin() + i, data.begin() + j);
      i++;
    }
  }
  (*trace)[1]++;
  iter_swap(data.begin() + i, data.begin() + high);
  return (i);
}
