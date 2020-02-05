#include "gtest/gtest.h"
#include "../Calculator_lib/Interpreter.h"


TEST(infixToPostfix, ExampleData) {
    Interpreter a;

    EXPECT_EQ ("0", a.infixToPostfix("2+3*(6-8)"));
}