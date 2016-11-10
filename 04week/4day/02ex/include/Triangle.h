#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Shape.h>

using namespace std;

class Triangle : public Shape {
    public:
        Triangle();
        string* getName();
        virtual ~Triangle();
};

#endif // TRIANGLE_H
