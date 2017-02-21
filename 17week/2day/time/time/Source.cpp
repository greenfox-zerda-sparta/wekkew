#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_afternoon(string time);
string return_hours(string time);
string return_minutes(string time);
string return_seconds(string time);
string get_afternoon_hours(string time);
string get_military_time(string time);


int main() {
  string time = "07:05:45PM";
  cout << get_military_time(time) << endl;
  string noon = "00:12:12AM";
  cout << get_military_time(noon) << endl;
  return 0;
}

bool is_afternoon(string time) {
  return time[8] == 'P';
}

string return_hours(string time) {
  string hours;
  if (is_afternoon(time)) {
    return get_afternoon_hours(time);
  }
  else {
    if (time.substr(0, 2) == "12") {
      return "00";
    }
    else {
      return time.substr(0, 2);
    }
  }
}

string return_minutes(string time) {
  return time.substr(3, 2);
}

string return_seconds(string time) {
  return time.substr(6, 2);
}

string get_afternoon_hours(string time) {
  int hours = stoi(time.substr(0, 2));
  int afternoon_hours = hours == 12 ? 12 : hours + 12; 
  return to_string(afternoon_hours);
}

string get_military_time(string time) {
  string miltime = "";
  miltime += return_hours(time);
  miltime += ":";
  miltime += return_minutes(time);
  miltime += ":";
  miltime += return_seconds(time);
  return miltime;
}