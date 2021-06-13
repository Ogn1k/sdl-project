#pragma once
#include <stdio.h>
class Vector2f
{
public:
	Vector2f()
		:x(0.0f), y(0.0f)
	{}

	Vector2f(float p_x, float p_y)
		:x(p_x), y(p_y)
	{}

	void print()
	{
		printf("%f", x, y);
	}

	float x, y;
};

