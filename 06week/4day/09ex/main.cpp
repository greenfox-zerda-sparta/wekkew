#include <iostream>
#include <vector>

using namespace std;

void pushTheSameThingToAVectorVictorVectorFuckYeah(vector<vector<int> >& myVector) {
  myVector.push_back(myVector[0]);
}

int main() {
	//create a vector of vector of integers, yeah a vector that holds vectors of integers
	//the inner vectors have 5 integers, all of them 0
	//the outer vector is holding 5 vector at the begining
	//create a function that will add a new vector of integers to the end of our outer vector
  vector<vector<int> > vectorMatrix(5, vector<int>(5,0));
//  vectorMatrix.push_back(vector<int>(5,0));
  pushTheSameThingToAVectorVictorVectorFuckYeah(vectorMatrix);

 return 0;
}
