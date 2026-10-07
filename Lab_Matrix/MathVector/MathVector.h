#pragma once
#include "TVector.h"

template <class T>
class TMathVector : public TVector<T> {
public:
    TMathVector(size_t size = 0);

    bool operator==(const TMathVector& other) const;
    bool operator!=(const TMathVector& other) const;
    TMathVector operator+(const TMathVector& other) const;
    TMathVector operator-(const TMathVector& other) const;
    TMathVector operator*(T number) const;
    T operator*(const TMathVector& other) const;
};

template <class T>
TMathVector<T>::TMathVector(size_t size) : TVector<T>(size) {
}

template <class T>
bool TMathVector<T>::operator==(const TMathVector& other) const {
    if (this->size() != other.size()) {
        return false;
    }
    for (size_t i = 0; i < this->size(); i++) {
        if ((*this)[i] != other[i]) {
            return false;
        }
    }
    return true;
}

template <class T>
bool TMathVector<T>::operator!=(const TMathVector& other) const {
    return !(*this == other);
}

template <class T>
TMathVector<T> TMathVector<T>::operator+(const TMathVector& other) const {
    if (this->size() != other.size()) {
        throw std::invalid_argument("Different sizes");
    }
    TMathVector result(this->size());
    for (size_t i = 0; i < this->size(); i++) {
        result[i] = (*this)[i] + other[i];
    }
    return result;
}

template <class T>
TMathVector<T> TMathVector<T>::operator-(const TMathVector& other) const {
    if (this->size() != other.size()) {
        throw std::invalid_argument("Different sizes");
    }
    TMathVector result(this->size());
    for (size_t i = 0; i < this->size(); i++) {
        result[i] = (*this)[i] - other[i];
    }
    return result;
}

template <class T>
TMathVector<T> TMathVector<T>::operator*(T number) const {
    TMathVector result(this->size());
    for (size_t i = 0; i < this->size(); i++) {
        result[i] = (*this)[i] * number;
    }
    return result;
}

template <class T>
T TMathVector<T>::operator*(const TMathVector& other) const {
    if (this->size() != other.size()) {
        throw std::invalid_argument("Different sizes");
    }
    T result = T();
    for (size_t i = 0; i < this->size(); i++) {
        result += (*this)[i] * other[i];
    }
    return result;
}