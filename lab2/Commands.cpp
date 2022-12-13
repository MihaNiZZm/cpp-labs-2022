#include "Commands.h"
#include "Interpreter.h"

namespace {

    Command* multiplyCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new Multiply();
    }
    bool multiplyCommand = Interpreter::getInstance().registerCreator("*", multiplyCreator);

    Command* addCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new Add();
    }
    bool addCommand = Interpreter::getInstance().registerCreator("+", addCreator);

    Command* divideCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new Divide();
    }
    bool divideCommand = Interpreter::getInstance().registerCreator("/", divideCreator);

    Command* subtractCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new Subtract();
    }
    bool subtractCommand = Interpreter::getInstance().registerCreator("-", subtractCreator);

    Command* modCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new Mod();
    }
    bool modCommand = Interpreter::getInstance().registerCreator("mod", modCreator);

    Command* dupCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new Dup();
    }
    bool dupCommand = Interpreter::getInstance().registerCreator("dup", dupCreator);

    Command* writeCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new Write();
    }
    bool writeCommand = Interpreter::getInstance().registerCreator(".", writeCreator);

    Command* swapCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new Swap();
    }
    bool swapCommand = Interpreter::getInstance().registerCreator("swap", swapCreator);

    Command* rotateCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new Rotate();
    }
    bool rotateCommand = Interpreter::getInstance().registerCreator("rot", rotateCreator);

    Command* copySecondCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new CopySecond();
    }
    bool copySecondCommand = Interpreter::getInstance().registerCreator("over", copySecondCreator);

    Command* writeAsAsciiCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new WriteAsAscii();
    }
    bool writeAsAsciiCommand = Interpreter::getInstance().registerCreator("emit", writeAsAsciiCreator);

    Command* lineBreakCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new LineBreak();
    }
    bool lineBreakCommand = Interpreter::getInstance().registerCreator("cr", lineBreakCreator);

    Command* moreCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new More();
    }
    bool moreCommand = Interpreter::getInstance().registerCreator(">", moreCreator);

    Command* lessCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new Less();
    }
    bool lessCommand = Interpreter::getInstance().registerCreator("<", lessCreator);

    Command* equalCreator(std::string::iterator& it, const std::string::iterator& end) {
        return new Equal();
    }
    bool equalCommand = Interpreter::getInstance().registerCreator("<", equalCreator);
}