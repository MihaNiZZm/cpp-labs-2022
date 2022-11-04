#include <algorithm>
#include <assert.h>
#include <cstdlib>
#include <iostream>

#include "LinkedHashSet.h"

using namespace LinkedHashSet;

student::student(unsigned age, std::string name) : age_(age), name_(name) {}

bool student::operator==(const student& other) const {
    return (age_ == other.age_ && name_ == other.name_);
}
bool student::operator!=(const student& other) const {
    return !(*this == other);
}

long long student::hash() const {
    long long h = 0;
    int p = 31;
    for (char c : name_) {
        h += (c - 'a' + 1) * p;
        p *= 31;
    }
    h = p * h + age_;
    return abs(h);
}

// node

node::node(element data) : prevInserted_(nullptr), nextInserted_(nullptr), prev_(nullptr), next_(nullptr), nodeValue_(data) {}

// iterator

// CR: explicit
linkedhs::iterator::iterator(node* node) : pointedNode_(node) {}

element linkedhs::iterator::operator*() {
    return pointedNode_->nodeValue_;
}
linkedhs::iterator linkedhs::iterator::operator++(int) {
    iterator temp(*this);
    this->pointedNode_ = this->pointedNode_->nextInserted_;
    return temp;    
}
linkedhs::iterator& linkedhs::iterator::operator++() {
    this->pointedNode_ = this->pointedNode_->nextInserted_;
    return *this;
}
linkedhs::iterator linkedhs::iterator::operator--(int) {
    iterator temp(*this);
    this->pointedNode_ = this->pointedNode_->prevInserted_;
    return temp;    
}
linkedhs::iterator& linkedhs::iterator::operator--() {
    this->pointedNode_ = this->pointedNode_->prevInserted_;
    return *this;
}
bool linkedhs::iterator::operator==(const iterator& other) const {
    return pointedNode_ == other.pointedNode_;
}
bool linkedhs::iterator::operator!=(const iterator& other) const {
    return !(*this == other);
}

// LinkedHashSet

// CR: invoke private ctor with capacity instead
linkedhs::linkedhs() : size_(0), capacity_(DEFAULT_CAPACITY), firstInserted_(nullptr), lastInserted_(nullptr), data_(new node*[DEFAULT_CAPACITY]()), numberOfNodes_(0) {}

linkedhs::~linkedhs() {
    node* it = firstInserted_;
    node* temp = nullptr;
    while (it) {
        temp = it;
        it = it->nextInserted_;
        delete temp;
    }
    delete[] data_;
}

// CR: init list
linkedhs::linkedhs(const linkedhs& other) : capacity_(other.capacity_) {


    // size_ = 0;
    // numberOfNodes_ = 0;
    // capacity_ = other.capacity_;
    // // CR: use default capacity
    // data_ = new node*[capacity_]();
    // // CR: use iterators
    // // for (element e : other) ....
    // node* temp = other.firstInserted_;
    // while (temp) {
    //     insert(temp->nodeValue_);
    //     temp = temp->nextInserted_;
    // }
}

linkedhs& linkedhs::operator=(const linkedhs& other) {
    if (*this == other) {
        return *this;
    }

    clear();
    for (element e : other) {
        insert(e);
    }

    return *this;
}

bool linkedhs::insert(const element& e) {
    if (fullnessFactor() >= 0.75) {
        rehash();
    }

    int idx = e.hash() % capacity_;
    node* temp = data_[idx];
    node* nodeToInsert = new node(e);
    
    while (temp) {
        if (temp->nodeValue_ == e) {
            return false;
        }
        if (!temp->next_) {
            redefineRelationsToInsert(temp, nodeToInsert);
            ++numberOfNodes_;
            return true;
        }
        temp = temp->next_;
    }
    ++size_;
    data_[idx] = nodeToInsert;
    redefineRelationsToInsert(temp, nodeToInsert);
    ++numberOfNodes_;
    return true;
}

bool linkedhs::remove(const element& e) {
    linkedhs::iterator target = find(e);
    if (target == end()) {
        return false;
    }

    if (!target.pointedNode_->prev_ && !target.pointedNode_->next_) {
        --size_;
        firstInserted_ = nullptr;
        lastInserted_ = nullptr;
        data_[(*target).hash() % capacity_] = nullptr;
    }
    redefineRelationsToRemove(target.pointedNode_);
    delete target.pointedNode_;

    --numberOfNodes_;
    return true;
}

void linkedhs::swap(linkedhs& other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(firstInserted_, other.firstInserted_);
    std::swap(lastInserted_, other.lastInserted_);
}

size_t linkedhs::size() const {
    return numberOfNodes_;
}

bool linkedhs::empty() const {
    return size() == 0;
}

bool linkedhs::contains(const element& e) const {
    return find(e) != end();
}

linkedhs::iterator linkedhs::find(const element& e) const {
    int idx = e.hash() % capacity_;
    if (!data_[idx]) {
        return end();
    }
    node* tempNode = data_[idx];
    while (tempNode) {
        if (tempNode->nodeValue_ == e) {
            return iterator(tempNode);
        }
    }
    return end();
}

bool linkedhs::operator==(const linkedhs& other) const {
    if (size() != other.size()) {
      return false;
    }
    // CR: order does not matter, capacity can differ
    for (element e : *this) {
        if (!other.contains(e)) {
            return false;
        }
    }
    return true;
}

bool linkedhs::operator!=(const linkedhs& other) const {
    return !(*this == other);
}

linkedhs::iterator linkedhs::begin() const {
    return iterator(firstInserted_);
}
linkedhs::iterator linkedhs::end() const {
    return iterator(nullptr);
}

void linkedhs::clear() {
    for (int i = 0; i < capacity_; ++i) {
        if (!data_[i]) {
            continue;
        }
        node* it = data_[i];
        node* prev = nullptr;
        while (it) {
            prev = it;
            it = it->next_;
            delete prev;
        }
        // CR: write test
        data_[i] = nullptr;
    }
    size_ = 0;
    numberOfNodes_ = 0;
    lastInserted_ = nullptr;
    firstInserted_ = nullptr;
}

void linkedhs::rehash() {
    node** dataToDelete = data_;
    capacity_ *= 2;
    node** newData = new node*[capacity_]();
    // CR: firstInserted_ = nullptr, ...
    node* temp = firstInserted_;
    firstInserted_ = nullptr;
    lastInserted_ = nullptr;
    size_ = 0;
    numberOfNodes_ = 0;
    data_ = newData;
    while (temp) {
        insert(temp->nodeValue_);
        temp = temp->nextInserted_;
    }
    delete[] dataToDelete;
}

double linkedhs::fullnessFactor() const {
    return double(size_) / double(capacity_);
}

void linkedhs::redefineRelationsToRemove(node* node) {
    if (node->prev_) {
        node->prev_->next_ = node->next_;
    }
    if (node->next_) {
        node->next_->prev_ = node->prev_;
    }
    if (node->prevInserted_) {
        node->prevInserted_->nextInserted_ = node->nextInserted_;
    }
    if (node->nextInserted_) {
        node->nextInserted_->prevInserted_ = node->prevInserted_;
    }
}

void linkedhs::redefineRelationsToInsert(node* prevNode, node* nodeToInsert) {
    if (prevNode) {
        prevNode->next_ = nodeToInsert;
        nodeToInsert->prev_ = prevNode;
    }
    if (!firstInserted_) {
        firstInserted_ = nodeToInsert;
    }
    if (lastInserted_) {
        lastInserted_->nextInserted_ = nodeToInsert;
        nodeToInsert->prevInserted_ = lastInserted_;
    }
    lastInserted_ = nodeToInsert;
}