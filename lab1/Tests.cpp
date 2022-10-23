#include <gtest/gtest.h>
#include "LinkedHashSet.h"

using namespace LinkedHashSet;

TEST(insert, inEmpty) {
    linkedhs set;
    student Nadya(14, "Nadya");
    ASSERT_EQ(set.insert(Nadya), true);
    ASSERT_EQ(set.size(), 1);
}

TEST(insert, inSameBucket) {
    linkedhs set;
    student Nadya1(14, "Nadya");
    student Nadya2(12, "Nadya");
    ASSERT_EQ(set.insert(Nadya1), true);
    ASSERT_EQ(set.size(), 1);
    ASSERT_EQ(set.insert(Nadya2), true);
    ASSERT_EQ(set.size(), 2);
}

TEST(insert, inDifferentBuckets) {
    linkedhs set;
    student Nadya(14, "Nadya");
    student Vanya(14, "Vanya");
    ASSERT_EQ(set.insert(Nadya), true);
    ASSERT_EQ(set.size(), 1);
    ASSERT_EQ(set.insert(Vanya), true);
    ASSERT_EQ(set.size(), 2);
}

TEST(insert, withRehash) {
    linkedhs set(1); // created set with capacity = 1.
    student Nadya(14, "Nadya");
    student Vanya(14, "Vanya");
    ASSERT_EQ(set.insert(Nadya), true);
    ASSERT_EQ(set.insert(Vanya), /* set will be resized and rehashed */ true);
}

TEST(insert, inZeroCapacitySet) {
    linkedhs set(0);
    student Nadya(14, "Nadya");
    ASSERT_EQ(set.insert(Nadya), false);
}

TEST(remove, fromZeroCapacitySet) {
    linkedhs set(0);
    student Nadya(14, "Nadya");
    ASSERT_EQ(set.remove(Nadya), false);
}

TEST(remove, fromEmpty) {
    linkedhs set;
    ASSERT_EQ(set.remove(student(15, "Vova")), false);
    ASSERT_EQ(set.size(), 0);
}

TEST(remove, exists) {
    linkedhs set;
    student Vasya(55, "Vasya");
    set.insert(Vasya);
    ASSERT_EQ(set.remove(Vasya), true);
    ASSERT_EQ(set.size(), 0);
}

TEST(remove, lastElementFromNotEmptyBucket) {
    linkedhs set;
    student Vasya1(55, "Vasya"); // ---\ Have same hash. 
    student Vasya2(23, "Vasya"); // ---/
    set.insert(Vasya1);
    set.insert(Vasya2);
    ASSERT_EQ(set.remove(Vasya2), true);
    ASSERT_EQ(set.size(), 1);
}

TEST(remove, firstElementFromNotEmptyBucket) {
    linkedhs set;
    student Vasya1(55, "Vasya"); // ---\ Have same hash. 
    student Vasya2(23, "Vasya"); // ---/
    set.insert(Vasya1);
    set.insert(Vasya2);
    ASSERT_EQ(set.remove(Vasya1), true);
    ASSERT_EQ(set.size(), 1);
}