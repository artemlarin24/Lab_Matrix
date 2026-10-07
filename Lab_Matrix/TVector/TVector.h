#pragma once
#include <cstddef>
#include <stdexcept>

using std::size_t;

template <class T>
class TVector {
    T* _data;
    size_t _size;

public:
    TVector(size_t size = 0) {
        _size = size;
        _data = new T[_size]();
    }

    TVector(const TVector& other) {
        _size = other._size;
        _data = new T[_size]();
        for (size_t i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }

    ~TVector() {
        delete[] _data;
    }

    TVector& operator=(const TVector& other) {
        if (this == &other) {
            return *this;
        }
        T* data = new T[other._size]();
        for (size_t i = 0; i < other._size; i++) {
            data[i] = other._data[i];
        }
        delete[] _data;
        _data = data;
        _size = other._size;
        return *this;
    }

    T& operator[](size_t pos) {
        if (pos >= _size) {
            throw std::out_of_range("Wrong index");
        }
        return _data[pos];
    }

    const T& operator[](size_t pos) const {
        if (pos >= _size) {
            throw std::out_of_range("Wrong index");
        }
        return _data[pos];
    }

    template <class Type>
    class Iterator {
        Type* p_cur;

    public:
        Iterator() {
            p_cur = nullptr;
        }

        Iterator(Type* ptr) {
            p_cur = ptr;
        }

        Iterator(const Iterator& other) {
            p_cur = other.p_cur;
        }

        Iterator& operator=(const Iterator& other) noexcept {
            p_cur = other.p_cur;
            return *this;
        }

        bool operator==(const Iterator& other) const noexcept {
            return p_cur == other.p_cur;
        }

        bool operator!=(const Iterator& other) const noexcept {
            return p_cur != other.p_cur;
        }

        Iterator& operator++() {
            ++p_cur;
            return *this;
        }

        Iterator operator++(int) {
            Iterator old = *this;
            ++p_cur;
            return old;
        }

        Iterator& operator--() {
            --p_cur;
            return *this;
        }

        Iterator operator--(int) {
            Iterator old = *this;
            --p_cur;
            return old;
        }

        Iterator operator+(int n) const {
            return Iterator(p_cur + n);
        }

        Iterator operator-(int n) const {
            return Iterator(p_cur - n);
        }

        Iterator& operator+=(int n) {
            p_cur += n;
            return *this;
        }

        Iterator& operator-=(int n) {
            p_cur -= n;
            return *this;
        }

        Type& operator*() {
            return *p_cur;
        }

        Type& operator*() const {
            return *p_cur;
        }
    };

    typedef Iterator<T> iterator;
    typedef Iterator<const T> const_iterator;

    iterator begin() noexcept {
        return iterator(_data);
    }

    iterator end() noexcept {
        return iterator(_data + _size);
    }

    const_iterator begin() const noexcept {
        return const_iterator(_data);
    }

    const_iterator end() const noexcept {
        return const_iterator(_data + _size);
    }
};