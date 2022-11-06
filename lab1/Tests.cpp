#include <gtest/gtest.h>
#include "LinkedHashSet.h"

using namespace LinkedHashSet;

TEST(Insert, InEmpty) {
    linkedhs set;
    student n(14, "n");
    // CR: ASSERT_???
    ASSERT_TRUE(set.insert(n));
    ASSERT_EQ(set.size(), 1);
}

// CR: insert many
TEST(Insert, Many) {
    linkedhs set;
    student n1(14, "nsdf");
    student n2(2, "nsdsa");
    student n3(144, "ngbdf");
    student n4(112, "nas21");
    student n5(1412, "ngsd");
    student n6(13452, "naadsfg");
    student n7(53414, "ndgfg");
    student n8(132, "nasdf");
    student n9(1465, "ngads");
    student n10(1287, "nasdg");
    student n11(1004, "nasdbc");
    student n12(12676, "asdfn");
    student n13(1804, "asdfgn");
    student n14(9912, "bvsdfn");
    student n15(1465, "5ersn");
    student n16(127, "ngadf");

    ASSERT_EQ(set.size(), 0);
    ASSERT_TRUE(set.insert(n1));
    ASSERT_EQ(set.size(), 1);
    ASSERT_TRUE(set.insert(n2));
    ASSERT_EQ(set.size(), 2);
    ASSERT_TRUE(set.insert(n3));
    ASSERT_EQ(set.size(), 3);
    ASSERT_TRUE(set.insert(n4));
    ASSERT_EQ(set.size(), 4);
    ASSERT_TRUE(set.insert(n5));
    ASSERT_EQ(set.size(), 5);
    ASSERT_TRUE(set.insert(n6));
    ASSERT_EQ(set.size(), 6);
    ASSERT_TRUE(set.insert(n7));
    ASSERT_EQ(set.size(), 7);
    ASSERT_TRUE(set.insert(n8));
    ASSERT_EQ(set.size(), 8);
    ASSERT_TRUE(set.insert(n9));
    ASSERT_EQ(set.size(), 9);
    ASSERT_TRUE(set.insert(n10));
    ASSERT_EQ(set.size(), 10);
    ASSERT_TRUE(set.insert(n11));
    ASSERT_EQ(set.size(), 11);
    ASSERT_TRUE(set.insert(n12));
    ASSERT_EQ(set.size(), 12);
    ASSERT_TRUE(set.insert(n13));
    ASSERT_EQ(set.size(), 13);
    ASSERT_TRUE(set.insert(n14));
    ASSERT_EQ(set.size(), 14);
    ASSERT_TRUE(set.insert(n15));
    ASSERT_EQ(set.size(), 15);
    ASSERT_TRUE(set.insert(n16));
    ASSERT_EQ(set.size(), 16);
}

// CR: test for insert same element
TEST(Insert, SameElement) {
    linkedhs lhs;
    ASSERT_EQ(lhs.size(), 0);

    student n(14, "n");
    ASSERT_TRUE(lhs.insert(n));
    ASSERT_EQ(lhs.size(), 1);

    ASSERT_FALSE(lhs.insert(n));
    ASSERT_EQ(lhs.size(), 1);
}

// CR: test insert different element
TEST(Insert, Different) {
    linkedhs set;
    student n(14, "n");
    student Vova(22, "Vova");

    ASSERT_EQ(set.size(), 0);
    ASSERT_TRUE(set.insert(n));
    ASSERT_EQ(set.size(), 1);
    ASSERT_TRUE(set.insert(Vova));
    ASSERT_EQ(set.size(), 2);
}

TEST(Remove, FromEmpty) {
    linkedhs set;
    ASSERT_FALSE(set.remove(student(15, "Vova")));
    ASSERT_EQ(set.size(), 0);
}

TEST(Remove, Exists) {
    linkedhs set;
    student s1(15, "Globglobgabgalab");

    ASSERT_TRUE(set.insert(s1));
    ASSERT_EQ(set.size(), 1);
    ASSERT_TRUE(set.remove(s1));
    ASSERT_EQ(set.size(), 0);
}

TEST(Remove, LastElementFromNotEmptyBucket) {
    linkedhs set;
    student Vasya1(55, "Vasya"); // ---\ Have same hash. 
    student Vasya2(23, "Vasya"); // ---/
    set.insert(Vasya1);
    set.insert(Vasya2);
    ASSERT_TRUE(set.remove(Vasya2));
    ASSERT_EQ(set.size(), 1);
}

TEST(Remove, FirstElementFromNotEmptyBucket) {
    linkedhs set;
    student Vasya1(55, "Vasya"); // ---\ Have same hash. 
    student Vasya2(23, "Vasya"); // ---/
    set.insert(Vasya1);
    set.insert(Vasya2);
    ASSERT_TRUE(set.remove(Vasya1));
    ASSERT_EQ(set.size(), 1);
}

TEST(Ctor, Student) {
    student s1(17, "Bill");
    ASSERT_EQ(s1.age_, 17);
    ASSERT_EQ(s1.name_, "Bill");
}

TEST(Ctor, Linkedhs) {
    linkedhs lhs1;
    ASSERT_EQ(lhs1.size(), 0);
}

TEST(Iterator, OperatorDereference) {
    linkedhs lhs1 = linkedhs();
    student s1 = student(25, "Maksim");
    lhs1.insert(s1);
    linkedhs::iterator it = lhs1.begin();

    ASSERT_EQ(*it, s1);
}

TEST(Iterator, IncrementOperator) {
    linkedhs lhs1 = linkedhs();
    student s1 = student(25, "Maksim");
    student s2 = student(22, "Oleg");
    lhs1.insert(s1);
    lhs1.insert(s2);

    //prefix
    linkedhs::iterator it1 = lhs1.begin();
    ASSERT_EQ(*(++it1), s2);
    ASSERT_EQ(*it1, s2);

    //postfix
    linkedhs::iterator it2 = lhs1.begin();
    ASSERT_EQ(*(it2++), s1);
    ASSERT_EQ(*it2, s2);
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
    ASSERT_EQ(*(--it1), s1);
    ASSERT_EQ(*it1, s1);

    //postfix
    linkedhs::iterator it2 = lhs1.begin();
    ++it2;
    ASSERT_EQ(*(it2--), s2);
    ASSERT_EQ(*it2, s1);
}

TEST(Iterator, EqualOperator) {
    linkedhs lhs1 = linkedhs();
    student s1 = student(25, "Maksim");
    student s2 = student(22, "Oleg");
    lhs1.insert(s1);
    lhs1.insert(s2);

    linkedhs::iterator i1 = lhs1.begin();
    linkedhs::iterator i2 = lhs1.begin();

    ASSERT_TRUE(i1 == i2);
    ++i2;
    ASSERT_FALSE(i1 == i2);
}

TEST(Iterator, NotEqualOperator) {
    linkedhs lhs1 = linkedhs();
    student s1 = student(25, "Maksim");
    student s2 = student(22, "Oleg");
    lhs1.insert(s1);
    lhs1.insert(s2);

    linkedhs::iterator i1 = lhs1.begin();
    linkedhs::iterator i2 = lhs1.begin();

    ASSERT_FALSE(i1 != i2);
    ++i2;
    ASSERT_TRUE(i1 != i2);
}

TEST(Linkedhs, AssignmentOperator) {
    linkedhs lhs1 = linkedhs();
    linkedhs lhs2 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    lhs1.insert(s1);
    lhs2 = lhs1;
    ASSERT_TRUE(lhs1 == lhs2);
    lhs1.insert(s2);
    ASSERT_FALSE(lhs1 == lhs2);
    lhs1.remove(s2);
    lhs2.insert(s3);
    ASSERT_FALSE(lhs1 == lhs2);
}

TEST(Linkedhs, AssignmentOperatorLargeTest) {
    linkedhs lhs1 = linkedhs();
    linkedhs lhs2 = linkedhs();

    student n1(14, "nsdf");
    student n2(2, "nsdsa");
    student n3(144, "ngbdf");
    student n4(112, "nas21");
    student n5(1412, "ngsd");
    student n6(13452, "naadsfg");
    student n7(53414, "ndgfg");
    student n8(132, "nasdf");
    student n9(1465, "ngads");
    student n10(1287, "nasdg");
    student n11(1004, "nasdbc");
    student n12(12676, "asdfn");
    student n13(1804, "asdfgn");
    student n14(9912, "bvsdfn");
    student n15(1465, "5ersn");
    student n16(127, "ngadf");

    ASSERT_TRUE(lhs1.insert(n1));
    ASSERT_TRUE(lhs2.insert(n1));
    ASSERT_TRUE(lhs1 == lhs2);
    ASSERT_TRUE(lhs1.insert(n2));
    ASSERT_TRUE(lhs1.insert(n3));
    ASSERT_TRUE(lhs1.insert(n4));
    ASSERT_TRUE(lhs1.insert(n5));
    ASSERT_TRUE(lhs1.insert(n6));
    ASSERT_TRUE(lhs1.insert(n7));
    ASSERT_TRUE(lhs1.insert(n8));
    ASSERT_TRUE(lhs1.insert(n9));
    ASSERT_TRUE(lhs1.insert(n10));
    ASSERT_TRUE(lhs1.insert(n11));
    ASSERT_TRUE(lhs1.insert(n12));
    ASSERT_TRUE(lhs1.insert(n13));
    ASSERT_TRUE(lhs1.insert(n14));
    ASSERT_TRUE(lhs1.insert(n15));
    ASSERT_TRUE(lhs1.insert(n16));
    ASSERT_FALSE(lhs1 == lhs2);
    ASSERT_TRUE(lhs1.remove(n2));
    ASSERT_TRUE(lhs1.remove(n3));
    ASSERT_TRUE(lhs1.remove(n4));
    ASSERT_TRUE(lhs1.remove(n5));
    ASSERT_TRUE(lhs1.remove(n6));
    ASSERT_TRUE(lhs1.remove(n7));
    ASSERT_TRUE(lhs1.remove(n8));
    ASSERT_TRUE(lhs1.remove(n9));
    ASSERT_TRUE(lhs1.remove(n10));
    ASSERT_TRUE(lhs1.remove(n11));
    ASSERT_TRUE(lhs1.remove(n12));
    ASSERT_TRUE(lhs1.remove(n13));
    ASSERT_TRUE(lhs1.remove(n14));
    ASSERT_TRUE(lhs1.remove(n15));
    ASSERT_TRUE(lhs1.remove(n16));
    ASSERT_TRUE(lhs1 == lhs2);
    ASSERT_TRUE(lhs1.remove(n1));
    ASSERT_FALSE(lhs1 == lhs2);
}

TEST(Linkedhs, Swap) {
    linkedhs lhs1 = linkedhs();
    linkedhs lhs2 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    lhs1.insert(s1);
    lhs2.insert(s3);

    ASSERT_FALSE(lhs1.contains(s3));
    ASSERT_TRUE(lhs1.contains(s1));

    ASSERT_TRUE(lhs2.contains(s3));
    ASSERT_FALSE(lhs2.contains(s1));

    lhs1.swap(lhs2);

    ASSERT_FALSE(lhs1.contains(s1));
    ASSERT_TRUE(lhs1.contains(s3));

    ASSERT_TRUE(lhs2.contains(s1));
    ASSERT_FALSE(lhs2.contains(s3));
}

TEST(Linkedhs, Size) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    lhs1.insert(s1);
    ASSERT_EQ(lhs1.size(), 1);
    lhs1.insert(s2);
    ASSERT_EQ(lhs1.size(), 2);
    lhs1.insert(s3);
    ASSERT_EQ(lhs1.size(), 3);
    lhs1.remove(s1);
    ASSERT_EQ(lhs1.size(), 2);
}

TEST(Linkedhs, Empty) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    ASSERT_TRUE(lhs1.empty());
    lhs1.insert(s1);
    ASSERT_FALSE(lhs1.empty());
    lhs1.remove(s1);
    ASSERT_TRUE(lhs1.empty());
}

TEST(Linkedhs, Contains) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    ASSERT_FALSE(lhs1.contains(s1));
    lhs1.insert(s1);
    ASSERT_TRUE(lhs1.contains(s1));
    lhs1.remove(s1);
    ASSERT_FALSE(lhs1.contains(s1));
}

TEST(Linkedhs, Find) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    ASSERT_TRUE(lhs1.find(s1) == linkedhs::iterator(nullptr));
    lhs1.insert(s1);
    ASSERT_FALSE(lhs1.find(s1) == linkedhs::iterator(nullptr));
    ASSERT_TRUE(lhs1.find(s1) == lhs1.begin());
}

TEST(Linkedhs, EqualOperator) {
    linkedhs lhs1 = linkedhs();
    linkedhs lhs2 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    ASSERT_TRUE(lhs1 == lhs2);
    lhs1.insert(s1);
    ASSERT_FALSE(lhs1 == lhs2);
    lhs2.insert(s1);
    ASSERT_TRUE(lhs1 == lhs2);
    lhs2.insert(s2);
    ASSERT_FALSE(lhs1 == lhs2);
    lhs2.remove(s2);
    ASSERT_TRUE(lhs1 == lhs2);
    lhs1.remove(s1);
    ASSERT_FALSE(lhs1 == lhs2);
}

TEST(Linkedhs, NotEqualOperator) {
    linkedhs lhs1 = linkedhs();
    linkedhs lhs2 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    ASSERT_FALSE(lhs1 != lhs2);
    lhs1.insert(s1);
    ASSERT_TRUE(lhs1 != lhs2);
    lhs2.insert(s1);
    ASSERT_FALSE(lhs1 != lhs2);
    lhs2.insert(s2);
    ASSERT_TRUE(lhs1 != lhs2);
    lhs2.remove(s2);
    ASSERT_FALSE(lhs1 != lhs2);
    lhs1.remove(s1);
    ASSERT_TRUE(lhs1 != lhs2);
}

TEST(Linkedhs, Begin) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    ASSERT_TRUE(lhs1.begin() == linkedhs::iterator(nullptr));
    lhs1.insert(s1);
    ASSERT_TRUE(lhs1.begin() == lhs1.find(s1));
    lhs1.remove(s1);
    ASSERT_TRUE(lhs1.begin() == linkedhs::iterator(nullptr));
}

TEST(Linkedhs, End) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    ASSERT_TRUE(lhs1.end() == linkedhs::iterator(nullptr));
    lhs1.insert(s1);
    ASSERT_FALSE(lhs1.end() == lhs1.find(s1));
    ASSERT_TRUE(lhs1.end() == linkedhs::iterator(nullptr));
    lhs1.remove(s1);
    ASSERT_TRUE(lhs1.end() == linkedhs::iterator(nullptr));
}

TEST(Linkedhs, Clear) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    lhs1.insert(s1);
    ASSERT_FALSE(lhs1.empty());
    lhs1.insert(s2);
    ASSERT_FALSE(lhs1.empty());
    lhs1.insert(s3);
    ASSERT_FALSE(lhs1.empty());
    lhs1.clear();
    ASSERT_TRUE(lhs1.empty());
    ASSERT_EQ(lhs1.find(s1), lhs1.end());
    ASSERT_EQ(lhs1.find(s2), lhs1.end());
    ASSERT_EQ(lhs1.find(s3), lhs1.end());
}

TEST(Linkedhs, AssignOperatorToItself) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    lhs1 = lhs1;
    ASSERT_TRUE(lhs1.empty());
    lhs1.insert(s1);
    lhs1 = lhs1;
    ASSERT_FALSE(lhs1.empty());
    ASSERT_TRUE(lhs1.contains(s1));
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
    ASSERT_TRUE(i1 == i2);
    i2++;
    ASSERT_FALSE(i1 == i2);
    i1++;
    ASSERT_TRUE(i1 == i2);
    i2--;
    ASSERT_FALSE(i1 == i2);
    i1--;
    ASSERT_TRUE(i1 == i2);
}

TEST(Copyctor, Linkedhs) {
    linkedhs lhs1 = linkedhs();

    student s1 = student(18, "Vadim");
    student s2 = student(28, "Artem");
    student s3 = student(18, "Kolya");

    lhs1.insert(s1);
    linkedhs lhs2(lhs1);
    ASSERT_TRUE(lhs1 == lhs2);
    lhs1.insert(s2);
    ASSERT_FALSE(lhs1 == lhs2);
    lhs1.remove(s2);
    ASSERT_TRUE(lhs1 == lhs2);
    lhs2.insert(s2);
    ASSERT_FALSE(lhs1 == lhs2);
    lhs2.remove(s2);
    ASSERT_TRUE(lhs1 == lhs2);
}