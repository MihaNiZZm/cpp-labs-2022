#pragma once

#include <iostream>
#include <stack>

class Command {
  public:
    virtual void apply(std::stack<int>& numStack) = 0;
    virtual ~Command() = 0;
};

class Multiply: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
        int res = numStack.top();
        numStack.pop();
        res *= numStack.top();
        numStack.pop();
        numStack.push(res);
    }
    ~Multiply() override {

    }
};

class Add: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
        int res = numStack.top();
        numStack.pop();
        res += numStack.top();
        numStack.pop();
        numStack.push(res);
    }
    ~Add() override {

    }
};

class Divide: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
        int divider = numStack.top();
        numStack.pop();
        int divident = numStack.top();
        numStack.pop();
        numStack.push(divident / divider);
    }
    ~Divide() override {

    }
};

class Subtract: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
        int deductible = numStack.top();
        numStack.pop();
        int reduced = numStack.top();
        numStack.pop();
        numStack.push(reduced - deductible);
    }
    ~Subtract() override {

    }
};

class Mod: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
        int divider = numStack.top();
        numStack.pop();
        int divident = numStack.top();
        numStack.pop();
        numStack.push(divident % divider);
    }
    ~Mod() override {

    }
};

class Dup: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
        numStack.push(numStack.top());
    }
    ~Dup() override {

    }
};

class Drop: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
        numStack.pop();
    }
    ~Drop() override {
        
    }
};

class Write: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
        std::cout << numStack.top() << std::endl;
        numStack.pop();
    }
    ~Write() override {
        
    }
};

class Swap: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
        int num1, num2;
        num1 = numStack.top();
        numStack.pop();
        num2 = numStack.top();
        numStack.pop();

        numStack.push(num1);
        numStack.push(num2);
    }
    ~Swap() override {
        
    }
};

class Rotate: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
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
    ~Rotate() override {
        
    }
};

class CopySecond: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
        int num1, num2;
        num1 = numStack.top();
        numStack.pop();
        num2 = numStack.top();

        numStack.push(num1);
        numStack.push(num2);
    }
    ~CopySecond() override {
        
    }
};

class WriteAsAscii: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
        std::cout << char(numStack.top()) << std::endl;
        numStack.pop();
    }
    ~WriteAsAscii() override {
        
    }
};

class LineBreak: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
        std::cout << std::endl;
    }
    ~LineBreak() override {
        
    }
};

class More: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
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
    ~More() override {
        
    }
};

class Less: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
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
    ~Less() override {
        
    }
};

class Equal: public Command {
  public:
    void apply(std::stack<int>& numStack) override {
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
    ~Equal() override {
        
    }
};

class WriteString: public Command {
  public:
    WriteString(const std::string string) : stringToWrite_(string) {}

    void apply(std::stack<int>& numStack) override {
        //TODO: body
    }
    ~WriteString() override {
        
    }
  private:
    std::string stringToWrite_;
};