#include "Data.h"

void data::pop() {
    data_.pop();
}

void data::push(int number) {
    data_.push(number);
}

int data::top() {
    return data_.top();
}