#pragma once

#include <iostream>
#include <stack>

#include "Data.h"
#include "InterpreterError.h"

class Command {
public:
    virtual void apply(context& data) = 0;
    virtual ~Command() {}
};

class Multiply: public Command {
public:
    void apply(context& data) override {
        int res = data.stack_.topPop();
        res *= data.stack_.topPop();
        data.stack_.push(res);
    }
    ~Multiply() = default;
};

class Add: public Command {
public:
    void apply(context& data) override {
        int res = data.stack_.topPop();
        res += data.stack_.topPop();
        data.stack_.push(res);
    }
    ~Add() = default;
};

class Divide: public Command {
public:
    void apply(context& data) override {
        int divider = data.stack_.topPop();
        int divident = data.stack_.topPop();
        if (divider == 0) {
            throw InterpreterError("Can't divide by zero.");
        }
        data.stack_.push(divident / divider);
    }
    ~Divide() = default;
};

class Subtract: public Command {
public:
    void apply(context& data) override {
        int deductible = data.stack_.topPop();
        int reduced = data.stack_.topPop();
        data.stack_.push(reduced - deductible);
    }
    ~Subtract() = default;
};

class Mod: public Command {
public:
    void apply(context& data) override {
        int divider = data.stack_.topPop();
        int divident = data.stack_.topPop();
        if (divider == 0) {
            throw InterpreterError("Can't divide by zero.");
        }
        data.stack_.push(divident % divider);
    }
    ~Mod() = default;
};

class Dup: public Command {
public:
    void apply(context& data) override {
        data.stack_.push(data.stack_.top());
    }
    ~Dup() = default;
};

class Drop: public Command {
public:
    void apply(context& data) override {
        if (!data.stack_.top()) {

        }
        data.stack_.pop();
    }
    ~Drop() = default;
};

class Write: public Command {
public:
    void apply(context& data) override {
        data.msgStream_ << data.stack_.topPop() << std::endl;
    }
    ~Write() = default;
};

class Swap: public Command {
public:
    void apply(context& data) override {
        int num1, num2;
        num1 = data.stack_.topPop();
        num2 = data.stack_.topPop();

        data.stack_.push(num1);
        data.stack_.push(num2);
    }
    ~Swap() = default;
};

class Rotate: public Command {
public:
    void apply(context& data) override {
        int num1, num2, num3;
        num1 = data.stack_.topPop();
        num2 = data.stack_.topPop();
        num3 = data.stack_.topPop();

        data.stack_.push(num1);
        data.stack_.push(num3);
        data.stack_.push(num2);
    }
    ~Rotate() = default;
};

class CopySecond: public Command {
public:
    void apply(context& data) override {
        int num1, num2;
        num1 = data.stack_.topPop();
        num2 = data.stack_.top();

        data.stack_.push(num1);
        data.stack_.push(num2);
    }
    ~CopySecond() = default;
};

class WriteAsAscii: public Command {
public:
    void apply(context& data) override {
        data.msgStream_ << char(data.stack_.topPop()) << std::endl;
    }
    ~WriteAsAscii() = default;
};

class LineBreak: public Command {
public:
    void apply(context& data) override {
        data.msgStream_ << std::endl;
    }
    ~LineBreak() = default;
};

class Greater: public Command {
public:
    void apply(context& data) override {
        int left, right;
        right = data.stack_.topPop();
        left = data.stack_.top();

        data.stack_.push(right);
        if (left > right) {
            data.stack_.push(1);
        }
        else {
            data.stack_.push(0);
        }
    }
    ~Greater() = default;
};

class Less: public Command {
public:
    void apply(context& data) override {
        int left, right;
        right = data.stack_.topPop();
        left = data.stack_.top();

        data.stack_.push(right);
        if (left < right) {
            data.stack_.push(1);
        }
        else {
            data.stack_.push(0);
        }
    }
    ~Less() = default;
};

class Equal: public Command {
public:
    void apply(context& data) override {
        int left, right;
        right = data.stack_.topPop();
        left = data.stack_.top();

        data.stack_.push(right);
        if (left == right) {
            data.stack_.push(1);
        }
        else {
            data.stack_.push(0);
        }
    }
    ~Equal() = default;
};
