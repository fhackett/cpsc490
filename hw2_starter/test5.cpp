#include "talker_interface.hpp"
#include <cassert>
#include <iostream>

int main(){
    try{
        auto p1 = talker_interface::load(PLUGIN4_FILE);
        assert(false && "that shouldn't have worked");
    }catch(std::runtime_error& e){
        std::cout << e.what() << "\n";
    }
    return 0;
}

