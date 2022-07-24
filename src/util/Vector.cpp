#include "Vector.hpp"

void Vector2D::operator+=(const Vector2D &vec2)
{
    x += vec2.x;
    y += vec2.y;
}