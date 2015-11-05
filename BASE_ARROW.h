#pragma once
#include "hge.h"
class BASE_ARROW
{
public:
	float x, y;
	int speed;
	bool alive;
	bool hit_or_not;
	bool foe;
	float angle;
	int count;
	int count2;
	int damage;
	bool die;
	int count3;
	float delta;
	bool boomed;
	BASE_ARROW();
	void Init(float x1, float y1, float angle1, int speed1, bool foe1,int damage1);
	~BASE_ARROW();
};

