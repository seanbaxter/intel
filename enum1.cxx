#include <iostream>

enum typename my_types_t {
  double,
  int,
  char*,
  int[5],
  char,
};

int main() {
  std::cout<< "With for loop:\n";
  @meta for(int i : @enum_count(my_types_t))
    std::cout<< "  "<< @enum_type_string(my_types_t, i)<< "\n";

  std::cout<< "With for-enum loop:\n";
  @meta for enum(my_types_t e : my_types_t)
    std::cout<< "  "<< @enum_type_string(e)<< "\n";

  std::cout<< "With parameter pack:\n";
  std::cout<< "  "<< @enum_type_strings(my_types_t)<< "\n" ...;
}
