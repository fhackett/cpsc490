#include "catch.hpp"
#include "proxy.hpp"
#include <vector>

using namespace proxy;

TEST_CASE("no-op"){
    std::vector<int> val{1,2,3,4,5};
    CHECK(make_vector(make_proxy(val)) == val);
}

TEST_CASE("simple sum"){
    std::vector<int> a{1,2,3}, b{1,1,1};
    CHECK(
        make_vector(make_proxy(a)+make_proxy(b))
        == std::vector<int>{2,3,4});
}

