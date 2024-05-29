#pragma once
#include <iostream>
#include "sequenceAbstract.h"
#include "../../../collections/dynamicArrayDirectory/dynamicArray.h"

template <typename T>
class ArraySequence : public SequenceAbstract<T> {
protected:
    DynamicArray<T> *data;
    virtual ArraySequence<T> *getInstance() = 0;
    virtual const ArraySequence<T> *getInstance() const = 0;
public:
    ArraySequence() {
        this -> data = new DynamicArray<T>();
    };

    explicit ArraySequence(int count) {
        this -> data = new DynamicArray<T>(count);
    };

    ArraySequence(int count, T *data) {
        this -> data = new DynamicArray<T>(count, data);
    }

    explicit ArraySequence(const DynamicArray<T> &array) {
        this -> data = new DynamicArray<T>(array);
    }

    explicit ArraySequence(DynamicArray<T> *arrayPtr) {
        this -> data = arrayPtr;
    }

    explicit ArraySequence(const SequenceAbstract<T> &abstractSequence) {
        this -> data = new DynamicArray<T>(abstractSequence.getLength());

        for (int i = 0; i < abstractSequence.getLength(); i ++) {
            this -> data -> set(i, abstractSequence.get(i));
        }
    }

    ArraySequence(const ArraySequence<T> &array) {
        this -> data = new DynamicArray<T>(*(array.data));
    }

    virtual ~ArraySequence() {
        delete data;
    }
    void printSequence() const override;
    T getFirst() const override;
    T getLast() const override;
    size_t getLength() const override;
    T get(int index) const override;
    ArraySequence<T> *append(T item) override;
    ArraySequence<T> *prepend(T item) override;
    ArraySequence<T> *insertAt(T item, int index) override;
};

template<typename T>
void ArraySequence<T>::printSequence() const {
    std::cout << "(";

    for (int i = 0; i < this -> data -> getSize(); i++) {
        std::cout << " " << this -> data -> get(i);

        if (i < this -> data -> getSize() - 1) {
            std::cout << ",";
        }
    }

    std::cout << " )" << std::endl;
}

template<typename T>
T ArraySequence<T>::getFirst() const {
    return this -> data -> get(0);
}

template<typename T>
T ArraySequence<T>::getLast() const {
    return this -> data -> get(this -> data -> getSize() - 1);
}

template<typename T>
size_t ArraySequence<T>::getLength() const {
    return this -> data -> getSize();
}

template<typename T>
T ArraySequence<T>::get(int index) const {
    return this -> data -> get(index);
}

template<typename T>
ArraySequence<T> *ArraySequence<T>::append(T item) {
    ArraySequence<T> *result = getInstance();
    result -> data -> resize(result -> data -> getSize() + 1);
    result -> data -> set(result -> data -> getSize() - 1, item);

    return result;
}

template<typename T>
ArraySequence<T>* ArraySequence<T>::prepend(T item) {
    ArraySequence<T>* result = getInstance();
    result -> data -> resize(result -> data -> getSize() + 1);
    result -> data -> set(0, item);

    for (int i = 1; i <= data -> getSize() - 1; i++) {
        result -> data -> set(i, data -> get(i));
    }

    return result;
}

template<typename T>
ArraySequence<T> *ArraySequence<T>::insertAt(T item, int index) {
    ArraySequence<T> *result = getInstance();
    auto *buf = new DynamicArray<T>(data -> getSize() + 1);

    for (int i = 0; i < index; i++) {
        buf -> set(i, data -> get(i));
    }

    buf -> set(index, item);

    for (int i = index; i < data -> getSize(); i++) {
        buf -> set(i + 1, data -> get(i));
    }

    delete result -> data;
    result -> data = buf;

    return result;
}


template <typename T>
class MutableArraySequence : public ArraySequence<T> {
protected:
    ArraySequence<T> *getInstance() override {
        return static_cast<ArraySequence<T> *>(this);
    }

    const ArraySequence<T> *getInstance() const override  {
        return static_cast<const ArraySequence<T>*>(this);
    }
public:
    using ArraySequence<T>::ArraySequence;

    MutableArraySequence<T> *getSubSequence(int startIndex, int endIndex) const override;
    MutableArraySequence<T> *concat(SequenceAbstract<T> *sequenceAbstract) const override;
};

template<typename T>
MutableArraySequence<T> *MutableArraySequence<T>::getSubSequence(int startIndex, int endIndex) const {
    if (startIndex < 0 or endIndex > this -> data -> getSize() or startIndex > endIndex or endIndex < 0) {
        throw std::out_of_range("Invalid start or end index");
    }

    auto *resultDynamicArray = new DynamicArray<T>(endIndex - startIndex);

    for (int i = startIndex; i < endIndex; i++) {
        resultDynamicArray -> set(i - startIndex, this -> data -> get(i));
    }

    return new MutableArraySequence<T>(resultDynamicArray);
}

template<typename T>
MutableArraySequence<T> *MutableArraySequence<T>::concat(SequenceAbstract<T> *sequenceAbstract) const {
    auto *resultDynamicArray = new DynamicArray<T>(this -> data -> getSize() + sequenceAbstract -> getLength());

    for (int i = 0; i < this -> data -> getSize(); i++) {
        resultDynamicArray -> set(i, this -> data -> get(i));
    }

    for (int i = 0; i < sequenceAbstract -> getLength(); i++) {
        resultDynamicArray -> set(i + this->data -> getSize(), sequenceAbstract ->get(i));
    }

    return new MutableArraySequence<T>(*resultDynamicArray);
}

template <typename T>
class ImmutableArraySequence : public ArraySequence<T> {
private:
    ArraySequence<T> *getInstance() override {
        return new ImmutableArraySequence<T>(*this);
    }

    const ArraySequence<T> *getInstance() const override {
        return new const ImmutableArraySequence<T>(*this);
    }

public:
    using ArraySequence<T>::ArraySequence;

    ImmutableArraySequence<T> *getSubSequence(int startIndex, int endIndex) const override;
    ImmutableArraySequence<T> *concat(SequenceAbstract<T> *sequenceAbstract) const override;
};

template<typename T>
ImmutableArraySequence<T> *ImmutableArraySequence<T>::getSubSequence(int startIndex, int endIndex) const {
    auto *resultDynamicArray = new DynamicArray<T>(endIndex - startIndex);

    for (int i  = startIndex; i < endIndex; i ++) {
        resultDynamicArray -> set(i, resultDynamicArray -> get(i));
    }

    auto *result = new ImmutableArraySequence<T>(resultDynamicArray);
    result -> data = resultDynamicArray;

    return result;
}

template<typename T>
ImmutableArraySequence<T> *ImmutableArraySequence<T>::concat(SequenceAbstract<T> *sequenceAbstract) const {
    auto *resultDynamicArray = new DynamicArray<T>(this -> data -> getSize() + sequenceAbstract -> getLength());

    for (int i = 0; i < this -> data -> getSize(); i++) {
        resultDynamicArray -> set(i, this -> data -> get(i));
    }

    for (int i = 0; i < sequenceAbstract -> getLength(); i++) {
        resultDynamicArray -> set(i + this -> data -> getSize(), sequenceAbstract -> get(i));
    }

    return new ImmutableArraySequence<T>(*resultDynamicArray);
}