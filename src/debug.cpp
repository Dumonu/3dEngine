#include "geo/vector.h"
#include "geo/point.h"

int main()
{
    {
    Point point1(1, 2, 1);
    Point point2(0, 4, 4);
    Vector vector1(2, 0, 0);
    Vector vector2(0,0,0);

    point1.draw();
    point2.draw();

    vector2 = point1 - point2;
    vector1 = vector1 + vector2;

    point1 = point1 + vector1;
    point1.draw();

    point2 = point2 - vector2;
    point2.draw();
    }
    return 0;
}
