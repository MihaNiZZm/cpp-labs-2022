#ifndef LINKEDHASHSET_H
#define LINKEDHASHSET_H

#include <cstdlib>
#include <string>

namespace LinkedHashSet {
    typedef student element;
    
    struct student {
        student();
        student(unsigned age, std::string name);

        bool operator==(const student& other) const;
        bool operator!=(const student& other) const;

        long long hash() const;

        unsigned age_;
        std::string name_;
    };

    struct node {
        node() = default;
        node(element data);

        node* prevInserted_;
        node* nextInserted_;
        node* next_;
        element data_;
    };
    
    class linkedhs {
    public:
        class iterator {
        public:
            element operator*();
            iterator operator++(int);
            iterator operator--();
            bool operator==(const iterator& other) const;
            bool operator!=(const iterator& other) const;

        private:
            int idx_;
            node* pointedNode_;
        };
    
        linkedhs();
        
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
        void resize(int newCapacity);
        void rehash();

        static const int RESIZE_FACTOR = 2;
        static const int DEFAULT_CAPACITY = 26;

        int size_;
        int capacity_;
        double fullnessFactor_;
        LinkedHashSet::node* lastInserted_;
        LinkedHashSet::node** data_;
    };
}

#endif //LINKEDHASHSET_H
