#include <iostream>

// Create a function like macro, that get's one parameter.
// This macro should print out that parameter using cout.
// Illustrate that it works in Your main function.

#define print(a) cout << a << endl
using namespace std;

int main() {
    string hello = "Hello, word!";
    print(hello);
    return 0;
}
