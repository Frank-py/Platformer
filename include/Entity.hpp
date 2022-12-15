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
	void updatePos(Vector2f offset) {
		pos.x = pos.x + offset.x;
		pos.y = pos.y + offset.y;
	}
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
	SDL_Rect currentFrame;
	Vector2f pos;
	SDL_Texture* tex;
};