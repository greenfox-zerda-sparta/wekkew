#include <iostream>
using namespace std;

struct Vector {
  unsigned int size;
  double* vector = NULL;
};

void printVector(Vector& vector) {
  for (unsigned int i = 0; i < vector.size; i++) {
    cout <<"vector.array[" << i << "]: " << vector.vector[i] << endl;
  }
  cout << "vector.size: " << vector.size << endl;
}

Vector* constructVector(double* input,unsigned int size) {
  Vector* newVector = new Vector;
  newVector->size = size;
  newVector->vector = new double[size];
  for (unsigned int i = 0; i < size; i++) {
    newVector->vector[i] = input[i];
  }
  return newVector;
}

double atVectorIndex(Vector& vector, unsigned int index) {
  return index > vector.size-1 ? 0: vector.vector[index];
}

void insertToVectorIndex(Vector& vector, unsigned int index, double value) {
  vector.size++;
  double* newVector  = new double[vector.size];
//  for (unsigned int i = 0; i < vector.size; i++) {
//    if (i < index) {
//      newVector[i] = vector.vector[i];
//    }
//    else if (i == index) {
//      newVector[i] = value;
//    }
//    else {
//      newVector[i] = vector.vector[i-1];
//    }
//  }
  for (unsigned int i = 0; i < index; i++) {
    newVector[i] = vector.vector[i];
  }
  newVector[index] = value;
  for (unsigned int i = index+1; i < vector.size; i++) {
    newVector[i] = vector.vector[i-1];
  }
  delete[] vector.vector;
  vector.vector = newVector;
}

int findIndexInVector(Vector& vector, double value) {
  for (unsigned int i = 0; i < vector.size; i++) {
    if (vector.vector[i] == value) {
      return i;
    }
  }
  return -1;
}

void removeFromVectorIndex(Vector& vector, unsigned int index) {
  vector.size--;
  double* newVector = new double[vector.size];
  for (unsigned int i = 0; i < index; i++) {
    newVector[i] = vector.vector[i];
  }
  for (unsigned int i = index; i < vector.size; i++) {
    newVector[i] = vector.vector[i+1];
  }
  delete vector.vector;
  vector.vector = newVector;
}

Vector* concatTwoVectors(Vector& firstV, Vector& secondV) {
  Vector* concatVector = new Vector;
  concatVector->size = firstV.size+secondV.size;
  concatVector->vector = new double[concatVector->size];
  for (unsigned int i = 0; i < firstV.size; i++) {
    concatVector->vector[i] = firstV.vector[i];
  }
  for (unsigned int i = firstV.size; i < concatVector->size; i++) {
    concatVector->vector[i] = secondV.vector[i-firstV.size];
  }
  return concatVector;
}

int main() {
  double array[2] = {1, 2};
  double secondArray[4] = {3, 4, 5, 6};
  Vector* myVector = constructVector(array, 2);
  Vector* secondVector = constructVector(secondArray, 4);
  printVector(*myVector);
  printVector(*secondVector);
  Vector* mySuperMotherFuckerConcatedVector = concatTwoVectors(*myVector, *secondVector);
  printVector(*mySuperMotherFuckerConcatedVector);
	delete[] myVector->vector;
	delete[] secondVector->vector;
	delete[] mySuperMotherFuckerConcatedVector->vector;
	delete myVector;
	delete secondVector;
	delete mySuperMotherFuckerConcatedVector;
  return 0;
}
