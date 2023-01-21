#include "Data.h"
#include "Commands.h"
#include "Interpreter.h"
#include "InterpreterError.h"

int main(int argc, char** argv) {
    std::string oneLine;
    while (true) {
        getline(std::cin, oneLine);
        std::cout << Interpreter::getInstance().interpret(oneLine.begin(), oneLine.end());
    }
    return 0;
}