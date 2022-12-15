#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "Math.hpp"
class Camera
{
public:
    Camera(Vector2f p_pos);
    void updateCamera(Vector2f p_pos);
    Vector2f offset;

private:
    float velocity = 0.5;
    Vector2f pos;
};