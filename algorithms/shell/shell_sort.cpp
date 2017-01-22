#include "../../sort_headers.hpp"
#include <appareo.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

double sort::ShellSort(bool display) {
  if (display == true) {
    appareo::induco::CreateProgressBar("Shell Sort");
  }
  double timeelapsed;
  appareo::induco::Timer(true);
  std::vector<int> gaps;
  int gap = (values.size() / (pow(2, 1)));
  int counter = 1;
  while (gap <= 1) {
    gaps.push_back(gap);
    counter++;
    gap = (values.size() / (pow(2, counter)));
  }
  if (gap > 1) {
    gaps.push_back(1);
  }
  for (int i = 0; i < gaps.size(); i++) {
    for (int j = gaps[i]; j < values.size(); j++) {
      int k;
      for (k = j; k >= gaps[i] && values[k - gaps[i]] > values[j];
           k -= gaps[i]) {
        values[k] = values[k - gaps[i]];
      }
      values[k] = values[j];
    }
  }
  timeelapsed = appareo::induco::Timer();
  if (display == true) {
    appareo::induco::TerminateProgressBar();
  }
  return (timeelapsed);
}
