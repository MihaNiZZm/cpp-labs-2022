#include <algorithm>
#include <cstdlib>
#include <iostream>

#include "LinkedHashSet.h"

LinkedHashSet::student::student() : age_(0), name_("") {}
LinkedHashSet::student::student(unsigned age, std::string name) : age_(age), name_(name) {}

bool LinkedHashSet::student::operator==(const student& other) const {
    return (age_ == other.age_ && name_ == other.name_);
}

bool LinkedHashSet::student::operator!=(const student& other) const {
    return !(*this == other);
}

long long LinkedHashSet::student::hash() const {
    long long h = 0;
    int p = 31;
    for (char c : name_) {
        h += (c - 'a' + 1) * p;
        p *= 31;
    }
    h = p * h + age_;
    return abs(h);
}

LinkedHashSet::node::node() : prevInserted_(nullptr), nextInserted_(nullptr), next_(nullptr), nodeValue_(student()) {}
LinkedHashSet::node::node(element data) : prevInserted_(nullptr), nextInserted_(nullptr), next_(nullptr), nodeValue_(data) {}

LinkedHashSet::linkedhs::linkedhs() : size_(0), capacity_(DEFAULT_CAPACITY), fullnessFactor_(0.0), firstInserted_(nullptr), lastInserted_(nullptr), data_(new node*[DEFAULT_CAPACITY]()) {}
LinkedHashSet::linkedhs::linkedhs(int capacity) : size_(0), capacity_(capacity), fullnessFactor_(0.0), firstInserted_(nullptr), lastInserted_(nullptr), data_(new node*[capacity]()) {}

LinkedHashSet::linkedhs::~linkedhs() {
    for (int i = 0; i < capacity_; ++i) {
        if (data_[i] == nullptr) {
            continue;
        }

    }
}

LinkedHashSet::linkedhs::linkedhs(const linkedhs& other) : size_(other.size_), capacity_(other.capacity_), fullnessFactor_(other.fullnessFactor_) {
    data_ = new node*[capacity_]();
    std::copy(other.data_, other.data_ + other.capacity_, data_);
}

LinkedHashSet::linkedhs& LinkedHashSet::linkedhs::operator=(const linkedhs& other) {
    delete[] data_;
    capacity_ = other.capacity_;
    size_ = other.size_;
    fullnessFactor_ = other.fullnessFactor_;
    data_ = new node*[capacity_]();
    std::copy(other.data_, other.data_ + other.capacity_, data_);
}

void LinkedHashSet::linkedhs::updateFullnessFactor() {
    fullnessFactor_ = double(size_ / capacity_);
}

bool LinkedHashSet::linkedhs::insert(const element& e) {
    updateFullnessFactor();
    if (fullnessFactor_ >= 0.75) {
        //rehash();
    }

    int idx = e.hash() % capacity_;
    node* curNode = data_[idx];
    node* prevNode = nullptr;

    if (!curNode) {
        ++size_;
    }
    while (curNode) {
        if (curNode->nodeValue_ == e) {
            std::cout << "Insertion failed! Element " << e.name_ << " is already in the set!" << std::endl;
            return false;
        }
        prevNode = curNode;
        curNode = curNode->next_;
    }

    curNode = new node(e);
    if (prevNode) {
        prevNode->next_ = curNode;
    }

    if (!firstInserted_) {
        firstInserted_ = curNode;
    }
    if (lastInserted_) {
        lastInserted_->nextInserted_ = curNode;
    }
    curNode->prevInserted_ = lastInserted_;
    lastInserted_ = curNode;

    std::cout << "Inserted element " << e.name_ << std::endl;
    return true;
}

bool LinkedHashSet::linkedhs::remove(const element& e) {
    int idx = e.hash() % capacity_;
    node* curNode = data_[idx];
    node* prevNode = nullptr;
    
    while (curNode) {
        if (curNode->nodeValue_ == e) {
            if (!prevNode) {
                data_[idx] = curNode->next_;
                if (!curNode->next_) {
                    --size_;
                }
            }
            else {
                prevNode->next_ = curNode->next_;
            }
            
            if (curNode == firstInserted_) {
                firstInserted_ = curNode->nextInserted_;
            }
            if (curNode == lastInserted_) {
                lastInserted_ = curNode->prevInserted_;
            }
            if (curNode != firstInserted_ && curNode != lastInserted_) {
                curNode->prevInserted_->nextInserted_ = curNode->nextInserted_;
                curNode->nextInserted_->prevInserted_ = curNode->prevInserted_;
            }
            delete curNode;
            std::cout << "Removed element " << e.name_ << std::endl;
            return true;
        }
        prevNode = curNode;
        curNode = curNode->next_;
    }

    std::cout << "Removal failed! Element " << e.name_ << " is not exists!" << std::endl;
    return false;
}

void LinkedHashSet::linkedhs::clear() {
    // linkedhs* temp = new linkedhs(this->capacity_);
    // delete[] this;
    // this = temp;
}