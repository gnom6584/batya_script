#include "keywords.hpp"

using namespace batya_script::resources::keywords;

bool batya_script::resources::keywords::equals(const std::string& str, Key key) noexcept(true) {
   for(size_t i = 0; i < 2; ++i)
        if(words[i][(int)key] == str)
            return true;
    return false;
}