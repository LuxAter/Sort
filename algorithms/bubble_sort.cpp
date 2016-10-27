#include <pessum.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include "../sort_headers.h"

double sort::BubbleSort() {
  DivideLine();
  std::cout << "Bubble Sort:\n";
  double timeelapsed;
  Timer();
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
    DrawLoadingBar((values.size() - n) / (float)values.size(), 50);
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
