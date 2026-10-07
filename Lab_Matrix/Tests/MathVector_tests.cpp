#include "pch.h"
#include "MathVector.h"

TEST(MathVectorTest, Constructor) {
    TMathVector<int> v(3);
    EXPECT_EQ(v.size(), 3u);
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(TMathVector<int>().size(), 0u);
}

TEST(MathVectorTest, CopyAndAssignment) {
    TMathVector<int> a(2);
    a[0] = 1;
    a[1] = 2;
    TMathVector<int> b(a);
    EXPECT_TRUE(a == b);
    b[0] = 10;
    EXPECT_EQ(a[0], 1);
    TMathVector<int> c;
    c = a;
    c[1] = 20;
    EXPECT_EQ(a[1], 2);
}

TEST(MathVectorTest, Comparison) {
    TMathVector<int> a(2), b(2), c(3);
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
    b[0] = 1;
    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a == c);
}

TEST(MathVectorTest, Addition) {
    TMathVector<int> a(2), b(2);
    a[0] = 1; a[1] = 2;
    b[0] = 3; b[1] = 4;
    auto c = a + b;
    EXPECT_EQ(c[0], 4);
    EXPECT_EQ(c[1], 6);
    EXPECT_EQ(a[0], 1);
}

TEST(MathVectorTest, Subtraction) {
    TMathVector<int> a(2), b(2);
    a[0] = 1; a[1] = 2;
    b[0] = 3; b[1] = 4;
    auto c = a - b;
    EXPECT_EQ(c[0], -2);
    EXPECT_EQ(c[1], -2);
}

TEST(MathVectorTest, MultiplyByNumber) {
    TMathVector<int> a(2);
    a[0] = 1; a[1] = 2;
    auto c = a * 3;
    EXPECT_EQ(c[0], 3);
    EXPECT_EQ(c[1], 6);
}

TEST(MathVectorTest, ScalarProduct) {
    TMathVector<int> a(2), b(2);
    a[0] = 1; a[1] = 2;
    b[0] = 3; b[1] = 4;
    EXPECT_EQ(a * b, 11);
}

TEST(MathVectorTest, DifferentSizes) {
    TMathVector<int> a(2), b(3);
    EXPECT_THROW(a + b, std::invalid_argument);
    EXPECT_THROW(a - b, std::invalid_argument);
    EXPECT_THROW(a * b, std::invalid_argument);
}

TEST(MathVectorTest, EmptyVectors) {
    TMathVector<int> a, b;
    EXPECT_EQ((a + b).size(), 0u);
    EXPECT_EQ((a - b).size(), 0u);
    EXPECT_EQ(a * b, 0);
    EXPECT_EQ((a * 3).size(), 0u);
}

TEST(MathVectorTest, DoubleType) {
    TMathVector<double> a(2);
    a[0] = 1.5; a[1] = 2.5;
    auto b = a * 2.0;
    EXPECT_DOUBLE_EQ(b[0], 3.0);
    EXPECT_DOUBLE_EQ(b[1], 5.0);
    EXPECT_DOUBLE_EQ(a * a, 8.5);
}