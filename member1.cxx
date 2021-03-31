#include <iostream>
#include <tuple>

int main() {
  struct foo_t {
    int a;
    float b;
    const char* c;
  };
  foo_t obj { 42, 3.14f, "A class" };
  std::cout<< "A class:\n";
  std::cout<< "  "<< int...<< ": "<< obj...[:]<< "\n"...;

  auto tuple = std::make_tuple(128, 1.618, "A tuple");
  std::cout<< "A tuple:\n";
  std::cout<< "  "<< int...<< ": "<< tuple...[:]<< "\n"...;

  [](auto... x) {
    std::cout<< "Lambda:\n";
    std::cout<< "  "<< int...<< ": "<< x<< "\n"...;
  }(obj...[:]..., tuple...[:]...);
}