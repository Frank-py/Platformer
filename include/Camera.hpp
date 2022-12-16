#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "Math.hpp"
class Camera
{
public:
    Camera(Vector2f p_pos);
    void updateCamera(Vector2f p_pos, int width, int height);


    Vector2f pos;
private:
    float velocity = 0.5;
};