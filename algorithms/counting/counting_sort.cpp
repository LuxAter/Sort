#include "../../sort_headers.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <appareo_files/appareo_headers.h>

double sort::CountingSort(bool display) {
  if (display == true) {
    appareo::curse::out::Print("Counting Sort");
    appareo::curse::out::NewLine();
    appareo::induco::CreateProgressBar("Counting Sort");
  }
  double timeelapsed;
  appareo::induco::Timer(true);
  std::vector<int> counters;
  int max = values[0], min = values[0];
  for (int i = 1; i < values.size(); i++) {
    if (values[i] > max) {
      max = values[i];
    }
    if (values[i] < min) {
      min = values[i];
    }
  }
  for (int i = min; i <= max; i++) {
    counters.push_back(0);
  }
  for (int i = 0; i < values.size(); i++) {
    counters[values[i] - min]++;
    if (display == true) {
      appareo::induco::UpdateProgressBar(0.5 * (i / (double)values.size()));
    }
  }
  values.clear();
  for (int i = 0; i <= max; i++) {
    if (display == true) {
      appareo::induco::UpdateProgressBar((0.5 * (i / (double)max)) + 0.5);
    }
    for (int j = 0; j < counters[i]; j++) {
      values.push_back(i + min);
    }
  }
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
