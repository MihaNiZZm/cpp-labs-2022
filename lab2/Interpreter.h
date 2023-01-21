#pragma once

#include <unordered_map>
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
    stack numStack_;

    Interpreter() = default;
    Interpreter(const Interpreter& other) = delete;
    Interpreter& operator=(const Interpreter& other) = delete;

    void interpretEachWord(const std::string::iterator& begin, const std::string::iterator& end, context& context);
    std::string::iterator& applyWriteString(std::string::iterator& begin, const std::string::iterator& end, context& context);
    void applyCommand(std::string& word, context& context);
    void putNumberOnStack(std::string& word);

    bool isNumber(std::string& word);
    bool isWriteString(const std::string& word);
};