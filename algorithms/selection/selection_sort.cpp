#include "../../sort_headers.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <appareo_files/appareo_headers.h>

double sort::SelectionSort(bool display) {
  if (display == true) {
    appareo::curse::out::Print("Selection Sort");
    appareo::curse::out::NewLine();
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
    appareo::curse::out::Print("Sorted "+ std::to_string(values.size()));
    appareo::curse::out::NewLine();
    appareo::curse::out::Print(appareo::induco::DisplayTime(timeelapsed, true));
    appareo::curse::out::NewLine();
  }
  return (timeelapsed);
}
