#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::accumulate;
using std::map;
using std::string;
using std::for_each;

enum car_type {VOLVO, VW, FERRARI, TESLA, TOYOTA, LADA, TRABANT};

class Car {
public:
  string car_color;
  car_type type;
  Car(car_type _type, string _color) {
    car_color = _color;
    type = _type;
  };
};


void with_for_loop(vector<Car>& store) {
  map<string, int> solution;

  for (unsigned int i = 0; i < store.size(); i++) {
    string current_color = store[i].car_color;
    if (solution.find(current_color) != solution.end()) {
      solution[current_color]++;
    }
    else {
      solution[current_color] = 1;
    }
  }

  for (map<string, int>::iterator it = solution.begin(); it != solution.end(); it++) {
    cout << it->first << " : " << it->second << endl;
  }
}

void with_for_each(vector<Car>& store) {
  map<string, int> sol;
  for_each(store.begin(), store.end(), [&](Car car) {
    sol[car.car_color] = sol.find(car.car_color) != sol.end() ? sol[car.car_color] + 1 : 1;
  });
  
  for (map<string, int>::iterator it = sol.begin(); it != sol.end(); it++) {
    cout << it->first << " : " << it->second << endl;
  }
}

//void with_accumulate(vector<Car>& store) {
//  /*map<string, int>* solution_pointer = */
//  accumulate(store.begin(), store.end(), new map<string, int>, [](map<string, int> &sol, Car car) {
//    sol[car.car_color] = sol.find(car.car_color) != sol.end() ? sol[car.car_color] + 1 : 1;
//    //return sol;
//  });
//
//  /*map<string, int> solution = *solution_pointer;
//  
//  for (map<string, int>::iterator it = solution.begin(); it != solution.end(); it++) {
//    cout << it->first << " : " << it->second << endl;
//  }*/
//}

int main() {
  Car my_car(VOLVO, "RED");
  Car kinga_s_car(TESLA, "GREEN");
  Car dr_koi(TRABANT, "WHITE");
  Car eggdice(LADA, "YELLOW");
  Car attus(TRABANT, "GREEN");

  vector<Car> store;
  store.push_back(my_car);
  store.push_back(kinga_s_car);
  store.push_back(dr_koi);
  store.push_back(eggdice);
  store.push_back(attus);

  with_for_loop(store);
  with_for_each(store);
  //with_accumulate(store);
  //not working :(
  return 0;
}