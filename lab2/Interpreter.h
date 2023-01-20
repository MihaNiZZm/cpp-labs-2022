#pragma once

#include <stack>
#include <unordered_map>
#include <string>
#include <functional>
#include <list>
#include <cctype>
#include <algorithm>
#include <memory>
#include <utility>

#include "Commands.h"
#include "InterpreterError.h"
#include "Data.h"

class Interpreter {
public:

    static Interpreter& getInstance() {
        static Interpreter i;
        return i;
    }

    bool addCommandToMap(std::string string, std::unique_ptr<Command> command);
    std::string interpret(const std::string::iterator& begin, const std::string::iterator& end);

private:
    std::unordered_map<std::string, std::unique_ptr<Command>> commands_;
    context data_;

    Interpreter() = default;
    Interpreter(const Interpreter& other) = delete;
    Interpreter& operator=(const Interpreter& other) = delete;

    void getWords(std::list<std::string>& str, const std::string::iterator& begin, const std::string::iterator& end);
    bool isNumber(std::string word);
    bool isWriteString(const std::string::iterator& firstSymbol);
};