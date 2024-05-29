#pragma once
#include <iostream>

template <typename T>
class SequenceAbstract {
public:
    virtual void printSequence() const = 0;
    virtual T getFirst() const = 0;
    virtual T getLast() const = 0;
    virtual size_t getLength() const = 0;
    virtual T get(int index) const = 0;
    virtual SequenceAbstract<T>* append(T item) = 0;
    virtual SequenceAbstract<T>* prepend(T item) = 0;
    virtual SequenceAbstract<T>* insertAt(T item, int index) = 0;
    virtual SequenceAbstract<T>* getSubSequence(int startIndex, int endIndex) const = 0;
    virtual SequenceAbstract<T> *concat(SequenceAbstract<T> *list) const = 0;
    virtual ~SequenceAbstract() = default;
};