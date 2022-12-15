
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Grass.hpp"
#include "Character.hpp"
SDL_DisplayMode DM;

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;
/*
TTF_Font* font32 = TTF_OpenFont("res/font/font.ttf", 32);
TTF_Font* font48 = TTF_OpenFont("res/font/font.ttf", 48);
TTF_Font* font24 = TTF_OpenFont("res/font/font.ttf", 24);
Mix_Chunk* chargeSfx = Mix_LoadWAV("res/sfx/charge.mp3");
Mix_Chunk* swingSfx = Mix_LoadWAV("res/sfx/swing.mp3");
Mix_Chunk* holeSfx = Mix_LoadWAV("res/sfx/hole.mp3");
TTF_CloseFont(font32);
TTF_CloseFont(font24);
SDL_Quit();
TTF_Quit();
Mix_PlayChannel(-1, swingSfx, 0);
    window.renderCenter(0, 0 + 3, "POLYMARS", font32, black);
    window.renderCenter(0, 0, "POLYMARS", font32, white);
deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency() );
*/

            
// bool collide(std::vector<Grass> blocks, Character player){
// for (Grass& e : blocks){
// 		if (
// 			e.pos.x + e.currentFrame.w*4 >= player.pos.x+15*4 &&
// 			player.pos.x-13*4 + player.currentFrame.w*4 >= e.pos.x &&
// 			e.pos.y + e.currentFrame.h*4 >= player.pos.y+15*4 &&
// 			player.pos.y-8*4 + player.currentFrame.h*4 >= e.pos.y
// 		)
// 		{
// 				std::cout << "true\n";
// 				return true;
// 		}
// }
// std::cout << "false\n";
// return false;
// }	



int main(int argc, char* args[])
{
if (SDL_Init(SDL_INIT_VIDEO) > 0)
    std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

if (!(IMG_Init(IMG_INIT_PNG)))
    std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

//if (TTF_Init() == -1)
//	std::cout << "TTF_init has failed. Error: " << SDL_GetError() << std::endl;

// Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
SDL_GetCurrentDisplayMode(0, &DM);
RenderWindow window("Spiel", DM.w, DM.h);


SDL_Texture* grass = window.loadTexture("bin/debug/res/gfx/ground_grass_1.png");
SDL_Texture* Player = window.loadTexture("bin/debug/res/gfx/Idle1.png");
SDL_Texture* Hintergrund = window.loadTexture("bin/debug/res/gfx/sky.png");
//std::vector<Grass> grassEntitiees = {Grass(Vector2f(0, DM.h-128), grass)};
std::vector<Grass> grassEntitiees = {Grass(Vector2f(0, DM.h-128), grass)};
for (int i = 128; i < DM.w; i+=128)
{
    grassEntitiees.push_back(Grass(Vector2f(i, DM.h-128), grass));
};
grassEntitiees.push_back(Grass(Vector2f(200, 700), grass));
grassEntitiees.push_back(Grass(Vector2f(0, DM.h-2*128), grass));
Character PlayerEntity = Character(Vector2f(DM.w/2, 0), Player);




bool gameRunning = true;

SDL_Event event;
const Uint8 *keystate = SDL_GetKeyboardState(NULL);
while (gameRunning)
{
    Vector2f alte = PlayerEntity.getPosCopy();
    lastTick = currentTick;
    currentTick = SDL_GetPerformanceCounter();
    deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency() );

    PlayerEntity.move(deltaTime,keystate);
    

    std::vector <Entity> grassEntities(grassEntitiees.begin(), grassEntitiees.end());
    //PlayerEntity.collision(grassEntities, deltaTime);

    PlayerEntity.update(grassEntities,deltaTime);
    //std::cout << std::endl;
    
    


    while (SDL_PollEvent(&event))
    {
        switch (event.type) {
            case SDL_QUIT:
                gameRunning = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                    {
                    case SDLK_f:  window.ToggleFullscreen(); break;
                    case SDLK_q: gameRunning = false; break;
                    case SDLK_e: PlayerEntity.reset();break;

                    }
                }
            }


            window.clear();
            window.renderbg(Hintergrund, DM.w, DM.h);
            window.render(PlayerEntity);
            for (Grass& e : grassEntitiees)
            { 
                    window.render(e);
            }
            window.display();
}
window.cleanUp();
// TTF_CloseFont(font32);
// TTF_CloseFont(font24);
//	TTF_Quit();

SDL_Quit();

return 0;
}
