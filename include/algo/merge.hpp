#include <array>
#include <vector>

namespace merge {
  std::array<int, 2> Run();
  void Base(int low, int high, std::array<int, 2>* trace);
  void Merge(int low1, int high1, int low2, int high2,
             std::array<int, 2>* trace);
}  // namespace merge
