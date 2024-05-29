#include <cassert>
#include "linkedList.h"

template<typename T>
void getFirstTest(LinkedList<T> *list, std::string *typeOfCollection, int firstElement) {
    if (list -> getLength() == 0) {
        try {
            list -> getFirst();
        }
        catch (const std::out_of_range &exception) {
            assert(std::string(exception.what()) == "Getter call in empty collection");
            std::cout << "GetFirst method in " << *typeOfCollection << " works correctly \n" << std::endl;
        }
    }
    else {
        if (list -> getFirst() == firstElement) {
            std::cout << "GetFirst method in " << *typeOfCollection << " works correctly \n" << std::endl;
        }
    }
}

template<typename T>
void getLastTest(LinkedList<T> *list, std::string *typeOfCollection, int lastElement) {
    if (list -> getLength() == 0) {
        try {
            list -> getLast();
        }
        catch (const std::out_of_range &exception) {
            assert(std::string(exception.what()) == "Getter call in empty collection");
            std::cout << "GetLast method in " << *typeOfCollection << " works correctly \n" << std::endl;
        }
    }
    else {
        if (list -> getLast() == lastElement) {
            std::cout << "GetLast method in " << *typeOfCollection << " works correctly \n" << std::endl;
        }
    }
}

template<typename T>
void getTest(LinkedList<T> *list, std::string *typeOfCollection, int element) {
    if (list -> getLength() == 0) {
        try {
            list -> get(0);
        }
        catch(const std::out_of_range & exception) {
            assert(std::string(exception.what()) == "Getter call in empty collection");
            std::cout << "Get method in empty LinkedList works correctly \n" << std::endl;
        }
    }
    else {
        if (list -> get(2) == element) {
            std::cout << "Get method in " << *typeOfCollection << " works correctly \n" << std::endl;
        }
    }
}

template<typename T>
void getSubListTest(LinkedList<T> *list, std::string *typeOfCollection) {
    if (list -> getLength() == 0) {
        try {
            list -> getSubList(1, 3);
        }
        catch(const std::invalid_argument & exeption) {
            assert(std::string(exeption.what()) == "Invalid argument in getSubList function");
            std::cout << "GetSubList method in " << *typeOfCollection << " works correctly \n" << std::endl;
        }
    }
    else {

    }
}

template<typename T>
void appendMethodTest(LinkedList<T> *list, std::string *typeOfCollection) {
    list -> append(5);
    int length = list -> getLength();
    assert((*list)[length - 1] == 5);
    std::cout << "Append method in " << *typeOfCollection << " works correctly \n" << std::endl;
}

template<typename T>
void prependMethodTest(LinkedList<T> *list, std::string *typeOfCollection) {
    list -> prepend(10);
    assert((*list)[0] == 10);
    std::cout << "Prepend method in " << *typeOfCollection << " works correctly \n" << std::endl;
}

template<typename T>
void insertAtMethodTest(LinkedList<T>& list, std::string* typeOfCollection) {
    if (list.getLength() == 0) {
        try {
            list.insertAt(15, 5);
        } catch (std::out_of_range& exception) {
            assert(std::string(exception.what()) == "Invalid index in InsertAt function");
        }

        list.insertAt(15, 0);
        assert(list[0] == 15);
        std::cout << "InsertAt method in " << *typeOfCollection << " works correctly for empty list\n" << std::endl;
    } else {
        try {
            list.insertAt(15, -5);
        } catch (std::out_of_range& exception) {
            assert(std::string(exception.what()) == "Invalid index in InsertAt function");
        }

        list.insertAt(15, list.getLength());
        assert(list[list.getLength() - 1] == 15);
        std::cout << "InsertAt method in " << *typeOfCollection << " works correctly for non-empty list\n" << std::endl;
    }
}



void emptyLinkedListTest() {
    std::cout << "#######################################[ EmptyLinkedListTest ]####################################### \n" << std::endl;
    std::string typeOfCollection = "empty LinkedList";
    LinkedList<int> list;

    if (list.getLength() == 0) {
        std::cout << "Empty Constructor of LinkedList works correctly \n" << std::endl;
        std::cout << "GetLength method in empty LinkedList works correctly \n" << std::endl;
    }

    getFirstTest(&list, &typeOfCollection, 0);
    getLastTest(&list, &typeOfCollection, 0);
    getTest(&list, &typeOfCollection, 0);
    getSubListTest(&list, &typeOfCollection);
    appendMethodTest(&list, &typeOfCollection);
    insertAtMethodTest(list, &typeOfCollection);
    prependMethodTest(&list, &typeOfCollection);
    std::cout << "#######################################[ EmptyLinkedListTest was PASSED ]####################################### \n" << std::endl;
}

void linkedListTest() {
    std::cout << "#######################################[ LinkedListTest ]####################################### \n" << std::endl;
    int dataset[] = {1, 2, 3, 4, 5};
    std::string typeOfCollection = "LinkedList";
    LinkedList<int> list(5, dataset);
    assert(list.getLength() == 5);
    std::cout << "From array filled Constructor of LinkedList works correctly \n" << std::endl;
    std::cout << "GetLength method in LinkedList works correctly \n" << std::endl;
    LinkedList<int> list2(list);
    std::cout << "Copy Constructor of LinkedList works correctly \n" << std::endl;
    assert(list2.getLength() == 5);
    getFirstTest(&list, &typeOfCollection, 1);
    getLastTest(&list, &typeOfCollection, 5);
    getTest(&list, &typeOfCollection, 3);
    getSubListTest(&list, &typeOfCollection);
    insertAtMethodTest(list, &typeOfCollection);
    appendMethodTest(&list, &typeOfCollection);
    prependMethodTest(&list, &typeOfCollection);
    std::cout << "#######################################[ LinkedListTest was PASSED ]####################################### \n" << std::endl;
}

void startLinkedListTest() {
    emptyLinkedListTest();
    linkedListTest();
}