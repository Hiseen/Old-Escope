#pragma once
#include"hge.h"
#include"hgesprite.h"

class PROGRESS
{
public:
	PROGRESS(const char* texture,float w,float h, float center_x,float center_y);
	void render(float x,float y,float pro);
	~PROGRESS();


private:
	hgeSprite *spr;
	hgeQuad Q1;
	hgeQuad Q2;
};

