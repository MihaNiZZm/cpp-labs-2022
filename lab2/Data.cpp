#include "Data.h"

void stack::pop() {
    stack_.pop();
}

void stack::push(int number) {
    stack_.push(number);
}

int stack::top() {
    return stack_.top();
}

int stack::topPop() {
   int result = stack_.top();
   stack_.pop();
   return result; 
}