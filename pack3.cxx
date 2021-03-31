#include <iostream>
#include <vector>
#include <string>

int main() {
  std::string s = "Hello world";

  // Reverse the string in place.
  std::swap(s[0:s.size()/2], s[:s.size()/2:-1])...;
  std::cout<< s<< "\n";

  // Reverse back using list comprehension.
  std::string s2 = [s[::-1]...];
  std::cout<< s2<< "\n";
}