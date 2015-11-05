#pragma once
#include "hge.h"
class Point
{
public:
	Point();
	~Point();
	inline bool operator < (const Point &pt)const
	{
		return distance < pt.distance;
	}
	float distance;
	bool Isnew;
	int x, y;
	int level;
	bool used;
	void init(int i);
	void Input(int x1, int y1,int i);
	void GetDis(int centerx, int centery);
	int distance2;
};

