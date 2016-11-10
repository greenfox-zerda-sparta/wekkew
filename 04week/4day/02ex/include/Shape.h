#ifndef SHAPE_H
#define SHAPE_H
#include <string>

using namespace std;

class Shape {
    public:
        Shape();
        virtual string* getName();
        virtual ~Shape();
};

#endif // SHAPE_H
