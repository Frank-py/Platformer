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
    void move(int dir);
    bool collision(std::vector<Grass>* grassEntitiees);
    void update(int time, std::vector<Grass>* grassEntitiees);
private:
    float xaccel, yaccel, xvel, yvel = 0;

};