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
  extern int data_count, data_min, data_max;
  void LoadAlgos();
  bool RunAlgo(std::string algo);
  void ClearResults();
  void GenData(std::string settings);
  void GenData(int count = -1, int min = -1, int max = -1);
  bool IsSorted();
  void BadSort();
  void Run(std::vector<std::string> algos);
}
#endif
