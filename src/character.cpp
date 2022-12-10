#include "Character.hpp"
#include "Entity.hpp"
#include "SDL2/SDL.h"
#include "Grass.hpp"
#include <iostream>
Character::Character(Vector2f p_pos, SDL_Texture* p_tex)
:Entity(p_pos, p_tex){
        currentFrame.w = 64;
        currentFrame.h = 64;
}
void Character::reset()  {
        GRAVITY = 0.08;
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
               // currentFrame.y = (currentFrame.y == 0) ? 1 : 0;
                currentFrame.x = 0;
        }
        if (counter % 8 == 0)
        {
                currentFrame.x += 64;
        }
}


void Character::move(int time,const Uint8* keystate)
{

        
if (keystate[SDL_SCANCODE_W]){
       acceleration.y = -ACCEL;
        acceleration.y += GRAVITY;
    }
    if (keystate[SDL_SCANCODE_A]){
        acceleration.x = -ACCEL;
        acceleration.y += GRAVITY;
        
    }
    if (keystate[SDL_SCANCODE_D]){
        acceleration.x = +ACCEL;
        acceleration.y += GRAVITY;
    }
    if (keystate[SDL_SCANCODE_S]){
        acceleration.x = +ACCEL;
        acceleration.y += GRAVITY;
    }
   
        return;
        
}


void Character::update(int time)
{
        Animation();

        
        velocity = acceleration * time;
        //pos += velocity * time;
        pos += velocity;

        std::cout << "velocity x: " << velocity.x << "velocity y:" << velocity.y << "\t acceleration x:" << acceleration.x << "acceleration y:" << acceleration.y << std::endl;
        //acceleration = Vector2f();
        acceleration.x *= 0.99;
        acceleration.y += GRAVITY; 


}





bool Character::collision(std::vector<Entity> Entities, int time) {
        

        Vector2f fvelocity = velocity;
        fvelocity = acceleration * time;
        Vector2f fpos = pos;
        fpos += velocity;

for (Entity e: Entities)
        {
                if ((fpos.y+getCurrentFrame().h*4 > e.pos.y && fpos.y < e.pos.y+e.getCurrentFrame().h*4) && (fpos.x+getCurrentFrame().w*4 > e.pos.x && fpos.x < e.pos.x+e.getCurrentFrame().w*4)) {
                        std::cout << "collision" << std::endl;                       
                if ((fvelocity.x != 0 ) && (fvelocity.y != 0) ) {
                    std::cout << "shit shit shit" << std::endl;
                    acceleration.x = 0;
                    acceleration.y = 0;
                    return 1;
                } 
                else if (fvelocity.x != 0) {
                        acceleration.x = 0;
                    return 2;
                } 
                else if (fvelocity.y != 0) {
                        acceleration.y = 0;

                    return 4;
                } 

                }

        }
        return false;
}