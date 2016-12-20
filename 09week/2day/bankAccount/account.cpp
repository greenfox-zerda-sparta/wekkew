#include "account.h"

using namespace std;

Account::Account(string name) {
  this->name = name;
  balance = 0;
}

double Account::getBalance() {
  return balance;
}

void Account::topUp(double amount) {
  balance += amount;
}
