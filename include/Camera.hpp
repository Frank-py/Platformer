#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"
#include <vector>
#include "Math.hpp"
class Camera: public Entity
{
public:
    Camera(int p_pos);
    

private:
    int C_pos;
    float velocity = 0.5;
};