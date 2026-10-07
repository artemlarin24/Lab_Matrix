#include "pch.h"
#include "TVector.h"
#include <type_traits>

TEST(TVectorTest, EmptyVector) {
    TVector<int> v;
    EXPECT_TRUE(v.begin() == v.end());
    const TVector<int>& cv = v;
    EXPECT_TRUE(cv.begin() == cv.end());
}

TEST(TVectorTest, IndexAndCopy) {
    TVector<int> a(2);
    a[0] = 10;
    a[1] = 20;
    TVector<int> b(a);
    b[0] = 30;
    EXPECT_EQ(a[0], 10);
    TVector<int> c;
    c = a;
    c[1] = 40;
    EXPECT_EQ(a[1], 20);
    a = a;
    EXPECT_EQ(a[0], 10);
    const TVector<int>& ca = a;
    EXPECT_EQ(ca[1], 20);
    EXPECT_THROW(a[2], std::out_of_range);
    EXPECT_THROW(ca[2], std::out_of_range);
}

TEST(IteratorTest, Constructors) {
    TVector<int>::iterator a;
    TVector<int>::iterator b;
    EXPECT_TRUE(a == b);
    int data[2] = { 10, 20 };
    TVector<int>::iterator it(data);
    EXPECT_EQ(*it, 10);
    TVector<int>::iterator copy(it);
    EXPECT_TRUE(copy == it);
    EXPECT_EQ(&(a = it), &a);
    EXPECT_EQ(*a, 10);
    ++copy;
    EXPECT_TRUE(copy != it);
}

TEST(IteratorTest, Comparison) {
    TVector<int> v(2);
    EXPECT_TRUE(v.begin() == v.begin());
    EXPECT_FALSE(v.begin() != v.begin());
    EXPECT_TRUE(v.begin() != v.end());
    EXPECT_FALSE(v.begin() == v.end());
}

TEST(IteratorTest, Increment) {
    TVector<int> v(3);
    v[0] = 10;
    v[1] = 20;
    v[2] = 30;
    auto it = v.begin();
    EXPECT_EQ(&(++it), &it);
    EXPECT_EQ(*it, 20);
    auto old = it++;
    EXPECT_EQ(*old, 20);
    EXPECT_EQ(*it, 30);
}

TEST(IteratorTest, Decrement) {
    TVector<int> v(3);
    v[0] = 10;
    v[1] = 20;
    v[2] = 30;
    auto it = v.end();
    auto old = it--;
    EXPECT_TRUE(old == v.end());
    EXPECT_EQ(*it, 30);
    EXPECT_EQ(&(--it), &it);
    EXPECT_EQ(*it, 20);
}

TEST(IteratorTest, Arithmetic) {
    TVector<int> v(4);
    for (int i = 0; i < 4; i++) v[i] = i + 1;
    auto it = v.begin();
    EXPECT_EQ(*(it + 2), 3);
    EXPECT_EQ(*it, 1);
    it += 3;
    EXPECT_EQ(*it, 4);
    EXPECT_EQ(*(it - 2), 2);
    EXPECT_EQ(*it, 4);
    it -= 2;
    EXPECT_EQ(*it, 2);
    it += -1;
    EXPECT_TRUE(it == v.begin());
}

TEST(IteratorTest, Dereference) {
    TVector<int> v(1);
    auto it = v.begin();
    *it = 10;
    EXPECT_EQ(v[0], 10);
    const TVector<int>::iterator fixed = it;
    EXPECT_EQ(*fixed, 10);
    static_assert(std::is_same<decltype(*it), int&>::value, "Mutable iterator");
}

TEST(ConstIteratorTest, Constructors) {
    TVector<int>::const_iterator a;
    TVector<int>::const_iterator b;
    EXPECT_TRUE(a == b);
    const int data[2] = { 10, 20 };
    TVector<int>::const_iterator it(data);
    TVector<int>::const_iterator copy(it);
    a = it;
    EXPECT_TRUE(a == copy);
    EXPECT_EQ(*a, 10);
}

TEST(ConstIteratorTest, Operations) {
    TVector<int> v(4);
    for (int i = 0; i < 4; i++) v[i] = i + 1;
    const TVector<int>& cv = v;
    auto it = cv.begin();
    EXPECT_TRUE(it != cv.end());
    EXPECT_FALSE(it == cv.end());
    EXPECT_EQ(*it, 1);
    const TVector<int>::const_iterator fixed = it;
    EXPECT_EQ(*fixed, 1);
    auto old = it++;
    EXPECT_EQ(*old, 1);
    EXPECT_EQ(*it, 2);
    EXPECT_EQ(&(++it), &it);
    EXPECT_EQ(*it, 3);
    old = it--;
    EXPECT_EQ(*old, 3);
    EXPECT_EQ(*it, 2);
    EXPECT_EQ(&(--it), &it);
    EXPECT_EQ(*it, 1);
    EXPECT_EQ(*(it + 3), 4);
    it += 3;
    EXPECT_EQ(*(it - 2), 2);
    it -= 2;
    EXPECT_EQ(*it, 2);
    static_assert(std::is_same<decltype(*it), const int&>::value, "Const iterator");
}

TEST(IteratorTest, FillVector) {
    TVector<int> v(8);
    int val = 1;
    for (auto it = v.begin(); it != v.end(); it++) *it = val++;
    const TVector<int>& cv = v;
    val = 1;
    for (auto it = cv.begin(); it != cv.end(); ++it) EXPECT_EQ(*it, val++);
    EXPECT_EQ(val, 9);
}

TEST(IteratorTest, DoubleType) {
    TVector<double> v(2);
    *v.begin() = 1.5;
    *(v.begin() + 1) = 2.5;
    EXPECT_DOUBLE_EQ(v[0], 1.5);
    EXPECT_DOUBLE_EQ(v[1], 2.5);
}