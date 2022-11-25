#include <stack>
#include <unordered_map>
#include <string>
#include <functional>

#include "Commands.h"

class Interpreter {
  public:
    typedef std::function<Command* (std::string::iterator&, const std::string::iterator&)> creatorType;

    bool registerCreator(const std::string& tmp, creatorType creator) {
        creators_[tmp] = creator;
        return true;
    }

  private:
    std::unordered_map<std::string, creatorType> creators_;
    std::stack<int> numStack_;
};