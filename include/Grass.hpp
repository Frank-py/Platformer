#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"
#include <Math.hpp>

class Grass : public Entity
{
public:
    Grass(Vector2f p_pos, SDL_Texture* p_tex);
};