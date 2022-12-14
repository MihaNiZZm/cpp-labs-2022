#pragma once

#include <stack>
#include <sstream>
#include <iostream>
#include <string>

class data{
public:
    std::stringstream msgStream_();

    void pop();
    int top();
    void push(int number);
private:
    std::stack<int> data_;

    data() = default;
};

struct context {
    stack stack;
    std::stringstream out;
};

class stack {
public:
    // CR: merge top + pop
    void pop();
    int top();
    void push(int number);

private:
    std::stack<int> stack_;
};