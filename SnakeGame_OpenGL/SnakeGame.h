#pragma once
#include "Dish.h"
#include "Snake.h"

using namespace std;

//the snake dish that is active in current time.
struct ActiveDish
{
	Dish active_dish{};

	u_short time_life{ 0 };

	u_short start_time{ 0 };

	bool is_active{ false };

	bool CanLive(u_short system_time)
	{
		if (time_life > (system_time - start_time))
			return true;

		return false;
	};

	void Alive(u_short system_time)
	{
		start_time	= system_time;
		is_active	= true;
		time_life	= rand() % MTLD + 1;
	};

	void Dead()
	{
		start_time	= 0;
		is_active	= false;
		time_life	= 0;
	};
};


class SnakeGame
{

	Snake _snake;

	static u_short _time_life;

	vector<ActiveDish> _dishes{ MSD };

	void PlantDrow();

	void SnakeDrow();

	void DishDrow(int count_of_dish);

public:

	SnakeGame();

	~SnakeGame();

	void ChangeSD(u_char press_key_value);

	int GetSnakeLenght();

	XY GetSnakeHeadPosition();

	void GameDraw();
};

