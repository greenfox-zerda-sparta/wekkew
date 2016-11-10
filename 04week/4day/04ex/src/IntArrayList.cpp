#include <iostream>
#include "IntList.h"
#include "IntArrayList.h"

using namespace std;

IntArrayList::IntArrayList() {
    mArray = new int[getLength()];
}

void IntArrayList::append(int value) {
    int* newArray = new int[getLength()+1];
    for (int i = 0; i < getLength(); i++) {
        newArray[i] = mArray[i];
    }
    newArray[getLength()] = value;
    delete[] mArray;
    mArray = newArray;
    increaseLength();
//    cout << "mArray elso es uccso eleme: " << mArray[0] << " | " << mArray[getLength()-1] << endl;
}

void IntArrayList::insert(int index, int value) {
    if (getLength() < index) {
        cerr << "index out of range i'll insert it to the end of the array" << endl;
        append(value);
        return;
    }
    increaseLength();
    int* newArray = new int[getLength()];
    for (int i = 0; i < index; i++) {
        newArray[i] = mArray[i];
    }
    newArray[index] = value;
    for (int i = index + 1; i < getLength(); i++) {
        newArray[i] = mArray[i-1];
    }
    delete[] mArray;
    mArray = newArray;
//    cout << "mArray index es uccso eleme: " << mArray[index] << " | " << mArray[getLength()-1] << endl;
}

int IntArrayList::getFirst() {
    if (isEmpty()) {
        cerr << "empty list" << endl;
        return -1;
    }
    return mArray[0];
}

int IntArrayList::getLast() {
    if (isEmpty()) {
        cerr << "empty list" << endl;
        return -1;
    }
    return mArray[getLength()-1];
}

int IntArrayList::getIndex(int value) {
    for (int i = 0; i < getLength(); i++) {
        if (mArray[i] == value) {
            return i;
        }
    }
    cerr << "not found" << endl;
    return -1;
}

int IntArrayList::deleteAtIndex(int index) {
    if (index > getLength()) {
        cerr << "out of range" << endl;
        return -1;
    }
    int* newArray = new int[getLength()-1];
    for (int i = 0; i < index; i++) {
        newArray[i] = mArray[i];
    }
    decreaseLength();
    for (int i = index; i < getLength(); i++) {
        newArray[i] = mArray[i+1];
    }
    delete[] mArray;
    mArray = newArray;
}

IntArrayList::~IntArrayList() {
    delete[] mArray;
    mArray = NULL;
}
