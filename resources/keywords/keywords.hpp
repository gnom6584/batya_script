//
// Created by batya on 24.07.2021.
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

constexpr std::array<std::array<const char*, 7>, 2> words = {
std::array<const char*, 7> {
    "var",
    "val",
    "while",
    "do",
    "if",
    "else",
    "is"
},
std::array<const char*, 7> {
    "пер",
    "пос",
    "пока",
    "делать",
    "если",
    "иначе",
    "есть"
}
};

[[nodiscard]] bool equals(const std::string& str, Key key) noexcept(true);

}


#endif //BATYA_SCRIPT_RESOURCES_KEYWORDS_KEYWORDS_HPP_