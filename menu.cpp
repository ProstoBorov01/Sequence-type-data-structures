#include <iostream>
#include <limits>
#include "implementations/arraySequenceImpl/arraySequence.h"
#include "implementations/arraySequenceImpl/arraySequenceUnitTests.h"
#include "implementations/listSequence/listSequenceUnitTests.h"


class TUI {
public:
    TUI() = default;

    static int listenUser(int numItems) {
        int chosenItem = -1;
        while (true) {
            std::cin >> chosenItem;

            if (std::cin.fail() or chosenItem < 0 or chosenItem > numItems) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 0 and " << numItems << ".\n";
            } else {
                break;
            }
        }

        return chosenItem;
    }

    static void sayHello() {
        std::cout << "~ Hello, dear User! This is the TUI of my small library that show its main features:)"<< std::endl;
        std::cout << "~ Follow the prompts on the screen! \n" << std::endl;
    }

    void mainScreen() {
        std::cout << "~ Enter the number(0 - to exit from the programm):" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "1 - HELP (this point additionally explains what is each point about)" << std::endl;
        std::cout << "2 - Work with ArraySequence" << std::endl;
        std::cout << "3 - Work with ListSequence" << std::endl;
        std::cout << "--------------------- \n" << std::endl;

        switch (listenUser(3)) {
            case 0:
                exit(1);
            case 1:
                this -> firstMenuHelpScreen();
                break;
            case 2:
                this -> creatingSequenceChooseSequenceType(1);
                break;
            case 3:
                this -> creatingSequenceChooseSequenceType(2);
                break;
        }
    }

    void firstMenuHelpScreen() {
        std::cout << "~ This is the explanations" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "1 - [Work with DynamicArray] (This menu item allows you to work with DynamicArray)" << std::endl;
        std::cout << "2 - [Work with ListSequence] (This menu item allows you to work with ListSequence)" << std::endl;
        std::cout << "~ Input 0 - to continue" << std::endl;
        std::cout << "---------------------\n" << std::endl;

        switch (listenUser(0)) {
            case 0:
                mainScreen();
        }
    }

    void creatingSequenceChooseSequenceType(int typeOfSequence) {
        std::cout << "~ Great! Now you you will build ArraySequence object and test it!" << std::endl;
        std::cout << "~ You should to choose type of Sequence - Mutable or Immutable." << std::endl;
        std::cout << "~ Follow the prompts on the screen! \n" << std::endl;

        std::cout << "~ Enter the number(0 - to exit from the program):" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "1 - HELP (what is the meaning of mutable and immutable)" << std::endl;
        std::cout << "2 - Mutable" << std::endl;
        std::cout << "3 - Immutable" << std::endl;
        std::cout << "--------------------- \n" << std::endl;

        switch(listenUser(3)) {
            case 0:
                exit(1);
            case 2:
                creatingSequenceChooseTypeOfElementsScreen(1, typeOfSequence);
                break;
            case 3:
                creatingSequenceChooseTypeOfElementsScreen(2, typeOfSequence);
                break;
        }
    }

    void creatingSequenceChooseTypeOfElementsScreen(int typeOfChangeability, int typeOfSequence) {
        std::cout << "~ Great! Now you you will build ArraySequence object and test it!" << std::endl;
        std::cout << "~ You should to choose the type of elements in your Sequence \n" << std::endl;
        std::cout << "~ Follow the prompts on the screen! \n" << std::endl;

        std::cout << "~ Eneter the number(0 - to exit from the program):" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "0 - HELP (this point additionally explains what is each point about)" << std::endl;
        std::cout << "1 - Integer" << std::endl;
        std::cout << "2 - Double" << std::endl;
        std::cout << "3 - Char" << std::endl;
        std::cout << "4 - String" << std::endl;
        std::cout << "--------------------- \n" << std::endl;
        std::string nameOfSequence;
        typeOfSequence == 1 ? nameOfSequence = "Array Sequence" : nameOfSequence = "List Sequence";
        int intDataset[] = {1, 2, 3, 4, 5, 6, 7, 8};
        double doubleDataset[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
        char charDataset[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        std::string strDataset[] = {"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth"};

        switch (listenUser(4)) {
            case 0:
                exit(1);
            case 1:
                if (typeOfChangeability == 1) { // Mutable
                    if (nameOfSequence == "Array Sequence"){
                        MutableArraySequence<int> sequenceObject(8, intDataset);
                        MutableArraySequence<int> *pointer = &sequenceObject;
                        std::string type = "int";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);

                    } else {
                        MutableListSequence<int> sequenceObject(8, intDataset);
                        MutableListSequence<int> *pointer = &sequenceObject;
                        std::string type = "int";
                        std::cout << "3";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);
                    }
                }
                else {
                    if (nameOfSequence == "Array Sequence"){
                        ImmutableArraySequence<int> sequenceObject(8, intDataset);
                        ImmutableArraySequence<int> *pointer = &sequenceObject;
                        std::string type = "int";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);

                    } else {
                        ImmutableListSequence<int> sequenceObject(8, intDataset);
                        ImmutableListSequence<int> *pointer = &sequenceObject;
                        std::string type = "int";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);
                    }
                }
                break;
            case 2:
                if (typeOfChangeability == 1) { // Mutable
                    if (nameOfSequence == "Array Sequence"){
                        MutableArraySequence<double> sequenceObject(8, doubleDataset);
                        MutableArraySequence<double> *pointer = &sequenceObject;
                        std::string type = "double";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);

                    } else {
                        MutableListSequence<double> sequenceObject(8, doubleDataset);
                        MutableListSequence<double> *pointer = &sequenceObject;
                        std::string type = "double";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);
                    }
                }
                else {
                    if (nameOfSequence == "Array Sequence"){
                        ImmutableArraySequence<double> sequenceObject(8, doubleDataset);
                        ImmutableArraySequence<double> *pointer = &sequenceObject;
                        std::string type = "double";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);

                    } else {
                        ImmutableListSequence<double> sequenceObject(8, doubleDataset);
                        ImmutableListSequence<double> *pointer = &sequenceObject;
                        std::string type = "double";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);
                    }
                }
                break;
            case 3:
                if (typeOfChangeability == 1) { // Mutable
                    if (nameOfSequence == "Array Sequence"){
                        MutableArraySequence<char> sequenceObject(8, charDataset);
                        MutableArraySequence<char> *pointer = &sequenceObject;
                        std::string type = "char";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);

                    } else {
                        MutableListSequence<char> sequenceObject(8, charDataset);
                        MutableListSequence<char> *pointer = &sequenceObject;
                        std::string type = "char";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);
                    }
                }
                else {
                    if (nameOfSequence == "Array Sequence"){
                        ImmutableArraySequence<char> sequenceObject(8, charDataset);
                        ImmutableArraySequence<char> *pointer = &sequenceObject;
                        std::string type = "char";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);

                    } else {
                        ImmutableListSequence<char> sequenceObject(8, charDataset);
                        ImmutableListSequence<char> *pointer = &sequenceObject;
                        std::string type = "char";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);
                    }
                }
                break;
            case 4:
                if (typeOfChangeability == 1) { // Mutable
                    if (nameOfSequence == "Array Sequence"){
                        MutableArraySequence<std::string> sequenceObject(8, strDataset);
                        MutableArraySequence<std::string> *pointer = &sequenceObject;
                        std::string type = "str";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);

                    } else {
                        MutableListSequence<std::string> sequenceObject(8, strDataset);
                        MutableListSequence<std::string> *pointer = &sequenceObject;
                        std::string type = "str";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);
                    }
                }
                else {
                    if (nameOfSequence == "Array Sequence"){
                        ImmutableArraySequence<std::string> sequenceObject(8, strDataset);
                        ImmutableArraySequence<std::string> *pointer = &sequenceObject;
                        std::string type = "str";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);

                    } else {
                        ImmutableListSequence<std::string> sequenceObject(8, strDataset);
                        ImmutableListSequence<std::string> *pointer = &sequenceObject;
                        std::string type = "str";
                        this -> workingWithSequenceScreen(pointer, nameOfSequence, type);
                    }
                }
                break;
        }
    }

    template<typename T>
    void workingWithSequenceScreen(SequenceAbstract<T> *arrayObject, std::string nameOfSequence, std::string typeOfContent) {
        std::cout << "~ You succesfully created ArraySequence object! Now you you will build ArraySequence object and test it!" << std::endl;

        if (typeOfContent == "int") {
            std::cout << "~ An object was filled by test values from this array -> [1, 2, 3, 4, 5, 6, 7, 8]" << std::endl;
        } else if (typeOfContent == "double") {
            std::cout << "~ An object was filled by test values from this array -> [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0]" << std::endl;
        } else if (typeOfContent == "char") {
            std::cout << "~ An object was filled by test values from this array -> ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']" << std::endl;
        } else {
            std::cout << "~ An object was filled by test values from this array -> [first, second, third, fourth, fifth, sixth, seventh, eighth]" << std::endl;
        }

        std::cout << "~ At that moment you can test methods of this object." << std::endl;
        std::cout << "~ Follow the prompts on the screen! \n" << std::endl;
        std::cout << "~ Enter the number(0 - to exit from the program):" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "1 - HELP (this point additionally explains what is each point about)" << std::endl;
        std::cout << "2 - Get first element from " << nameOfSequence << std::endl;
        std::cout << "3 - Get last element from " << nameOfSequence << std::endl;
        std::cout << "4 - Get element by index from " << nameOfSequence << std::endl;
        std::cout << "5 - Get length of " << nameOfSequence << std::endl;
        std::cout << "6 - Append element to " << nameOfSequence << std::endl;
        std::cout << "7 - Prepend element to " << nameOfSequence << std::endl;
        std::cout << "8 - Insert element by index into " << nameOfSequence << std::endl;
        std::cout << "9 - Concatenate two " << nameOfSequence << "s" << std::endl;
        std::cout << "10 - Test by unit test " << nameOfSequence << std::endl;
        std::cout << "11 - Get sub " << nameOfSequence << "from source " << nameOfSequence << std::endl;
        std::cout << "--------------------- \n" << std::endl;

        T item;
        switch(listenUser(11)) {
            case 0:
                exit(1);
            case 1:
                std::cout << "-------result------->" << std::endl;
                workingWithSequenceScreen(arrayObject, nameOfSequence, typeOfContent);
                break;
            case 2:
                std::cout << "-------result------->" << std::endl;
                std::cout << "First element is " << arrayObject -> getFirst() << std::endl;
                std::cout << "<-------------------- \n" << std::endl;
                break;
            case 3:
                std::cout << "-------result------->" << std::endl;
                std::cout << "Last element is " << arrayObject -> getLast() << std::endl;
                std::cout << "<-------------------- \n" << std::endl;
                break;
            case 4:
                std::cout << "-------result------->" << std::endl;
                std::cout << "Enter index of element that you want to get " << std::endl;
                int index;
                std::cin >> index;
                std::cout << "Element with index " << index << " is " << arrayObject -> get(index) << std::endl;
                std::cout << "<-------------------- \n" << std::endl;
                break;
            case 5:
                std::cout << "-------result------->" << std::endl;
                std::cout << "Length of Sequence is " << arrayObject -> getLength() << std::endl;
                std::cout << "<-------------------- \n" << std::endl;
                break;
            case 6:
                std::cout << "-------result------->" << std::endl;
                std::cout << "Current sequence: ";
                arrayObject -> printSequence();
                std::cout << "Input item that you want to add: ";
                std::cin >> item;
                arrayObject -> append(item);
                std::cout << "Updated sequence: ";
                arrayObject -> printSequence();
                std::cout << "<-------------------- \n" << std::endl;
                break;
            case 7:
                std::cout << "-------result------->" << std::endl;
                std::cout << "Current sequence: ";
                arrayObject -> printSequence();
                std::cout << "Input item that you want to add: ";
                std::cin >> item;
                arrayObject -> prepend(item);
                std::cout << "Updated sequence: ";
                arrayObject -> printSequence();
                std::cout << "<-------------------- \n" << std::endl;
                break;
            case 8:
                std::cout << "-------result------->" << std::endl;
                std::cout << "Current sequence: ";
                arrayObject -> printSequence();
                std::cout << "Input item that you want to add: ";
                std::cin >> item;
                std::cout << "Input index: ";
                std::cin >> index;
                arrayObject -> insertAt(item, index);
                std::cout << "Updated sequence: ";
                arrayObject -> printSequence();
                std::cout << "<-------------------- \n" << std::endl;
                break;
            case 9:
                std::cout << "-------result------->" << std::endl;
                std::cout << "The result of coupling a sequence with itself" << std::endl;
                arrayObject -> concat(arrayObject) -> printSequence();
                std::cout << "<-------------------- \n" << std::endl;
                break;
            case 10:
                if (nameOfSequence == "Array Sequence") {
                    testArraySequence();
                }
                else {
                    testListSequence();
                }
                break;
            case 11:
                std::cout << "-------result------->" << std::endl;
                int startIndex, endIndex;
                std::cout << "Input startIndex:" << std::endl;
                std::cout << "Input endIndex:" << std::endl;
                std::cin >> startIndex;
                std::cin >> endIndex;
                SequenceAbstract<T> *subSequence = arrayObject -> getSubSequence(startIndex, endIndex);
                std::cout << "Sub-sequence from " << startIndex << " to " << endIndex << " is: ";
                subSequence -> printSequence();
                delete subSequence;
                std::cout << "<-------------------- \n" << std::endl;
                break;
            }

        std::cout << "~ Input 0 - to continue" << std::endl;

        switch (listenUser(0)) {
            case 0:
                workingWithSequenceScreen(arrayObject, nameOfSequence, typeOfContent);
                break;
        }
    }
};

int main() {
    TUI session;
    TUI::sayHello();
    session.mainScreen();
}