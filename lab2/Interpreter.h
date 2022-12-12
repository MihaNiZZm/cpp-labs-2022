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
      
      getWords(strCommands, begin, end);

      for (std::string cmd : strCommands) {
        if (isNumber(cmd)) {
          numStack_.push(stoi(cmd));
          // TODO: throw error if number doesn't fit into int type range.
        }
        auto creatorIt = creators_.find(cmd);
        if (creatorIt == creators_.end()) {
          // TODO: throw error "unknown command"
        }
        creatorType creator = (*creatorIt).second;
      }
    }

  private:
    Interpreter() = default;
    Interpreter(const Interpreter& other) = delete;
    Interpreter& operator=(const Interpreter& other) = delete;

    std::unordered_map<std::string, creatorType> creators_;
    data numStack_;
};