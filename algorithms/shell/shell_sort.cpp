#include "../../sort_headers.hpp"
#include <appareo.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <pessum.h>
#include <vector>

double sort::ShellSort(bool display) {
  if (display == true) {
    appareo::induco::CreateProgressBar("Shell Sort");
  }
  double timeelapsed;
  appareo::induco::Timer(true);
  for (int gap = values.size() / 2; gap > 0; gap /= 2) {
    for (int i = 0; i < values.size(); i++) {
      for (int j = i; j - gap >= 0 && values[j] < values[j - gap]; j -= gap) {
        iter_swap(values.begin() + j, values.begin() + j - gap);
      }
    }
    if (display == true) {
      appareo::induco::UpdateProgressBar(((values.size() / 2) - gap) /
                                         (double)(values.size() / 2));
    }
  }
  timeelapsed = appareo::induco::Timer();
  if (display == true) {
    appareo::induco::TerminateProgressBar();
  }
  return (timeelapsed);
}
