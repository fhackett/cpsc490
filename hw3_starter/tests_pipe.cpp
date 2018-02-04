#include "catch.hpp"
#include "proxy.hpp"
#include <vector>

using namespace proxy;

// uncomment when you think your solution to part 2 works
/*

TEST_CASE("empty proxy case"){
    std::vector<int> a{1,2,3}, b{};
    CHECK(
        make_vector(make_proxy(a)|make_proxy(b))
        == a);
}

TEST_CASE("simple case"){
    std::vector<int> a{1,2,3}, b{4, 5, 6};
    CHECK(
        make_vector(make_proxy(a)|make_proxy(b))
        == std::vector<int>{1,2,3,4,5,6});
}

TEST_CASE("composite case"){
    std::vector<int> a{1,2,3}, b{4,5,6}, c{1,1,1,2,2,2};
    CHECK(
        make_vector((make_proxy(a)|make_proxy(b))+make_proxy(c))
        == std::vector<int>{2,3,4,6,7,8});
}

*/

