#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

Student::Student(string name) {
  this->name = name;
}

void Student::addGrade(int grade) {
  if (grade < 1 || grade > 5) {
    cerr << "Invalid grade value! " << grade << endl;
    return;
  }
  gradeCount++;
  int* newArray = new int[gradeCount];
  for (int i = 0; i < gradeCount; i++) {
    newArray[i] = array[i];
  }
  newArray[gradeCount-1] = grade;
  delete array;
  array = newArray;
}

double Student::gradeAverage() {
  int sum = 0;
  for (int i = 0; i < gradeCount; i++) {
    sum = sum + array[i];
  }
  return (sum/gradeCount);
}

Student::~Student() {
  delete[] array;
  array = NULL;
}
