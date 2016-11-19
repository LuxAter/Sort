#include "../../induco.h"
#include "../../sort_headers.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <pessum.h>
#include <vector>

namespace sort {
int totalrecursioncount = 0;
}

double sort::QuickSort(bool display) {
  if (display == true) {
    std::cout << "Quick Sort:\n";
  }
  totalrecursioncount = 0;
  double timeelapsed;
  induco::Timer(true);
  Recursive(0, values.size(), display);
  timeelapsed = induco::Timer();
  if (display == true) {
    induco::DrawLoadingBar(1, 50);
    std::cout << "\nSorted " << values.size() << "\n";
    std::cout << induco::DisplayTime(timeelapsed, true) << "\n";
  }
  return (timeelapsed);
}

void sort::Recursive(int low, int high, bool display) {
  if (low < high) {
    int partition = Partition(low, high);
    Recursive(low, partition - 1, display);
    Recursive(partition + 1, high, display);
  }
  totalrecursioncount++;
  if (display == true) {
    induco::DrawLoadingBar(totalrecursioncount / (double)(2 * values.size()),
                           50);
  }
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
