#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"
#include <vector>
#include "Math.hpp"
#include "Grass.hpp"
class Character: public Entity
{
public:
    Character(Vector2f p_pos, SDL_Texture* p_tex);
    std::vector<SDL_Rect> animationFrames;
    Vector2f frame_size;
    void Animation();
    void move(int time, const Uint8* keystate);
    void update(std::vector<Entity> Entities,int time);
    void reset();
    Vector2f velocity = Vector2f();
	bool collision(std::vector<Entity> Entities, int time);

private:
    Vector2f acceleration = Vector2f();
     Vector2f faccel = Vector2f();
    Vector2f fvelocity = Vector2f(); 
    const double ACCEL = 0.5;
    double GRAVITY = 0.025;
};