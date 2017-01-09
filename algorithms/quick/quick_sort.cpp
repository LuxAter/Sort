#include "../../sort_headers.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <appareo_files/appareo_headers.h>

namespace sort {
int Qtotalrecursioncount = 0;
}

double sort::QuickSort(bool display) {
  if (display == true) {
    appareo::curse::out::Print("Quick Sort");
    appareo::curse::out::NewLine();
    appareo::induco::CreateProgressBar("Quick Sort");
  }
  Qtotalrecursioncount = 0;
  double timeelapsed= appareo::induco::Timer(true);
  QRecursive(0, values.size(), display);
  timeelapsed = appareo::induco::Timer();
  if (display == true) {
    appareo::induco::TerminateProgressBar();
    appareo::curse::out::Print("Sorted "+ std::to_string(values.size()));
    appareo::curse::out::NewLine();
    appareo::curse::out::Print(appareo::induco::DisplayTime(timeelapsed, true));
    appareo::curse::out::NewLine();
  }
  return (timeelapsed);
}

void sort::QRecursive(int low, int high, bool display) {
  if (low < high) {
    int partition = QPartition(low, high);
    QRecursive(low, partition - 1, display);
    QRecursive(partition + 1, high, display);
  }
  if (display == true) {
    Qtotalrecursioncount++;
    appareo::induco::UpdateProgressBar(Qtotalrecursioncount / (double)(2 * values.size()));
  }
}

int sort::QPartition(int low, int high) {
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
