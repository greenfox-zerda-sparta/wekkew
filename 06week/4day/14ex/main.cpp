#include <iostream>
#include <vector>
#include "car.h"
using namespace std;

void fillParkingHouse(vector<vector<vector<car> > >& actualVector) {
  for (int i = 0; i < actualVector.size(); i++) {
    for (int j = 0; j < actualVector[i].size(); j++) {
      for (int k = 0; k < actualVector[i][j].size(); k++) {
        actualVector[i][j][k] = car();
      }
    }
  }
}

int main () {
	//Create a vector of string, for the following car types:
	//"Moszkvics", "Volga", "ZISZ", "Tatra", "Zbrojovka", "Hotchkiss", "DAF", "Warszawa", "Puli", "Balaton",
	//"Benz", "Marauder", "Zsiguli" , "IFA", "Fjord", "Trabant", "Wartburg", "Martini"
	//Create a vector of strings, for the following colors:
	//"Piros", "Narancss�rga", "Z�ld", "K�k", "T�rkiz", "Barna", "Lila", "S�rga", "Fekete", "Feh�r"
	//Create a Car class, which holds 3 strings, the name of a car, the color of it, and the platenumber in a format like "AAA"-"000"
	//Create a 3 dimensional vector of our car class, that will represent a "parking house"
		//1 dimension: row of cars
		//2 dimension: cars on a platform like a table game
		//3 dimension: "parking house"
	//Make this parking house 4*4*8 (4*4 platform on 8 floors), then fill it with cars! :)
	//Give these cars a random type from our car type vector!
	//Give these cars a random color from our color vector!
	//Give these cars a random plate number!

	//Make sure there are no duplicates in car plates!

	//Print out how much "S�rga"-"Zsiguli" we have, with their position and platenumber in the parking house!
	//At the end empty the parking house!
  srand(time(NULL));
  vector<vector<vector<car> > > parkingHouse(8, vector<vector<car> >(4, vector<car>(4)));
  fillParkingHouse(parkingHouse);
  cout << parkingHouse[2][2][2].getData() << endl;
  cout << parkingHouse[3][3][3].getData() << endl;
  cout << parkingHouse[1][1][1].getData() << endl;
  return 0;
}
