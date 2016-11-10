#ifndef INTARRAYLIST_H
#define INTARRAYLIST_H

#include "IntList.h"
// Inherit from IntList and create an implementation that uses an array to store list elements!

class IntArrayList: public IntList {
    private:
        int* mArray;
    public:
        IntArrayList();
        void append(int);
		void insert(int, int);
		int getFirst();
		int getLast();
		int getIndex(int);
		int deleteAtIndex(int);
        ~IntArrayList();
};

#endif // INTARRAYLIST_H
