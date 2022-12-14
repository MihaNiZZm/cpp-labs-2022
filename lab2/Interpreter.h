#pragma once

#include <stack>
#include <unordered_map>
#include <string>
#include <functional>
#include <list>
#include <cctype>
#include <algorithm>

#include "Commands.h"
#include "InterpreterError.h"
#include "Parser.h"
#include "Data.h"

class Interpreter {
public:
    typedef std::function<Command* (std::string::iterator&, const std::string::iterator&)> creatorType;

    static Interpreter& getInstance() {
        static Interpreter i;
        return i;
    }

    bool registerCreator(std::string name, const creatorType& creator) {
        creators_[name] = creator;
        return true;
    }

    std::list<Command*> getCommands(const std::string::iterator& begin, const std::string::iterator& end) {
        std::list<std::string> strCommands;
        std::list<Command*> commands;
        std::string newCommand = "";
        std::string::iterator it = begin;
      
        getWords(strCommands, begin, end);

        for (std::string cmd : strCommands) {
            if (isNumber(cmd)) {
              // CR: 1 . 2
                try {
                    data_.push(stoi(cmd));
                } catch(std::out_of_range const& errorMessage) {
                    data_.msgStream_() << errorMessage.what() << std::endl;
                }
            }
            auto creatorIt = creators_.find(cmd);
            if (creatorIt == creators_.end()) {
                // TODO: throw error "unknown command".
            }
            creatorType creator = (*creatorIt).second;
            Command* newCmd = creator(it, end);
            // CR: apply command right away
            commands.push_back(newCmd);
        }
        return commands;
    }

    std::string interpret(const std::string::iterator& begin, const std::string::iterator& end) {
        std::string::iterator it = begin;
        try {
            std::list<Command*> cmds = getCommands(it, end);
            for (Command* cmd: cmds) {
                cmd->apply(data_);
                delete cmd;
            }
        } catch(interpreterError& error) {
            std::cerr << error.what() << std::endl;
        }
        // CR: only when no commands printed
        data_.msgStream_() << " ok" << std::endl;
        return data_.msgStream_().str();
    }

private:
    // CR: <std::string, creatorType> -> <std::string, command *>
    std::unordered_map<std::string, creatorType> creators_;
    data data_;

    friend void getWords(std::list<std::string>& str, const std::string::iterator& begin, const std::string::iterator& end);

    Interpreter() = default;
    Interpreter(const Interpreter& other) = delete;
    Interpreter& operator=(const Interpreter& other) = delete;
};