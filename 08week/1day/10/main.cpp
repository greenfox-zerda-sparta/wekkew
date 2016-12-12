#include <iostream>

// Create a function like macro that takes an argument.
// It should print the the code of the argument and the value of the argument too.
// E.g.:
//
// #define FunctionLikeMacro(a) //here comes magic
// int Main() {
// 	int a = 23;
// 	FunctionLikeMacro(a);
//
// }
//
// Should have the output:
// Variable a = 23;
// Where both 'a' and '23' are set by the macro.

#define printEverything(a) cout << "variable: " << #a << " ,value: " << a << endl
using namespace std;

int main() {
    string alma = "apple";
    printEverything(alma);
    return 0;
}
