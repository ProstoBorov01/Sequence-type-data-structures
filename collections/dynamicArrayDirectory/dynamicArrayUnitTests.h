#include <iostream>
#include <cassert>

#include "dynamicArray.h"

void testGet(const DynamicArray<int> &array, std:: string &typeOfCollection, int element, int index) {
    if (array.getSize() == 0) {
        try {
            array.get(index);
        }
        catch (const std::out_of_range &exception) {
            assert(std::string(exception.what()) == "Unavailable index in Get Function\n");
            std::cout << "Get method in " << typeOfCollection << " works correctly \n" << std::endl;
        }
    }
    else {
        if (array.get(index) == element) {
            std::cout << "Get method in " << typeOfCollection << " works correctly \n" << std::endl;
        }
    }
}

int  testGetSize(const DynamicArray<int>& array) {
    return array.getSize();
};

void testConstructor(const DynamicArray<int> &array, std::string &typeOfCollection, int size) {
    if (testGetSize(array) == size) {
        std::cout << "Empty Constructor of" << typeOfCollection << "works correctly \n" << std::endl;
        std::cout << "GetLength method in empty" << typeOfCollection << "works correctly \n" << std::endl;
    }
}

void testSet(DynamicArray<int> &array, std:: string &typeOfCollection, int element, int index) {
    if (array.getSize() == 0) {
        try {
            array.set(index, element);
        }
        catch (std::out_of_range &exception) {
            assert(std::string(exception.what()) == "Unavailable index in Set Function");
            std::cout << "Set method in " << typeOfCollection << " works correctly \n" << std::endl;
        }
    }
    else {
        array.set(index, element);

        if (array.get(index) == element) {
            std::cout << "Set method in " << typeOfCollection << " works correctly \n" << std::endl;
        }
    }
};

void testResize(DynamicArray<int> &array, std::string &typeOfCollection) {
    try {
        array.resize(-100);
    }
    catch (std::invalid_argument &exception) {
        array.resize(100);
        assert(std::string(exception.what()) == "Length of new array must be >= 0 and > the last length of array \n");

        if (array.getSize() == 100) {
            std::cout << "Resize method in " << typeOfCollection << " works correctly \n" << std::endl;
        }
    }
};

void emptyDynamicArrayTest() {
    std::cout << "#######################################[ EmptyDynamicArrayTest ]####################################### \n" << std::endl;
    DynamicArray<int> array;
    std::string typeOfCollection = "empty DynamicArrayTest";
    testConstructor(array, typeOfCollection, 0);
    testGet(array, typeOfCollection, 5 ,5);
    testSet(array, typeOfCollection, 5, 5);
    testResize(array, typeOfCollection);
    std::cout << "#######################################[ EmptyDynamicArrayTest was PASSED ]####################################### \n" << std::endl;
}

void dynmaicArrayTest() {
    std::cout << "#######################################[ DynamicArrayTest ]####################################### \n" << std::endl;
    int dataset[] = {1, 2, 3, 4, 5};
    DynamicArray<int> array(5, dataset);
    std::string typeOfCollection = "empty LinkedList";
    testConstructor(array, typeOfCollection, 5);
    testGet(array, typeOfCollection, 4 ,3);
    testSet(array, typeOfCollection, 200, 3);
    testResize(array, typeOfCollection);
    std::cout << "#######################################[ DynamicArrayTest was PASSED ]####################################### \n" << std::endl;
}

void startDyanmicTest() {
    emptyDynamicArrayTest();
    dynmaicArrayTest();
}

