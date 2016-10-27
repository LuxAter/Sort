#include <pessum.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include "../sort_headers.h"

namespace sort {
std::vector<int> workvector;
}

double sort::MergeSort() {
  DivideLine();
  std::cout << "Merge Sort:\n";
  savedbarcount = -1;
  double timeelapsed;
  Timer();
  workvector = values;
  for (int i = 1; i < values.size(); i = 2 * i) {
    for (int j = 0; j < values.size(); j = j + 2 * i) {
      DrawLoadingBar(j / (double)values.size(), 50);
      int vara, varb;
      if (j + i >= values.size()) {
        vara = values.size();
      } else {
        vara = j + i;
      }
      if (j + 2 * i >= values.size()) {
        varb = values.size();
      } else {
        varb = j + 2 * i;
      }
      Merge(j, vara, varb);
    }
    values = workvector;
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

void sort::Merge(int ileft, int iright, int iend) {
  int i = ileft;
  int j = iright;
  for (int k = ileft; k < iend; k++) {
    if (i < iright && (j >= iend || values[i] <= values[j])) {
      workvector[k] = values[i];
      i++;
    } else {
      workvector[k] = values[j];
      j++;
    }
  }
}
