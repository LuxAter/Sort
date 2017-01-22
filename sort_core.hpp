#ifndef SORT_CORE_H_
#define SORT_CORE_H_
#include <map>
#include <string>
#include <vector>
namespace sort {
typedef double (*algo)(bool);
typedef std::map<std::string, algo> mappedalgos;
extern std::vector<int> values, scramble;
extern bool display;
extern int count, min, max;
double GenorateValues();
void Reset();
void Clean();
bool CheckSort();
void List();
void RunAlgorithms(std::vector<std::string> algos, bool display = false);
}
#endif
