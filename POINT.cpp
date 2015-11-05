#include "POINT.h"


Point::Point()
{
	x = 0;
	y = 0;
	level = 0;

}


Point::~Point()
{
}

void Point::init(int i)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	x = hge->Random_Int(100, 980);
	y = hge->Random_Int(100, 620);
	level = i;
	used = false;
	distance = (x - 540)*(x - 540) + (y - 360)*(y - 360);
	Isnew = true;
}

void Point::Input(int x1, int y1,int i)
{
	x = x1;
	y = y1;
	level = i;
	used = false;
	Isnew = true;
}

void Point::GetDis(int centerx, int centery)
{
	distance = (x - centerx)*(x - centerx) + (y - centery)*(y - centery);
}
