#include "Data.h"
#include "InterpreterError.h"

void stack::customPop() {
    if (stack_.size() == 0) {
        throw InterpreterError("Stack Underflow.");
    }
    stack_.pop();
}

void stack::customPush(int number) {
    stack_.push(number);
}

int stack::customTop() {
    if (stack_.size() == 0) {
        throw InterpreterError("Stack Underflow.");
    }
    return stack_.top();
}

int stack::topPop() {
    if (stack_.size() == 0) {
        throw InterpreterError("Stack Underflow.");
    }
   int result = stack_.top();
   stack_.pop();
   return result; 
}