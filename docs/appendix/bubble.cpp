#include "algo/bubble.hpp"

#include <array>
#include <vector>

#include "sort.hpp"

std::array<int, 2> bubble::Run() {
  int length = data.size();
  std::array<int, 2> track = {{0, 0}};
  while (length != 0) {
    int new_length = 0;
    for (int i = 1; i < length; i++) {
      track[0] += 2;
      if (data[i - 1] > data[i]) {
        track[1]++;
        iter_swap(data.begin() + i - 1, data.begin() + i);
        new_length = i;
      }
    }
    length = new_length;
  }
  return track;
}
