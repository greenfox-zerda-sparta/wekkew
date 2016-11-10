#include <iostream>
#include "IntList.h"
#include "IntArrayList.h"


using namespace std;
// Take the attached hpp and cpp files. Read them trough.
// Choose either IntArrayList or IntLinkedList and implement it.
// Write code here in a main function that uses it and tests it in edge cases as well.

int main() {
    IntList* theList = new IntArrayList();
    cout << theList->getLast() << endl;
    cout << "length: " << theList->getLength() << endl;
    theList->append(123);
	cout << "length: " << theList->getLength() << endl;
	theList->append(2);
	cout << "length: " << theList->getLength() << endl;
	theList->insert(4, 3);
	cout << "length: " << theList->getLength() << endl;
    theList->insert(1, 1);
    cout << "length: " << theList->getLength() << endl;
    cout << theList->getLast() << endl;
    cout << boolalpha << theList->isEmpty() << endl;

    return 0;
}
