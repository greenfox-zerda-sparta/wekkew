#include <string>
#include <iostream>

using namespace std;

// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters
//
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a reference to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)
//
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.
//
// Create a function that takes an array of houses (and it's length),
// then it creates a new array that consists new houses with the calculated price,
// but all the other properties are the same.

struct House {
  string address;
  long int price;
  int rooms;
  int area;
};

bool worthToBuy(House houses) {
  int marketPrice = 400;
  if (houses.price/houses.area <= marketPrice) {
    return true;
    }
  return false;
}

int howmanyWorthToBuy(House* houses, int length) {
  int counter;
  for (int i = 0; i < length; i++) {
    if (worthToBuy(houses[i])) {
      counter++;
    }
  }
  return counter;
}

House* cheapHouses(House* houses, int length) {
  House* worthToBuyHouses = new House[howmanyWorthToBuy(houses, length)];
  int wtbhIndex = 0;
  for (int i = 0; i < length; i++) {
    if (worthToBuy(houses[i])) {
      worthToBuyHouses[wtbhIndex] = houses[i];
      wtbhIndex++;
    }
  }
  return worthToBuyHouses;
}

int main() {
  House* houses = new House[3];
//  houses = {
//      {"1032 Bp. Váradi u 24", 42000, 1, 29},
//      {"1066 Bp Andrássy u 66", 300000, 8, 200},
//      {"Gyöngyöstarján Rózsa utca 5", 10000, 4, 80}
//  };
  houses[0] = {"1032 Bp. Váradi u 24", 42000, 1, 29};
  houses[1] = {"1066 Bp Andrássy u 66", 300000, 8, 200};
  houses[2] = {"Gyöngyöstarján Rózsa utca 5", 10000, 4, 80};
  int length = 3;
  cout << worthToBuy(houses[0]) << endl;
  cout << howmanyWorthToBuy(houses, length) << endl;

  House* worthToBuyHouses = cheapHouses(houses, length);

  delete[] houses;
  houses = NULL;
  delete[] worthToBuyHouses;
  worthToBuyHouses = NULL;
  return 0;
}
