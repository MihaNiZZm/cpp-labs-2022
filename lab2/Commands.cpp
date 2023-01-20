#include "Commands.h"
#include "Interpreter.h"

namespace {
    bool addMultiply = Interpreter::getInstance().addCommandToMap("*", std::make_unique<Multiply>());
    bool addAdd = Interpreter::getInstance().addCommandToMap("+", std::make_unique<Add>());
    bool addDivide = Interpreter::getInstance().addCommandToMap("/", std::make_unique<Divide>());
    bool addSubtract = Interpreter::getInstance().addCommandToMap("-", std::make_unique<Subtract>());
    bool addMod = Interpreter::getInstance().addCommandToMap("mod", std::make_unique<Mod>());
    bool addDup = Interpreter::getInstance().addCommandToMap("dup", std::make_unique<Dup>());
    bool addDrop = Interpreter::getInstance().addCommandToMap("drop", std::make_unique<Drop>());
    bool addWrite = Interpreter::getInstance().addCommandToMap(".", std::make_unique<Write>());
    bool addSwap = Interpreter::getInstance().addCommandToMap("swap", std::make_unique<Swap>());
    bool addRotate = Interpreter::getInstance().addCommandToMap("rot", std::make_unique<Rotate>());
    bool addCopySecond = Interpreter::getInstance().addCommandToMap("over", std::make_unique<CopySecond>());
    bool addWriteAsAscii = Interpreter::getInstance().addCommandToMap("emit", std::make_unique<WriteAsAscii>());
    bool addLineBreak = Interpreter::getInstance().addCommandToMap("cr", std::make_unique<LineBreak>());
    bool addGreater = Interpreter::getInstance().addCommandToMap(">", std::make_unique<Greater>());
    bool addLess = Interpreter::getInstance().addCommandToMap("<", std::make_unique<Less>());
    bool addEqual = Interpreter::getInstance().addCommandToMap("=", std::make_unique<Equal>());
}