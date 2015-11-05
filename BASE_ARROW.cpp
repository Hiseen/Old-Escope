#include "BASE_ARROW.h"


BASE_ARROW::BASE_ARROW()
{
	count3 = 0;
	count = 0;
}


BASE_ARROW::~BASE_ARROW()
{
	alive = false;
}

void BASE_ARROW::Init(float x1, float y1, float angle1, int speed1, bool foe1,int damage1)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	x = x1;
	y = y1;
	angle = angle1;
	alive = true;
	speed = speed1;
	foe = foe1;
	damage = damage1;
	die = false;
	count3 = 0;
	delta = hge->Random_Float(0.5, 1.2);
	boomed = false;
}