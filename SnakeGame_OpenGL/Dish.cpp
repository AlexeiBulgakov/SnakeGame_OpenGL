#include "Dish.h"


Dish::Dish()
{
	_gpe = GPE{};
};


Dish::Dish(XY x_y, GPE_RGB r_g_b)
{
	_gpe = GPE{x_y, r_g_b};
};


Dish::~Dish() {};


XY Dish::GetPosition()
{
	return _gpe.GetPosition();
};


void Dish::Draw(XY x_y, GPE_RGB r_g_b)
{
	_gpe.Draw(x_y, r_g_b);
};


void Dish::Redraw()
{
	_gpe.Redraw();
};
