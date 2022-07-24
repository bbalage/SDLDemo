#ifndef SDLDEMO_UTIL_VECTOR_H
#define SDLDEMO_UTIL_VECTOR_H

struct Vector2D
{
    Vector2D() : x(0), y(0) {}
    Vector2D(int x, int y) : x(x), y(y) {}

    void operator+=(const Vector2D &vec2);

    int x;
    int y;
};

#endif