#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account {
public:
  double balance;
  string name;
public:
  Account(string);
  double getBalance();
  void topUp(double);
};

#endif
