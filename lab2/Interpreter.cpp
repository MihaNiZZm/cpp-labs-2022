#include "Interpreter.h"

bool Interpreter::addCommandToMap(std::string string, std::unique_ptr<Command> command) {
    commands_[string] = std::move(command);
    return true;
}

bool Interpreter::isNumber(std::string& word) {
    std::string::iterator it = word.begin();
    if (!isdigit(*it) && *it != '-') {
        return false;
    }
    if (word[0] == '-' && word.length() == 1) {
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

bool Interpreter::isWriteString(const std::string& word) {
    return word == ".\"";
}

std::string::iterator& Interpreter::applyWriteString(std::string::iterator& begin, const std::string::iterator& end, context& context) {
    std::string::iterator endOfString;
    try {
        endOfString = std::find_if(begin, end, [](char c) { return c == '\"'; });
        if (endOfString == end) {
            throw InterpreterError("No closing quote.");
            return endOfString;
        }
        context.msgStream_ << std::string(begin + 1, endOfString) << " ";
        begin = endOfString + 1;
        return begin;
    }
    catch (std::length_error) {
        throw InterpreterError("No closing quote.");
        return endOfString;
    }
}

void Interpreter::putNumberOnStack(std::string& word) {
    try {
        numStack_.customPush(std::stoi(word));
    }
    catch (std::out_of_range) {
        throw InterpreterError("Number is out of range of integer type.");
    }
}

void Interpreter::applyCommand(std::string& word, context& context) {
    if (!commands_[word]) {
        std::string errorMessage = "Command \"" + word + "\" doesn't exists.";
        throw InterpreterError(errorMessage);
    }
    commands_[word]->apply(context);
}

void Interpreter::interpretEachWord(const std::string::iterator& begin, const std::string::iterator& end, context& context) {
    std::string::iterator it = begin;
    std::string word = "";

    while (it != end) {
        if (isspace(*it) || ((it + 1) == end)) {
            if ((it + 1) == end && *it != ' ') {
                word += *it;
            }

            if (word == "") {
                ++it;
                continue;
            }

            if (isWriteString(word)) {
                it = applyWriteString(it, end, context);
                word = "";
                continue;
            }

            if (isNumber(word)) {
                putNumberOnStack(word);
            }
            else {
                applyCommand(word, context);
            }
            word = "";
            ++it;
            continue;
        }
        word += *it;
        ++it;
    }
}

std::string Interpreter::interpret(const std::string::iterator& begin, const std::string::iterator& end) {
    std::string::iterator it = begin;
    std::stringstream outStream;
    context context(numStack_, outStream);
    
    try {
        interpretEachWord(it, end, context);
        if (outStream.str() == "") {
            outStream << "ok" << std::endl;
        }
        else {
            outStream << std::endl;
        }
    }
    catch (InterpreterError& error) {
        outStream << error.what() << std::endl;
    }
    return outStream.str();
}