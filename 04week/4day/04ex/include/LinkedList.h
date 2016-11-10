#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <IntList.h>


class LinkedList : public IntList {
    private:
        class Node {
            public:
                int value;
                int* nextItem;
                Node(int value) {this.value = value;}
                ~Node();
        };
    public:
        LinkedList();
        void append(int);
		void insert(int, int);
		int getFirst();
		int getLast();
		int getIndex(int);
		int deleteAtIndex(int);
        virtual ~LinkedList();
};

#endif // LINKEDLIST_H
