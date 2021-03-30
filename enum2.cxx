#include <tuple>
#include <iostream>

enum typename my_types_t {
  int, float, char, const char*, void(*)(int)
};

int main() {
  // Create a tuple with the types from the typelist.
  @meta std::tuple<@enum_types(my_types_t)...> my_tuple;
  std::cout<< @type_string(decltype(my_tuple), true)<< "\n";

  // Use an extended slice to drop the first and last types.
  @meta std::tuple<@enum_types(my_types_t)...[1:-2]...> my_tuple2;
  std::cout<< @type_string(decltype(my_tuple2), true)<< "\n";

  // Create a class with members from the typelist.
  struct foo_t {
    @enum_types(my_types_t) @(int...)[2] ...;
  };
  std::cout<< "foo_t:\n";
  std::cout<< "  "<< @member_decl_strings(foo_t)<< "\n"...;
}