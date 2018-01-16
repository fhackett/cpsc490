#pragma once

#include <string>
#include <stdexcept>
#include <dlfcn.h>

namespace plugin{

    class Instance{
        private:
        void* handle;
        void(*_foo)(void*,int);
        void(*_free_instance)(void*);

        protected:
        Instance(void* p, void(*foo)(void*, int), void(*_free_instance)(void*)):
            handle{p},
            _foo{foo},
            _free_instance{_free_instance}
        {}
        public:
        Instance(Instance const&) = delete;
        Instance& operator=(Instance const&) = delete;
        Instance(Instance&&) = default;
        Instance& operator=(Instance&&) = default;

        void foo(int x){
            _foo(handle, x);
        }
        ~Instance(){
            _free_instance(handle);
        }
        friend class Handle;
    };

    class Handle{
        private:
        void* handle;
        void* (*_new_instance)();
        void (*_foo)(void*, int);
        void (*_free_instance)(void*);

        protected:
        Handle(void* p):
            handle{p}
        {
            if(!p){
                throw std::runtime_error(dlerror());
            }
            _new_instance = reinterpret_cast<void*(*)()>(dlsym(p, "make_instance"));
            _foo = reinterpret_cast<void(*)(void*, int)>(dlsym(p, "foo"));
            _free_instance = reinterpret_cast<void(*)(void*)>(dlsym(p, "free_instance"));
        }
        public:
        Instance new_instance(){
            return Instance{_new_instance(), _foo, _free_instance};
        }
        Handle(Handle const&) = delete;
        Handle(Handle&&) = default;
        Handle& operator=(Handle const&) = delete;
        Handle& operator=(Handle&&) = default;
        friend Handle new_plugin(std::string);

        ~Handle(){
            dlclose(handle);
        }
    };

    Handle new_plugin(std::string s){
        return Handle{dlopen(s.c_str(), RTLD_LAZY)};
    }
}

