#pragma once

#include <stack>

class data{
public:
    void pop();
    int top();
    void push(int number);
private:
    std::stack<int> data_;
    friend class Interpreter;

    data() = default;
};