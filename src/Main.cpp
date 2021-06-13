#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <vector>

#include "time.h"
#include "RenderWindow.h"
#include "Entity.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



int main(int argc, char* args[])
{

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	if (!(IMG_Init(IMG_INIT_PNG)))
		printf("IMG_Init could not initialize! Error: %s\n", SDL_GetError());

	RenderWindow window("title", SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_Texture* sky = window.loadTexture("gfx/tiles1.png");
	SDL_Texture* quote = window.loadTexture("gfx/quote.png");
	std::vector<Entity> entities = {
		Entity(Vector2f(0,0), sky),
		Entity(Vector2f(100,100), quote),
		Entity(Vector2f(100,0), sky),
	};

	bool progRunning = true;
	SDL_Event event;
	const float timeStep = 0.01f;
	float ac = 0.0f;
	float currentTime = time::hireTimeInSeconds();
	while (progRunning)
	{
		int startTicks = SDL_GetTicks();
		float newTime = time::hireTimeInSeconds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;
		ac += frameTime;

		while (ac >= timeStep)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					progRunning = false;
			}
			ac -= timeStep;
			
		}
		const float alpha = ac / timeStep;
		window.clear();
		for (Entity& i : entities)
			window.render(i);
		window.display();

		int frameTicks = SDL_GetTicks() - startTicks;
		if (frameTicks < 1000)
			SDL_Delay(1000 - frameTicks);
	}
	window.cleanUp();
	SDL_Quit();
	return 0;
}