#include "talker_interface.hpp"
#include <cassert>
#include <iostream>

int main(){
    auto p3 = talker_interface::load(PLUGIN3_FILE);
    auto p2 = talker_interface::load(PLUGIN2_FILE);
    auto i3 = p3.make();
    auto i2 = p2.make();
    auto result = i3.say_to(i2, "Hello");
    std::cout << result << "\n";
    assert(result == "plugin3 says Hello to plugin2");
    return 0;
}

