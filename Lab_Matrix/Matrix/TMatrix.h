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

template <class T>
TMatrix<T>::TMatrix(size_t size) : TMathVector<TMathVector<T>>(size) {
    for (size_t i = 0; i < size; i++) {
        (*this)[i] = TMathVector<T>(size);
    }
}