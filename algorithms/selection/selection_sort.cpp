#include "../../sort_headers.hpp"
#include <appareo.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

double sort::SelectionSort(bool display) {
  if (display == true) {
    appareo::induco::CreateProgressBar("Selection Sort");
  }
  double timeelapsed;
  appareo::induco::Timer(true);
  for (int i = 0; i < values.size() - 1; i++) {
    int smallestpointer = i;
    for (int j = i + 1; j < values.size(); j++) {
      if (values[j] < values[smallestpointer]) {
        smallestpointer = j;
      }
    }
    if (smallestpointer != i) {
      iter_swap(values.begin() + i, values.begin() + smallestpointer);
    }
    if (display == true) {
      appareo::induco::UpdateProgressBar(i / (double)values.size());
    }
  }
  timeelapsed = appareo::induco::Timer();
  if (display == true) {
    appareo::induco::TerminateProgressBar();
  }
  return (timeelapsed);
}
