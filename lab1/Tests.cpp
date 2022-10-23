#include <gtest/gtest.h>
#include "LinkedHashSet.h"

using namespace LinkedHashSet;

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