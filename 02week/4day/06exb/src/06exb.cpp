#include <iostream>
#include <string>

using namespace std;

int evenFollower(int* array, int length) {
  int followedEven = 0;
  for (int i = 0; i < length - 1; i++) {
    if (array[i] % 2 == 0 && array[i + 1] % 2 == 0) {
      followedEven += 1;
    }
  }
  return followedEven;
}

int main() {
  int numbers[] = { 5, 2, 6, 3, 4, 8, 5, 2, 2, 2 };

  // Write a function that counts how many times is an even number is folowed by
  // another even number in an array

  int length = sizeof(numbers) / sizeof(int);
  cout << evenFollower(numbers, length);

  return 0;
}
