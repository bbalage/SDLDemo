#ifndef SDLDEMO_UTIL_VECTOR_H
#define SDLDEMO_UTIL_VECTOR_H

struct Vec2
{
    Vec2() : x(0), y(0) {}
    Vec2(int x, int y) : x(x), y(y) {}

    void operator+=(const Vec2 &vec2);

    int x;
    int y;
};

#endif