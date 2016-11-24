#include <iostream>
#include <vector>

using namespace std;

void increaseAllElementInnerVector(vector<vector<int> >& myVector, int exIndex, int inIndex) {
 myVector[exIndex][inIndex] ++;
}

void printVectorMatrix(vector<vector<int> >& myVector) {
  for (int i = 0; i < myVector.size(); i++) {
    for (int j = 0; j < myVector[i].size(); j++) {
      cout << myVector[i][j] << " | ";
    }
    cout << endl;
  }
}

int main() {
	//create a vector of vector of integers
	//the inner vectors have 5 integers, all of them 0
	//the outer vector is holding 5 vector
	//create a function which increase a specific element of an inner vector by 1
  vector<vector<int> > vectorMatrix(5, vector<int>(5,0));
  increaseAllElementInnerVector(vectorMatrix, 2, 2);
  printVectorMatrix(vectorMatrix);

  return 0;
}


