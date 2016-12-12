#include <iostream>

using namespace std;
// Define a function like macro that prints out the parameter it gets,
// and adds this string before it "DEBUG: " if __DEBUG is defined.
// Otherwise adds "RELEASE: " before the string.
// Use try it out. Illustrate that it works.
#define __DEBUG
#ifdef __DEBUG
#define print(a) cout << a << "__DEBUG" << endl;
#else
#define print(a) cout << "Release: " << a << endl;
#endif

int main()
{
    print("alma");
    return 0;
}
