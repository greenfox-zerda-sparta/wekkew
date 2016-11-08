#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int main() {
  // Create a student Class
  // that has a method `add_grade`, that takes a grade from 1 to 5
  // an other method `get_average`, that returns the average of the grades
  Student juli("Juli");
  juli.addGrade(5);
  juli.addGrade(3);
  juli.addGrade(1);
  juli.addGrade(7);
  cout << juli.gradeAverage() << endl;


  return 0;
}
