//
// Created by Computer on 28.11.2018.
//
#pragma once

#include <cstddef>
#include <iostream>


template<typename T>
class Array {
public:
    explicit Array(size_t size = 0);
    Array(const Array &);
    Array &operator=(const Array<T> &);
    ~Array();
    size_t size() const;


    T &operator[](size_t);
    const T &operator[](size_t) const;


    Array(Array&&) noexcept;
    Array &operator=(Array<T> &&) noexcept;

    void print() const ;

private:
    size_t size_;
    T *data_;
};

#include "Array.hpp"