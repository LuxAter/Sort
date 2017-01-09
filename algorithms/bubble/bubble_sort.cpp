#include "../../sort_headers.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <appareo_files/appareo_headers.h>

double sort::BubbleSort(bool display) {
  if (display == true) {
    appareo::curse::out::Print("Bubble Sort");
    appareo::curse::out::NewLine();
    appareo::induco::CreateProgressBar("Bubble Sort");
  }
  double timeelapsed;
  appareo::induco::Timer(true);
  int n = values.size();
  while (n != 0) {
    int newn = 0;
    for (int i = 1; i < n; i++) {
      if (values[i - 1] > values[i]) {
        iter_swap(values.begin() + i - 1, values.begin() + i);
        newn = i;
      }
    }
    n = newn;
    if (display == true) {
      appareo::induco::UpdateProgressBar((values.size() - n) / (float)values.size());
    }
  }
  timeelapsed = appareo::induco::Timer();
  if (display == true) {
    appareo::induco::TerminateProgressBar();
    appareo::curse::out::Print("Sorted " + std::to_string(values.size()));
    appareo::curse::out::NewLine();
    appareo::curse::out::Print(appareo::induco::DisplayTime(timeelapsed, true));
    appareo::curse::out::NewLine();
  }
  return (timeelapsed);
}
