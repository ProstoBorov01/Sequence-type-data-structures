#pragma once
#include <iostream>
#include <cassert>
#include "implementations/arraySequenceImpl/arraySequence.h"
#include "../../../collections/dynamicArrayDirectory/dynamicArrayUnitTests.h"

void testArrayConstructors() {
    int dataset[] = {1,2,3,4,5,6};
    MutableArraySequence<int> testMutableArraySequence1(6);
    assert(testMutableArraySequence1.getLength()==6);
    ImmutableArraySequence<int> testImmutableArraySequence1(6);
    assert(testImmutableArraySequence1.getLength() == 6);

    ImmutableArraySequence<int> testImmutableArraySequence2(6, dataset);
    assert(testImmutableArraySequence2.getLength()==6);

    for (int i = 0; i < testImmutableArraySequence2.getLength(); i++) {
        assert(testImmutableArraySequence2.get(i) == dataset[i]);
    }

    MutableArraySequence<int> testMutableArraySequence2(testImmutableArraySequence2);
    assert(testMutableArraySequence2.getLength() == 6);

    for (int i = 0; i < testMutableArraySequence2.getLength(); i++) {
        assert(testMutableArraySequence2.get(i) == dataset[i]);
    }

    const MutableArraySequence<int>& testMutableArraySequence3 = testMutableArraySequence2;
    const ImmutableArraySequence<int>& testImmutableArraySequence3 = testImmutableArraySequence2;

    assert(testMutableArraySequence3.getLength() == testMutableArraySequence2.getLength());
    assert(testImmutableArraySequence3.getLength() == testImmutableArraySequence2.getLength());

    for (int i = 0; i < testMutableArraySequence3.getLength(); i++){
        assert(testMutableArraySequence2.get(i) == testMutableArraySequence3.get(i));
    }
    for (int i = 0; i < testImmutableArraySequence3.getLength(); i++){
        assert(testImmutableArraySequence2.get(i) == testImmutableArraySequence3.get(i));
    }

    std::cout << "Constructors works correctly \n" << std::endl;
}

void mutableArraySequenceGetTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int index, int elem) {
    assert(object.get(index) == elem);
    std::cout << "Get method in " << typeOfCollection << " works correctly \n" << std::endl;
}

void mutableArraySequenceGetFirstTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int elem) {
    assert(object.getFirst() == elem);
    std::cout << "GetFirst method in " << typeOfCollection << " works correctly \n" << std::endl;
}

void mutableArraySequenceGetLastTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int elem) {
    assert(object.getLast() == elem);
    std::cout << "GetLast method in " << typeOfCollection << " works correctly \n" << std::endl;
}

void mutableArraySequenceAppendTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int elem) {
    object.append(elem);
    assert(object.getLast() == elem);
    std::cout << "Append method in " << typeOfCollection << " works correctly \n" << std::endl;
}

void mutableArraySequencePrependTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int elem) {
    object.prepend(elem);
    assert(object.getFirst() == elem);
    std::cout << "Prepend method in " << typeOfCollection << " works correctly \n" << std::endl;
}

void mutableArraySequenceInsertAtTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int index, int elem) {
    object.insertAt(elem, index);
    assert(object.get(index) == elem);
    std::cout << "InsertAt method in " << typeOfCollection << " works correctly \n" << std::endl;
}

void mutableArraySequenceGetSubSequenceTest(MutableArraySequence<int> &object, const std::string &typeOfCollection, int startIndex, int endIndex, const int *expected) {
    MutableArraySequence<int> *subSequence = object.getSubSequence(startIndex, endIndex);

    for (int i = 0; i < endIndex - startIndex; i++) {
        assert(subSequence -> get(i) == expected[i]);
    }

    std::cout << "GetSubSequence method in " << typeOfCollection << " works correctly \n" << std::endl;
    delete subSequence;
}

void mutableArraySequenceConcatTest(MutableArraySequence<int> &object1, MutableArraySequence<int> &object2, const std::string &typeOfCollection, const int *expected) {
    MutableArraySequence<int> *concatSequence = object1.concat(&object2);

    for (int i = 0; i < concatSequence -> getLength(); i ++) {
        assert(concatSequence -> get(i) == expected[i]);
    }

    std::cout << "Concat method in " << typeOfCollection << " works correctly \n" << std::endl;
    delete concatSequence;
}

void testArraySequence() {
    std::cout << "####################################### ArraySequenceTest ####################################### \n" << std::endl;
    MutableArraySequence<int> mutableArray;
    MutableArraySequence<int> mutableArray2;
    std::string mutableType = "MutableArraySequence";
    std::string immutableType = "ImmutableArraySequence";
    int expected[] = {2, 3, 4};
    int expected2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    mutableArray.append(1);
    mutableArray.append(2);
    mutableArray.append(3);
    mutableArray.append(4);
    mutableArray.append(5);
    mutableArray2.append(6);
    mutableArray2.append(7);
    mutableArray2.append(8);
    testArrayConstructors();
    mutableArraySequenceGetTest(mutableArray, mutableType, 1, 2);
    mutableArraySequenceGetFirstTest(mutableArray, mutableType, 1);
    mutableArraySequenceGetLastTest(mutableArray, mutableType, 5);
    mutableArraySequenceGetSubSequenceTest(mutableArray, mutableType, 1, 3, expected);
    mutableArraySequenceConcatTest(mutableArray, mutableArray2,mutableType, expected2);
    mutableArraySequenceAppendTest(mutableArray, mutableType, 4);
    mutableArraySequencePrependTest(mutableArray, mutableType, 1);
    mutableArraySequenceInsertAtTest(mutableArray, mutableType, 2, 5);
    startDyanmicTest();
    std::cout << "####################################### ArraySequenceTest was PASSED ####################################### \n" << std::endl;
}
