#pragma once

#include <cctype>
#include <string>
#include <algorithm>
#include <list>
#include <iostream>

void getWords(std::list<std::string>& str, const std::string::iterator& begin, const std::string::iterator& end);

bool isNumber(std::string word);

bool isWriteString(const std::string::iterator& firstSymbol);