#include <iostream>
#include <string>

using namespace std;

class Student {
  private:
    string name;
    unsigned int age;
  public:
    Student(string name, unsigned int age) {
      this->age = age;
      this->name = name;
    }

    string greet() {
      return "Hello my name is: " + this->name;
    }
    void getName(string newName) {
      this->name = newName;
    }
};

int main() {
  // Create a method on student that takes a string as an argument and
  // changes it's name property
  Student student1("John", 21);
  student1.getName("Carlos");
  cout << student1.greet();

  return 0;
}
