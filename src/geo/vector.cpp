#include "vector.h"

Vector::Vector(double x, double y, double z)
{
    tuple[0] = x;
    tuple[1] = y;
    tuple[2] = z;
}

Vector Vector::operator+(Vector V)
{
    Vector *ret = new Vector(this->tuple[0] + V.tuple[0], this->tuple[1] + V.tuple[1], this->tuple[2] + V.tuple[2]);
    return *ret;
}

Vector Vector::operator-(Vector V)
{
    Vector *ret = new Vector(this->tuple[0] - V.tuple[0], this->tuple[1] - V.tuple[1], this->tuple[2] - V.tuple[2]);
    return *ret;
}
