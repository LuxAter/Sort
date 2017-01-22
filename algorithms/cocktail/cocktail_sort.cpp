#include "../../sort_headers.h"
#include <appareo_files/appareo_headers.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

double sort::CocktailSort(bool display) {
  if (display == true) {
    appareo::induco::CreateProgressBar("Cocktail Sort");
  }
  double timeelapsed;
  appareo::induco::Timer(true);
  bool swapped = true;
  int start = 0, end = values.size() - 1;
  while (swapped == true) {
    swapped = false;
    for (int i = start; i < end; i++) {
      if (values[i] > values[i + 1]) {
        iter_swap(values.begin() + i, values.begin() + i + 1);
        swapped = true;
      }
    }
    if (swapped == true) {
      end--;
      swapped = false;
      for (int i = end; i >= start; i--) {
        if (values[i] > values[i + 1]) {
          iter_swap(values.begin() + i, values.begin() + i + 1);
          swapped = true;
        }
      }
      start++;
      if (display == true) {
        appareo::induco::UpdateProgressBar((values.size() - (end - start)) /
                                           (double)values.size() * 2);
      }
    }
  }
  timeelapsed = appareo::induco::Timer();
  if (display == true) {
    appareo::induco::TerminateProgressBar();
  }
  return (timeelapsed);
}
