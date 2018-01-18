#include "common.hpp"
#include <iostream>

int main(){
    // check if new_fn is present. If we link against a .so file
    // that doesn't contain that function, the linker will set
    // the address of new_fn to nullptr.
    if(common::new_fn){
        std::cout << common::new_fn("beep") << "\n";
    }else{
        std::cout << common::old_fn("boop") << "\n";
    }
    return 0;
}

