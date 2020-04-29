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
}

TEST(evaluateExpression, ExampleData1) {
    Interpreter a;
    EXPECT_EQ (Number("56"), a.evaluateExpression("12+2*(3*4+10)"));
    EXPECT_EQ (Number("67"), a.evaluateExpression("12+2*(3*4+10)+11"));
    EXPECT_EQ (Number("45"), a.evaluateExpression("12+2*(3*4+10)-11"));


    EXPECT_EQ (Number("-133537708786018680"), a.evaluateExpression("(2345*4312-1234-645)*34*(234*(234-16*234)*473)"));

    // EXPECT_EQ (Number("392523869470591"), a.evaluateExpression("((0-(1234*6421+1234-(1654*867234-678234)*(234+4*234)-43)*234)+1)"));

    // EXPECT_EQ (Number("-5572470664154"), a.evaluateExpression("-1234-1234-1234-4378*2234+712*-123*(10000*6363)"));
}