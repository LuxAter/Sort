#ifndef ALGO
#define ALGO
#include <map>
#include <string>
#include <vector>
namespace sort {
  struct AlgoResult {
    double time;
    long int comparisons;
    long int vec_access;
    long int vec_writes;
  };
  extern AlgoResult Result;
  extern std::map<std::string, double (*)(std::vector<int>)> algorithms;
  extern std::vector<int> data_base;
  void LoadAlgos();
  void RunAlgo(std::string algo);
}
#endif
