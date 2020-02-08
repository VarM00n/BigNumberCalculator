#include "gtest/gtest.h"
#include "../Calculator_lib/Interpreter.h"


TEST(infixToPostfix, ExampleData) {
    Interpreter a;


    EXPECT_EQ ("12 2 3 4 * 10 5 / + * +", a.infixToRPN("12+2*(3*4+10/5)"));
    EXPECT_EQ ("0 12 - 0 b - 0 c - * d / +", a.infixToRPN("(0-12)+((0-b)*(0-c))/d"));
    EXPECT_EQ ("3 4 2 * 1 5 - 2 ^ / +", a.infixToRPN("3+4*2/(1-5)^2"));
    EXPECT_EQ ("12 a b c * d e / + * +", a.infixToRPN("12 + a * (b * c + d / e)"));
    EXPECT_EQ ("66 99 ^ 5 15 * / 10 +", a.infixToRPN("66 ^ 99 / (5 * 15) + 10"));
    EXPECT_EQ ("66.0 99.15 ^ 5.3 -15.4 * / 10 +", a.infixToRPN("66.0 ^ 99.15 / (5.3 * -15.4) + 10"));


    EXPECT_EQ (Number("56"), a.evaluateExpression("12+2*(3*4+10)"));
}