#pragma once

#include <stack>
#include <unordered_map>
#include <string>
#include <functional>
#include <list>
#include <cctype>

#include "Commands.h"

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
      for (auto it = begin; it < end; ++it) {
        newCommand += *it;
        if (isspace(*it)) {
          strCommands.push_back(newCommand);
          newCommand = "";
        }
      }

      for (std::string cmd : strCommands) {
        auto creatorIt = creators_.find(cmd);
        if (isdigit(cmd[0])) {
          for (char c : cmd) {
            if (!isdigit(c)) {
              // TODO: throw error "unknown command"
              break;
            }
          }
          numStack_.push(atoi(cmd.c_str()));
        }
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
    std::stack<int> numStack_;
};