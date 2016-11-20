#include "../../induco.h"
#include "../../sort_headers.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <pessum.h>
#include <vector>

double sort::CountingSort(bool display) {
  if (display == true) {
    std::cout << "Counting Sort:\n";
  }
  double timeelapsed;
  induco::Timer(true);
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
      induco::DrawLoadingBar(0.5 * (i / (double)values.size()), 50);
    }
  }
  values.clear();
  for (int i = 0; i <= max; i++) {
    if (display == true) {
      induco::DrawLoadingBar((0.5 * (i / (double)max)) + 0.5, 50);
    }
    for (int j = 0; j < counters[i]; j++) {
      values.push_back(i + min);
    }
  }
  timeelapsed = induco::Timer();
  if (display == true) {
    induco::DrawLoadingBar(1, 50);
    std::cout << "\nSorted " << values.size() << "\n";
    std::cout << induco::DisplayTime(timeelapsed, true) << "\n";
  }
  return (timeelapsed);
}
