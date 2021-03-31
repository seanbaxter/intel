#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
  std::vector v { 10, 20, 30, 40, 50 };
  std::cout<< v[:]<< "\n"...; // Print all elements.

  std::string s = "Hello Circle";
  std::cout<< s[:]<< "\n"...; // Print all characters.

  std::map<int, std::string> m { { 1, "one" }, { 2, "two" }, { 3, "three" } };
  std::cout<< m[:].first<< ": "<< m[:].second<< "\n"...;
}