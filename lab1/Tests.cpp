#include <gtest/gtest.h>
#include "LinkedHashSet.h"

using namespace LinkedHashSet;

TEST(Insert, InEmpty) {
    linkedhs set;
    student Nadya(14, "Nadya");
    // CR: ASSERT_???
    ASSERT_EQ(set.insert(Nadya), true);
    ASSERT_EQ(set.size(), 1);
}

// CR: insert many
TEST(Insert, Many) {
    linkedhs set;
    student Nadya1(14, "Nadya");
    student Nadya2(2, "Nadya");
    student Nadya3(144, "Nadya");
    student Nadya4(112, "Nadya");
    student Nadya5(1412, "Nadya");
    student Nadya6(13452, "Nadya");
    student Nadya7(53414, "Nadya");
    student Nadya8(132, "Nadya");
    student Nadya9(1465, "Nadya");
    student Nadya10(1287, "Nadya");
    student Nadya11(1004, "Nadya");
    student Nadya12(12676, "Nadya");
    student Nadya13(1804, "Nadya");
    student Nadya14(9912, "Nadya");
    student Nadya15(1465, "Nadya");
    student Nadya16(127, "Nadya");

    ASSERT_EQ(set.size(), 0);
    ASSERT_TRUE(set.insert(Nadya1));
    ASSERT_EQ(set.size(), 1);
    ASSERT_TRUE(set.insert(Nadya2));
    ASSERT_EQ(set.size(), 2);
    ASSERT_TRUE(set.insert(Nadya3));
    ASSERT_EQ(set.size(), 3);
    ASSERT_TRUE(set.insert(Nadya4));
    ASSERT_EQ(set.size(), 4);
    ASSERT_TRUE(set.insert(Nadya5));
    ASSERT_EQ(set.size(), 5);
    ASSERT_TRUE(set.insert(Nadya6));
    ASSERT_EQ(set.size(), 6);
    ASSERT_TRUE(set.insert(Nadya7));
    ASSERT_EQ(set.size(), 7);
    ASSERT_TRUE(set.insert(Nadya8));
    ASSERT_EQ(set.size(), 8);
    ASSERT_TRUE(set.insert(Nadya9));
    ASSERT_EQ(set.size(), 9);
    ASSERT_TRUE(set.insert(Nadya10));
    ASSERT_EQ(set.size(), 10);
    ASSERT_TRUE(set.insert(Nadya11));
    ASSERT_EQ(set.size(), 11);
    ASSERT_TRUE(set.insert(Nadya12));
    ASSERT_EQ(set.size(), 12);
    ASSERT_TRUE(set.insert(Nadya13));
    ASSERT_EQ(set.size(), 13);
    ASSERT_TRUE(set.insert(Nadya14));
    ASSERT_EQ(set.size(), 14);
    ASSERT_TRUE(set.insert(Nadya15));
    ASSERT_EQ(set.size(), 15);
    ASSERT_TRUE(set.insert(Nadya16));
    ASSERT_EQ(set.size(), 16);
}   

// CR: test for insert same element
TEST(Insert, SameElement) {
    linkedhs lhs;
    ASSERT_EQ(lhs.size(), 0);

    student Nadya(14, "Nadya");
    ASSERT_EQ(lhs.insert(Nadya), true);
    ASSERT_EQ(lhs.size(), 1);

    ASSERT_EQ(lhs.insert(Nadya), false);
    ASSERT_EQ(lhs.size(), 1);
}

// CR: test insert different element
TEST(Insert, Different) {
    linkedhs set;
    student Nadya(14, "Nadya");
    student Vova(22, "Vova");

    ASSERT_EQ(set.size(), 0);
    ASSERT_TRUE(set.insert(Nadya));
    ASSERT_EQ(set.size(), 1);
    ASSERT_TRUE(set.insert(Vova));
    ASSERT_EQ(set.size(), 2);
}

TEST(Remove, FromEmpty) {
    linkedhs set;
    EXPECT_EQ(set.remove(student(15, "Vova")), false);
    EXPECT_EQ(set.size(), 0);
}

TEST(Remove, Exists) {
    linkedhs set;
    student Vasya(55, "Vasya");
    set.insert(Vasya);
    EXPECT_EQ(set.remove(Vasya), true);
    EXPECT_EQ(set.size(), 0);
}

TEST(Remove, LastElementFromNotEmptyBucket) {
    linkedhs set;
    student Vasya1(55, "Vasya"); // ---\ Have same hash. 
    student Vasya2(23, "Vasya"); // ---/
    set.insert(Vasya1);
    set.insert(Vasya2);
    EXPECT_EQ(set.remove(Vasya2), true);
    EXPECT_EQ(set.size(), 1);
}

TEST(Remove, FirstElementFromNotEmptyBucket) {
    linkedhs set;
    student Vasya1(55, "Vasya"); // ---\ Have same hash. 
    student Vasya2(23, "Vasya"); // ---/
    set.insert(Vasya1);
    set.insert(Vasya2);
    EXPECT_EQ(set.remove(Vasya1), true);
    EXPECT_EQ(set.size(), 1);
}

TEST(Ctor, StudentWithParams) {
    student s1 = student(17, "Bill");
    EXPECT_EQ(s1.age_, 17);
    EXPECT_EQ(s1.name_, "Bill");
}

TEST(Ctor, Linkedhs) {
    linkedhs lhs1 = linkedhs();
    EXPECT_EQ(lhs1.size(), 0);
}

TEST(Iterator, OperatorDereference) {
    linkedhs lhs1 = linkedhs();
    student s1 = student(25, "Maksim");
    lhs1.insert(s1);
    linkedhs::iterator it = lhs1.begin();

    EXPECT_EQ(*it, s1);
}

TEST(Iterator, IncrementOperator) {
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

TEST(Iterator, DecrementOperator) {
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

TEST(Iterator, EqualOperator) {
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

TEST(Iterator, NotEqualOperator) {
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

TEST(Linkedhs, AssignmentOperator) {
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

TEST(Linkedhs, Swap) {
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

TEST(Linkedhs, Size) {
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

TEST(Linkedhs, Empty) {
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

TEST(Linkedhs, Contains) {
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

TEST(Linkedhs, Find) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    EXPECT_EQ((lhs1.find(s1) == linkedhs::iterator(nullptr)), true);
    lhs1.insert(s1);
    EXPECT_EQ((lhs1.find(s1) == linkedhs::iterator(nullptr)), false);
    EXPECT_EQ((lhs1.find(s1) == lhs1.begin()), true);
}

TEST(Linkedhs, EqualOperator) {
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

TEST(Linkedhs, NotEqualOperator) {
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

TEST(Linkedhs, Begin) {
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

TEST(Linkedhs, End) {
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

TEST(Linkedhs, Clear) {
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

TEST(Linkedhs, AssignOperatorToItself) {
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

TEST(Copyctor, Iterator) {
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

TEST(Copyctor, Linkedhs) {
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