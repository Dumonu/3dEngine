#ifndef VECTOR_H_
#define VECTOR_H_

class Vector
{
    public:
        double tuple[3]; //(x, y, z)

        Vector(double x = 0, double y = 0, double z = 0);

        Vector operator+(Vector V);
        Vector operator-(Vector V);
};

#endif
