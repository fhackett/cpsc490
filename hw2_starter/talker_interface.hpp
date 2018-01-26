#pragma once

#include <stdexcept>
#include <memory>
#include <string>
#include <dlfcn.h>
#include "talker.hpp"

namespace talker_interface{

    class Instance{
    private:
        std::shared_ptr<void> handle;
        talker_t* functions;

        Instance(void* handle, talker_t* functions):
            handle(handle, [=](handle_t p){
                // handle deletion here
                // (you can refer to _free_instance, it'll work)
            }),
            functions{functions}
        {
            // set things up here
        }

    public:
        friend class Handle;

        std::string say_to(Instance const& other, std::string msg){
            // TODO: implement
            return "";
        }
    };

    class Handle{
    private:
        std::shared_ptr<void> handle;
        talker_t* functions;

        Handle(void* _handle):
            handle(_handle, [](void* p){
                // code to free the handle here
            })
        {
            // initialise stuff here?
            functions = nullptr;
        }
    public:
        // circumvent the privateness of the constructor for this one
        // function's sake
        friend Handle load(std::string);

        Instance make(){
            // TODO: implement
            return Instance(nullptr, nullptr);
        }
    };

    Handle load(std::string s){
        // code to open the shared object file here
        return Handle(nullptr);
    }
}

