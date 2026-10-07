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

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix& other) const {
    if (this->size() != other.size()) {
        throw std::invalid_argument("Different sizes");
    }
    TMatrix result(this->size());
    for (size_t i = 0; i < this->size(); i++) {
        result[i] = (*this)[i] + other[i];
    }
    return result;
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix& other) const {
    if (this->size() != other.size()) {
        throw std::invalid_argument("Different sizes");
    }
    TMatrix result(this->size());
    for (size_t i = 0; i < this->size(); i++) {
        result[i] = (*this)[i] - other[i];
    }
    return result;
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix& other) const {
    if (this->size() != other.size()) {
        throw std::invalid_argument("Different sizes");
    }
    size_t size = this->size();
    TMatrix result(size);
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            for (size_t k = 0; k < size; k++) {
                result[i][j] += (*this)[i][k] * other[k][j];
            }
        }
    }
    return result;
}