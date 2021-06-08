#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include "RenderWindow.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



int main(int argc, char* args[])
{

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	if (!(IMG_Init(IMG_INIT_PNG)))
		printf("IMG_Init could not initialize! Error: %s\n", SDL_GetError());
	RenderWindow window("title", SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_Texture* sky = window.loadTexture("gfx/sky.png");
	bool progRunning = true;
	SDL_Event event;
	while (progRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				progRunning = false; 
		}
		window.clear();
		window.render(sky);
		window.display();
	}
	window.cleanUp();
	SDL_Quit();
	return 0;
}