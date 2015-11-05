#pragma once
#include "hgeanim.h"
#ifndef SKILL_LAYER
#define SKILL_LAYER 0.0000001
#endif

class MUTIBOOM
{
public:
	MUTIBOOM(hgeAnimation *anim2,float x1,float y1,float size1);
	//MUTIBOOM(MUTIBOOM &m);
	~MUTIBOOM();
	void init(float x1, float y1, float size1);
	float GetX()const;
	float GetY()const;
	float GetSize()const;
	int IsAlive()const;
	bool GetPlay()const;
	void Play();
	hgeAnimation *anim;
	int lifespan;
private:
	float x, y, size;
	bool isPlay;

};

