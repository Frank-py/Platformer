#include "Grass.hpp"
#include "Entity.hpp"
#include "SDL2/SDL.h"

Grass::Grass(Vector2f p_pos, SDL_Texture* p_tex)
:Entity(p_pos, p_tex){
        currentFrame.x = 0;
        currentFrame.y = 0;
        currentFrame.w = 32;
        currentFrame.h = 32;
}