#include <catch2/catch.hpp>

#include "multiplier/multiplier.hpp"

TEST_CASE("multiplier multiplies", "[multiplier]") {
    auto a = 1;
    auto b = 2;
    
    REQUIRE(multiply(a, b) == 2);
}