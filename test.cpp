#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "balance.h"

TEST_CASE("Balanced brackets", "[balance]") {
    REQUIRE(Balance(""));
    REQUIRE(Balance("()"));
    REQUIRE(Balance("[]"));
    REQUIRE(Balance("{}"));
    REQUIRE(Balance("([]{})"));
    REQUIRE(Balance("{[()]}"));
}

TEST_CASE("Unbalanced brackets", "[balance]") {
    REQUIRE_FALSE(Balance("("));
    REQUIRE_FALSE(Balance("((("));
    REQUIRE_FALSE(Balance(")"));
    REQUIRE_FALSE(Balance("())"));
    REQUIRE_FALSE(Balance("([)]"));
    REQUIRE_FALSE(Balance("{[}"));
}

TEST_CASE("Text containing brackets", "[balance]") {
    REQUIRE(Balance("abc"));
    REQUIRE(Balance("a + (b * c)"));
    REQUIRE(Balance("func([1, 2, {3}])"));

    REQUIRE_FALSE(Balance("func([1, 2})"));
}

TEST_CASE("Long input", "[balance]") {
    std::string input;

    for (int i = 0; i < 10000; ++i) {
        input += '(';
    }

    for (int i = 0; i < 10000; ++i) {
        input += ')';
    }

    REQUIRE(Balance(input));

    input += ')';
    REQUIRE_FALSE(Balance(input));
}