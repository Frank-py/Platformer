#include "Character.hpp"
#include "Entity.hpp"
#include "SDL2/SDL.h"
#include "Grass.hpp"
#include <iostream>
Character::Character(Vector2f p_pos, SDL_Texture* p_tex)
:Entity(p_pos, p_tex){
        currentFrame.w = 64;
        currentFrame.h = 64;

        framesAmount.x = 4;
        framesAmount.y = 2;
        
}
void Character::reset()  {
        GRAVITY = 0.08;
        acceleration.x = 0;
        acceleration.y = 0;
        velocity.x = 0;
        velocity.y = 0;
        pos.x = 0;
        pos.y =0;
        

}

void Character::Animation(){
        static int counter = 0;
        ++counter;
        if (counter == 20){
                counter = 0;
                currentFrame.y = (currentFrame.y == 0) ? 1 : 0;
                currentFrame.x = 0;
        }
        if (counter % 5 == 0)
        {
                currentFrame.x += 64;
        }
}


void Character::move(int dir, int time)
{

        

   switch (dir)
        {
                case 0:
                        acceleration.y = -ACCEL;
                        GRAVITY = 0.08;
                        acceleration.y -= GRAVITY;
                        
                        break;
                case 1:
                        acceleration.x = -ACCEL;
                        break;
                case 2:
                        acceleration.x = +ACCEL;
                        break;
                case 3:
                        acceleration.x = 0;
                        acceleration.y += GRAVITY; 
                        velocity.x = 0;
                        velocity.y = 0;
                        break;
                default:
                        break;
        }
        return;
        
}


void Character::update(int time)
{
        Animation();
        GRAVITY *= 1.03;
        
        velocity += acceleration * time;
        pos += velocity * time;

        acceleration = Vector2f();
}




