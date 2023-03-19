
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Camera.hpp"
#include "Entity.hpp"
#include "Grass.hpp"
#include "Character.hpp"
SDL_DisplayMode DM;

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;
/*
TTF_Font* font48 = TTF_OpenFont("res/font/font.ttf", 48);
TTF_Font* font24 = TTF_OpenFont("res/font/font.ttf", 24);
Mix_Chunk* chargeSfx = Mix_LoadWAV("res/sfx/charge.mp3");
Mix_Chunk* swingSfx = Mix_LoadWAV("res/sfx/swing.mp3");
Mix_Chunk* holeSfx = Mix_LoadWAV("res/sfx/hole.mp3");
TTF_CloseFont(font24);
SDL_Quit();

Mix_PlayChannel(-1, swingSfx, 0);
    window.renderCenter(0, 0 + 3, "POLYMARS", font32, black);
    window.renderCenter(0, 0, "POLYMARS", font32, white);

*/


int main(int argc, char* args[])
{
if (SDL_Init(SDL_INIT_VIDEO) > 0)
    std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

if (!(IMG_Init(IMG_INIT_PNG)))
    std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

if (TTF_Init() == -1)
	std::cout << "TTF_init has failed. Error: " << SDL_GetError() << std::endl;
TTF_Font* font128 = TTF_OpenFont("bin/debug/res/font/font.ttf", 128);
TTF_Font* comment = TTF_OpenFont("bin/debug/res/font/font.ttf", 32);

// Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

SDL_GetCurrentDisplayMode(0, &DM);
RenderWindow window("Spiel", DM.w, DM.h);

SDL_Texture* Hintergrund = window.loadTexture("bin/debug/res/gfx/sky.png");

window.renderbg(Hintergrund, DM.w, DM.h);
if (window.displayWelcomeMessage(font128, comment, DM.h, DM.w, "Welcome to my Game") == 1) {
    window.cleanUp();
    // TTF_CloseFont(font32);
    // TTF_CloseFont(font24);
    //	TTF_Quit();

    TTF_Quit();
    TTF_CloseFont(comment);
    TTF_CloseFont(font128);
    SDL_Quit();
    return 0;
}
window.display();

SDL_Texture* grass = window.loadTexture("bin/debug/res/gfx/ground_grass_1.png");
SDL_Texture* Player = window.loadTexture("bin/debug/res/gfx/Idlee.png");
//std::vector<Grass> grassEntitiees = {Grass(Vector2f(0, DM.h-128), grass)};
std::vector<Grass> grassEntitiees;
for (int i = -1*DM.w; i < DM.w; i+=128)
{
    grassEntitiees.push_back(Grass(Vector2f(i, 1*DM.h), grass));
};


grassEntitiees.push_back(Grass(Vector2f(200, 1200), grass));
Character PlayerEntity = Character(Vector2f(0, DM.h-32*4), Player);
Camera cam= Camera(PlayerEntity.pos);
cam.updateCamera(PlayerEntity.pos, DM.w, DM.h);

std::vector <Entity> grassEntities(grassEntitiees.begin(), grassEntitiees.end());



bool gameRunning = true;

SDL_Event event;
const Uint8 *keystate = SDL_GetKeyboardState(NULL);
PlayerEntity.reset(0, 0);
while (gameRunning)
{
    lastTick = currentTick;
    currentTick = SDL_GetPerformanceCounter();
    deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency() );


    
    PlayerEntity.move(deltaTime,keystate);
    

    //PlayerEntity.collision(grassEntities, deltaTime);
    std::cout << "grassEntities[0].x: " << grassEntities[0].pos.x << ", grassEntities[0].y: " << grassEntities[0].pos.y << std::endl;  
    PlayerEntity.update(grassEntities,deltaTime);
    if (PlayerEntity.checkifdead(DM.h)) {
        window.displayWelcomeMessage(font128, comment, DM.h, DM.w, "You Died!");
        PlayerEntity.reset(0,0);
    }
    cam.updateCamera(PlayerEntity.pos, DM.w, DM.h);
    
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
                    case SDLK_e: PlayerEntity.reset(0, 0); 
                    cam = Camera(PlayerEntity.pos);
                    break;

                    }
                }
            }


            window.clear();
            window.renderbg(Hintergrund, DM.w, DM.h);
            std::cout << PlayerEntity.pos.x << " " << PlayerEntity.pos.y << std::endl;
            window.render(PlayerEntity, cam.pos);
            for (Entity& e : grassEntities)
            { 
                    window.render(e, cam.pos);
                    //window.render(e, Vector2f(0,0));
            }
            window.display();
}
window.cleanUp();
// TTF_CloseFont(font32);
// TTF_CloseFont(font24);
//	TTF_Quit();

TTF_Quit();
TTF_CloseFont(comment);
TTF_CloseFont(font128);
SDL_Quit();

return 0;
}
