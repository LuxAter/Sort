#include "../../induco.h"
#include "../../sort_headers.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <pessum.h>
#include <vector>

double sort::BubbleSort(bool display) {
  if (display == true) {
    std::cout << "Bubble Sort:\n";
  }
  double timeelapsed;
  induco::Timer(true);
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
      induco::DrawLoadingBar((values.size() - n) / (float)values.size(), 50);
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
