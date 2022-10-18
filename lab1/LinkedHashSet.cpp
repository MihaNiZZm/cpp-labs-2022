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

LinkedHashSet::node::node() : prevInserted_(nullptr), nextInserted_(nullptr), next_(nullptr), data_(student()) {}
LinkedHashSet::node::node(element data) : prevInserted_(nullptr), nextInserted_(nullptr), next_(nullptr), data_(data) {}

LinkedHashSet::linkedhs::linkedhs() : size_(0), capacity_(DEFAULT_CAPACITY), fullnessFactor_(0.0), lastInserted_(nullptr), data_(new node*[capacity_]()) {}

LinkedHashSet::linkedhs::~linkedhs() {
    delete[] data_;
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
    fullnessFactor_ = size_ / capacity_;
}

bool LinkedHashSet::linkedhs::insert(const element& e) {
    updateFullnessFactor();
    if (fullnessFactor_ >= 0.75) {
        rehash();
    }

    node* newNode = data_[e.hash() % capacity_];
    while (newNode) {
        if (newNode->data_ == e) {
            std::cout << "Insertion failed. There is the same element exists in the set." << std::endl;
            return false;
        }
        newNode = newNode->next_;
    }
    if (!newNode) {
        ++size_;
    }

    newNode = new node(e);
    newNode->prevInserted_ = lastInserted_;
    lastInserted_->nextInserted_ = newNode;

    std::cout << "Inserted: " << e.name_ << std::endl;
    return true;
}

bool LinkedHashSet::linkedhs::remove(const element& e) {
    node* tempNode = data_[e.hash() % capacity_];
    
    // if (!tempNode->next_) {
    //     if (tempNode->data_ == e) {
    //         tempNode->prevInserted_->nextInserted_ = tempNode->nextInserted_;
    //         tempNode->nextInserted_->prevInserted_ = tempNode->prevInserted_;
    //         delete[] tempNode;

    //         --size_;
    //         fullnessFactor_ = (size_ / capacity_);

    //         std::cout << "Removed: " << e.name_ << std::endl;
    //         return true;
    //     }
    //     else {
    //         std::cout << "Removal failed. There is no element like this in the set." << std::endl;
    //         return false;
    //     }
    // }
    // else {
    //     while (tempNode) {
            
    //     }
    // }

    while (tempNode) {
        if (tempNode->data_ == e) {
            if (!data_[e.hash() % capacity_]->next_) {
                --size_;
            }
            
            tempNode->prevInserted_->nextInserted_ = tempNode->nextInserted_;
            tempNode->nextInserted_->prevInserted_ = tempNode->prevInserted_;
            delete[] tempNode;
        }
    }
}