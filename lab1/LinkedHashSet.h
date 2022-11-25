#ifndef LINKEDHASHSET_H
#define LINKEDHASHSET_H

#include <cstdlib>
#include <string>

namespace LinkedHashSet {
    struct student {
        // Creates student type variable with given name and age.
        student(unsigned age, std::string name);

        // Returns true if age and name of two given students are equal,
        // else returns false.
        bool operator==(const student& other) const;
        // Returns false if age and name of two given students are equal,
        // else returns true.
        bool operator!=(const student& other) const;

        unsigned age_;
        std::string name_;

    private:
        friend struct node;
        friend class linkedhs;

        long long hash() const;
    };

    typedef student element;

    struct node {
    private:
        node();
        node(element data);
        node(node* prevInserted, node* nextInserted, element data);

        node* prevInserted_;
        node* nextInserted_;
        node* prev_;
        node* next_;
        element nodeValue_;

        friend class linkedhs;
    };
    
    class linkedhs {
    public:
        class iterator {
        public:
            // Returns independent copy of other iterator.
            iterator(const iterator& other) = default;
            // Returns new iterator with given pointed node.
            explicit iterator(node* node);
  
            // Returns student, that this iterator contains.
            element operator*();
            // Returns same iterator and then increments it.
            iterator operator++(int);
            // Increments this iterator and then returns it.
            iterator& operator++();
            // Returns same iterator and then decrements it.
            iterator operator--(int);
            // Decrements this iterator and then returns it.
            iterator& operator--();
            // Returns true, if this and other iterators contain the same node,
            // else returns false.
            bool operator==(const iterator& other) const;
            // Returns true, if this and other iterators contain different nodes,
            // else returns false.
            bool operator!=(const iterator& other) const;

        private:
            node* pointedNode_;
            friend class linkedhs;
        };
    
        linkedhs();
        
        ~linkedhs();
        
        // Creates independent copy of other linkedhashset.
        linkedhs(const linkedhs& other);
        // Copies values of other linkedhashset to this linkedhashset. Linkedhashsets are still being independent.
        linkedhs& operator=(const linkedhs& other);
        
        // Inserts given student in this linkedhashset.
        // Returns true, if there is no the same student in the set,
        // else returns false.
        bool insert(const element& e);
        // Removes given student from this linkedhashset.
        // Returns true if given student was found,
        // else returns false.
        bool remove(const element& e);
        
        // Swaps all fields of this linkedhashset and other linkedhashset.
        void swap(linkedhs& other);
        
        // Returns number of elements in this linkedhashset.
        size_t size() const;
        
        // Returns true if this linkedhashset has no elements,
        // else returns false.
        bool empty() const;
        
        // Returns true if the given element exists in this linkedhashset,
        // else returns false.
        bool contains(const element& e) const;
        // If the given element was found in this linkedhashset,
        // returns iterator of that element,
        // else returns end-iterator.
        iterator find(const element& e) const;
        
        // Returns true, if this and other linkedhashsets have the same elements,
        // else returns false.
        bool operator==(const linkedhs& other) const;
        // Returns false, if this and other linkedhashsets have the same elements,
        // else returns true.
        bool operator!=(const linkedhs& other) const;
        
        // Returns iterator that contains first added element.
        // If this linkedhashset is empty, returns end-iterator. 
        iterator begin() const;
        // Returns end-iterator. This iterator contains nullptr.
        iterator end() const;
        
        // Deletes all elements of this linkedhashset and sets size to 0.
        void clear();

    private:
        linkedhs(size_t capacity); 
        void rehash();
        double fullnessFactor() const;
        void redefineRelationsToRemove(node* node);
        void redefineRelationsToInsert(node* prevNode, node* nodeToInsert);
        void removeNode(node* node);
        void addNode(node* prevNode, element e, int idx);

        static const int RESIZE_FACTOR = 2;
        static const int DEFAULT_CAPACITY = 8;
        static constexpr double REHASH_THRESHOLD = 0.75;

        int size_;
        int numberOfBuckets_;
        int capacity_;
        
        node* firstInserted_;
        node* lastInserted_;
        node** data_;
    };
}

#endif //LINKEDHASHSET_H
