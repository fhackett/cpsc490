#include "common.hpp"
#include <iostream>

int main(){
    if(common::new_fn){
        std::cout << common::new_fn("beep") << "\n";
    }else{
        std::cout << common::old_fn("boop") << "\n";
    }
    return 0;
}

