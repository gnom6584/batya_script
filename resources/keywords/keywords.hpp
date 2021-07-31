//
// Created by Name on 30.07.2021.
//

#ifndef BATYA_SCRIPT_RESOURCES_KEYWORDS_KEYWORDS_HPP_
#define BATYA_SCRIPT_RESOURCES_KEYWORDS_KEYWORDS_HPP_

#include <array>

#include "keys.hpp"
namespace batya_script::resources::keywords {

enum class Locale {
    Eng,
    Ru
};

constexpr std::array<std::array<const char*, 22>, 2> words = {
std::array<const char*, 22> {
    "Nothing",
    "Bool",
    "I1",
    "U1",
    "I2",
    "U2",
    "I4",
    "U4",
    "I8",
    "U8",
    "F4",
    "F8",
    "true",
    "false",
    "var",
    "val",
    "while",
    "do",
    "if",
    "else",
    "is",
    "fun"
},
std::array<const char*, 22> {
    "Nothing",
    "Bool",
    "I1",
    "U1",
    "I2",
    "U2",
    "I4",
    "U4",
    "I8",
    "U8",
    "F4",
    "F8",
    "true",
    "false",
    "var",
    "val",
    "for",
    "do",
    "if",
    "else",
    "is",
    "fun"
}
};

[[nodiscard]] bool equals(const std::string& str, Key key) noexcept(true);

}


#endif //BATYA_SCRIPT_RESOURCES_KEYWORDS_KEYWORDS_HPP_