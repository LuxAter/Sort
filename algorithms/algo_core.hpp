#ifndef ALGO
#define ALGO
#include <map>
#include <string>
#include <vector>
namespace sort {
  struct AlgoResult {
    double time_elapsed;
    long int comparisons;
    long int vec_access;
    long int vec_writes;
  };
  extern AlgoResult result;
  extern std::map<std::string, void (*)(std::vector<int>)> algorithms;
  extern std::vector<int> data_base;
  void LoadAlgos();
  bool RunAlgo(std::string algo);
  void PrintResults();
  void ClearResults();
  void GenData(std::string settings);
}
#endif
