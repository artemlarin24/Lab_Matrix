#include "pch.h"
#include "TMatrix.h"

TEST(MatrixInheritedTest, SizeAndIndex) {
    TMatrix<int> a(2);
    EXPECT_EQ(a.size(), 2u);
    EXPECT_EQ(a.capacity(), 2u);
    EXPECT_EQ(a[0].size(), 2u);
    EXPECT_EQ(a[1].size(), 2u);
    EXPECT_EQ(a[0][0], 0);
    a[1][0] = 7;
    EXPECT_EQ(a[1][0], 7);
    const TMatrix<int>& ca = a;
    EXPECT_EQ(ca[1][0], 7);
}

TEST(MatrixInheritedTest, CopyAndAssignment) {
    TMatrix<int> a(2);
    a[0][0] = 1;
    a[1][1] = 2;
    TMatrix<int> b(a);
    EXPECT_TRUE(a == b);
    b[0][0] = 10;
    EXPECT_EQ(a[0][0], 1);
    TMatrix<int> c(1);
    c = a;
    c[1][1] = 20;
    EXPECT_EQ(c.size(), 2u);
    EXPECT_EQ(a[1][1], 2);
}

TEST(MatrixInheritedTest, Comparison) {
    TMatrix<int> a(2), b(2), c(3);
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
    b[0][0] = 1;
    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a == c);
}

TEST(MatrixInheritedTest, ReserveAndShrink) {
    TMatrix<int> a(2);
    a[1][1] = 7;
    a.reserve(5);
    EXPECT_EQ(a.size(), 2u);
    EXPECT_EQ(a.capacity(), 5u);
    a.shrink_to_fit();
    EXPECT_EQ(a.capacity(), 2u);
    EXPECT_EQ(a[1][1], 7);
}

TEST(MatrixInheritedTest, Iterator) {
    TMatrix<int> a(2);
    (*a.begin())[0] = 10;
    const TMatrix<int>& ca = a;
    EXPECT_EQ((*ca.begin())[0], 10);
    EXPECT_TRUE(ca.begin() + 2 == ca.end());
}

TEST(MatrixInheritedTest, EmptyAndWrongIndex) {
    TMatrix<int> empty;
    EXPECT_EQ(empty.size(), 0u);
    EXPECT_TRUE(empty.begin() == empty.end());
    TMatrix<int> a(2);
    EXPECT_THROW(a[2], std::out_of_range);
    const TMatrix<int>& ca = a;
    EXPECT_THROW(ca[0][2], std::out_of_range);
}