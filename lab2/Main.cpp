#include "Data.h"
#include "Commands.h"
#include "Interpreter.h"
#include "InterpreterError.h"

int main(int argc, char** argv) {
    std::string oneLine;

    while (true) {
        std::cin >> oneLine;
        std::cout << Interpreter::getInstance().interpret(oneLine.begin(), oneLine.end()) << std::endl;
    }
    return 0;
}