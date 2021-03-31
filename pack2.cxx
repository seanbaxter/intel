#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
  std::vector v { 10, 20, 30, 40, 50 };
  std::cout<< v[::-1]<< "\n"...;  // Print in reverse order
  
  std::string s = "Hello Circle";
  std::cout<< s[1::2]<< "\n"...;  // Print the odd characters

  // Print the map keys in forward order and values in reverse order.
  std::map<int, std::string> m { { 1, "one" }, { 2, "two" }, { 3, "three" } };
  std::cout<< m[:].first<< ": "<< m[::-1].second<< "\n"...;
}