/*
 * Student.h
 *
 *  Created on: 2016. nov. 8.
 *      Author: dixi
 */

#ifndef STUDENT_H_
#define STUDENT_H_

namespace std {

class Student {
public:
  Student(string name);
  void addGrade(int grade);
  double gradeAverage();

  virtual ~Student();
private:
  string name;
  int* array = new int[0];
  int gradeCount = 0;
};

} /* namespace std */

#endif /* STUDENT_H_ */
