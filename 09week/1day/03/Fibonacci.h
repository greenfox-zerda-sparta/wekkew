#ifndef FIBONACCI_H
#define FIBONACCI_H

using namespace std;

class Fibonacci {
public:
  FibonacciNumber(int number) {
    if (number <= 1) {
      return number;
    } else {
      return FibonacciNumber(number-1) + FibonacciNumber(number-2);
  
    }
  }
};

#endif
