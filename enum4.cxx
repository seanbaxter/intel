#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

// A nice order-preserving unique function.
template<typename value_t>
void stable_unique(std::vector<value_t>& vec) {
  auto begin = vec.begin();
  auto end = begin;
  for(value_t& value : vec) {
    if(end == std::find(begin, end, value))
      *end++ = std::move(value);
  }
  vec.resize(end - begin);
}

enum typename typelist_t {
  int,
  double,
  char[4],
  int,
  char[4],
  void*,
  long,
  double,
  long,
};

// Create a collection of the unique types. Use an order-preserving unique
// function.
enum typename unique_list_t {
  // Convert each type in joined_list_t to an @mtype.
  @meta std::vector types { 
    @dynamic_type(@enum_types(typelist_t)) ... 
  };

  // Create a unique set of @mtypes.
  @meta stable_unique(types);

  // Convert all the unique types into enumerator declarations.
  @pack_type(types)...;
};

int main() {
  std::cout<< "unique_list_t:\n";
  std::cout<< int...<< ": "<< @enum_type_strings(unique_list_t)<< "\n"...;
}