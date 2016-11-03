#include <string>
#include <iostream>

using namespace std;

enum Subject {MATH, HISTORY, ENGLISH, SCIENCE};

struct Grade {
  Subject subject;
  int value;
};

struct Student {
  string name;
  int age;
  Grade* grades;
  int grade_count;
};

// Create a function that constructs a Student (returns a pointer to a new student)
// It should take it's name and it's age as parameter
// It should allocate 5 grades
// It should set the grade_count to 0

Student* newStudent(string callsign, int age) {
  Student* actualStudent = new Student;
  actualStudent->name = callsign;
  actualStudent->age = age;
  actualStudent->grade_count = 0;
  actualStudent->grades = new Grade[5];

  return actualStudent;
}

// Create a function that takes 3 parameters:
// A reference to a Student
// A Subject
// An int (1-5)
// It should set the last grade's values with the given arguments

void grader(Student& student, Subject subject, int grade) {
  int gradeIndex = student.grade_count;
  student.grades[gradeIndex].subject = subject;
  student.grades[gradeIndex].value = grade;
  student.grade_count++;
}

// Create a function that takes a Student as a reference and returns the subject
// that the student has worst grade in

Subject worstGrade(Student& student) {
  int worst = student.grades[0].value;
  int worstIndex;
  for (int i = 0; i < student.grade_count; i++) {
    if(student.grades[i].value < worst) {
      worst = student.grades[i].value;
      worstIndex = i;
    }
  }
  return student.grades[worstIndex].subject;
}

// Create a function that deconstructs a Student
// It should take a pointer that points to the student
// It should deallocate each Grade and the Student itself

void deleteStudent(Student* student) {
  delete[] student->grades;
  student->grades = NULL;
  delete student;
  student = NULL;
}

int main() {
  Student* bakijulia = newStudent("Juli", 26);

  grader(*bakijulia, MATH, 3);
  grader(*bakijulia, HISTORY, 4);
  grader(*bakijulia, ENGLISH, 5);
  grader(*bakijulia, SCIENCE, 2);

  cout << worstGrade(*bakijulia);

  deleteStudent(bakijulia);

  return 0;
}
