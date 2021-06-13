#pragma once
#include <SDL.h>

namespace time
{
	inline float hireTimeInSeconds()
	{
		float t = SDL_GetTicks();
		t *= 0.001f;
		return t;
	}
};

