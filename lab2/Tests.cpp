#include <gtest/gtest.h>
#include "Interpreter.h"

TEST(Add, TwoNums) {
    std::string test = "5 2 + .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "7");
}

TEST(Add, TwoEqualNums) {
    std::string test = "5 5 + .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "10");
}

TEST(Add, ManyNums) {
    std::string test = "5 2 3 4 9 0 12 324 8 7 + + + + + + + + + .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "374");
}

TEST(Subtract, TwoNums) {
    std::string test = "5 2 - .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "3");
}

TEST(Subtract, TwoEqualNums) {
    std::string test = "5 5 - .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "0");
}

TEST(Add, ManyNums) {
    std::string test = "1 1 1 1 1 1 1 1 1 1 - - - - - - - - - .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "0");
}

TEST(Multiply, TwoNums) {
    std::string test = "5 2 * .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "10");
}

TEST(Multiply, TwoEqualNums) {
    std::string test = "5 5 * .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "25");
}

TEST(Multiply, ManyNums) {
    std::string test = "5 2 1 9 42 10 * * * * * .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "37800");
}

TEST(Divide, TwoNums) {
    std::string test = "5 2 / .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "2");
}

TEST(Divide, TwoEqualNums) {
    std::string test = "5 5 / .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "1");
}

TEST(Divide, ManyNums) {
    std::string test = "1 1 1 1 1 1 / / / / / .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "1");
}

TEST(Modulo, TwoNums) {
    std::string test = "5 2 mod .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "1");
}

TEST(Modulo, TwoEqualNums) {
    std::string test = "5 5 mod .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "0");
}

TEST(Print, OneNum) {
    std::string test = "5 .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "5");
}

TEST(Print, ManyNums) {
    std::string test = "1 2 3 4 5 .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "5");
}