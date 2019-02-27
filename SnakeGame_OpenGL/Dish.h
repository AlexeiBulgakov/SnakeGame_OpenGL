#pragma once
#include "GPE.h"

class Dish : public IOGLDraw
{
private:

	GPE _gpe;

public:

	Dish();

	Dish(XY x_y, GPE_RGB r_g_b);

	~Dish();

	XY GetPosition();

	void Draw(XY x_y, GPE_RGB r_g_b);

	void Redraw();
};

