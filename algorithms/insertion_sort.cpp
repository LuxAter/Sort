#include <pessum.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include "../sort_headers.h"

double sort::InsertionSort() {
  DivideLine();
  std::cout << "Insertion Sort:\n";
  double timeelapsed;
  Timer();
  for (int i = 1; i < values.size(); i++) {
    int j = i;
    while (j > 0 && values[j - 1] > values[i]) {
      j--;
    }
    iter_swap(values.begin() + j, values.begin() + i);
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
