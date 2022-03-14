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


void Character::move(int dir)
{
   switch (dir)
        {
                case 0:
                        yaccel = -1.5;
                        break;
                case 1:
                        xaccel = -1.5;
                        break;
                case 2:
                        xaccel = 1.5;
                        break;
                case 3:
                        yaccel = 1.5;
                        break;
                //case 4:
                        //yaccel = 2;
        }
        return;
        
}


void Character::update(int time, std::vector<Grass>* grassEntitiees)
{
        if (yvel == 0 && xvel == 0){
                Animation();
        }

        xvel = xaccel * time;
        yvel = yaccel * time;

        if (!(collision(grassEntitiees))){
                pos.y += yvel;
                pos.x += xvel;
                //yaccel = 2;
        }
        yaccel = 0;
        xaccel = 0;
}




bool Character::collision(std::vector<Grass>* grassEntitiees){
        for (Grass& e : *grassEntitiees){
                        if (
                                e.pos.x + e.currentFrame.w*4 >= pos.x+xvel+15*4 &&
                                pos.x+xvel-13*4 + currentFrame.w*4 >= e.pos.x &&
                                e.pos.y + e.currentFrame.h*4 >= pos.y+yvel+15*4 &&
                                pos.y+yvel-8*4 + currentFrame.h*4 >= e.pos.y
                        )
                        {
                                std::cout << "true\n";
                                        return true;
                        }
        }
                                std::cout << "false\n";
        return false;
}	