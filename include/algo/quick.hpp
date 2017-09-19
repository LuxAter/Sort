#include <array>
#include <vector>

namespace quick {
  std::array<int, 2> Run();
  void Base(int low, int high, std::array<int, 2>* trace);
  int Partition(int low, int high, std::array<int, 2>* trace);
}  // namespace quick
