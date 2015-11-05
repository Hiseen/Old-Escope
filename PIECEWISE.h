#pragma once
#include "hge.h"
#include "hgeanim.h"
#include <math.h>
#include "SKILLBASE.h"
#ifndef FPS
#define FPS 100
#endif

#ifndef SKILL_LAYER
#define SKILL_LAYER 0.0000001
#endif

class PIECEWISE
{
public:


	PIECEWISE
		(
		HGE *hge,
		const char *filename_for_anim1,
		const char *filename_for_anim2,
		const char *filename_for_anim3,
		const char *filename_for_sound1,
		const char *filename_for_sound2,
		const char *filename_for_sound3,
		int nframes1,
		int nframes2,
		int nframes3,
		int w1,
		int h1,
		int w2,
		int h2,
		int w3,
		int h3,
		float center_x1,
		float center_y1,
		float center_x2,
		float center_y2,
		float center_x3,
		float center_y3
		);
	void STENDBY(float dt, float x1, float y1);
	void EFFECT(float x1, float y1,float angle1,float &Mp,int deMp);
	bool isalive()const;
	void RENDER();
	int GetStep()const;
	int GetFrame()const;

	~PIECEWISE();
	SKILLBASE *combo1;
	SKILLBASE *combo2;
	SKILLBASE *combo3;



private:
	
	float x, y;
	bool alive;
	bool isPlaying;
	int step;
	int time_limit;
	float angle;
	int std_time_limit;
};

