#pragma once
#include "GPE.h"


struct OneSnakeSegment
{
	GPE segment{};
	
	bool is_active{ false };

	bool is_grow_position{ false };
};


class Snake : public IOGLDraw
{
private:

	int _current_lenght{ 0 };

	GPE_RGB _C{ 1.0, 0.0, 0.0 };

	vector<OneSnakeSegment> _B{ MSL };

	SD _sd;

public:

	Snake();

	~Snake();

	SD GetSD();

	void SetSD(SD next);

	int GetLenght();

	XY GetHeadPosition();

	void SetBodyElement(int & numer_body_segment, GPE sbe);

	void MoveTo(SD sd);

	void Grow();

	void MoveAndGrow(SD sd);

	bool IsItSnake(XY sd);

	void Draw(XY x_y, GPE_RGB r_g_b);

	void Redraw();
};

