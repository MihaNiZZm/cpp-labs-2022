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
    ~Multiply() {

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
    ~Add() {

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
    ~Divide() {

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
    ~Subtract() {

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
    ~Mod() {

    }
};

class Dup: public Command {
    void apply(std::stack<int>& numStack) override {
        numStack.push(numStack.top());
    }
    ~Dup() {

    }
};

class Drop: public Command {
    void apply(std::stack<int>& numStack) override {
        numStack.pop();
    }
    ~Drop() {
        
    }
};

class Write: public Command {
    void apply(std::stack<int>& numStack) override {
        std::cout << numStack.top() << std::endl;
        numStack.pop();
    }
    ~Write() {
        
    }
};

class Swap: public Command {
    void apply(std::stack<int>& numStack) override {
        int num1, num2;
        num1 = numStack.top();
        numStack.pop();
        num2 = numStack.top();
        numStack.pop();

        numStack.push(num1);
        numStack.push(num2);
    }
    ~Swap() {
        
    }
};

class Rotate: public Command {
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
    ~Rotate() {
        
    }
};

class CopySecond: public Command {
    void apply(std::stack<int>& numStack) override {
        int num1, num2;
        num1 = numStack.top();
        numStack.pop();
        num2 = numStack.top();

        numStack.push(num1);
        numStack.push(num2);
    }
    ~CopySecond() {
        
    }
};

class WriteAsAscii: public Command {
    void apply(std::stack<int>& numStack) override {
        std::cout << char(numStack.top()) << std::endl;
        numStack.pop();
    }
    ~WriteAsAscii() {
        
    }
};

class LineBreak: public Command {
    void apply(std::stack<int>& numStack) override {
        std::cout << std::endl;
    }
    ~LineBreak() {
        
    }
};

class More: public Command {
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
    ~More() {
        
    }
};

class Less: public Command {
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
    ~Less() {
        
    }
};

class Equal: public Command {
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
    ~Equal() {
        
    }
};

class WriteString: public Command {
    void apply(std::stack<int>& numStack) override {
        //TODO: body
    }
    ~WriteString() {
        
    }
};