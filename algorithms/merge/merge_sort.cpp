#include "../../induco.h"
#include "../../sort_headers.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

namespace sort {
std::vector<int> Mworkvector;
}

double sort::MergeSort(bool display) {
  if (display == true) {
    std::cout << "Merge Sort:\n";
  }
  double timeelapsed;
  induco::Timer(true);
  Mworkvector = values;
  for (int i = 1; i < values.size(); i = 2 * i) {
    for (int j = 0; j < values.size(); j = j + 2 * i) {
      if (display == true) {
        induco::DrawLoadingBar(j / (double)values.size(), 50);
      }
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
      MMerge(j, vara, varb);
    }
    values = Mworkvector;
  }
  timeelapsed = induco::Timer();
  if (display == true) {
    induco::DrawLoadingBar(1, 50);
    std::cout << "\nSorted " << values.size() << "\n";
    std::cout << induco::DisplayTime(timeelapsed, true) << "\n";
  }
  return (timeelapsed);
}

void sort::MMerge(int ileft, int iright, int iend) {
  int i = ileft;
  int j = iright;
  for (int k = ileft; k < iend; k++) {
    if (i < iright && (j >= iend || values[i] <= values[j])) {
      Mworkvector[k] = values[i];
      i++;
    } else {
      Mworkvector[k] = values[j];
      j++;
    }
  }
}
