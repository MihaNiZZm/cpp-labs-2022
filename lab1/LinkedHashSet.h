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

        // Returns hash-value of the student.
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
    
    // class MyStudentHasher {
    //   public:
    //     long long operator()(student & student) {

    //     }
    // };
    // MyStudentHasher()(s1)
    // Hasher()(e);
    // lhs<int>
    //template<typename T, typename Hasher = std::hash<T>>
    class linkedhs {
    public:
        class iterator {
        public:
            // Creates iterator with values copied from other iterator.
            iterator(const iterator& other) = default;
            // Creates iterator with given pointed node.
            explicit iterator(node* node);
  
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
            node* pointedNode_;
            friend class linkedhs;
        };
    
        // Creates empty linkedhashset with capacity = 32.
        linkedhs();
        
        // Deletes all linkedhashset data.
        ~linkedhs();
        
        // Creates linkedhashset with values of other linkedhashset.
        linkedhs(const linkedhs& other);
        // Changes this linkedhashset values to other linkedhashset values.
        linkedhs& operator=(const linkedhs& other);
        
        /// Inserts given element in the linkedhashset.
        /// Returns true if the element was inserted successfully,
        /// else returns false.
        bool insert(const element& e);
        // Removes given element from the linkedhashset.
        // Returns true if the element was deleted succesfully,
        // else returns false.
        bool remove(const element& e);
        
        // Swaps all fields' vaules of two linkedhashsets.
        void swap(linkedhs& other);
        
        // Returns number of nodes.
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
        iterator begin() const;
        // Returns iterator that contains nullptr.
        iterator end() const;
        
        // Deletes all nodes of this linkedhashset, sets size to 0.
        void clear();

    private:
        linkedhs(size_t capacity); 
        void rehash();
        double fullnessFactor() const;
        void redefineRelationsToRemove(node* node);
        void redefineRelationsToInsert(node* prevNode, node* nodeToInsert);
        void removeNode(node* node);
        void addNode(node* prevNode, node* nodeToInsert);

        static const int RESIZE_FACTOR = 2;
        static const int DEFAULT_CAPACITY = 8;
        static constexpr double REHASH_THRESHOLD = 0.75;

        int size_;
        // CR: rename?
        int numberOfBuckets_;
        int capacity_;
        
        node* firstInserted_;
        node* lastInserted_;
        node** data_;
    };
}

#endif //LINKEDHASHSET_H
