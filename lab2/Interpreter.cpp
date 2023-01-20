#include "Interpreter.h"

void Interpreter::getWords(std::list<std::string>& str, const std::string::iterator& begin, const std::string::iterator& end) {
    std::string::iterator it = begin;
    std::string tempWord = "";
    while (it != end) {
        std::string strToPrint;
        if (isWriteString(it)) {
            it += 3;
            std::string::iterator temp = std::find_if(it, end, [&strToPrint, it](char c) mutable {
                strToPrint += *it; 
                return c == '"'; });
        }
        ++it;
        Interpreter::getInstance().data_.msgStream_ << strToPrint << std::endl;
        strToPrint = "";
        continue;

        if (isspace(*it)) {
            str.push_back(tempWord);
            tempWord = "";
        }
        tempWord += *it;
        ++it;
    }
}

bool Interpreter::isNumber(std::string word) {
    std::string::iterator it = word.begin();
    if (!isdigit(*it) && *it != '-') {
        return false;
    }
    ++it;
    while (it != word.end()) {
        if (!isdigit(*it)) {
            return false;
        }
        ++it;
    }
    return true;
}

bool Interpreter::isWriteString(const std::string::iterator& firstSymbol) {
    if (!(*firstSymbol && *(firstSymbol + 1) && *(firstSymbol + 2))) {
        return false;
    }
    return *firstSymbol == '.' && *(firstSymbol + 1) == '"' && *(firstSymbol + 2) == ' ';
}

bool Interpreter::addCommandToMap(std::string string, std::unique_ptr<Command> command) {
    commands_[string] = std::move(command);
    return true;
}

std::string Interpreter::interpret(const std::string::iterator& begin, const std::string::iterator& end) {
    data_.msgStream_.str("");
    std::list<std::string> stringCommands;
    getWords(stringCommands, begin, end);

    try {
        for (std::string cmd : stringCommands) {
            if (isNumber(cmd)) {
                try {
                    data_.stack_.push(stoi(cmd));
                } catch(std::out_of_range const& errorMessage) {
                    data_.msgStream_ << errorMessage.what() << std::endl;
                }
            }
            auto finder = commands_.find(cmd);
            if (finder == commands_.end()) {
                throw InterpreterError("Unknown command.");
            }
            std::unique_ptr<Command> newCmd = std::move(commands_[cmd]);
            newCmd->apply(data_);
        }
        
    } catch(InterpreterError& error) {
        std::cerr << error.what() << std::endl;
    }
    // CR: only when no commands printed
    if (data_.msgStream_.str().empty()) {
        data_.msgStream_ << " ok" << std::endl;
    }
    return data_.msgStream_.str();
}