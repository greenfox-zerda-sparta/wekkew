#include <iostream>

// Create a function like macro, that gets an expression as it's input.
// If the expression is false, it should print out some error message.
#define printErrorIfFalse(a) a ? : cout << "error" << endl
using namespace std;

int main() {
    printErrorIfFalse(1>2);
    return 0;
}
