#pragma once
#include <iostream>
#include "sequenceAbstract.h"
#include "../../../collections/linkedListDirectory/linkedList.h"


template <typename T>
class ListSequence : public SequenceAbstract<T> {
protected:
    LinkedList<T> *data;
/*
иначе появиться цепочка:
создать обьект -> использовать append -> append вызывает инстансирование -> оно копирует обьект -> нужен конструктор
цепь замыкается
*/
    void independentAppend (T &item) {
        this -> data -> append(item);
    }

public:
    ListSequence() {
        this -> data = new LinkedList<T>();
    };

    ListSequence(int count, T *data) {
        this -> data = new LinkedList<T>(count, data);
    }

    explicit ListSequence(LinkedList<T> *list) {
        this -> data = new LinkedList<T>(list);
    }

    explicit ListSequence(const SequenceAbstract<T> *abstractSequence) {
        this -> data = new LinkedList<T>(abstractSequence -> getLength());

        for (int i = 0; i < abstractSequence -> getLength(); i ++) {
            independentAppend(abstractSequence -> get(i));
        }
    }

    explicit ListSequence(const ListSequence<T> *list) {
        this -> data = new LinkedList<T>(*(list -> data));
    }

    virtual ~ListSequence<T>(){
        delete data;
    }

    void printSequence() const override;
    T getFirst() const override;
    T getLast() const override;
    size_t getLength() const override;
    T get(int index) const override;
    ListSequence<T> *append(T item) override;
    ListSequence<T> *prepend(T item) override;
    ListSequence<T> *insertAt(T item, int index) override;
    virtual ListSequence<T> *getInstance() = 0;
    virtual const ListSequence<T> *getInstance() const = 0;
};

template<typename T>
void ListSequence<T>::printSequence() const {
    std::cout << "(";

    for (int i = 0; i < this -> data -> getLength(); i ++) {
        std::cout << " " << this -> data -> get(i);

        if (i < this -> data -> getLength() - 1) {
            std::cout << ",";
        }
    }

    std::cout << ")" << std::endl;
}

template<typename T>
T ListSequence<T>::getFirst() const {
    return this -> data -> getFirst() ;
}

template<typename T>
T ListSequence<T>::getLast() const {
    return this -> data -> getLast();
}

template<typename T>
size_t ListSequence<T>::getLength() const {
    return this -> data -> getLength();
}

template<typename T>
T ListSequence<T>::get(int index) const {
    return this -> data -> get(index);
}

template<typename T>
ListSequence<T> *ListSequence<T>::append(T item) {
    ListSequence<T> *result = getInstance();
    result -> data -> append(item);

    return result;
}

template<typename T>
ListSequence<T> *ListSequence<T>::prepend(T item) {
    ListSequence<T> *result = getInstance();
    result -> data -> prepend(item);

    return result;
}

template<typename T>
ListSequence<T> *ListSequence<T>::insertAt(T item, int index) {
    ListSequence<T> *result = getInstance();
    result -> data -> insertAt(item, index);

    return result;
}

template <typename T>
class MutableListSequence : public ListSequence<T> {
private:
    ListSequence<T> *getInstance() override {
        return this;
    }

    const ListSequence<T> *getInstance() const override {
        return this;
    }

public:
    using ListSequence<T>::ListSequence;

    MutableListSequence<T> *getSubSequence(int startIndex, int endIndex) const override;
    MutableListSequence<T> *concat(SequenceAbstract<T> *sequenceAbstract) const override;
};

template<typename T>
MutableListSequence<T> *MutableListSequence<T>::getSubSequence(int startIndex, int endIndex) const {
    LinkedList<T> *resultLinkedList = this -> data -> getSubList(startIndex, endIndex);

    return new MutableListSequence<T>(resultLinkedList);
}

template<typename T>
MutableListSequence<T> *MutableListSequence<T>::concat(SequenceAbstract<T>* sequenceAbstract) const {
    auto *resultListSequence = new MutableListSequence<T>();

    for (int i = 0; i < this -> data -> getLength(); i++) {
        resultListSequence -> append(this -> data -> get(i));
    }

    for (int i = 0; i < sequenceAbstract -> getLength(); i++) {
        resultListSequence -> append(sequenceAbstract -> get(i));
    }

    return new MutableListSequence<T>(resultListSequence);
}

template <typename T>
class ImmutableListSequence : public ListSequence<T> {
private:
    ListSequence<T> *getInstance() override {
        return new ImmutableListSequence<T>(*this);
    }
    const ListSequence<T> *getInstance() const override {
        return new const ImmutableListSequence<T>(*this);
    }
public:
    using ListSequence<T>::ListSequence;

    ImmutableListSequence<T> *getSubSequence(int startIndex, int endIndex) const override;
    ImmutableListSequence<T> *concat(SequenceAbstract<T> *seq) const override;
};

template<typename T>
ImmutableListSequence<T> *ImmutableListSequence<T>::getSubSequence(int startIndex, int endIndex) const {
    LinkedList<T> *resultLinkedList = this -> data -> getSubList(startIndex, endIndex);

    return new ImmutableListSequence<T>(resultLinkedList);
}

template<typename T>
ImmutableListSequence<T> *ImmutableListSequence<T>::concat(SequenceAbstract<T> *sequenceAbstract) const {
    auto *resultListSequence = new ImmutableListSequence<T>();

    for (int i = 0; i < this -> data -> getLength(); i++) {
        resultListSequence -> append(this -> data -> get(i));
    }

    for (int i = 0; i < sequenceAbstract -> getLength(); i++) {
        resultListSequence -> append(sequenceAbstract -> get(i));
    }

    return new ImmutableListSequence<T>(resultListSequence);
}
