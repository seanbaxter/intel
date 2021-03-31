#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

int main() {
  std::vector v = [for i : 10 => rand() % 1000...];
  std::sort(v.begin(), v.end());
  std::cout<< @range()<< ": "<< v[:]<< "\n"...;

  // Use C++17 fold expression to test if sorted.
  bool is_sorted = (... && (v[:] <= v[1:]));

  // A functional fold to find the max element.
  auto max = (... std::max v[:]);

  // A functional fold to find the smallest gap between consecutive elements.
  auto closest = (... std::min (v[1:] - v[:]));

  std::cout<< "is_sorted = "<< is_sorted<< "\n";
  std::cout<< "max = "<< max<< "\n";
  std::cout<< "closest = "<< closest<< "\n";
}