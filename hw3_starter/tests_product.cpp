#include "catch.hpp"
#include "proxy.hpp"
#include <vector>

using namespace proxy;

// uncomment once you think your solution to part 1 works
/*
TEST_CASE("simple product"){
    std::vector<float> a{1,2,3}, b{3,2,1};
    CHECK(
        make_vector(make_proxy(a)*make_proxy(b))
        == std::vector<float>{3,4,3});
}

TEST_CASE("trucation case"){
    std::vector<int> a{1,2,3}, b{};
    CHECK(
        make_vector(make_proxy(a)*make_proxy(b))
        == b);
}

TEST_CASE("sum and product"){
    std::vector<float> a{1,2,3}, b{4,5,6}, c{7,8,9};
    CHECK(
        make_vector(make_proxy(a)+make_proxy(b)*make_proxy(c))
        == std::vector<float>{4*7+1, 5*8+2, 6*9+3});
}
*/
