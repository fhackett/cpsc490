#include "plugin_api.hpp"

int main(){
    auto p1 = plugin::new_plugin("./libplugin1.so");
    auto p1i = p1.new_instance();
    auto p2 = plugin::new_plugin("./libplugin2.so");
    auto p2i = p2.new_instance();

    p1i.foo(22);
    p2i.foo(33);

    return 0;
}

