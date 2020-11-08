#include <catch2/catch.hpp>

TEST_CASE("vectors can be resized", "[vector-tests]") {
  std::vector<int> v(5);
  REQUIRE(v.size() == 5);

  SECTION("resizing changes capacity") {
    v.resize(10);
    REQUIRE(v.size() == 10);
  }
}