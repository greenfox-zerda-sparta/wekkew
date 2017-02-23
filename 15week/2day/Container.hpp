#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <vector>

using std::vector;

class Container {
public:
Container();
~Container();
void copy_holding_to_manip();
void fill_holding();
bool search(int);
void less_then_half(int);
void more_then_half(int);
vector<int> holding;
vector<int> manip_vector;
};

#endif
