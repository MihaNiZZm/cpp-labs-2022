#ifndef LINKEDHASHSET_H
#define LINKEDHASHSET_H

#include <cstdlib>
#include <string>

namespace LinkedHashSet {
    struct student {
        // Creates student type variable with name_ = "" and age_ = 0.
        student();
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

        // Returns hash-value of the student.
        long long hash() const;
    };

    typedef student element;

    struct node {
    private:
        node();
        node(element data);

        node* prevInserted_;
        node* nextInserted_;
        node* next_;
        element nodeValue_;

        friend class linkedhs;
    };
    
    class linkedhs {
    public:
        class iterator {
        public:
            // Creates iterator with values copied from other iterator.
            iterator(const iterator& other);
            // Creates iterator with given set and pointed node.
            iterator(node** set, node* node);

            // Returns student type value of the node iterator contains.
            element operator*();
            // Returns same value of iterator and updates this iterator: it will contain next inserted node.
            iterator operator++(int);
            // Updates this iterator: it will contain next inserted node and returns updated operator.
            iterator& operator++();
            // Returns same value of iterator and updates this iterator: it will contain previous inserted node.
            iterator operator--(int);
            // Updates this iterator: it will contain previous inserted node and returns updated operator.
            iterator& operator--();
            // Returns true if two iterators contain the same node and the same set,
            // else returns false.
            bool operator==(const iterator& other) const;
            // Returns false if two iterators contain the same node and the same set,
            // else returns true.
            bool operator!=(const iterator& other) const;

        private:
            node** set_;
            node* pointedNode_;
        };
    
        // Creates empty linkedhashset with capacity = 32.
        linkedhs();
        // Creates empty linkedhashset with given capacity.
        linkedhs(int capacity);
        
        // Deletes all linkedhashset data.
        ~linkedhs();
        
        // Creates linkedhashset with values of other linkedhashset.
        linkedhs(const linkedhs& other);
        // Changes this linkedhashset values to other linkedhashset values.
        linkedhs& operator=(const linkedhs& other);
        
        // Inserts given element in the linkedhashset.
        // Returns true if the element was inserted successfully,
        // else returns false.
        bool insert(const element& e);
        // Removes given element from the linkedhashset.
        // Returns true if the element was deleted succesfully,
        // else returns false.
        bool remove(const element& e);
        
        // Swaps all fields' vaules of two linkedhashsets.
        void swap(linkedhs& other);
        
        // Returns 
        size_t size() const;
        
        // Returns true if this linkedhashset has no elements,
        // else returns false.
        bool empty() const;
        
        // Returns true if the element 'e' exists in this linkedhashset,
        // else returns false.
        bool contains(const element& e) const;
        // If element 'e' was found in this linkedhashset,
        // returns iterator that contains node with value = 'e',
        // else returns end-iterator.
        iterator find(const element& e) const;
        
        // Returns true if this linkedhashset contains same nodes as other linkedhashset (insertion order doesn't matter),
        // else returns false.
        bool operator==(const linkedhs& other) const;
        // Returns false if this linkedhashset contains same nodes as other linkedhashset (insertion order doesn't matter),
        // else returns true.
        bool operator!=(const linkedhs& other) const;
        
        // Returns iterator that contains node that was inserted first in this linkedhashset.
        // If this linkedhashset is empty, returns iterator that contains nullptr node.
        iterator begin();
        // Returns iterator that contains nullptr.
        iterator end();
        
        // Deletes all nodes of this linkedhashset, sets size to 0.
        void clear();

    private:
        void rehash();
        void updateFullnessFactor();

        static const int RESIZE_FACTOR = 2;
        static const int DEFAULT_CAPACITY = 32;

        int numberOfNodes_;
        int size_;
        int capacity_;
        double fullnessFactor_;
        node* firstInserted_;
        node* lastInserted_;
        node** data_;
    };
}

#endif //LINKEDHASHSET_H
