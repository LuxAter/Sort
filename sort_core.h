#ifndef SORT_CORE_H_
#define SORT_CORE_H_
#include <string>
#include <vector>
namespace sort {
extern std::vector<int> values;
extern std::vector<int> scrambledvalues;
extern int savedbarcount;
extern bool display;
extern clock_t starttime;
int GenorateValues();
void DivideLine();
void DrawLoadingBar(double percent, int size);
double Timer(bool stop = false);
void List();
void Reset();
}
#endif
