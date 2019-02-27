#pragma once
#include "constants.h"

__interface IOGLDraw
{
public:

	virtual void Draw(XY x_y, GPE_RGB r_g_b);

	virtual void Redraw();
};