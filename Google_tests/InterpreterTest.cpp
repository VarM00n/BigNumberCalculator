#include "gtest/gtest.h"
#include "../Calculator_lib/Interpreter.h"


TEST(infixToPostfix, ExampleData) {
    Interpreter a;

    EXPECT_EQ ("0 12 - 0 b - 0 c - * d / +", a.infixToPostfix("(0-12)+((0-b)*(0-c))/d"));
    EXPECT_EQ ("12 2 3 4 * 10 5 / + * +", a.infixToPostfix("12+2*(3*4+10/5)"));
    EXPECT_EQ ("3 4 2 * 1 5 - 2 ^ / +", a.infixToPostfix("3+4*2/(1-5)^2"));
    EXPECT_EQ ("12 a b c * d e / + * +", a.infixToPostfix("12 + a * (b * c + d / e)"));
    EXPECT_EQ ("66 99 ^ 5 15 * / 10 +", a.infixToPostfix("66 ^ 99 / (5 * 15) + 10"));
}