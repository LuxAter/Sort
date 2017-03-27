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
  };
  extern AlgoResult result;
  extern std::map<std::string, void (*)()> algorithms;
  extern std::vector<int> data_base, data;
  void LoadAlgos();
  bool RunAlgo(std::string algo);
  void PrintResults();
  void ClearResults();
  void GenData(std::string settings);
  bool IsSorted();
  void BadSort();
}
#endif
