#include <string>
#include <iostream>

using namespace std;

struct Computer {
  string name;
  long long int cpu_speed_hz;
  long long int ram_size;
};

int main() {
  Computer computer;
  computer.name = "Macbook";
  computer.cpu_speed_hz = 3.2e9;
  computer.ram_size = 8e9;

  // Change the name of the computer to "Macbook Pro" and print all the stats

  computer.name = "Macbook Pro";
  cout << computer.cpu_speed_hz << endl;
  cout << computer.name << endl;
  cout << computer.ram_size << endl;

  return 0;
}
