#include <iostream>

template<typename... types>
struct tuple {
  @meta for(int i : sizeof...(types))
    types...[i] @(i);
};

template<typename... types>
struct tuple2 {
  // An abbreviated form of above. 
  types @("element_", int...) ...;
};

int main() {
  typedef tuple<long, float, const char*> my_tuple;
  my_tuple obj { 10001, 3.14f, "Hello tuple" };

  std::cout<< "tuple:\n";
  std::cout<< "  "<< @member_decl_strings(my_tuple)<< ": "
    << obj.@member_values()<< "\n" ...;

  typedef tuple2<char, int, double> my_tuple2;
  my_tuple2 obj2 { 'A', 200, 1.618 };

  std::cout<< "tuple2:\n";
  std::cout<< "  "<< @member_decl_strings(my_tuple2)<< ": "
    << obj2.@member_values()<< "\n" ...;
}