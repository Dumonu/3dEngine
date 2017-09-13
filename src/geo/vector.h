#ifndef VECTOR_H_
#define VECTOR_H_

class Vector
{
    public:
        double tuple[3]; //(x, y, z)

        Vector(double x, double y, double z);

        Vector operator+(Vector V);
        Vector operator-(Vector V);
};

#endif
