#include <string>

namespace common{
    std::string __attribute__((weak)) new_fn(std::string s);
    std::string old_fn(std::string s);
}

