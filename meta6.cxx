#include "json.hpp"
#include <fstream>
#include <iostream>

using namespace nlohmann;

// Load types.json at compile time.
@meta std::ifstream file("types.json");
@meta json j;
@meta file>> j;

@meta for(json& types : j["types"]) {

  // Use a dynamic name to turn the JSON "name" value into an identifier.
  struct @(types["name"]) {

    // Loop over the JSON "members" array.
    @meta for(json& members : types["members"]) {
      // Emit each member.
      @type_id(members["type"]) @(members["name"]);

      // Imagine
      // @type_id("int*") @("p");
    }
  };
}

// Make a typed enum to keep a record of the types we injected.
enum typename new_types_t {
  @meta for(json& types : j["types"])
    @type_id(types["name"]);
};

int main() {
  @meta for enum(new_types_t e : new_types_t) {
    std::cout<< @enum_type_string(e)<< ":\n";
    std::cout<< "  "<< @member_decl_strings(@enum_type(e))<< ";\n" ...;
  }

  // You can use these as normal types.
  address_t my_address;
  my_address.zip = 10003;
}