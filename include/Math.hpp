#pragma once

#include <iostream>
struct Vector2f
{
  Vector2f()
  :x(0.0f), y(0.0f)
  {}

  Vector2f(float p_x, float p_y)
  :x(p_x), y(p_y)
  {}

  void print()
  {
    std::cout << x << ", " << y << std::endl;
  }

  //Define the multiplication operator:
  Vector2f operator*(const float& scalar) const
  {
    return Vector2f(x * scalar, y * scalar);
  }

  Vector2f operator*(const int& scalar) const
  {
    return Vector2f(x * scalar, y * scalar);
  }
  //Define the *= operator in terms of the * operator:
  Vector2f& operator*=(const float& scalar)
  {
    *this = *this * scalar;
    return *this;
  }

  //Define the addition operator:
  Vector2f operator+(const Vector2f& other) const
  {
    return Vector2f(x + other.x, y + other.y);
  }

  //Define the + operator that adds a scalar to a Vector2f object:
  Vector2f operator+(const float& scalar) const
  {
    return Vector2f(x + scalar, y + scalar);
  }

  //Define the += operator in terms of the + operator:
  Vector2f& operator+=(const Vector2f& other)
  {
    *this = *this + other;
    return *this;
  }
  
  float x, y;
};
