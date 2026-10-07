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