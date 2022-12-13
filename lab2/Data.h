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
    friend class Interpreter;

    data() = default;
};