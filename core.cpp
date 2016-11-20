#include "induco.h"
#include "sort_headers.h";
#include <iostream>

int main(int argc, char *argv[]) {
  bool running = true;
  int count = 1000000, min = 0, max = 100000000;
  srand(time(NULL));
  std::vector<std::string> options = {"Meta Average Analize", "Average Analize",
                                      "Set Value Paramaters",
                                      "Single Method Sort", "Quit"};
  std::vector<std::string> sortoptions = {
      "Bubble",      "Bucket",    "Counting",   "Cube[TODO]",  "Heap[TODO]",
      "Insertion",   "Merge",     "Quick[BUG]", "Radix[TODO]", "Selection",
      "Shell[TODO]", "Tim[TODO]", "Tree[TODO]", "Back"};
  while (running == true) {
    induco::Break();
    int input = induco::Menu("Sorting Algorithms", options);
    if (input == 1) {
      induco::Break();
    }
    if (input == 2) {
      induco::Break();
    }
    if (input == 3) {
      induco::Break();
      count = induco::GetValue("n");
      min = induco::GetValue("Minimum");
      max = induco::GetValue("Maximum");
    }
    if (input == 4) {
      induco::Break();
      int inputtwo = induco::Menu("Algorithms", sortoptions);
      induco::Break();
      if (inputtwo != 14) {
        sort::Clean();
        sort::GenorateValues(count, min, max, true);
        induco::Line(50);
      }
      if (inputtwo == 1) {
        sort::Reset();
        sort::QuickSort(true);
      }
      if (inputtwo == 2) {
        sort::Reset();
        sort::MergeSort(true);
      }
      if (inputtwo == 3) {
      }
      if (inputtwo == 4) {
      }
      if (inputtwo == 5) {
        sort::Reset();
        sort::BubbleSort(true);
      }
      if (inputtwo == 6) {
        sort::Reset();
        sort::InsertionSort(true);
      }
      if (inputtwo == 7) {
        sort::Reset();
        sort::SelectionSort(true);
      }
      if (inputtwo == 8) {
      }
      if (inputtwo == 9) {
      }
      if (inputtwo == 10) {
        sort::Reset();
        sort::BucketSort(10, true);
      }
      if (inputtwo == 11) {
      }
      if (inputtwo == 12) {
        sort::Reset();
        sort::CountingSort(true);
      }
      if (inputtwo == 13) {
      }
    }
    if (input == 5) {
      induco::Break();
      running = false;
    }
  }
  return (1);
}
