#include "talker_interface.hpp"
#include <cassert>

int main(){
    auto p1 = talker_interface::load(PLUGIN1_FILE);
    auto p2 = talker_interface::load(PLUGIN2_FILE);
    auto i1 = p1.make();
    auto i2 = p2.make();
    return 0;
}

