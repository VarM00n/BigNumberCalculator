#include "gtest/gtest.h"
#include "../Calculator_lib/Number.h"


TEST(Greater, ExampleData1) {
    Number a("-15");
    Number b("15");
    EXPECT_EQ (true, a < b);
    EXPECT_EQ (false, a > b);
    EXPECT_EQ (false, a == b);
    EXPECT_EQ (true, a != b);
}

TEST(Greater, ExampleData2) {
    Number a("-0");
    Number b("0");
    EXPECT_EQ (false, a < b);
    EXPECT_EQ (false, a > b);
    EXPECT_EQ (true, a == b);
    EXPECT_EQ (false, a != b);
}

TEST(Greater, ExampleData3) {
    Number a("-0");
    Number b("-0");
    EXPECT_EQ (false, a < b);
    EXPECT_EQ (false, a > b);
    EXPECT_EQ (true, a == b);
    EXPECT_EQ (false, a != b);
}

TEST(Greater, ExampleData4) {
    Number a("0");
    Number b("-0");
    EXPECT_EQ (false, a < b);
    EXPECT_EQ (false, a > b);
    EXPECT_EQ (true, a == b);
    EXPECT_EQ (false, a != b);
}

TEST(Greater, ExampleData5) {
    Number a("512659821736519238765123985712651827956123985762354834653487652345");
    Number b("-34592437659238457623489576234895346");
    EXPECT_EQ (false, a < b);
    EXPECT_EQ (true, a > b);
    EXPECT_EQ (false, a == b);
    EXPECT_EQ (true, a != b);
}

TEST(Greater, ExampleData6) {
    Number a("-512659821736519238765123985712651827956123985762354834653487652345");
    Number b("-512659821736519238765123985712651827956123985762354834653487652345");
    EXPECT_EQ (false, a < b);
    EXPECT_EQ (false, a > b);
    EXPECT_EQ (true, a == b);
    EXPECT_EQ (false, a != b);
}

TEST(removeLeadingZeros, WhenNumberIsZero) {
    Number a("0");
    EXPECT_EQ ("0", a.getValue());
}