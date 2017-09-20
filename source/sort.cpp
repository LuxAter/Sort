#include "sort.hpp"

#include <unistd.h>
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "cursor.hpp"
#include "output.hpp"

#include "algo/algos.hpp"

std::map<unsigned int, std::string> algorithm_names = {
    {QUICK, "Quicksort"},
    {MERGE, "Merge Sort"},
    {HEAP, "Heapsort"},
    {INSERTION, "Insertion Sort"},
    {INTRO, "Introsort"},
    {SELECTION, "Selection Sort"},
    {TIM, "Timsort"},
    {CUBE, "Cubesort"},
    {SHELL, "Shell Sort"},
    {BUBBLE, "Bubble Sort"},
    {BINARY_TREE, "Binary Tree Sort"},
    {CYCLE, "Cycle Sort"},
    {LIBRARY, "Library Sort"},
    {PATIENCE, "Patience Sort"},
    {SMOOTH, "Smoothsort"},
    {STRAND, "Strand Sort"},
    {TOURNAMENT, "Tournamet Sort"},
    {COCKTAIL, "Cocktail Sort"},
    {COMB, "Comb Sort"},
    {GNOME, "Gnome Sort"},
    {UNSHUFFLE, "UnShuffle Sort"},
    {BLOCK, "Block Sort"},
    {ODD_EVEN, "Odd-Even Sort"}};

std::map<unsigned int, std::function<std::array<int, 2>(void)>> algorithm_run =
    {{QUICK, quick::Run}, {BUBBLE, bubble::Run}, {MERGE, merge::Run}};

std::vector<int> data, backup;

void Pause() { std::cin.ignore(); }

void PrintData() {
  for (int i = 0; i < data.size(); i++) {
    std::cout << data[i];
    if (i != data.size() - 1) {
      std::cout << ",";
    }
  }
  std::cout << "\n";
}

bool CheckSort() {
  for (int i = 1; i < data.size(); i++) {
    if (data[i] <= data[i - 1]) {
      return false;
    }
  }
  return true;
}

std::array<int, 4> RunAlgo(unsigned int algo) {
  unsigned int status;
  std::array<int, 2> trace = {{1, 1}};
  clock_t start = 0, end = 0;
  if (algorithm_run.find(algo) != algorithm_run.end()) {
    start = clock();
    trace = algorithm_run[algo]();
    end = clock();
    status = COMPLETED;
    if (CheckSort() == false) {
      status = FAILED;
    }
  } else {
    status = NOTFOUND;
  }
  data = backup;
  return {{status, end - start, trace[0], trace[1]}};
}

void Print(std::vector<std::array<unsigned int, 2>> algos, bool first) {
  if (first != true) {
    std::cout << "\033[" + std::to_string(algos.size()) + "A";
  }
  for (std::vector<std::array<unsigned int, 2>>::iterator it = algos.begin();
       it != algos.end(); ++it) {
    if ((*it)[1] > 22 || (*it)[0] == NOTFOUND) {
      (*it)[0] = NOTFOUND;
      std::cout << cli::Bold(cli::Red("[ Invalid   ]")) << " "
                << cli::Magenta(std::to_string((*it)[1]))
                << " is not a valid algorithm\n";
    } else if ((*it)[0] == RUNNING) {
      std::cout << cli::Bold(cli::Yellow("[ Running   ]")) << " "
                << cli::Blue(algorithm_names[(*it)[1]]) << "\n";
    } else if ((*it)[0] == COMPLETED) {
      std::cout << cli::Bold(cli::Green("[ Completed ]")) << " "
                << cli::Blue(algorithm_names[(*it)[1]]) << "\n";
    } else if ((*it)[0] == QUEUED) {
      std::cout << cli::Bold(cli::Magenta("[ Queued    ]")) << " "
                << cli::Blue(algorithm_names[(*it)[1]]) << "\n";
    } else if ((*it)[0] == FAILED) {
      std::cout << cli::Bold(cli::Red("[ Failed    ]")) << " "
                << cli::Blue(algorithm_names[(*it)[1]]) << "\n";
    }
  }
}

void PrintResults(
    std::vector<std::pair<unsigned int, std::vector<int>>> results) {
  std::cout << "\u2502" << cli::Blue("       Algorithm Name ") << "\u2502"
            << cli::Yellow(" Average Time ") << "\u2502"
            << cli::Green(" Best Time ") << "\u2502" << cli::Red(" Worst Time ")
            << "\u2502\n";
  std::cout << "\u251C";
  for (int i = 0; i < 22; i++) {
    std::cout << "\u2500";
  }
  std::cout << "\u253C";
  for (int i = 0; i < 14; i++) {
    std::cout << "\u2500";
  }
  std::cout << "\u253C";
  for (int i = 0; i < 11; i++) {
    std::cout << "\u2500";
  }
  std::cout << "\u253C";
  for (int i = 0; i < 12; i++) {
    std::cout << "\u2500";
  }
  std::cout << "\u2524\n";
  for (std::vector<std::pair<unsigned int, std::vector<int>>>::iterator it =
           results.begin();
       it != results.end(); ++it) {
    std::string line = "\u2502";
    std::string name, average, best, worst;
    char buffer[80];
    if (algorithm_names.find(it->first) == algorithm_names.end()) {
      algorithm_names[it->first] = "Error";
    }
    sprintf(buffer, " %20s ", algorithm_names[it->first].c_str());
    name = std::string(buffer);
    sprintf(buffer, " %12f ", it->second[0] / (double)CLOCKS_PER_SEC);
    average = std::string(buffer);
    sprintf(buffer, " %9f ", it->second[1] / (double)CLOCKS_PER_SEC);
    best = std::string(buffer);
    sprintf(buffer, " %10f ",
            it->second[it->second.size() - 1] / (double)CLOCKS_PER_SEC);
    worst = std::string(buffer);
    std::cout << "\u2502" << cli::Blue(name) << "\u2502" << cli::Yellow(average)
              << "\u2502" << cli::Green(best) << "\u2502" << cli::Red(worst)
              << "\u2502\n";
  }
}

void CalculateResults(
    std::vector<std::pair<unsigned int, std::vector<int>>>* results) {
  for (std::vector<std::pair<unsigned int, std::vector<int>>>::iterator it =
           results->begin();
       it != results->end(); ++it) {
    if (it->second.size() == 1) {
      it->second.push_back(it->second[0]);
      it->second.push_back(it->second[0]);
    } else if (it->second.size() == 0) {
      it->second = {-1, -1, -1};
    } else {
      std::sort(it->second.begin(), it->second.end());
      double average = 0.0;
      for (std::vector<int>::iterator vit = it->second.begin();
           vit != it->second.end(); ++vit) {
        average += (*vit);
      }
      average /= (double)it->second.size();
      it->second.insert(it->second.begin(), (int)average);
      average = 0.0;
    }
  }
}

void Run() {
  int loops = 1;
  std::cout << cli::White("Running Sorting Algorithms") << "\n";
  // data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // data = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12,
  // 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
  std::random_shuffle(data.begin(), data.end());
  for (int i = 0; i < 10000; i++) {
    data.push_back(rand());
  }
  backup = data;
  std::vector<std::array<unsigned int, 2>> algos;
  std::vector<std::pair<unsigned int, std::vector<int>>> results;
  for (std::map<unsigned int, std::string>::iterator it =
           algorithm_names.begin();
       it != algorithm_names.end(); ++it) {
    algos.push_back({QUEUED, it->first});
  }
  Print(algos, true);
  for (int i = 0; i < algos.size(); i++) {
    std::pair<unsigned int, std::vector<int>> algo_result = {algos[i][1], {}};
    algos[i][0] = RUNNING;
    Print(algos);
    for (int j = 0; j < loops; j++) {
      std::array<int, 4> ret = RunAlgo(algos[i][1]);
      algos[i][0] = ret[0];
      algo_result.second.push_back(ret[1]);
    }
    results.push_back(algo_result);
  }
  Print(algos);
  std::cout << cli::White("Compleated Sorting Algorithms") << "\n";
  CalculateResults(&results);
  PrintResults(results);
}
