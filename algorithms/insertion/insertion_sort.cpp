#include "../../induco.h"
#include "../../sort_headers.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <pessum.h>
#include <vector>

double sort::InsertionSort(bool display) {
  if (display == true) {
    std::cout << "Insertion Sort:\n";
  }
  double timeelapsed;
  induco::Timer(true);
  for (int i = 1; i < values.size(); i++) {
    int j = i;
    while (j > 0 && values[j - 1] > values[i]) {
      j--;
    }
    iter_swap(values.begin() + j, values.begin() + i);
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
