#ifndef SORT_CORE_H_
#define SORT_CORE_H_
#include <string>
#include <vector>
namespace sort {
struct Algorithm {
  int n, i;
  std::string algorithmname;
  double elapsed;
};
extern std::vector<int> values;
extern std::vector<int> scrambledvalues;
int GenorateValues(int count = 100, int min = 0, int max = 100,
                   bool display = false);
void List();
void Reset();
void UseAll();
void MassCheck();
void Clean();
}
#endif
