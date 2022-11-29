#pragma once

#include <stdexcept>    
#include <exception>
#include <string>

class interpreter_error: public std::runtime_error {
  public:
    interpreter_error(const std::string & msg): std::runtime_error(msg) {}
};