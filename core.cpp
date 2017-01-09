#include <appareo_files/appareo_headers.h>
#include <iostream>
#include "sort_headers.h"

int main(int argc, char *argv[]) {
  appareo::InitializeAppareo();
  appareo::curse::InitializeWindow();
  appareo::curse::windows[0].CreateWindow("Sorting Algorithms", -1, -1, -1, -1,
                                          true, true);
  appareo::curse::out::BindWindow("Sorting Algorithms");
  bool running = true;
  int count = 10000, min = 0, max = 100000;
  srand(time(NULL));
  std::vector<std::string> options = {"Meta Average Analize", "Average Analize",
                                      "Set Value Paramaters", "Use All Sort",
                                      "Single Method Sort",   "Quit"};
  std::vector<std::vector<std::string>> sortoptions = {
      {"Bubble", "Bucket", "Counting"},
      {"Cube[TODO]", "Heap[TODO]", "Insertion"},
      {"Merge", "Quick", "Radix[TODO]"},
      {"Selection", "Shell[TODO]", "Tim[TODO]"},
      {"Tree[TODO]"},
      {"Back"}};
  while (running == true) {
    std::vector<std::string> inputs =
        appareo::curse::NewMenu(options, "Sorting Algorithms", 50, 20);
    std::string input = inputs[0];
    if (input == options[0]) {
    }
    if (input == options[1]) {
    }
    if (input == options[2]) {
      appareo::curse::Field newfield;
      std::vector<appareo::curse::Field> fields;
      newfield.name = "Count";
      newfield.type = 1;
      newfield.sval = std::to_string(count);
      fields.push_back(newfield);
      newfield.name = "Minimum";
      newfield.type = 1;
      newfield.sval = std::to_string(min);
      fields.push_back(newfield);
      newfield.name = "Maximum";
      newfield.type = 1;
      newfield.sval = std::to_string(max);
      fields.push_back(newfield);
      fields = appareo::curse::NewForm(fields, "Parameters", 50, 10);
      count = fields[0].ival;
      min = fields[1].ival;
      max = fields[2].ival;
    }
    if (input == options[3]) {
      sort::GenorateValues(count, min, max, false);
      sort::UseAll();
    }
    if (input == options[4]) {
      std::vector<std::string> inputstwo = appareo::curse::NewMenu(
          sortoptions, "Algorithms", 50, 30, -1, -1, true);
      std::vector<std::string> comoptions;
      std::vector<double> times;
      for (int i = 0; i < sortoptions.size(); i++) {
        for (int j = 0; j < sortoptions[i].size(); j++) {
          comoptions.push_back(sortoptions[i][j]);
        }
      }
      if (inputstwo[0] != comoptions[comoptions.size() - 1]) {
        sort::Clean();
        sort::GenorateValues(count, min, max, true);
      }
      for (int i = 0; i < inputstwo.size(); i++) {
        std::string inputtwo = inputstwo[i];
        if (inputtwo == comoptions[0]) {
          sort::Reset();
          times.push_back(sort::BubbleSort(true));
        }
        if (inputtwo == comoptions[1]) {
          sort::Reset();
          times.push_back(sort::BucketSort(10, true));
        }
        if (inputtwo == comoptions[2]) {
          sort::Reset();
          times.push_back(sort::CountingSort(true));
        }
        if (inputtwo == comoptions[3]) {
        }
        if (inputtwo == comoptions[4]) {
        }
        if (inputtwo == comoptions[5]) {
          sort::Reset();
          times.push_back(sort::InsertionSort(true));
        }
        if (inputtwo == comoptions[6]) {
          sort::Reset();
          times.push_back(sort::MergeSort(true));
        }
        if (inputtwo == comoptions[7]) {
          sort::Reset();
          times.push_back(sort::QuickSort(true));
        }
        if (inputtwo == comoptions[8]) {
        }
        if (inputtwo == comoptions[9]) {
          sort::Reset();
          times.push_back(sort::SelectionSort(true));
        }
        if (inputtwo == comoptions[10]) {
        }
        if (inputtwo == comoptions[11]) {
        }
        if (inputtwo == comoptions[12]) {
        }
      }
      int win = appareo::curse::windows.size();
      appareo::curse::InitializeWindow();
      appareo::curse::win->CreateWindow("Results", appareo::curse::scrwidth / 2,
                                        3 * appareo::curse::scrheight / 4, -1, -1, true,
                                        true);
      // induco::Line(51);
      std::string line = "    ALGORITHM| HOURS |  MIN |  SEC |  MS  |  US";
      appareo::curse::out::Print(line, 1, (appareo::curse::windows[win].width - line.size()) / 2, win);
      for (int i = 0; i < times.size(); i++) {
         line = inputstwo[i];
         while (line.size() < 15) {
          line = " " + line;
        }
         line += "|";
         line += appareo::induco::DisplayTime(times[i], true);
         appareo::curse::out::Print(line, i + 2, (appareo::curse::windows[win].width - line.size()) / 2, win);
      }
      getch();
      appareo::curse::TerminateWindow(win);
      appareo::curse::windows[0].Clear();
    }
    if (input == options[5]) {
      running = false;
    }
  }
  appareo::TerminateAppareo();
  return (1);
}
