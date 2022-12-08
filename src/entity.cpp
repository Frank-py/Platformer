#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex)
{
}

SDL_Texture* Entity::getTex()
{
	return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}

bool Entity::collision(std::vector<Entity> Entities) {
for (Entity e: Entities)
        {
                if ((pos.y+getCurrentFrame().h*4 > e.pos.y && pos.y < e.pos.y+e.getCurrentFrame().h*4) && (pos.x+getCurrentFrame().w*4 > e.pos.x && pos.x < e.pos.x+e.getCurrentFrame().w*4)) {
                        std::cout << "collision" << std::endl;                       

                }

        }
        return true;
}