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
extern int savedbarcount;
extern bool display;
extern bool pausecheck;
extern clock_t starttime;
int GenorateValues();
void DivideLine();
void DrawLoadingBar(double percent, int size);
double Timer(bool stop = false);
void List();
void Reset();
void UseAll();
void MassCheck();
}
#endif
