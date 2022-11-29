#pragma once

#include <cctype>
#include <string>
#include <algorithm>
#include <list>

void getWords(std::list<std::string>& str, const std::string::iterator& begin, const std::string::iterator& end);

bool isNumber(std::string word);