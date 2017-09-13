#include <cstdio>
#include "point.h"

Point::Point(double x, double y, double z)
{
    tuple[0] = x;
    tuple[1] = y;
    tuple[2] = z;
}

Point Point::operator+(Vector V)
{
    Point ret(this->tuple[0] + V.tuple[0], this->tuple[1] + V.tuple[1], this->tuple[2] + V.tuple[2]);
    return ret;
}

Point Point::operator-(Vector V)
{
    Point ret(this->tuple[0] - V.tuple[0], this->tuple[1] - V.tuple[1], this->tuple[2] - V.tuple[2]);
    return ret;
}

Vector Point::operator-(Point P)
{
    Vector ret(this->tuple[0] - P.tuple[0], this->tuple[1] - P.tuple[1], this->tuple[2] - P.tuple[2]);
    return ret;
}

void Point::draw()
{
    std::printf("(%lf, %lf, %lf)\n", tuple[0], tuple[1], tuple[2]);
}
