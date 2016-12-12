#include <iostream>

// Create a function like macro. The Macro should take one parameter and
// print out the parameter to the console after printing out in which file
// and at which line it has been called at.

#define printWhereIBelong(a) cout << "filename: " << __FILE__ << endl <<"line: " << __LINE__ << endl << "content:" << a << endl

using namespace std;

int main() {
  string alma = "apple";
    printWhereIBelong(alma);
    return 0;
}
