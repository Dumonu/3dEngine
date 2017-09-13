#ifndef POINT_H_
#define POINT_H_

#include "vector.h"

class Point
{
public:
    double tuple[3]; //(x,y,z)

    Point(double x, double y, double z);

    Point operator+(Vector V);
    Point operator-(Vector V);
    Vector operator-(Point P);

    void draw();
};

#endif
