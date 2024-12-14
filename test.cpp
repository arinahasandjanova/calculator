#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calc.h"
#include <stdexcept>
#include <cmath>
#include <string>

TEST_CASE("Test isValidExpression") {
    CHECK(isValidExpression("2+3"));
    CHECK(isValidExpression("1.5*2"));
    CHECK_FALSE(isValidExpression("2+3#"));
    CHECK_FALSE(isValidExpression("hello, world!"));
}

TEST_CASE("Test isValidOp") {
    CHECK(isValidOp('+'));
    CHECK(isValidOp('-'));
    CHECK(isValidOp('*'));
    CHECK(isValidOp('/'));
    CHECK(isValidOp('^'));
    CHECK_FALSE(isValidOp('%'));
    CHECK_FALSE(isValidOp('a'));
}

TEST_CASE("Test applyOperation") {
    CHECK(applyOperation(3, 2, '+') == 5);
    CHECK(applyOperation(3, 2, '-') == 1);
    CHECK(applyOperation(3, 2, '*') == 6);
    CHECK(applyOperation(3, 2, '/') == 1.5);
    CHECK_THROWS_AS(applyOperation(3, 0, '/'), std::runtime_error);
    CHECK(applyOperation(2, 3, '^') == 8);
    CHECK_THROWS_AS(applyOperation(3, 2, '%'), std::invalid_argument);
}

TEST_CASE("Test evaluateExpression") {
    CHECK(evaluateExpression("3+2^2") == 7);
    CHECK(evaluateExpression("3--2^2") == -1);
    CHECK(evaluateExpression("10-5*2") == 0);
    CHECK(evaluateExpression("2^3+4") == 12);
    CHECK(evaluateExpression("3/0.5") == 6);
    CHECK_THROWS_AS(evaluateExpression("3+2*"), std::invalid_argument);
    CHECK_THROWS_AS(evaluateExpression("3//2"), std::invalid_argument);
    CHECK_THROWS_AS(evaluateExpression("2^"), std::invalid_argument);
    CHECK_THROWS_AS(evaluateExpression("3+2/0"), std::runtime_error);
}

TEST_CASE("Test invalid expressions") {
    CHECK_THROWS_AS(evaluateExpression("3+2++4"), std::invalid_argument);
    CHECK_THROWS_AS(evaluateExpression("3---2"), std::invalid_argument);
    CHECK_THROWS_AS(evaluateExpression("3+2#4"), std::invalid_argument);
    CHECK_THROWS_AS(evaluateExpression("3.5.6+2"), std::invalid_argument);
}