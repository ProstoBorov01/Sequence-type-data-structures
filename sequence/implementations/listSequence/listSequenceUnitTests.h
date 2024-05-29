#pragma once
#include <iostream>
#include <cassert>
#include "implementations/listSequence/listSequence.h"
#include "../../../collections/linkedListDirectory/linkedListUnitTests.h"

void mutableListSequenceGetTest(MutableListSequence<int> &object, const std::string &typeOfCollection, int index, int elem) {
    assert(object.get(index) == elem);
    std::cout << "Get method in " << typeOfCollection << " works correctly \n" << std::endl;
}

void mutableListSequenceGetFirstTest(MutableListSequence<int> &object, const std::string &typeOfCollection, int elem) {
    assert(object.getFirst() == elem);
    std::cout << "GetFirst method in " << typeOfCollection << " works correctly \n" << std::endl;
}

void mutableListSequenceGetLastTest(MutableListSequence<int> &object, const std::string &typeOfCollection, int elem) {
    assert(object.getLast() == elem);
    std::cout << "GetLast method in " << typeOfCollection << " works correctly \n" << std::endl;
}

void mutableListSequenceAppendTest(MutableListSequence<int> &object, const std::string &typeOfCollection, int elem) {
    object.append(elem);
    assert(object.getLast() == elem);
    std::cout << "Append method in " << typeOfCollection << " works correctly \n" << std::endl;
}

void mutableListSequencePrependTest(MutableListSequence<int> &object, const std::string &typeOfCollection, int elem) {
    object.prepend(elem);
    assert(object.getFirst() == elem);
    std::cout << "Prepend method in " << typeOfCollection << " works correctly \n" << std::endl;
}

void mutableListSequenceInsertAtTest(MutableListSequence<int> &object, const std::string &typeOfCollection, int index, int elem) {
    object.insertAt(elem, index);
    assert(object.get(index) == elem);
    std::cout << "InsertAt method in " << typeOfCollection << " works correctly \n" << std::endl;
}

void mutableListSequenceGetSubSequenceTest(MutableListSequence<int> &object, const std::string &typeOfCollection, int startIndex, int endIndex, const int *expected) {
    MutableListSequence<int> *subSequence = object.getSubSequence(startIndex, endIndex);

    for (int i = 0; i < endIndex - startIndex; i++) {
        assert(subSequence -> get(i) == expected[i]);
    }

    std::cout << "GetSubSequence method in " << typeOfCollection << " works correctly \n" << std::endl;
    delete subSequence;
}

void mutableListSequenceConcatTest(MutableListSequence<int> &object1, MutableListSequence<int> &object2, const std::string &typeOfCollection, const int *expected) {
    MutableListSequence<int> *concatSequence = object1.concat(&object2);

    for (int i = 0; i < concatSequence -> getLength(); i ++) {
        assert(concatSequence -> get(i) == expected[i]);
    }

    std::cout << "Concat method in " << typeOfCollection << " works correctly \n" << std::endl;
    delete concatSequence;
}

void testListSequence() {
    std::cout << "####################################### ListSequenceTest ####################################### \n" << std::endl;
    MutableListSequence<int> mutableList;
    MutableListSequence<int> mutableList2;
    std::string mutableType = "MutableListSequence";
    std::string immutableType = "ImmutableListSequence";
    int expected[] = {2, 3, 4};
    int expected2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    mutableList.append(1);
    mutableList.append(2);
    mutableList.append(3);
    mutableList.append(4);
    mutableList.append(5);
    mutableList2.append(6);
    mutableList2.append(7);
    mutableList2.append(8);
    mutableListSequenceGetTest(mutableList, mutableType, 1, 2);
    mutableListSequenceGetFirstTest(mutableList, mutableType, 1);
    mutableListSequenceGetLastTest(mutableList, mutableType, 5);
    mutableListSequenceGetSubSequenceTest(mutableList, mutableType, 1, 3, expected);
    mutableListSequenceConcatTest(mutableList, mutableList2,mutableType, expected2);
    mutableListSequenceAppendTest(mutableList, mutableType, 4);
    mutableListSequencePrependTest(mutableList, mutableType, 1);
    mutableListSequenceInsertAtTest(mutableList, mutableType, 2, 5);
    startLinkedListTest();
    std::cout << "####################################### ListSequenceTest was PASSED ####################################### \n" << std::endl;
}
