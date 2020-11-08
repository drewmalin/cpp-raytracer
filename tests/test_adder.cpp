#include <catch2/catch.hpp>

#include "adder/adder.hpp"

TEST_CASE("adder adds", "[adder]") {
  auto a = 1;
  auto b = 2;

  REQUIRE(add(a, b) == 3);
}