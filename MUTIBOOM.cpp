#include "MUTIBOOM.h"


MUTIBOOM::MUTIBOOM(hgeAnimation *anim2, float x1, float y1, float size1)
{
	anim = new hgeAnimation(*anim2);
	x = x1;
	y = y1;
	size = size1;
	lifespan = 30;
}

float MUTIBOOM::GetSize()const
{
	return size;
}

float MUTIBOOM::GetX()const
{
	return x;
}

float MUTIBOOM::GetY()const
{
	return y;
}
MUTIBOOM::~MUTIBOOM()
{
}

void MUTIBOOM::Play()
{
	anim->Play();
	isPlay = true;
}

bool MUTIBOOM::GetPlay()const
{
	return isPlay;
}

//MUTIBOOM::MUTIBOOM(MUTIBOOM &m)
//{
//	anim = m.anim;
//	lifespan = m.lifespan;
//	x = m.x;
//	y = m.y;
//	isPlay = m.isPlay;
//	size = m.size;
//}

void MUTIBOOM::init(float x1, float y1, float size1)
{
	x = x1;
	y = y1;
	size = size1;
}