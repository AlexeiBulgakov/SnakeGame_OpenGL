#include "Snake.h"


Snake::Snake()
{
	for (auto & [gpe, is_active, is_grow_position] : _B)
	{
		gpe = GPE{ XY {0, 0}, _C };
		is_active = false;
	}

	_B.at(0).segment.SetPosition(XY{ GPS_W / 2, GPS_H / 2 });
	_B.at(0).is_active = true;
};


Snake::~Snake() {};


SD Snake::GetSD()
{
	return _sd;
};


void Snake::SetSD(SD next)
{
	_sd = next;
};


int Snake::GetLenght()
{
	return _current_lenght;
};


XY Snake::GetHeadPosition()
{
	return _B.at(0).segment.GetPosition();
};


void Snake::MoveTo(SD sd)
{
	SetSD(sd);

	for (int i = MSL - 1; i > 0; --i)
		if (_B.at(i).is_active)
			_B.at(i).segment.SetPosition(_B.at(i - 1).segment.GetPosition());

	switch (sd)
	{
		case SD::A:
		{
			_B.at(0).segment.SetPosition(XY{ _B.at(0).segment.GetPosition().X, (_B.at(0).segment.GetPosition().Y + 1) % GPS_H }); break;
		}
		case SD::D:
		{
			_B.at(0).segment.SetPosition(XY{ _B.at(0).segment.GetPosition().X, _B.at(0).segment.GetPosition().Y == 0 ? GPS_H - 1 : (_B.at(0).segment.GetPosition().Y - 1) }); break;
		}
		case SD::L:
		{
			_B.at(0).segment.SetPosition(XY{ _B.at(0).segment.GetPosition().X == 0 ? GPS_W - 1 : (_B.at(0).segment.GetPosition().X - 1), _B.at(0).segment.GetPosition().Y }); break;
		}
		case SD::R:
		{
			_B.at(0).segment.SetPosition(XY{ (_B.at(0).segment.GetPosition().X + 1) % GPS_W, _B.at(0).segment.GetPosition().Y }); break;
		}
		default:
			break;
	}
};

void Snake::Grow()
{
	XY x_y_last_segment = _B.at(_current_lenght++).segment.GetPosition();

	_B.at(_current_lenght).is_active = true;
	_B.at(_current_lenght).segment.SetPosition(x_y_last_segment);
};


void Snake::MoveAndGrow(SD sd)
{
	XY x_y_last_segment = _B.at(_current_lenght++).segment.GetPosition();

	MoveTo(sd);

	_B.at(_current_lenght).is_active = true;
	_B.at(_current_lenght).segment.SetPosition(x_y_last_segment);
};


void Snake::SetBodyElement(int & numer_body_segment, GPE sbe)
{
};


bool Snake::IsItSnake(XY sd)
{
	for (auto & [gpe, is_active, is_grow_position] : _B)
		if (is_active)
			if (gpe.GetPosition() == sd)
				return false;

	return true;
};


void Snake::Draw(XY x_y, GPE_RGB r_g_b) {};


void Snake::Redraw()
{
	for (auto & [gpe, is_active, is_grow_position] : _B)
		if (is_active)
			gpe.Redraw();
};
