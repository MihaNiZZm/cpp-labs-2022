#pragma once

#include <stack>
#include <sstream>
#include <iostream>
#include <string>

class stack {
public:
    int topPop();
    void pop();
    int top();
    void push(int number);
private:
    std::stack<int> stack_;
};

struct context {
    std::stringstream msgStream_;
    stack stack_;
};