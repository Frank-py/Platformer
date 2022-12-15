#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class RenderWindow 
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void render(Entity& p_entity, Vector2f offset);
	void renderbg(SDL_Texture* tex, int Groesex, int Groesey);

	void ToggleFullscreen();
	void display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};