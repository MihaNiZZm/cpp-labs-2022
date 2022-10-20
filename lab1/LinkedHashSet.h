#ifndef LINKEDHASHSET_H
#define LINKEDHASHSET_H

#include <cstdlib>
#include <string>

namespace LinkedHashSet {
    struct student {
        student();
        student(unsigned age, std::string name);

        bool operator==(const student& other) const;
        bool operator!=(const student& other) const;

        long long hash() const;

        unsigned age_;
        std::string name_;
    };

    typedef student element;

    struct node {
        node();
        node(element data);
        void clear();

        node* prevInserted_;
        node* nextInserted_;
        node* next_;
        element nodeValue_;
    };
    
    class linkedhs {
    public:
        class iterator {
        public:
            iterator(const iterator& other);
            iterator(node** set, node* node);

            element operator*();
            iterator operator++(int);
            iterator& operator++();
            iterator operator--(int);
            iterator& operator--();
            bool operator==(const iterator& other) const;
            bool operator!=(const iterator& other) const;

        private:
            node** set_;
            node* pointedNode_;
        };
    
        linkedhs();
        linkedhs(int capacity);
        
        ~linkedhs();
        
        linkedhs(const linkedhs& other);
        linkedhs& operator=(const linkedhs& other);
        
        bool insert(const element& e);
        bool remove(const element& e);
        
        void swap(linkedhs& other);
        
        size_t size() const;
        
        bool empty() const;
        
        bool contains(const element& e) const;
        iterator find(const element& e) const;
        
        bool operator==(const linkedhs& other) const;
        bool operator!=(const linkedhs& other) const;
        
        iterator begin();
        iterator end();
        
        void clear();

    private:
        void rehash();
        void updateFullnessFactor();

        static const int RESIZE_FACTOR = 2;
        static const int DEFAULT_CAPACITY = 32;

        int size_;
        int capacity_;
        double fullnessFactor_;
        node* firstInserted_;
        node* lastInserted_;
        node** data_;
    };
}

#endif //LINKEDHASHSET_H
