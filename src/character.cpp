#include "Character.hpp"
#include "Entity.hpp"
#include "SDL2/SDL.h"
#include "Grass.hpp"
#include <iostream>
Character::Character(Vector2f p_pos, SDL_Texture* p_tex)
:Entity(p_pos, p_tex){
        currentFrame.y = 0;
        currentFrame.w = 40;
        currentFrame.h = 64;
}
void Character::reset()  {
        GRAVITY = 0.025;
        acceleration.x = 0;
        acceleration.y = 0;
        velocity.x = 0;
        velocity.y = 0;
        pos.x = 0;
        pos.y = 0;
        
        

}

void Character::Animation(){
        static int counter = 0;
        ++counter;
        if (counter == 32){
                counter = 0;
                currentFrame.x = 10;
        }
        if (counter % 8 == 0)
        {
                currentFrame.x += 10;
        }
}


void Character::move(int time,const Uint8* keystate)
{

        
if (keystate[SDL_SCANCODE_W]){
       acceleration.y = -ACCEL;
       std::cout << "velocity x: " << velocity.x << "velocity y:" << velocity.y << "\t acceleration x:" << acceleration.x << "acceleration y:" << acceleration.y << std::endl;

    }
    if (keystate[SDL_SCANCODE_A]){
        acceleration.x = -ACCEL;
        std::cout << "velocity x: " << velocity.x << "velocity y:" << velocity.y << "\t acceleration x:" << acceleration.x << "acceleration y:" << acceleration.y << std::endl;
        
        
    }
    if (keystate[SDL_SCANCODE_D]){
        acceleration.x = +ACCEL;
        std::cout << "velocity x: " << velocity.x << "velocity y:" << velocity.y << "\t acceleration x:" << acceleration.x << "acceleration y:" << acceleration.y << std::endl;
        
    }
    if (keystate[SDL_SCANCODE_S]){
        acceleration.y = +ACCEL;
        std::cout << "velocity x: " << velocity.x << "velocity y:" << velocity.y << "\t acceleration x:" << acceleration.x << "acceleration y:" << acceleration.y << std::endl;
    }

        acceleration.x *= 0.9;
        acceleration.y += GRAVITY;

      
   
        return;
        
}


void Character::update(std::vector<Entity> Entities,int time)
{
        Animation();
        velocity = acceleration * time;
        collision(Entities,time);
        pos.x += velocity.x;
        pos.y += velocity.y;
        
       
  
        


}





void Character::collision(std::vector<Entity> Entities, int time) {
        
       
        
         Vector2f fpos = pos;
         fpos += velocity;
        

for (Entity e: Entities)
        {
                if ((pos.y+getCurrentFrame().h*4> e.pos.y && pos.y < e.pos.y+e.getCurrentFrame().h*4) && (fpos.x+(getCurrentFrame().w)*4> e.pos.x && fpos.x < e.pos.x+e.getCurrentFrame().w*4)) 
                        velocity.x = 0;
                if ((fpos.y+(getCurrentFrame().h)*4> e.pos.y && fpos.y < e.pos.y+e.getCurrentFrame().h*4) && (pos.x+(getCurrentFrame().w)*4> e.pos.x && pos.x < e.pos.x+e.getCurrentFrame().w*4)) {
                        velocity.y = 0;
                        acceleration.y = 0;
                        }

        }
}