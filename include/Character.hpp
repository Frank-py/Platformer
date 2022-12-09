#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"
#include <Math.hpp>
#include <vector>
#include "Math.hpp"
#include "Grass.hpp"
class Character: public Entity
{
public:
    Character(Vector2f p_pos, SDL_Texture* p_tex);
    std::vector<SDL_Rect> animationFrames;
    Vector2f frame_size, framesAmount;
    void Animation();
    void move(int dir, int time);
    void update(int time);
    void reset();
    Vector2f velocity = Vector2f();
	bool collision(std::vector<Entity> Entities, int time);

private:
    Vector2f acceleration = Vector2f();
    double ACCEL = 0.1;
    double GRAVITY = 0.08;
};