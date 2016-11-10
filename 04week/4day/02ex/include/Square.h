#ifndef SQUARE_H
#define SQUARE_H

using namespace std;

class Square : public Shape {
    public:
        Square();
        string* getName();
        virtual ~Square();
};

#endif // SQUARE_H
