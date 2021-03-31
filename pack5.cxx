#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

int main() {
  std::string s1 = "Hello world";
  std::string s2 = "What's new?";

  // Use list comprehension to build an initializer list.
  // Intersperse each character with a '*'.
  std::string s3 = [{s1[:], '*'}...];
  std::cout<< s3<< "\n";

  // Do the same with a for-expression.
  std::string s4 = [for c : s1 => { c, '!' }...];
  std::cout<< s4<< "\n";

  // Emit an upper/lowercase sequence.
  std::string s5 = [for c : s1 => { (char)toupper(c), (char)tolower(c) }...];
  std::cout<< s5<< "\n";

  // Interleave two strings.
  std::string s6 = [{ s1[:], s2[:] }...];
  std::cout<< s6<< "\n";
}
