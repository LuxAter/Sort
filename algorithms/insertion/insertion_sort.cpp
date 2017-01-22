#include "../../sort_headers.hpp"
#include <appareo.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

double sort::InsertionSort(bool display) {
  if (display == true) {
    appareo::induco::CreateProgressBar("Insertion Sort");
  }
  double timeelapsed;
  appareo::induco::Timer(true);
  for (int i = 1; i < values.size(); i++) {
    int j = i;
    while (j > 0 && values[j - 1] > values[j]) {
      iter_swap(values.begin() + j, values.begin() + j - 1);
      j--;
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
