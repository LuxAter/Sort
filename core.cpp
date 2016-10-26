#include "sort_headers.h";
#include <iostream>
#include <pessum.h>

int main(int argc, char *argv[]) {
  pessum::InitializePessumComponents();
  bool running = true;
  srand(time(NULL));
  sort::display = true;
  while (running == true) {
    char input = ' ';
    int integerinput = 0;
    sort::DivideLine();
    std::cout << "Sort Test Program\n"
                 "-----------------\n\n"
                 "[1]:Genorate Values\n"
                 "[2]:Use All Methods\n"
                 "[3]:Mass Comparison\n"
                 "[4/Q]:Quit Program\n\n"
                 "Individual Sorting Algorithms\n"
                 "-----------------------------\n\n"
                 "[A]:Quick Sort\n"
                 "[B]:Merge Sort\n"
                 "[c]:Tim Sort\n"
                 "[D]:Heap Sort\n"
                 "[E]:Bubble Sort\n"
                 "[F]:Insertion Sort\n"
                 "[G]:Selection Sort\n"
                 "[H]:Tree Sort\n"
                 "[I]:Shell Sort\n"
                 "[J]:Bucket Sort\n"
                 "[K]:Radix Sort\n"
                 "[L]:Counting Sort\n"
                 "[M]:Cube Sort\n\n"
                 "----------------------\n";
    std::cin >> input;
    if (input == '1') {
      sort::GenorateValues();
    }
    if (input == '2') {
    }
    if (input == '3') {
    }
    if (input == '4' || input == 'q' || input == 'Q') {
      running = false;
    }
    if (input == 'e' || input == 'E') {
      sort::BubbleSort();
      sort::Reset();
    }
    if (input == 'f' || input == 'F') {
      sort::InsertionSort();
      sort::Reset();
    }
    if (input == 'g' || input == 'G') {
      sort::SelectionSort();
      sort::Reset();
    }
  }
  pessum::TerminatePessumComponents();
  return (1);
}
