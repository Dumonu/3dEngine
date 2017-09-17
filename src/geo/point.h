#ifndef POINT_H_
#define POINT_H_

#include "vector.h"
#include "geometry.h"

class Point : Geometry
{
public:
    double tuple[3]; //(x,y,z)

    Point(double x = 0, double y = 0, double z = 0);

    Point operator+(Vector V);
    Point operator-(Vector V);
    Vector operator-(Point P);

    void draw();
};

#endif
