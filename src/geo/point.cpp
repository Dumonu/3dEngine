#include <cstdio>
#include <SDL_video.h>
#include "../global.h"
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
    int x, y;
    int winWidth;
    int winHeight;
    SDL_GetWindowSize(win, &winWidth, &winHeight);
    x = (winWidth / 2) + (tuple[0]);
    y = (winHeight / 2) + (tuple[1]);
    SDL_RenderDrawPoint(renderer, x, y);
}
