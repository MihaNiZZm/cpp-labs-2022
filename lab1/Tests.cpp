#include <gtest/gtest.h>
#include "LinkedHashSet.h"

using namespace LinkedHashSet;

TEST(insert, inEmpty) {
    linkedhs set;
    student Nadya(14, "Nadya");
    // CR: ASSERT_???
    EXPECT_EQ(set.insert(Nadya), true);
    EXPECT_EQ(set.size(), 1);
}

// CR: remove
TEST(insert, inSameBucket) {
    linkedhs set;
    student Nadya1(14, "Nadya");
    student Nadya2(12, "Nadya");
    EXPECT_EQ(set.insert(Nadya1), true);
    EXPECT_EQ(set.size(), 1);
    EXPECT_EQ(set.insert(Nadya2), true);
    EXPECT_EQ(set.size(), 2);
}
// CR: remove
TEST(insert, inDifferentBuckets) {
    linkedhs set;
    student Nadya(14, "Nadya");
    student Vanya(14, "Vanya");
    EXPECT_EQ(set.insert(Nadya), true);
    EXPECT_EQ(set.size(), 1);
    EXPECT_EQ(set.insert(Vanya), true);
    EXPECT_EQ(set.size(), 2);
}

// CR: insert many
TEST(insert, withRehash) {
    linkedhs set(1); // created set with capacity = 1.
    student Nadya(14, "Nadya");
    student Vanya(14, "Vanya");
    EXPECT_EQ(set.insert(Nadya), true);
    EXPECT_EQ(set.insert(Vanya), /* set will be resized and rehashed */ true);
}

TEST(insert, inZeroCapacitySet) {
    linkedhs set(0);
    student Nadya(14, "Nadya");
    EXPECT_EQ(set.insert(Nadya), false);
}

// CR: test for insert same element
TEST(Insert, SameElement) {
    linkedhs lhs;
    ASSSERT_EQ(lhs.size(), 0);

    student Nadya(14, "Nadya");
    ASSERT_EQ(lhs.insert(Nadya), true);
    ASSSERT_EQ(lhs.size(), 1);

    ASSERT_EQ(lhs.insert(Nadya), false);
    ASSSERT_EQ(lhs.size(), 1);
}
// CR: test insert different element

TEST(remove, fromZeroCapacitySet) {
    linkedhs set(0);
    student Nadya(14, "Nadya");
    EXPECT_EQ(set.remove(Nadya), false);
}

TEST(remove, fromEmpty) {
    linkedhs set;
    EXPECT_EQ(set.remove(student(15, "Vova")), false);
    EXPECT_EQ(set.size(), 0);
}

TEST(remove, exists) {
    linkedhs set;
    student Vasya(55, "Vasya");
    set.insert(Vasya);
    EXPECT_EQ(set.remove(Vasya), true);
    EXPECT_EQ(set.size(), 0);
}

TEST(remove, lastElementFromNotEmptyBucket) {
    linkedhs set;
    student Vasya1(55, "Vasya"); // ---\ Have same hash. 
    student Vasya2(23, "Vasya"); // ---/
    set.insert(Vasya1);
    set.insert(Vasya2);
    EXPECT_EQ(set.remove(Vasya2), true);
    EXPECT_EQ(set.size(), 1);
}

TEST(remove, firstElementFromNotEmptyBucket) {
    linkedhs set;
    student Vasya1(55, "Vasya"); // ---\ Have same hash. 
    student Vasya2(23, "Vasya"); // ---/
    set.insert(Vasya1);
    set.insert(Vasya2);
    EXPECT_EQ(set.remove(Vasya1), true);
    EXPECT_EQ(set.size(), 1);
}

TEST(ctor, studentEmpty) {
    student s1 = student();
    EXPECT_EQ(s1.age_, 0);
    EXPECT_EQ(s1.name_, "");
}

TEST(ctor, studentWithParams) {
    student s1 = student(17, "Bill");
    EXPECT_EQ(s1.age_, 17);
    EXPECT_EQ(s1.name_, "Bill");
}

TEST(ctor, linkedhs) {
    linkedhs lhs1 = linkedhs();
    EXPECT_EQ(lhs1.size(), 0);

    linkedhs lhs2 = linkedhs(1234);
    EXPECT_EQ(lhs1.size(), 0);
}

TEST(iterator, operatorDereference) {
    linkedhs lhs1 = linkedhs();
    student s1 = student(25, "Maksim");
    lhs1.insert(s1);
    linkedhs::iterator it = lhs1.begin();

    EXPECT_EQ(*it, s1);
}

TEST(iterator, incrementOperator) {
    linkedhs lhs1 = linkedhs();
    student s1 = student(25, "Maksim");
    student s2 = student(22, "Oleg");
    lhs1.insert(s1);
    lhs1.insert(s2);

    //prefix
    linkedhs::iterator it1 = lhs1.begin();
    EXPECT_EQ(*(++it1), s2);
    EXPECT_EQ(*it1, s2);

    //postfix
    linkedhs::iterator it2 = lhs1.begin();
    EXPECT_EQ(*(it2++), s1);
    EXPECT_EQ(*it2, s2);
}

TEST(iterator, decrementOperator) {
    linkedhs lhs1 = linkedhs();
    student s1 = student(25, "Maksim");
    student s2 = student(22, "Oleg");
    lhs1.insert(s1);
    lhs1.insert(s2);

    //prefix
    linkedhs::iterator it1 = lhs1.begin();
    ++it1;
    EXPECT_EQ(*(--it1), s1);
    EXPECT_EQ(*it1, s1);

    //postfix
    linkedhs::iterator it2 = lhs1.begin();
    ++it2;
    EXPECT_EQ(*(it2--), s2);
    EXPECT_EQ(*it2, s1);
}

TEST(iterator, equalOperator) {
    linkedhs lhs1 = linkedhs();
    student s1 = student(25, "Maksim");
    student s2 = student(22, "Oleg");
    lhs1.insert(s1);
    lhs1.insert(s2);

    linkedhs::iterator i1 = lhs1.begin();
    linkedhs::iterator i2 = lhs1.begin();

    EXPECT_EQ((i1 == i2), true);
    ++i2;
    EXPECT_EQ((i1 == i2), false);
}

TEST(iterator, notEqualOperator) {
    linkedhs lhs1 = linkedhs();
    student s1 = student(25, "Maksim");
    student s2 = student(22, "Oleg");
    lhs1.insert(s1);
    lhs1.insert(s2);

    linkedhs::iterator i1 = lhs1.begin();
    linkedhs::iterator i2 = lhs1.begin();

    EXPECT_EQ((i1 != i2), false);
    ++i2;
    EXPECT_EQ((i1 != i2), true);
}

TEST(linkedhs, assignmentOperator) {
    linkedhs lhs1 = linkedhs();
    linkedhs lhs2 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    lhs1.insert(s1);
    lhs2 = lhs1;
    EXPECT_EQ(lhs1, lhs2);
    lhs1.insert(s2);
    EXPECT_EQ((lhs1 == lhs2), false);
    lhs1.remove(s2);
    lhs2.insert(s3);
    EXPECT_EQ((lhs1 == lhs2), false);
}

TEST(linkedhs, swap) {
    linkedhs lhs1 = linkedhs();
    linkedhs lhs2 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    lhs1.insert(s1);
    lhs2.insert(s3);

    lhs1.swap(lhs2);

    EXPECT_EQ(lhs1.contains(s1), false);
    EXPECT_EQ(lhs1.contains(s3), true);

    EXPECT_EQ(lhs2.contains(s1), true);
    EXPECT_EQ(lhs2.contains(s3), false);
}

TEST(linkedhs, size) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    lhs1.insert(s1);
    EXPECT_EQ(lhs1.size(), 1);
    lhs1.insert(s2);
    EXPECT_EQ(lhs1.size(), 2);
    lhs1.insert(s3);
    EXPECT_EQ(lhs1.size(), 3);
    lhs1.remove(s1);
    EXPECT_EQ(lhs1.size(), 2);
}

TEST(linkedhs, empty) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    EXPECT_EQ(lhs1.empty(), true);
    lhs1.insert(s1);
    EXPECT_EQ(lhs1.empty(), false);
    lhs1.remove(s1);
    EXPECT_EQ(lhs1.empty(), true);
}

TEST(linkedhs, contains) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    EXPECT_EQ(lhs1.contains(s1), false);
    lhs1.insert(s1);
    EXPECT_EQ(lhs1.contains(s1), true);
    lhs1.remove(s1);
    EXPECT_EQ(lhs1.contains(s1), false);
}

TEST(linkedhs, find) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    EXPECT_EQ((lhs1.find(s1) == linkedhs::iterator(nullptr)), true);
    lhs1.insert(s1);
    EXPECT_EQ((lhs1.find(s1) == linkedhs::iterator(nullptr)), false);
    EXPECT_EQ((lhs1.find(s1) == lhs1.begin()), true);
}

TEST(linkedhs, equalOperator) {
    linkedhs lhs1 = linkedhs();
    linkedhs lhs2 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    EXPECT_EQ((lhs1 == lhs2), true);
    lhs1.insert(s1);
    EXPECT_EQ((lhs1 == lhs2), false);
    lhs2.insert(s1);
    EXPECT_EQ((lhs1 == lhs2), true);
    lhs2.insert(s2);
    EXPECT_EQ((lhs1 == lhs2), false);
    lhs2.remove(s2);
    EXPECT_EQ((lhs1 == lhs2), true);
    lhs1.remove(s1);
    EXPECT_EQ((lhs1 == lhs2), false);
}

TEST(linkedhs, notEqualOperator) {
    linkedhs lhs1 = linkedhs();
    linkedhs lhs2 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    EXPECT_EQ((lhs1 != lhs2), false);
    lhs1.insert(s1);
    EXPECT_EQ((lhs1 != lhs2), true);
    lhs2.insert(s1);
    EXPECT_EQ((lhs1 != lhs2), false);
    lhs2.insert(s2);
    EXPECT_EQ((lhs1 != lhs2), true);
    lhs2.remove(s2);
    EXPECT_EQ((lhs1 != lhs2), false);
    lhs1.remove(s1);
    EXPECT_EQ((lhs1 != lhs2), true);
}

TEST(linkedhs, begin) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    EXPECT_EQ((lhs1.begin() == linkedhs::iterator(nullptr)), true);
    lhs1.insert(s1);
    EXPECT_EQ((lhs1.begin() == lhs1.find(s1)), true);
    lhs1.remove(s1);
    EXPECT_EQ((lhs1.begin() == linkedhs::iterator(nullptr)), true);
}

TEST(linkedhs, end) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    EXPECT_EQ((lhs1.end() == linkedhs::iterator(nullptr)), true);
    lhs1.insert(s1);
    EXPECT_EQ((lhs1.end() == lhs1.find(s1)), false);
    EXPECT_EQ((lhs1.end() == linkedhs::iterator(nullptr)), true);
    lhs1.remove(s1);
    EXPECT_EQ((lhs1.end() == linkedhs::iterator(nullptr)), true);
}

TEST(linkedhs, clear) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    lhs1.insert(s1);
    EXPECT_EQ(lhs1.empty(), false);
    lhs1.insert(s2);
    EXPECT_EQ(lhs1.empty(), false);
    lhs1.insert(s3);
    EXPECT_EQ(lhs1.empty(), false);
    lhs1.clear();
    EXPECT_EQ(lhs1.empty(), true);
}

TEST(linkedhs, assignOperatorToItself) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    lhs1 = lhs1;
    EXPECT_EQ(lhs1.empty(), true);
    lhs1.insert(s1);
    lhs1 = lhs1;
    EXPECT_EQ(lhs1.empty(), false);
    EXPECT_EQ(lhs1.contains(s1), true);
}

TEST(copyctor, iterator) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    lhs1.insert(s1);
    lhs1.insert(s2);
    lhs1.insert(s3);
    linkedhs::iterator i1 = lhs1.begin();
    linkedhs::iterator i2(i1);
    EXPECT_EQ((i1 == i2), true);
    i2++;
    EXPECT_EQ((i1 == i2), false);
    i1++;
    EXPECT_EQ((i1 == i2), true);
    i2--;
    EXPECT_EQ((i1 == i2), false);
    i1--;
    EXPECT_EQ((i1 == i2), true);
}

TEST(copyctor, linkedhs) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    lhs1.insert(s1);
    linkedhs lhs2(lhs1);
    EXPECT_EQ((lhs1 == lhs2), true);
    lhs1.insert(s2);
    EXPECT_EQ((lhs1 == lhs2), false);
    lhs1.remove(s2);
    EXPECT_EQ((lhs1 == lhs2), true);
    lhs2.insert(s2);
    EXPECT_EQ((lhs1 == lhs2), false);
    lhs2.remove(s2);
    EXPECT_EQ((lhs1 == lhs2), true);
}