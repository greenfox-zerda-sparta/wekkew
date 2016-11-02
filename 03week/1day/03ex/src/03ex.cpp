#include <iostream>

using namespace std;

void evridzsaajz() {
  cout << "how many numbers do you want to average?" << endl;
  int counter;
  cin >> counter;
  float* numbers = new float[counter];
  for (int i = 0; i < counter; i++){
    cout << "enter the " << i+1 << " number." << endl;
    cin >> numbers[i];
  }
  float sum;
  for (int i = 0; i < counter; i++) {
    sum += numbers[i];
  }
  cout << "The average is: " << sum/counter << endl;
  delete[] numbers;
  numbers = NULL;
}

/**
 * Please create a program that asks for a count when it starts.
 * It should ask for a number count times, then it should print the average of the numbers.
 * It should delete any dynamically allocated resource before the program exits.
 */

int main() {
  evridzsaajz();
  return 0;
}
