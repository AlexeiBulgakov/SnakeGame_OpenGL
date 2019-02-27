#pragma once
#include "stdafx.h"

//Abbreviations:
//MaxGS  - max game speed.
//MinGS  - min game speed.
//MTLD   - max time life of snake dish.
//GPS    - game-plant by square.
//GPP    - game-plant by pixels.
//GPE    - game-plant elenet.
//MSL    - max snake lenght.
//MSD    - max snake dish.
//SD     - directions of snake moving.
//DP     - display pixel.
//ST	 - system time.

const int DP_W = 1920;				//the display resolution on weight.
const int DP_H = 1080;				//the display resolution on height.

const int GPS_S = 10;				//a square size (gor OpenGL).
const int GPS_H = DP_H / GPS_S;		//count of square in GPS in height.
const int GPS_W = DP_W / GPS_S;		//count of square in GPS in weight.

const int MSL  = 1000;				//max snake lenght.
const int MSD  = 100;				//max snake dish.
const int MTLD = 20;				//max time life of snake dish.

const int MinGS = 50;				//min game speed.
const int MaxGS = 10;				//max game speed.


//Directions of snake moving.
enum SD
{
	A, //up.
	D, //down.
	L, //left.
	R  //right.
};


//Game-plant position.
struct XY
{
	int X{ 0 };
	int Y{ 0 };

	XY() {};

	XY(int x, int y)
	{
		X = x;
		Y = y;
	};

	void SetRandom()
	{
		X = rand() % GPS_W;
		Y = rand() % GPS_H;
	};

	static XY GetRandom()
	{
		XY x_y;
		x_y.SetRandom();
		return x_y;
	};

	bool operator == (XY x_y)
	{
		if (X == x_y.X && Y == x_y.Y)
			return true;

		return false;
	};
};


//RGB-color in into 0-1 diapason.
struct GPE_RGB
{
	float R{ 1.0 };
	float G{ 1.0 };
	float B{ 1.0 };

	GPE_RGB() {};

	GPE_RGB(float red, float green, float blue)
	{
		R = red;
		G = green;
		B = blue;
	};

	void SetRandom()
	{
		R = (rand() % 100) / 100; 
		G = (rand() % 100) / 100;
		B = (rand() % 100) / 100;
	};

	static GPE_RGB GetRandom()
	{
		GPE_RGB r_g_b{};
		r_g_b.SetRandom();
		return r_g_b;
	};
};


//For syncronization GPE.
inline SYSTEMTIME ST;
inline u_short GetSystemSeconds()
{
	GetLocalTime(&ST);
	return (ST.wHour * 3600 + ST.wMinute * 60 + ST.wSecond);
};