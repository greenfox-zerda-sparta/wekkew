#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVectorMatrix(vector<vector<int> >& actualVector) {
  for (int i = 0; i < actualVector.size(); i++) {
    for (int j = 0; j < actualVector[i].size(); j++) {
      cout << actualVector[i][j] << "| ";
    }
    cout << endl;
  }
}

void increaseOneVectorElement(vector<vector<int> >& actualVector, int exIndex, int inIndex) {
 actualVector[exIndex][inIndex] ++;
}

void increaseAllInnerVectorElement(vector<vector<int> >& actualVector, int index) {
  for (int i = 0; i < actualVector[index].size(); i++) {
    actualVector[index][i] ++;
  }
}

void expandVector(vector<vector<int> >& actualVector) {
  for (int i = 0; i < actualVector.size(); i++) {
    actualVector[i].push_back(0);
  }
  actualVector.push_back(actualVector[0]);
  printVectorMatrix(actualVector);
}

void mirrorVectorMatrixHorizontally(vector<vector<int> >& actualVector) {
  for (int i = 0 ; i < actualVector.size()/2; i++) {
    vector<int> temp = actualVector[i];
    actualVector[i] = actualVector[actualVector.size()-1-i];
    actualVector[actualVector.size()-1-i] = temp;
  }
  // here is the build in function for it :
  //reverse(actualVector.begin(), actualVector.end());
}

void mirrorVectorMatrixVertically(vector<vector<int> >& actualVector) {
  for (int i = 0; i < actualVector.size(); i++) {
    reverse(actualVector[i].begin(), actualVector[i].end());
  }
}

int main() {
	//Create a 2 dimensional vector with matrix!
      // 1 0 0 0
    	// 0 1 0 0
    	// 0 0 1 0
    	// 0 0 0 1
	// Extend it to the following format:
	    // 1 1 1 1 1
    	// 0 1 0 0 1
    	// 0 0 1 0 1
    	// 0 0 0 1 1
	    // 0 0 0 0 1
	// Mirror it horizontaly!
	// Mirror it verticaly!

	vector<vector<int> > vectorMatrix(4, vector<int>(4,0));
  printVectorMatrix(vectorMatrix);
  cout << endl;
  expandVector(vectorMatrix);
  cout << endl;
  increaseAllInnerVectorElement(vectorMatrix, 0);
  increaseOneVectorElement(vectorMatrix, 1, 4);
  increaseOneVectorElement(vectorMatrix, 2, 4);
  increaseOneVectorElement(vectorMatrix, 3, 4);
  increaseOneVectorElement(vectorMatrix, 4, 4);
  increaseOneVectorElement(vectorMatrix, 1, 1);
  increaseOneVectorElement(vectorMatrix, 2, 2);
  increaseOneVectorElement(vectorMatrix, 3, 3);
  printVectorMatrix(vectorMatrix);
  cout << endl;
  mirrorVectorMatrixHorizontally(vectorMatrix);
  printVectorMatrix(vectorMatrix);
  cout << endl;
  mirrorVectorMatrixVertically(vectorMatrix);
  printVectorMatrix(vectorMatrix);

  return 0;
}
