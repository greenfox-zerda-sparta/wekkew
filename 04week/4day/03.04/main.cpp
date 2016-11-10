#include <iostream>
#include <string>
using namespace std;
// Create a class called ParentClass. CHECK
// It should have two public functions. CHECK
// Both return a string. One virtual, the other not. CHECK
class ParentClass {
    public:
        virtual string* returnString();
        string* returnOtherString();

};
// Each should return a unique string. CHECK
string* ParentClass::returnString() {
    return new string("virtual TROLOLOLO");
}

string* ParentClass::returnOtherString() {
    return new string("SWAG");
}

// Create a ChildClass which inherits from the ParentClass publicly.
// This should override both functions. The virtual and the nonvirtual one both.
class ChildClass: public ParentClass {
    public:
        string* returnString();
        string* returnOtherString();
};
// These should return unique string again.
string* ChildClass::returnString() {
    return new string("child string");
}
string* ChildClass::returnOtherString() {
    return new string("child swagyolo");
}
// Create a main() function. In this function, create a ParentClass* pointer and instantiate a ChildClass member for that pointer.
// Hint: This should look something like this: ParentClass* a = new ChildClass();
int main() {
    ParentClass* a = new ChildClass;
// Print out the result of both functions on this a pointer.
    cout << *(a->returnString()) << endl;
    cout << *a->returnOtherString() << endl;
// Print out the result of both functions if You first cast pointer a to be interpreted as of type ChildClass*
    cout << *((ChildClass*)a)->returnString() << endl;
    cout << *((ChildClass*)a)->returnOtherString() << endl;
    return 0;
}
