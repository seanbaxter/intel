#include <type_traits>
#include <algorithm>
#include <iostream>

enum typename typelist_t {
  int,
  double,
  char[4],
  double(double),
  float,
  float,
  void*,
};

// Check if a type is in the list.
template<typename type_t, typename list_t>
constexpr bool is_type_in_list_v =  
  (... || std::is_same_v<type_t, @enum_types(list_t)>);

// Use + to get a count of the occurrences for a type in the list.
template<typename type_t, typename list_t>
constexpr size_t occurence_in_list_v =
  (... + (size_t)std::is_same_v<type_t, @enum_types(list_t)>);

int main() {
  std::cout<< "char* is in list = "<< is_type_in_list_v<char*, typelist_t><< "\n";
  std::cout<< "double is in list = "<< is_type_in_list_v<double, typelist_t><< "\n";

  std::cout<< "float count = "<< occurence_in_list_v<float, typelist_t><< "\n";
  std::cout<< "void* count = "<< occurence_in_list_v<void*, typelist_t><< "\n";
}