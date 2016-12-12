#include <iostream>

#define INTEGER 42
#undef INTEGER
#define INTEGER 43

using namespace std;
// Create a constatn using a prepocesor directive.
// Print it out to the console.
// Undefine it. And then redefine it with a new value.
// Print it out again.

int main() {
    cout << INTEGER << endl;
    return 0;
}
