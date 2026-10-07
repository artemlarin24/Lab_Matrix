#include "pch.h"
#include "TMatrix.h"

TEST(MatrixTest, AdditionAndSubtraction) {
    TMatrix<int> a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;
    auto c = a + b;
    EXPECT_EQ(c[0][0], 6);
    EXPECT_EQ(c[0][1], 8);
    EXPECT_EQ(c[1][0], 10);
    EXPECT_EQ(c[1][1], 12);
    c = a - b;
    EXPECT_EQ(c[0][0], -4);
    EXPECT_EQ(c[0][1], -4);
    EXPECT_EQ(c[1][0], -4);
    EXPECT_EQ(c[1][1], -4);
}

TEST(MatrixTest, Multiplication) {
    TMatrix<int> a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;
    auto c = a * b;
    EXPECT_EQ(c[0][0], 19);
    EXPECT_EQ(c[0][1], 22);
    EXPECT_EQ(c[1][0], 43);
    EXPECT_EQ(c[1][1], 50);
    EXPECT_EQ(a[0][0], 1);
    EXPECT_EQ(b[1][1], 8);
}

TEST(MatrixTest, IdentityMatrix) {
    TMatrix<int> a(2), identity(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;
    identity[0][0] = 1;
    identity[1][1] = 1;
    EXPECT_TRUE(a * identity == a);
    EXPECT_TRUE(identity * a == a);
}

TEST(MatrixTest, DifferentSizes) {
    TMatrix<int> a(2), b(3);
    EXPECT_THROW(a + b, std::invalid_argument);
    EXPECT_THROW(a - b, std::invalid_argument);
    EXPECT_THROW(a * b, std::invalid_argument);
}

TEST(MatrixTest, EmptyMatrices) {
    TMatrix<int> a, b;
    EXPECT_EQ((a + b).size(), 0u);
    EXPECT_EQ((a - b).size(), 0u);
    EXPECT_EQ((a * b).size(), 0u);
}

TEST(MatrixTest, DoubleType) {
    TMatrix<double> a(1);
    a[0][0] = 1.5;
    auto b = a * a;
    EXPECT_DOUBLE_EQ(b[0][0], 2.25);
}