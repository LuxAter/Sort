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
  ODD_EVEN
};

extern std::map<unsigned int, std::string> algorithm_names;
extern int cdot;

int RunAlgo(unsigned int algo, std::vector<int> data);

void Print(bool running, unsigned int algo, int dot);
