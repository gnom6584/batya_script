//
// Created by Name on 30.07.2021.
//

#ifndef BATYA_SCRIPT_RESOURCES_KEYWORDS_KEYS_HPP_
#define BATYA_SCRIPT_RESOURCES_KEYWORDS_KEYS_HPP_

#include <array>

namespace batya_script::resources::keywords {

enum class Key {
    Nothing,
    Boolean,
    Integer_1,
    Unsigned_integer_1,
    Integer_2,
    Unsigned_integer_2,
    Integer_4,
    Unsigned_integer_4,
    Integer_8,
    Unsigned_integer_8,
    Float_4,
    Float_8,
    True,
    False,
    Var,
    Val,
    While,
    Do,
    If,
    Else,
    Is,
    Fun
};

[[nodiscard]] constexpr const char* get_key_spelling(Key key) noexcept(true);
static constexpr std::array<const char*, 22> spelling = {    "Nothing",
    "Boolean",
    "Integer_1",
    "Unsigned_integer_1",
    "Integer_2",
    "Unsigned_integer_2",
    "Integer_4",
    "Unsigned_integer_4",
    "Integer_8",
    "Unsigned_integer_8",
    "Float_4",
    "Float_8",
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
};

constexpr const char* get_key_spelling(Key key) noexcept(true) {
   return spelling[(int)key];
}

}

#endif //BATYA_SCRIPT_RESOURCES_KEYWORDS_KEYS_HPP_