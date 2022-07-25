#include "Vector.hpp"

void Vec2::operator+=(const Vec2 &vec2)
{
    x += vec2.x;
    y += vec2.y;
}