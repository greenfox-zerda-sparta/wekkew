#include <iostream>
#include <vector>

using namespace std;

void increaseAllElementInnerVector(vector<vector<int> >& myVector, int index) {
 for (int i = 0; i < myVector[index].size(); i++) {
    myVector[index][i] ++;
 }
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
	//create a function which increase the given inner vector elements by 1 (one inside vector, holding five 0)
  vector<vector<int> > vectorMatrix(5, vector<int>(5,0));
  increaseAllElementInnerVector(vectorMatrix, 2);
  printVectorMatrix(vectorMatrix);


  return 0;
}
