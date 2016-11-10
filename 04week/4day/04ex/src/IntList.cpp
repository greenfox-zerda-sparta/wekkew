#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList() {
    mLength = 0;
}
void IntList::increaseLength() {
    mLength++;
}

void IntList::decreaseLength() {
    mLength--;
}

int IntList::getLength() {
    return mLength;
}

bool IntList::isEmpty() {
    return mLength == 0;
}

IntList::~IntList() {}
