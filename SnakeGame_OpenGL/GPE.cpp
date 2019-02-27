#include "GPE.h"



GPE::GPE() {};


GPE::GPE(XY x_y, GPE_RGB r_g_b)
{
	_P = x_y;
	_C = r_g_b;
};


GPE::~GPE() {};


void GPE::SetRandomColor()
{
	_C.SetRandom();
};


void GPE::SetRandomPosition()
{
	_P.SetRandom();
};


XY GPE::GetPosition()
{
	return _P;
};


void GPE::SetPosition(XY x_y)
{
	_P = x_y;
};


void GPE::Draw(XY x_y, GPE_RGB r_g_b)
{
	_P = x_y;
	_C = r_g_b;

	Redraw();
};


void GPE::Redraw()
{
	glColor3f(_C.R, _C.G, _C.B);

	glRectf(GPS_S * _P.X,
			GPS_S * _P.Y,
			GPS_S * (_P.X + 1),
			GPS_S * (_P.Y + 1));
};


GPE & GPE::operator = (GPE & gpe)
{
	_P = gpe._P;
	_C = gpe._C;

	return *this;
};

GPE & GPE::operator = (GPE gpe)
{
	_P = gpe._P;
	_C = gpe._C;

	return *this;
};