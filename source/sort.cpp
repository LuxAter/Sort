#include "sort.hpp"

#include <unistd.h>
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "output.hpp"

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

// std::map<unsigned int, std::string> algorithm_names = {
// {QUICK, "Quicksort"},
// {MERGE, "Merge Sort"},
// {HEAP, "Heapsort"},
// {INSERTION, "Insertion Sort"},
// {INTRO, "Introsort"},
// {SELECTION, "Selection Sort"},
// {TIM, "Timsort"},
// {CUBE, "Cubesort"},
// {SHELL, "Shell Sort"},
// {BUBBLE, "Bubble Sort"},
// {BINARY_TREE, "Binary Tree Sort"},
// {CYCLE, "Cycle Sort"},
// {LIBRARY, "Library Sort"},
// {PATIENCE, "Patience Sort"},
// {SMOOTH, "Smoothsort"},
// {STRAND, "Strand Sort"},
// {TOURNAMENT, "Tournamet Sort"},
// {COCKTAIL, "Cocktail Sort"},
// {COMB, "Comb Sort"},
// {GNOME, "Gnome Sort"},
// {UNSHUFFLE, "UnShuffle Sort"},
// {BLOCK, "Block Sort"},
// {ODD_EVEN, "Odd-Even Sort"}};

int cdot = 0;

int RunAlgo(unsigned int algo, std::vector<int> data) {
  if (algo > 22) {
    Print(false, algo, 0);
    return -1;
  }
  Print(true, algo, 0);
  Print(false, algo, 0);
  return 0;
}

void Print(bool running, unsigned int algo, int dot) {
  if (algo > 22) {
    std::cout << cli::Bold(cli::Red("[ Error      ]")) << " "
              << cli::Magenta(std::to_string(algo))
              << " is not a valid algorithm\n";
  } else if (running == true) {
    std::cout << cli::Bold(cli::Yellow("[ Running    ]")) << " "
              << cli::Blue(algorithm_names[algo]) << "\r";
  } else if (running == false) {
    std::cout << cli::Bold(cli::Green("[ Compleated ]")) << " "
              << cli::Blue(algorithm_names[algo]) << "\n";
  }
}
