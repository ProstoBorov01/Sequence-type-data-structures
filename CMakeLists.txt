cmake_minimum_required(VERSION 3.27)
project(lab_02)

set(CMAKE_CXX_STANDARD 14)

include_directories(sequence)

add_executable(lab_02
        collections/dynamicArrayDirectory/dynamicArray.h
        collections/linkedListDirectory/linkedList.h
        collections/linkedListDirectory/linkedListUnitTests.h
        collections/linkedListDirectory/linkedListUnitTests.h
        collections/dynamicArrayDirectory/dynamicArrayUnitTests.h
        sequence/sequenceAbstract.h
        sequence/sequenceAbstract.h
        sequence/sequenceAbstract.h
        sequence/implementations/arraySequenceImpl/arraySequence.h
        sequence/implementations/listSequence/listSequence.h
        sequence/implementations/listSequence/listSequenceUnitTests.h
        sequence/implementations/arraySequenceImpl/arraySequenceUnitTests.h
        menu.cpp
)
