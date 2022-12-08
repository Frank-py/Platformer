#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>
#include <Math.hpp>

class Entity
{
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tex);
	Vector2f& getPos()
	{
		return pos;
	}
	Vector2f getPosCopy()
	{
		return pos;
	}
	void setPos(Vector2f posold)
	{
		pos.x = posold.x;
		pos.y = posold.y;
	}
	SDL_Texture* getTex();
	bool collision(std::vector<Entity> Entities);
	SDL_Rect getCurrentFrame();
	SDL_Rect currentFrame;
	Vector2f pos;
	SDL_Texture* tex;
};