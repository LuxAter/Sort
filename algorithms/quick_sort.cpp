#include "../sort_headers.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <pessum.h>
#include <vector>

namespace sort {
int totalrecursioncount = 0;
}

double sort::QuickSort() {
  DivideLine();
  std::cout << "Quick Sort:\n";
  totalrecursioncount = 0;
  Timer();
  Recursive(0, values.size());
  DrawLoadingBar(1, 50);
  std::cout << "\nSorted " << values.size() << " values\nIn ";
  Timer(true);
  std::cout << "[Y]\n";
  char checkin;
  std::cin >> checkin;
}

void sort::Recursive(int low, int high) {
  if (low < high) {
    int partition = Partition(low, high);
    Recursive(low, partition - 1);
    Recursive(partition + 1, high);
  }
  totalrecursioncount++;
  DrawLoadingBar(totalrecursioncount / (double)(2 * values.size()), 50);
}

int sort::Partition(int low, int high) {
  int piviot = values[high];
  int i = low;
  for (int j = low; j < high; j++) {
    if (values[j] <= piviot) {
      iter_swap(values.begin() + i, values.begin() + j);
      i++;
    }
  }
  iter_swap(values.begin() + i, values.begin() + high);
  return (i);
}
