#include <pessum.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include "../sort_headers.h"

double sort::SelectionSort() {
  DivideLine();
  std::cout << "Seleciton Sort:\n";
  double timeelapsed;
  Timer();
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
      DrawLoadingBar(i / (double)values.size(), 50);
    }
  }
  DrawLoadingBar(1, 50);
  std::cout << "\nSorted " << values.size() << " values\nIn ";
  timeelapsed = Timer(true);
  if (pausecheck == true) {
    std::cout << "[Y]";
    char checkin;
    std::cin >> checkin;
  }
  return (timeelapsed);
}
