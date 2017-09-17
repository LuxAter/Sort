#include <map>
#include <string>
#include <vector>

enum Algorithms {
  QUICK,
  MERGE,
  HEAP,
  INSERTION,
  INTRO,
  SELECTION,
  TIM,
  CUBE,
  SHELL,
  BUBBLE,
  BINARY_TREE,
  CYCLE,
  LIBRARY,
  PATIENCE,
  SMOOTH,
  STRAND,
  TOURNAMENT,
  COCKTAIL,
  COMB,
  GNOME,
  UNSHUFFLE,
  BLOCK,
  ODD_EVEN,
  NONE
};

extern std::map<unsigned int, std::string> algorithm_names;

int RunAlgo(unsigned int algo, std::vector<int> data);

void Print(std::vector<std::array<unsigned int, 2>> algos, bool first = false);

void PrintResults(
    std::vector<std::pair<unsigned int, std::vector<int>>> results);

void CalculateResults(
    std::vector<std::pair<unsigned int, std::vector<int>>>* results);

void Run();
