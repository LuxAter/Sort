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
  List();
  double timeelapsed;
  induco::Timer(true);
  std::vector<int> counters;
  int min = values[0], max = values[0];
  for (int i = 1; i < values.size(); i++) {
    int value = values[i];
    if (value > max) {
      max = value;
    }
    if (value < min) {
      min = value;
    }
  }
  for (int i = min; i <= max; i++) {
    counters.push_back(0);
  }
  for (int i = 0; i < values.size(); i++) {
    counters[i]++;
  }
  values.clear();
  for (int i = 0; i < counters.size(); i++) {
    for (int j = 0; j < counters[i]; j++) {
      values.push_back(i);
    }
  }
  List();
  timeelapsed = induco::Timer();
  if (display == true) {
    induco::DrawLoadingBar(1, 50);
    std::cout << "\nSorted " << values.size() << "\n";
    std::cout << induco::DisplayTime(timeelapsed, true) << "\n";
  }
  return (timeelapsed);
}
