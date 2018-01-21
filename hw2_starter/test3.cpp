#include "talker_interface.hpp"
#include <cassert>
#include <iostream>

int main(){
    auto p1 = talker_interface::load(PLUGIN1_FILE);
    auto p2 = talker_interface::load(PLUGIN2_FILE);
    auto i1 = p1.make();
    auto i2 = p2.make();
    auto result = i1.say_to(i2, "Hello");
    std::cout << result << "\n";
    assert(result == "plugin1 says Hello to plugin2");
    return 0;
}

