#pragma once

#include "stdafx.h"
#include "IOGLDraw.h"
#include "constants.h"

using namespace std;

//Game-plant elenet.
class GPE : public IOGLDraw
{

private:

	XY _P{ 0, 0 };

	GPE_RGB _C{ 0.5, 0.5, 0.5 };

public:

	GPE();

	GPE(XY x_y, GPE_RGB r_g_b);

	~GPE();

	void SetRandomColor();

	void SetRandomPosition();

	XY GetPosition();

	void SetPosition(XY x_y);

	virtual void Draw(XY x_y, GPE_RGB r_g_b);

	virtual void Redraw();

	GPE & operator = (GPE & gpe);

	GPE & operator = (GPE gpe);
};

