#include <cmath>
#include "../global.h"
#include "vector.h"

Vector::Vector(double x, double y, double z)
{
    tuple[0] = x;
    tuple[1] = y;
    tuple[2] = z;
}

Vector Vector::operator+(Vector V)
{
    Vector ret(this->tuple[0] + V.tuple[0], this->tuple[1] + V.tuple[1], this->tuple[2] + V.tuple[2]);
    return ret;
}

Vector Vector::operator-(Vector V)
{
    Vector ret(this->tuple[0] - V.tuple[0], this->tuple[1] - V.tuple[1], this->tuple[2] - V.tuple[2]);
    return ret;
}

Vector Vector::rotateXY(double theta)
{
    Vector ret;
    theta = (theta * 2 * PI) / 360;
    ret.tuple[0] = (this->tuple[0] * std::cos(theta)) - (this->tuple[1] * std::sin(theta));
    ret.tuple[1] = (this->tuple[0] * std::sin(theta)) + (this->tuple[1] * std::cos(theta));
    ret.tuple[2] = this->tuple[2];

    return ret;
}

Vector Vector::rotateYZ(double theta)
{
    Vector ret;
    theta = (theta * 2 * PI) / 360;
    ret.tuple[0] = this->tuple[0];
    ret.tuple[1] = (this->tuple[1] * std::cos(theta)) - (this->tuple[2] * std::sin(theta));
    ret.tuple[2] = (this->tuple[1] * std::sin(theta)) + (this->tuple[2] * std::cos(theta));

    return ret;
}

Vector Vector::rotateXZ(double theta)
{
    Vector ret;
    theta = (theta * 2 * PI) / 360;
    ret.tuple[0] = (this->tuple[0] * std::cos(theta)) + (this->tuple[2] * std::sin(theta));
    ret.tuple[1] = this->tuple[1];
    ret.tuple[2] = (this->tuple[2] * std::cos(theta)) - (this->tuple[0] * std::sin(theta));

    return ret;
}

Vector Vector::scale(double s0, double s1, double s2)
{
    return Vector(this->tuple[0] * s0, this->tuple[1] * s1, this->tuple[2] * s2);
}
