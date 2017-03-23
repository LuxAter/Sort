#include <ncurses.h>
#include <ostendo.h>
#include <pessum.h>
#include <fstream>
#include <iostream>
#include <string>
#include "../algorithms/algo_core.hpp"
#include "sort.hpp"

namespace sort {
  bool running = true;
  std::vector<std::string> help_doc;
  ostendo::Window win(10, 10, 10, 10);
}

using namespace ostendo;

void sort::MainLoop() {
  running = true;
  win.NewWindow(ostendo::std_scr.w / 2, ostendo::std_scr.h / 2,
                ostendo::std_scr.w / 4, ostendo::std_scr.h / 4);
  win.ToggleTitle("Sorting Algorithms");
  win.ToggleBorder();
  win.ToggleScroll();
  PrintOpen();
  LoadHelp();
  LoadAlgos();
  GenData("");
  std::string input = "";
  bool update = true;
  while (running == true) {
    if (update == true) {
      update = false;
      win.Print(">>%s", input.c_str());
    }
    int in = getch();
    if (in == 10) {
      win.Print("\n");
      RunInput(input);
      input = "";
      update = true;
    } else if (in == KEY_BACKSPACE) {
      if (input.length() > 0) {
        win.ClearLine();
        input.pop_back();
        update = true;
      }
    } else if (in != ERR) {
      input += char(in);
      win.SetCurs(-1, 1);
      update = true;
    }
  }
  win.DelWin();
}

void sort::PrintOpen() {
  win.Print(
      "==========SORTING ALGORITHMS==========\n"
      "Type \"quit\" to quit\n"
      "Type \"help\" for help page\n\n");
}

void sort::Help(int page) {
  if (page < help_doc.size()) {
    std::string page_str = help_doc[page];
    win.Clear();
    win.Print("==========HELP PAGE %i==========\n%s", page, page_str.c_str());
  } else {
    win.Print("No Help Page %i Exists\n", page);
  }
}

void sort::LoadHelp() {
  std::ifstream help_file("help.txt");
  if (help_file.is_open()) {
    std::string line, page = "";
    while (getline(help_file, line)) {
      if (line == "/newpage") {
        help_doc.push_back(page);
        page = "";
      } else {
        page += line + "\n";
      }
    }
    help_doc.push_back(page);
  } else {
    win.Print("[ERR] : NO HELP FILE FOUND\n");
  }
}

void sort::RunInput(std::string input) {
  if (input == "quit") {
    running = false;
  } else if (input[0] == 'h' && input[1] == 'e' && input[2] == 'l' &&
             input[3] == 'p') {
    input.erase(input.begin(), input.begin() + 4);
    if (input.length() != 0) {
      Help(IsInt(input));
    } else {
      Help(0);
    }
  } else if (input == "clear") {
    win.Clear();
  } else if (input[0] == 'd' && input[1] == 'a' && input[2] == 't' &&
             input[3] == 'a') {
    input.erase(input.begin(), input.begin() + 4);
    GenData(input);
  } else if (RunAlgo(input) == true) {
  } else {
    win.Print("\"%s\" is not a valid command\n", input.c_str());
  }
}

int sort::IsInt(std::string str) {
  bool good = true;
  for (int i = 0; i < str.length(); i++) {
    if (int(str[i]) > 57 || int(str[i]) < 48) {
      good = false;
    }
  }
  int str_int = -1;
  if (good == true) {
    str_int = stoi(str);
  }
  return (str_int);
}

std::string sort::NormalizeInput(std::string input) {
  for (int i = 0; i < input.length(); i++) {
    input[i] = tolower(input[i]);
  }
  return (input);
}
