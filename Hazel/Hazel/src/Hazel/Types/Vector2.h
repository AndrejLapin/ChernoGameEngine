#pragma once

class Vector2
{
public:
    Vector2() = default;
    Vector2(float _n);
    Vector2(float _x, float _y);
    Vector2(const Vector2& _vec);

public:
    float x, y;
};