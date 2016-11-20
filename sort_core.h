#ifndef SORT_CORE_H_
#define SORT_CORE_H_
#include <string>
#include <vector>
namespace sort {
extern std::vector<int> values;
extern std::vector<int> scrambledvalues;
int GenorateValues(int count = 100, int min = 0, int max = 100,
                   bool display = false);
void List();
void Reset();
void Clean();
bool CheckSort();
}
#endif
