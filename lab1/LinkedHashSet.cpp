#include <algorithm>
#include <cstdlib>
#include <iostream>

#include "LinkedHashSet.h"

// CR: using namespace LinkedHashSet

// student

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

// node

LinkedHashSet::node::node() : prevInserted_(nullptr), nextInserted_(nullptr), next_(nullptr), nodeValue_(student()) {}
LinkedHashSet::node::node(element data) : prevInserted_(nullptr), nextInserted_(nullptr), next_(nullptr), nodeValue_(data) {}

//iterator

// CR: = default
LinkedHashSet::linkedhs::iterator::iterator(const iterator& other) : pointedNode_(other.pointedNode_) {}
// CR: explicit
LinkedHashSet::linkedhs::iterator::iterator(node* node) : pointedNode_(node) {}

LinkedHashSet::element LinkedHashSet::linkedhs::iterator::operator*() {
    return pointedNode_->nodeValue_;
}
LinkedHashSet::linkedhs::iterator LinkedHashSet::linkedhs::iterator::operator++(int) {
    iterator temp(*this);
    this->pointedNode_ = this->pointedNode_->nextInserted_;
    return temp;    
}
LinkedHashSet::linkedhs::iterator& LinkedHashSet::linkedhs::iterator::operator++() {
    this->pointedNode_ = this->pointedNode_->nextInserted_;
    return *this;
}
LinkedHashSet::linkedhs::iterator LinkedHashSet::linkedhs::iterator::operator--(int) {
    iterator temp(*this);
    this->pointedNode_ = this->pointedNode_->prevInserted_;
    return temp;    
}
LinkedHashSet::linkedhs::iterator& LinkedHashSet::linkedhs::iterator::operator--() {
    this->pointedNode_ = this->pointedNode_->prevInserted_;
    return *this;
}
bool LinkedHashSet::linkedhs::iterator::operator==(const iterator& other) const {
    return pointedNode_ == other.pointedNode_;
}
bool LinkedHashSet::linkedhs::iterator::operator!=(const iterator& other) const {
    return !(*this == other);
}

// LinkedHashSet

// CR: invoke private ctor with capacity instead
LinkedHashSet::linkedhs::linkedhs() : size_(0), capacity_(DEFAULT_CAPACITY), fullnessFactor_(0.0), firstInserted_(nullptr), lastInserted_(nullptr), data_(new node*[DEFAULT_CAPACITY]()), numberOfNodes_(0) {}
LinkedHashSet::linkedhs::linkedhs(int capacity) : size_(0), capacity_(capacity), fullnessFactor_(0.0), firstInserted_(nullptr), lastInserted_(nullptr), data_(new node*[capacity]()), numberOfNodes_(0) {
  assert(capacity != 0);
}

LinkedHashSet::linkedhs::~linkedhs() {
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
LinkedHashSet::linkedhs::linkedhs(const linkedhs& other) {
    fullnessFactor_ = 0;
    size_ = 0;
    numberOfNodes_ = 0;
    capacity_ = other.capacity_;
    // CR: use default capacity
    data_ = new node*[capacity_]();
    // CR: use iterators
    // for (element e : other) ....
    node* temp = other.firstInserted_;
    while (temp) {
        insert(temp->nodeValue_);
        temp = temp->nextInserted_;
    }
}

LinkedHashSet::linkedhs& LinkedHashSet::linkedhs::operator=(const linkedhs& other) {
    if (*this == other) {
        return *this;
    }
    clear();
    // CR: write to data_ using insert()
    delete[] data_;
    capacity_ = other.capacity_;
    size_ = other.size_;
    fullnessFactor_ = other.fullnessFactor_;
    numberOfNodes_ = other.numberOfNodes_;
    data_ = new node*[other.capacity_]();
    std::copy(other.data_, other.data_ + other.capacity_, data_);

    return *this;
}

bool LinkedHashSet::linkedhs::insert(const element& e) {
    if (capacity_ == 0) {
        return false;
    }
    // CR: find()?
    updateFullnessFactor();
    if (fullnessFactor_ >= 0.75) {
        rehash();
    }

    int idx = e.hash() % capacity_;
    // CR: refactor somehow
    if (!data_[idx]) {
        ++size_;
        data_[idx] = new node(e);

        if (!firstInserted_) {
            firstInserted_ = data_[idx];
        }

        if (lastInserted_) {
            lastInserted_->nextInserted_ = data_[idx];
        }
        data_[idx]->prevInserted_ = lastInserted_;
        lastInserted_ = data_[idx];

        //std::cout << "Inserted element " << e.name_ << std::endl;
        ++numberOfNodes_;
        return true;
    }

    node* curNode = data_[idx];
    node* prevNode = nullptr;
    while (curNode) {
        if (curNode->nodeValue_ == e) {
            //std::cout << "Insertion failed! Element " << e.name_ << " is already in the set!" << std::endl;
            return false;
        }
        prevNode = curNode;
        curNode = curNode->next_;
    }

    curNode = new node(e);
    if (prevNode) {
        prevNode->next_ = curNode;
    }

    if (lastInserted_) {
        lastInserted_->nextInserted_ = curNode;
    }
    curNode->prevInserted_ = lastInserted_;
    lastInserted_ = curNode;

    //std::cout << "Inserted element " << e.name_ << std::endl;
    ++numberOfNodes_;
    return true;
}

bool LinkedHashSet::linkedhs::remove(const element& e) {
    if (capacity_ == 0) {
        return false;
    }
    // CR: find()
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
            // CR: refactor somehow
            if (curNode == firstInserted_) {
                firstInserted_ = curNode->nextInserted_;
            }
            if (curNode == lastInserted_) {
                lastInserted_ = curNode->prevInserted_;
            }
            if (curNode->nextInserted_) {
                curNode->nextInserted_->prevInserted_ = curNode->prevInserted_;
            }
            if (curNode->prevInserted_) {
                curNode->prevInserted_->nextInserted_ = curNode->nextInserted_;
            }
            delete curNode;
            //std::cout << "Removed element " << e.name_ << std::endl;
            --numberOfNodes_;
            return true;
        }
        prevNode = curNode;
        curNode = curNode->next_;
    }

    //std::cout << "Removal failed! Element " << e.name_ << " doesn't exist!" << std::endl;
    return false;
}

void LinkedHashSet::linkedhs::swap(linkedhs& other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(firstInserted_, other.firstInserted_);
    std::swap(lastInserted_, other.lastInserted_);
}

size_t LinkedHashSet::linkedhs::size() const {
    return numberOfNodes_;
}

bool LinkedHashSet::linkedhs::empty() const {
    return size() == 0;
}

bool LinkedHashSet::linkedhs::contains(const element& e) const {
    return find(e) != end();
}

LinkedHashSet::linkedhs::iterator LinkedHashSet::linkedhs::find(const element& e) const {
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

bool LinkedHashSet::linkedhs::operator==(const linkedhs& other) const {
    if (size_ != other.size_) {
      return false;
    }
    // CR: order does not matter, capacity can differ
    for (int i = 0; i < capacity_; ++i) {
        if (!data_[i] && !other.data_[i]) {
            continue;
        }
        if (!data_[i] || !other.data_[i]) {
            return false;
        }
        node* thisTemp = data_[i];
        node* otherTemp = other.data_[i];
        while (thisTemp) {
            if (!otherTemp || thisTemp->nodeValue_ != otherTemp->nodeValue_) {
                return false;
            }
            thisTemp = thisTemp->next_;
            otherTemp = otherTemp->next_;
        }
        if (otherTemp) {
            return false;
        }
    }
    return true;
}
bool LinkedHashSet::linkedhs::operator!=(const linkedhs& other) const {
    return !(*this == other);
}

LinkedHashSet::linkedhs::iterator LinkedHashSet::linkedhs::begin() const {
    return iterator(firstInserted_);
}
LinkedHashSet::linkedhs::iterator LinkedHashSet::linkedhs::end() const {
    return iterator(nullptr);
}

void LinkedHashSet::linkedhs::clear() {
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

void LinkedHashSet::linkedhs::rehash() {
    node** dataToDelete = data_;
    capacity_ *= 2;
    node** newData = new node*[capacity_]();
    // CR: firstInserted_ = nullptr, ...
    node* temp = firstInserted_;
    data_ = newData;
    while (temp) {
        insert(temp->nodeValue_);
        temp = temp->nextInserted_;
    }
    delete[] dataToDelete;
}

void LinkedHashSet::linkedhs::updateFullnessFactor() {
    return double(size_ / capacity_);
}