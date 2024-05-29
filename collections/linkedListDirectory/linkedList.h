#pragma once
#include <iostream>

template <typename T>
class LinkedList {
public:

    LinkedList() {
        this -> length = 0;
        this -> head = nullptr;
    }

    LinkedList(int count, T *items) {
        if(count < 0)
            throw std::invalid_argument("invalid argument in constructor");

        if (count == 0) {
            this -> head = nullptr;
            this -> length = 0;
            return;
        }

        this -> head = new Node<T>(items[0]);
        Node<T>* current = this -> head;

        for (int i = 1; i < count; i++) {
            current -> pointerOnNextElement = new Node<T>(items[i]);
            current = current -> pointerOnNextElement;
        }

        this -> length = count;
    }

    LinkedList(const LinkedList<T> &list) {
        this -> head = nullptr;
        this -> length = 0;

        this -> head = new Node<T>(list.get(0));
        Node<T>* current = this -> head;

        for (int i = 1; i < list.getLength(); i++) {
            current -> pointerOnNextElement = new Node<T>(list.get(i));
            current = current -> pointerOnNextElement;
        }

        this -> length = list.length;
    }


    explicit LinkedList(LinkedList<T> *list) {
        this -> head = nullptr;
        this -> length = 0;

        this -> head = new Node<T>(list -> get(0));
        Node<T>* current = this -> head;

        for (int i = 1; i < list -> getLength(); i++) {
            current -> pointerOnNextElement = new Node<T>(list -> get(i));
            current = current -> pointerOnNextElement;
        }

        this -> length = list -> length;
    }

    virtual ~LinkedList() {
        Node<T> *current = this -> head;
        Node<T> *next;

        while (current != nullptr) {
            next = current -> pointerOnNextElement;
            delete current;
            current = next;
        }
        this -> head = nullptr;
        this -> length = 0;
    }

    T getFirst() const;
    T getLast() const;
    T operator[](int index) const;
    T get(int index) const;
    LinkedList<T> *getSubList(int startIndex, int endIndex) const;
    int getLength() const;
    void append(T data);
    void prepend(T data);
    void insertAt(T data, int index);
    LinkedList<T> *concat(LinkedList<T> * list);

private:

    template <typename NodeGeneric>
    class Node {
    public:

        Node<NodeGeneric> *pointerOnNextElement;
        NodeGeneric data;

        explicit Node(NodeGeneric data= NodeGeneric(), Node *pointer = nullptr) {
            this -> pointerOnNextElement = pointer;
            this -> data = data;
        }

    };

    int length {};
    Node<T> *head;
};

template<typename T>
T LinkedList<T>::getFirst() const {
    if (this -> head == nullptr) {
        throw std::out_of_range("Getter call in empty collection");
    }

    return this -> head -> data;
}

template<typename T>
T LinkedList<T>::getLast() const{
    if (this -> head == nullptr) {
        throw std::out_of_range("Getter call in empty collection");
    }

    Node<T> *current = this -> head;

    while (current -> pointerOnNextElement != nullptr) {
        current = current -> pointerOnNextElement;
    }

    return current -> data;

}

template<typename T>
T LinkedList<T>::operator[](int index) const {
    int counter = 0;
    Node<T> *current = this -> head;

    if (this -> head == nullptr) {
        throw std::out_of_range("Getter call in empty collection");
    }

    if (index >= this -> length or index < 0) {
        throw std::invalid_argument("Invaild argeument in [] operator");
    }

    while (counter != index) {
        current = current -> pointerOnNextElement;
        counter ++;
    }

    return current -> data;
}

template<typename T>
T LinkedList<T>::get(int index) const {
    int counter = 0;
    Node<T> *current = this -> head;

    if (this -> head == nullptr) {
        throw std::out_of_range("Getter call in empty collection");
    }

    if (index >= this -> length or index < 0) {
        throw std::invalid_argument("Invaild argeument in [] operator");
    }

    while (counter != index) {
        current = current -> pointerOnNextElement;
        counter ++;
    }

    return current -> data;
}

template<typename T>
LinkedList<T> *LinkedList<T>::getSubList(int startIndex, int endIndex) const {
    if (startIndex >= this -> length or endIndex >= this -> length or startIndex < 0 or endIndex < 0 or startIndex > endIndex) {
        throw std::invalid_argument("Invalid argument in getSubList function");
    }

    auto *list = new LinkedList<T>();

    for (int i = startIndex; i <= endIndex; i++) {
        list -> append((*this)[i]);
    }

    return list;
}

template<typename T>
int LinkedList<T>::getLength() const {
    return this -> length;
}

template<typename T>
void LinkedList<T>::append(T data) {
    Node<T>* newNode = new Node<T>(data);
    Node<T>** indirect = &this->head;

    while (*indirect != nullptr) {
        indirect = &(*indirect)->pointerOnNextElement;
    }

    *indirect = newNode;
    this -> length++;
}

template<typename T>
void LinkedList<T>::prepend(T data) {
    auto *buf = new Node<T>(data);
    buf -> pointerOnNextElement = this -> head;
    this -> head = buf;
    this -> length ++;
}

template<typename T>
void LinkedList<T>::insertAt(T data, int index) {
    if (index < 0 || index > length) {
        throw std::out_of_range("Invalid index in InsertAt function");
    }

    if (index == 0) {
        prepend(data);
        return;
    }

    Node<T> *current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current -> pointerOnNextElement;
    }

    auto *newNode = new Node<T>(data, current -> pointerOnNextElement);
    current -> pointerOnNextElement = newNode;
    this -> length ++;
}

template<typename T>
LinkedList<T> *LinkedList<T>::concat(LinkedList<T> *list) {
    auto *buf = new LinkedList<T>(*this);
    Node<T>* current = list -> head;

    while(current!= nullptr) {
        buf -> append(current -> data);
        current = current -> pointerOnNextElement;
    }

    buf -> length = this -> length + list -> length;

    return buf;
}



