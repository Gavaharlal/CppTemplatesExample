#include "Array.h"

template<typename T>
Array<T>::Array(size_t size) {
    size_ = size;
    data_ = new T[size];
}

template<typename T>
Array<T>::Array(const Array &array) {
    size_ = array.size_;
    data_ = new T[size_];
    for (int i = 0; i < size_; ++i) {
        data_[i] = array[i];
    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &array) {
    if (this != &array) {
        size_ = array.size_;
        delete[] data_;
        data_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = array[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] data_;
    size_ = 0;
}

template<typename T>
size_t Array<T>::size() const {
    return size_;
}

template<typename T>
T &Array<T>::operator[](size_t idx) {
    return data_[idx];
}

template<typename T>
const T &Array<T>::operator[](size_t idx) const {
    return data_[idx];
}

template<typename T>
Array<T>::Array(Array &&array) noexcept {
    size_ = array.size_;
    data_ = array.data_;
    array.data_ = nullptr;
    array.size_ = 0;
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> &&array) noexcept {
    if (this != &array) {
        size_ = array.size_;
        array.size_ = 0;
        data_ = array.data_;
        array.data_ = nullptr;
    }
    return *this;
}

template<typename T>
void Array<T>::print() const {
    for (int i = 0; i < size_; ++i) {
        std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
}
