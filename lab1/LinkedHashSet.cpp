#include <algorithm>
#include <assert.h>
#include <cstdlib>
#include <iostream>

#include "LinkedHashSet.h"

using namespace LinkedHashSet;

student::student(unsigned age, std::string name) : age_(age), name_(name) {}

bool student::operator==(const student& other) const {
    return age_ == other.age_ && name_ == other.name_;
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
node::node(node* prevInserted, node* nextInserted, element data): prevInserted_(prevInserted), nextInserted_(nextInserted), nodeValue_(data) {}

// iterator

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

linkedhs::linkedhs() : linkedhs(DEFAULT_CAPACITY) {}
linkedhs::linkedhs(size_t capacity): size_(0), numberOfBuckets_(0), capacity_(capacity), firstInserted_(nullptr), lastInserted_(nullptr), data_(new node*[capacity]()) {}

linkedhs::~linkedhs() {
    clear();
    delete[] data_;
}

linkedhs::linkedhs(const linkedhs& other) : linkedhs() {
    for (element e : other) {
        insert(e);
    }
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
    if (fullnessFactor() >= REHASH_THRESHOLD) {
        rehash();
    }

    int idx = e.hash() % capacity_;
    node* temp = data_[idx];
    
    while (temp) {
        if (temp->nodeValue_ == e) {
            return false;
        }
        if (!temp->next_) {
            addNode(temp, e, idx);
            return true;
        }
        temp = temp->next_;
    }
    addNode(temp, e, idx);
    return true;
}

bool linkedhs::remove(const element& e) {
    linkedhs::iterator target = find(e);
    if (target == end()) {
        return false;
    }
    removeNode(target.pointedNode_);
    return true;
}

void linkedhs::swap(linkedhs& other) {
    std::swap(data_, other.data_);
    std::swap(numberOfBuckets_, other.numberOfBuckets_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(firstInserted_, other.firstInserted_);
    std::swap(lastInserted_, other.lastInserted_);
}

size_t linkedhs::size() const {
    return size_;
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
        tempNode = tempNode->next_;
    }
    return end();
}

bool linkedhs::operator==(const linkedhs& other) const {
    if (size() != other.size()) {
      return false;
    }

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
    for (int i = 0; i < capacity_ && numberOfBuckets_ > 0; ++i) {
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
        data_[i] = nullptr;
        --numberOfBuckets_;
    }
    size_ = 0;
    lastInserted_ = nullptr;
    firstInserted_ = nullptr;
}

void linkedhs::rehash() {
    linkedhs temp(capacity_ * 2);
    for (element e: *this) {
        temp.insert(e);
    }
    swap(temp);
}

double linkedhs::fullnessFactor() const {
    return double(numberOfBuckets_) / capacity_;
}

void linkedhs::redefineRelationsToRemove(node* node) {
    assert(node != nullptr);

    if (!node->prev_) {
        data_[node->nodeValue_.hash() % capacity_] = node->next_;
    }
    if (node->prev_) {
        node->prev_->next_ = node->next_;
    }
    if (node->next_) {
        node->next_->prev_ = node->prev_;
    }

    if (node == firstInserted_) {
        firstInserted_ = node->nextInserted_;
    }
    if (node == lastInserted_) {
        lastInserted_ = node->prevInserted_;
    }

    if (node->prevInserted_) {
        node->prevInserted_->nextInserted_ = node->nextInserted_;
    }
    if (node->nextInserted_) {
        node->nextInserted_->prevInserted_ = node->prevInserted_;
    }
}

void linkedhs::removeNode(node* node) {
    if (!node->prev_ && !node->next_) {
        --numberOfBuckets_;
    }
    redefineRelationsToRemove(node);
    delete node;
    --size_;
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

void linkedhs::addNode(node* prevNode, element e, int idx) {
    node* newNode = new node(e);
    redefineRelationsToInsert(prevNode, newNode);
    ++size_;
    if (!prevNode) {
        ++numberOfBuckets_;
        data_[idx] = newNode;
    }
}
