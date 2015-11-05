#include "PIECEWISE.h"


PIECEWISE::PIECEWISE
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
)
{
	
	combo1 = new SKILLBASE(hge, filename_for_anim1, filename_for_sound1, nframes1, w1, h1, HGEANIM_NOLOOP, center_x1, center_y1, 1 * FPS);
	combo2 = new SKILLBASE(hge, filename_for_anim2, filename_for_sound2, nframes2, w2, h2, HGEANIM_NOLOOP, center_x2, center_y2, 1 * FPS);
	combo3 = new SKILLBASE(hge, filename_for_anim3, filename_for_sound3, nframes3, w3, h3, HGEANIM_NOLOOP, center_x3, center_y3, 1 * FPS);
	alive = false;
	x = 0;
	y = 0;
	step = 1;
	time_limit = 1 * FPS;
	std_time_limit = 1 * FPS;
}

void PIECEWISE::STENDBY(float dt,float x1,float y1)
{
	combo1->move(dt, x1, y1);
	combo2->move(dt, x1, y1);
	combo3->move(dt, x1, y1);
	switch (step)
	{
	case 1:
		if (combo1->isalive() == false)
		{
			if (combo1->iscdalive())
				step = 2;				
		}
		
		break;
	case 2:
		if (combo2->isalive() == false)
		{
			if (combo2->iscdalive())
				step = 3;
		}
		time_limit--;
		if (time_limit <= 0)step = 1;
		break;
	case 3:
		if (combo3->isalive() == false && combo3->iscdalive())step = 1;
		time_limit--;
		if (time_limit <= 0)step = 1;
		break;
	
	}
}

void PIECEWISE::EFFECT(float x1, float y1, float angle1,float &Mp,int deMp)
{
	angle = angle1;
	alive = true;
	x = x1;
	y = y1;
	switch (step)
	{
	case 1:
		combo1->born(x1, y1, angle,0);
		time_limit = std_time_limit;
		break;
	case 2:
		combo2->born(x1, y1, angle,0);
		time_limit = std_time_limit;
		Mp -= deMp;
		break;
	case 3:
		combo3->born(x1, y1, angle,0);
		time_limit = std_time_limit;
		Mp -= deMp*2;
		break;

	}



}




void PIECEWISE::RENDER()
{
	switch (step)
	{
	case 1:
		combo1->render();
		break;
	case 2:
		combo2->render();
		break;
	case 3:
		combo3->render();
		break;

	}

}

PIECEWISE::~PIECEWISE()
{
}


int PIECEWISE::GetStep()const
{
	return step;

}

bool PIECEWISE::isalive()const
{
	switch (step)
	{
	case 1:
		return combo1->isalive();
		break;
	case 2:
		return combo2->isalive();
		break;
	case 3:
		return combo3->isalive();
		break;

	}


}