//
// Created by Name on 03.08.2021.
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

constexpr std::array<std::array<const char*, 25>, 2> words = {
std::array<const char*, 25> {
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
    "Ptr",
    "USize",
    "true",
    "false",
    "var",
    "val",
    "while",
    "do",
    "if",
    "else",
    "is",
    "fun",
    "struct"
},
std::array<const char*, 25> {
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
    "Ptr",
    "USize",
    "true",
    "false",
    "var",
    "val",
    "for",
    "do",
    "if",
    "else",
    "is",
    "fun",
    "struct"
}
};

[[nodiscard]] bool equals(const std::string& str, Key key) noexcept(true);

}


#endif //BATYA_SCRIPT_RESOURCES_KEYWORDS_KEYWORDS_HPP_