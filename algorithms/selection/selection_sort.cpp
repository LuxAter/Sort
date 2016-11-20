#include "../../induco.h"
#include "../../sort_headers.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

double sort::SelectionSort(bool display) {
  if (display == true) {
    std::cout << "Seleciton Sort:\n";
  }
  double timeelapsed;
  induco::Timer(true);
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
      induco::DrawLoadingBar(i / (double)values.size(), 50);
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
