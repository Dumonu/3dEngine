#ifndef CAMERA_H_
#define CAMERA_H_

#include "../geo/geometry.h"

class Camera
{
public:
    int minX, maxY;
    int minY, maxY;
    int minZ, maxZ;

    int numObj;
    Geometry** worldObjects;

    Camera(int MaxObj);
    ~Camera();

    void drawScene();
}

#endif
