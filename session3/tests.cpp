#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <adder.hpp>

TEST_CASE("basic"){
    REQUIRE( adder::add(1,1) == 2 );
    REQUIRE( adder::add(0,0) == 0 );
    REQUIRE( adder::add(-1,-2) == -3);
}

