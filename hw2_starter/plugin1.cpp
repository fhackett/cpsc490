#include "talker.hpp"
#include <sstream>
#include <iostream>

extern "C"{

char const* get_name(handle_t){
    return "plugin1";
}

handle_t talker_make(){
    return nullptr;
}

char const * say_to(handle_t self, talker_t* other_fns, handle_t other, char const* msg){
    char const* name = other_fns->get_name(other);
    static std::string result;
    std::ostringstream out;
    out << get_name(self) << " says " << msg << " to " << name;
    result = out.str();
    return result.c_str();
}

void talker_free(handle_t self){
    // pass
}

talker_t* talker_get_functions(){
    static talker_t plugin_functions = {
        get_name,
        talker_make,
        say_to,
        talker_free
    };
    return &plugin_functions;
}

}

