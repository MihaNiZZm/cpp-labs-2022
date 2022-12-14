#include "Parser.h"
#include "Interpreter.h"

//class Predicate {
//public:
//    virtual bool operator()(char c)  = 0;
//};
//
//class __Char__Predicate: public Predicate {
//public:
//    __Char__Predicate(int & i): i_(i) {}
//
//    bool operator()(char c) override {
//      return c == '"';
//    }
//
//private:
//    int & i_;
//};
//
//std::string::iterator find_if(const std::string::iterator & start, const std::string::iterator & end, Predicate predicate) {
//  std::string::iterator it = start;
//  while(it != end) {
//    char c = *it;
//    if (predicate(c)) {
//      return it;
//    }
//  }
//  return end;
//}

void getWords(std::list<std::string>& str, const std::string::iterator& begin, const std::string::iterator& end) {
    std::string::iterator it = begin;
    std::string tempWord = "";
    while (it != end) {
        std::string strToPrint;
        if (isWriteString(it)) {
            it += 3;
            // CR: find_if
//            find_if(it, end, [&i](char c) { return c == '"'; })
//            find_if(it, end, __Char__Predicate());
            while (*it != '"' && *it != '\n' && it != end) {
                strToPrint += *it;
                ++it;
            }
        }
        ++it;
        Interpreter::getInstance().data_.msgStream_() << strToPrint << std::endl;
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

bool isWriteString(const std::string::iterator& firstSymbol) {
  // CR: check if string has 3 chars
    return *firstSymbol == '.' && *(firstSymbol + 1) == '"' && *(firstSymbol + 2) == ' ';
}