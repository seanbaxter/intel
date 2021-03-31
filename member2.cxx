#include <tuple>
#include <iostream>

typedef float __attribute__((vector_size(16))) vec4;

int main() {
  std::tuple<float, int, double, short> tuple(1, 2, 3, 4);
  vec4 v(1, 2, 3, 4);

  // Component-wise addition of different types.
  tuple...[:] += v...[:]...;
  std::cout<< "tuple += vector:\n";
  std::cout<< "  "<< int...<< ": "<< tuple...[:]<< "\n"...;

  // Use fold expressions.
  auto sum = (... + tuple...[:]);
  std::cout<< "tuple sum = "<< sum<< "\n";

  // Initialize a vector with the tuple's elements in reverse order.
  vec4 v2(tuple...[::-1]...);
  std::cout<< "vector:\n";
  std::cout<< "  "<< int...<< ": "<< v2...[:]<< "\n"...;
}