#include <iostream>

#include "adder/adder.hpp"
#include "multiplier/multiplier.hpp"

int main() {
  std::cout << "Hello, C++!" << std::endl;

  auto adder_result = add(1, 2);
  std::cout << adder_result << std::endl;

  auto muliplier_result = multiply(3, 4);
  std::cout << muliplier_result << std::endl;

  return 0;
}
