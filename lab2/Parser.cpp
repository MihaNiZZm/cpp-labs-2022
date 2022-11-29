#include "Parser.h"

void getWords(std::list<std::string>& str, const std::string::iterator& begin, const std::string::iterator& end) {
    std::string::iterator it = begin;
    std::string tempWord = "";
    while (it != end) {
        if (isspace(*it)) {
            str.push_back(tempWord);
            tempWord = "";
        }
        tempWord += *it;
        ++it;
    }
}

bool isNumber(std::string word) {
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