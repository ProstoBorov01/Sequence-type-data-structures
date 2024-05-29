#pragma once
#include <iostream>

template <typename T>
class DynamicArray {
private:
    int length = 0;
    T* elements = nullptr;

public:
    DynamicArray() = default;
    DynamicArray(int count, T* elemnts) {
        this -> length = count;
        this -> elements = new T[count];

        for (int i = 0; i < count; i ++) {
            this -> elements[i] = elemnts[i];
        }
    }

    explicit DynamicArray(int setLength) {
        if (setLength < 0) {
            throw std::invalid_argument("Length of Array must be >= 0");
        }
        this -> length = setLength;
        this -> elements = new T[setLength];
    };

    DynamicArray(const DynamicArray<T> &other) {
        this -> length = other.length;
        this -> elements = new T[other.length];

        for (int i = 0; i < other.length; i ++) {
            this -> elements[i] = other.elements[i];
        }
    }

    T operator[] (int index) {
        if (index >= this -> length) {
            throw std::out_of_range("Unavailable index in Get Function\n");
        }

        return this -> elements[index];
    }

    T get(int index) const {
        return this -> elements[index];
    }

    int getSize() const {
        return this -> length;
    }

    void set(int index, T value) {
        if(this -> getSize() <= index or index < 0) {
            throw std::out_of_range("Unavailable index in Set Function");
        }
        this -> elements[index] = value;
    }

    void resize(int setSize) {
        if (setSize < this -> length or setSize < 0) {
            throw std::invalid_argument("Length of new array must be >= 0 and > the last length of array \n");
        }

        if (setSize == 0) {
            delete[] this -> elements;
            this -> elements = nullptr;

            return;
        }

        T* buf = new T[setSize];
        for (int i = 0; i < this -> length; i ++) {
            buf[i] = this -> elements[i];
        }

        delete[] this -> elements;
        this -> elements = buf;
        this -> length = setSize;
    }

    virtual ~DynamicArray() {
        delete[] elements;
    }

};
