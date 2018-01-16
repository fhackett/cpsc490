#include <iostream>

extern "C"{

void* make_instance(){ return nullptr; }
void free_instance(void*){}

void foo(void*, int x){
    std::cout << "plugin2 " << x << "\n";
}

}

