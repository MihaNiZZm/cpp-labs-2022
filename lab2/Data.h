#pragma once

#include <stack>
#include <sstream>
#include <iostream>
#include <string>

class stack {
public:
    int topPop();
    void customPop();
    int customTop();
    void customPush(int number);
private:
    std::stack<int> stack_;
};

struct context {
    std::stringstream& msgStream_;
    stack& stack_;

    context(stack& stack, std::stringstream& stream): stack_(stack), msgStream_(stream) {}
};