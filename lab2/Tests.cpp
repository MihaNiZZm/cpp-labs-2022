#include <gtest/gtest.h>
#include "Interpreter.h"

TEST(Exception, NumIsOutOfRange) {
    std::string test = "999999999999";
    std::string result;
    ASSERT_THROW((result = Interpreter::getInstance().interpret(test.begin(), test.end())), InterpreterError);
}

TEST(Exception, StackUnderflow) {
    std::string test = ".";
    std::string result;
    ASSERT_THROW((result = Interpreter::getInstance().interpret(test.begin(), test.end())), InterpreterError);
}

TEST(Exception, NoClosingQuote1) {
    std::string test = ".\"";
    std::string result;
    ASSERT_THROW((result = Interpreter::getInstance().interpret(test.begin(), test.end())), InterpreterError);
}

TEST(Exception, NoClosingQuote2) {
    std::string test = ".\" ";
    std::string result;
    ASSERT_THROW((result = Interpreter::getInstance().interpret(test.begin(), test.end())), InterpreterError);
}

TEST(Exception, NoClosingQuote3) {
    std::string test = ".\" sdfsf";
    std::string result;
    ASSERT_THROW((result = Interpreter::getInstance().interpret(test.begin(), test.end())), InterpreterError);
}

TEST(Exception, NoSuchCommand) {
    std::string test = "aboba";
    std::string result;
    ASSERT_THROW((result = Interpreter::getInstance().interpret(test.begin(), test.end())), InterpreterError);
}

TEST(Add, TwoNums) {
    std::string test = "5 2 + .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "7 \n");
}

TEST(Add, TwoEqualNums) {
    std::string test = "5 5 + .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "10 \n");
}

TEST(Add, ManyNums) {
    std::string test = "5 2 3 4 9 0 12 324 8 7 + + + + + + + + + .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "374 \n");
}

TEST(Subtract, TwoNums) {
    std::string test = "5 2 - .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "3 \n");
}

TEST(Subtract, TwoEqualNums) {
    std::string test = "5 5 - .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "0 \n");
}

TEST(Subtract, ManyNums) {
    std::string test = "1 1 1 1 1 1 1 1 1 1 - - - - - - - - - .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "0 \n");
}

TEST(Multiply, TwoNums) {
    std::string test = "5 2 * .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "10 \n");
}

TEST(Multiply, TwoEqualNums) {
    std::string test = "5 5 * .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "25 \n");
}

TEST(Multiply, ManyNums) {
    std::string test = "5 2 1 9 42 10 * * * * * .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "37800 \n");
}

TEST(Divide, TwoNums) {
    std::string test = "5 2 / .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "2 \n");
}

TEST(Divide, TwoEqualNums) {
    std::string test = "5 5 / .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "1 \n");
}

TEST(Divide, ManyNums) {
    std::string test = "1 1 1 1 1 1 / / / / / .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "1 \n");
}

TEST(Modulo, TwoNums) {
    std::string test = "5 2 mod .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "1 \n");
}

TEST(Modulo, TwoEqualNums) {
    std::string test = "5 5 mod .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "0 \n");
}

TEST(Print, OneNum) {
    std::string test = "5 .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "5 \n");
}

TEST(Print, ManyNums) {
    std::string test = "1 2 3 4 5 . . . . .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "5 4 3 2 1 \n");
}

TEST(PrintString, RegularString) {
    std::string test = ".\" Random words\"";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "Random words \n");
}

TEST(PrintString, ManyStrings) {
    std::string test = ".\" Random words\" .\" Random words\" .\" Random words\" .\" Random words\" .\" Random words\"";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "Random words Random words Random words Random words Random words \n");
}

TEST(Duplicate, OneTime) {
    std::string test = "1 2 dup . . .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "2 2 1 \n");
}

TEST(Duplicate, ManyTimes) {
    std::string test = "1 2 dup dup dup dup . . . . . .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "2 2 2 2 2 1 \n");
}

TEST(Drop, OneNumber) {
    std::string test = "1 3 2 drop . .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "3 1 \n");
}

TEST(Drop, ManyNumbers) {
    std::string test = "1 3 4 drop 2 5 4 3 8 9 drop drop drop drop drop . . .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "2 3 1 \n");
}

TEST(Swap, RegularSwap) {
    std::string test = "1 2 swap . .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "1 2 \n");
}

TEST(Rotate, RegularRotate) {
    std::string test = "1 2 3 rot . . .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "2 1 3 \n");
}

TEST(Over, RegularOver) {
    std::string test = "3 2 1 over . . . .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "2 1 2 3 \n");
}

TEST(Emit, OneSymbol) {
    std::string test = "65 emit";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "A \n");
}

TEST(LineBreak, RegularLineBreak) {
    std::string test = "1 2 . cr .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "2 \n1 \n");
}

TEST(Greater, GreaterFalse) {
    std::string test = "1 3 > .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "0 \n");
}

TEST(Greater, GreaterTrue) {
    std::string test = "11 3 > .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "1 \n");
}

TEST(Less, LessFalse) {
    std::string test = "5 3 < .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "0 \n");
}

TEST(Less, LessTrue) {
    std::string test = "5 32 < .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "1 \n");
}

TEST(Equal, EqualFalse) {
    std::string test = "5 3 = .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "0 \n");
}

TEST(Equal, EqualTrue) {
    std::string test = "35 35 = .";
    ASSERT_EQ(Interpreter::getInstance().interpret(test.begin(), test.end()) , "1 \n");
}