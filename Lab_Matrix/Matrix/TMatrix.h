#pragma once

#include "MathVector.h"

template <class T>
class TMatrix : public TMathVector<TMathVector<T>> {
public:
    TMatrix(size_t size = 0);

    TMatrix operator+(const TMatrix& other) const;
    TMatrix operator-(const TMatrix& other) const;
    TMatrix operator*(const TMatrix& other) const;
};