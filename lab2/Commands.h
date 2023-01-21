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

class BinaryOperation: public Command {
    void apply(context& data) override {
        int number2 = data.stack_.topPop();
        int number1 = data.stack_.topPop();
        int result = operation(number1, number2);
        data.stack_.customPush(result);
    }

    virtual int operation(int num1, int num2) = 0;
};

class Multiply: public BinaryOperation {
public:
    int operation(int num1, int num2) override {
        return num1 * num2;
    }
};

class Add: public BinaryOperation {
public:
    int operation(int num1, int num2) override {
        return num1 + num2;
    }
};

class Divide: public BinaryOperation {
public:
    int operation(int num1, int num2) override {
        return num1 / num2;
    }
};

class Subtract: public BinaryOperation {
public:
    int operation(int num1, int num2) override {
        return num1 - num2;
    }
};

class Mod: public BinaryOperation {
public:
    int operation(int num1, int num2) override {
        return num1 % num2;
    }
};

class Dup: public Command {
public:
    void apply(context& data) override {
        data.stack_.customPush(data.stack_.customTop());
    }
};

class Drop: public Command {
public:
    void apply(context& data) override {
        data.stack_.customPop();
    }
};

class Write: public Command {
public:
    void apply(context& data) override {
        data.msgStream_ << data.stack_.topPop() << " ";
    }
};

class Swap: public Command {
public:
    void apply(context& data) override {
        int num1, num2;
        num1 = data.stack_.topPop();
        num2 = data.stack_.topPop();

        data.stack_.customPush(num1);
        data.stack_.customPush(num2);
    }
};

class Rotate: public Command {
public:
    void apply(context& data) override {
        int num1, num2, num3;
        num1 = data.stack_.topPop();
        num2 = data.stack_.topPop();
        num3 = data.stack_.topPop();

        data.stack_.customPush(num1);
        data.stack_.customPush(num3);
        data.stack_.customPush(num2);
    }
};

class CopySecond: public Command {
public:
    void apply(context& data) override {
        int num1, num2;
        num1 = data.stack_.topPop();
        num2 = data.stack_.customTop();

        data.stack_.customPush(num1);
        data.stack_.customPush(num2);
    }
};

class WriteAsAscii: public Command {
public:
    void apply(context& data) override {
        data.msgStream_ << char(data.stack_.topPop()) << " ";
    }
};

class LineBreak: public Command {
public:
    void apply(context& data) override {
        data.msgStream_ << std::endl;
    }
};

class Greater: public BinaryOperation {
public:
    int operation(int num1, int num2) override {
        return num1 > num2 ? 1 : 0;
    }
};

class Less: public BinaryOperation {
public:
    int operation(int num1, int num2) override {
        return num1 < num2 ? 1 : 0;
    }
};

class Equal: public BinaryOperation {
public:
    int operation(int num1, int num2) override {
        return num1 == num2 ? 1 : 0;
    }
};
