#include "hzpch.h"
#include "Vector2.h"

Vector2::Vector2(float _n)
{
    x = _n;
    y = _n;
}

Vector2::Vector2(float _x, float _y)
{
    x = _x;
    y = _y;
}

Vector2::Vector2(const Vector2& _vec)
{
    x = _vec.x;
    y = _vec.y;
}
