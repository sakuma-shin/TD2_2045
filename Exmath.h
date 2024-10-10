#pragma once
#include<math/Vector2.h>

using namespace KamataEngine;

Vector2 operator+(const Vector2& v1, const Vector2& v2);
Vector2 operator+=(const Vector2& v1, const Vector2& v2);
Vector2 operator-(const Vector2& v1, const Vector2& v2);
Vector2 operator-=(const Vector2& v1, const Vector2& v2);
Vector2 operator*(float s, const Vector2& v);
Vector2 operator*(const Vector2& v, float s);
Vector2 operator/(const Vector2& v, float s);

