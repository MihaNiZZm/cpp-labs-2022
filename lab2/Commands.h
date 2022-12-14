#pragma once

#include <iostream>
#include <stack>

#include "Data.h"
#include "InterpreterError.h"

class Command {
public:
    virtual void apply(data& numStack) = 0;
    // CR: possible will break when smart pointers added
    virtual ~Command() = 0;
};

//class BinOp: public Command {
//
//    void apply(data &numStack) override {
//      // CODE
//    }
//
//    // virtual ???
//
//};

class Multiply: public Command {
public:
    void apply(data& numStack) override {
        int res = numStack.top();
        numStack.pop();
        res *= numStack.top();
        numStack.pop();
        numStack.push(res);
    }
};

class Add: public Command {
public:
    void apply(data& numStack) override {
        int res = numStack.top();
        numStack.pop();
        res += numStack.top();
        numStack.pop();
        numStack.push(res);
    }
};

class Divide: public Command {
public:
    void apply(data& numStack) override {
        int divider = numStack.top();
        numStack.pop();
        int divident = numStack.top();
        numStack.pop();
        numStack.push(divident / divider);
    }
};

class Subtract: public Command {
public:
    void apply(data& numStack) override {
        int deductible = numStack.top();
        numStack.pop();
        int reduced = numStack.top();
        numStack.pop();
        numStack.push(reduced - deductible);
    }
};

class Mod: public Command {
public:
    void apply(data& numStack) override {
        int divider = numStack.top();
        numStack.pop();
        int divident = numStack.top();
        numStack.pop();
        numStack.push(divident % divider);
    }
};

class Dup: public Command {
public:
    void apply(data& numStack) override {
        numStack.push(numStack.top());
    }
};

class Drop: public Command {
public:
    void apply(data& numStack) override {
        numStack.pop();
    }
};

class Write: public Command {
public:
    void apply(data& numStack) override {
        std::cout << numStack.top() << std::endl;
        numStack.pop();
    }
};

class Swap: public Command {
public:
    void apply(data& numStack) override {
        int num1, num2;
        num1 = numStack.top();
        numStack.pop();
        num2 = numStack.top();
        numStack.pop();

        numStack.push(num1);
        numStack.push(num2);
    }
};

class Rotate: public Command {
public:
    void apply(data& numStack) override {
        int num1, num2, num3;
        num1 = numStack.top();
        numStack.pop();
        num2 = numStack.top();
        numStack.pop();
        num3 = numStack.top();
        numStack.pop();

        numStack.push(num1);
        numStack.push(num3);
        numStack.push(num2);
    }
};

class CopySecond: public Command {
public:
    void apply(data& numStack) override {
        int num1, num2;
        num1 = numStack.top();
        numStack.pop();
        num2 = numStack.top();

        numStack.push(num1);
        numStack.push(num2);
    }
};

class WriteAsAscii: public Command {
public:
    void apply(data& numStack) override {
        std::cout << char(numStack.top()) << std::endl;
        numStack.pop();
    }
};

class LineBreak: public Command {
public:
    void apply(data& numStack) override {
        std::cout << std::endl;
    }
};

class More: public Command {
public:
    void apply(data& numStack) override {
        int left, right;
        right = numStack.top();
        numStack.pop();
        left = numStack.top();

        numStack.push(right);
        if (left > right) {
            numStack.push(1);
        }
        else {
            numStack.push(0);
        }
    }
};

class Less: public Command {
public:
    void apply(data& numStack) override {
        int left, right;
        right = numStack.top();
        numStack.pop();
        left = numStack.top();

        numStack.push(right);
        if (left < right) {
            numStack.push(1);
        }
        else {
            numStack.push(0);
        }
    }
};

class Equal: public Command {
public:
    void apply(data& numStack) override {
        int left, right;
        right = numStack.top();
        numStack.pop();
        left = numStack.top();

        numStack.push(right);
        if (left == right) {
            numStack.push(1);
        }
        else {
            numStack.push(0);
        }
    }
};
