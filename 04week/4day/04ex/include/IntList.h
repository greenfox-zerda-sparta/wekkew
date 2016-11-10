#ifndef INT_LIST_HPP
#define INT_LIST_HPP

class IntList {
	private:
		int mLength;
	public:
	    IntList();
	    void increaseLength();
	    void decreaseLength();
		virtual void append(int) = 0;
		virtual void insert(int, int) = 0;
		virtual int getFirst() = 0;
		virtual int getLast() = 0;
		virtual int getIndex(int) = 0;
		virtual int deleteAtIndex(int) = 0;
		int getLength();
		bool isEmpty();
        virtual ~IntList();
};



#endif
