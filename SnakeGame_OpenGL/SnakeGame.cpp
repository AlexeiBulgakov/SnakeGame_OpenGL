#include "SnakeGame.h"


u_short SnakeGame::_time_life{ 0 };


void SnakeGame::PlantDrow()
{
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINES);

	for (int i = 0; i < DP_W; i += GPS_S)
	{
		glVertex2f(i, 0);
		glVertex2f(i, DP_H);
	}

	for (int i = 0; i < DP_H; i += GPS_S)
	{
		glVertex2f(0, i);
		glVertex2f(DP_W, i);
	}

	glEnd();
};


void SnakeGame::SnakeDrow()
{
	_snake.MoveTo(_snake.GetSD());

	for (auto & dish : _dishes)
		if (_snake.GetHeadPosition() == dish.active_dish.GetPosition())
		{
			_snake.Grow();
			dish.Dead();
			break;
		}

	_snake.Redraw();
};


void SnakeGame::DishDrow(int count_of_dish)
{
	if (int counter = 0; count_of_dish < MSD)
	{
		for (auto & dish : _dishes)
			if (dish.is_active)
				if (dish.CanLive(_time_life))
				{
					counter++;
					dish.active_dish.Redraw();
				}
				else
					dish.Dead();

		if (counter < count_of_dish)
		{
			for (auto & dish : _dishes)
			{
				if (counter < count_of_dish)
				{
					if (!dish.is_active)
					{
						counter++;
						dish.Alive(_time_life);
						while (true) //finding good condition value "XY".
							if (XY x_y = XY::GetRandom(); _snake.IsItSnake(x_y))
							{
								dish.active_dish.Draw(x_y, GPE_RGB::GetRandom());
								break;
							}
					}
				}
				else
					break;
			}//for
		}//if(2)
	}//if(1)
};


SnakeGame::SnakeGame() {};


SnakeGame::~SnakeGame() {};


void SnakeGame::ChangeSD(u_char press_key_value)
{
	switch (press_key_value)
	{
	case ('w'):
	{
		_snake.SetSD(SD::A); break;
	}
	case ('s'):
	{
		_snake.SetSD(SD::D); break;
	}
	case ('a'):
	{
		_snake.SetSD(SD::L); break;
	}
	case ('d'):
	{
		_snake.SetSD(SD::R); break;
	}
	default:
		break;
	}
};


int SnakeGame::GetSnakeLenght()
{
	return _snake.GetLenght();
};


XY SnakeGame::GetSnakeHeadPosition()
{
	return _snake.GetHeadPosition();
};


void SnakeGame::GameDraw()
{
	_time_life = GetSystemSeconds();

	glClear(GL_COLOR_BUFFER_BIT);

	PlantDrow();

	DishDrow(rand() % MSD + 1);

	SnakeDrow();

	glutSwapBuffers();
};