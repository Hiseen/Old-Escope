#include "BALLbase.h"


BALLbase::BALLbase()
{
	HGE *hge = hgeCreate(HGE_VERSION);
	x = hge->Random_Float(12, SCREEN_WIDTH - 15);
	y = hge->Random_Float(70, SCREEN_HEIGHT - 20);
	dx = 0;
	dy = 0;
	hited = false;
	HP = 100;
	godmode = false;
	reborn = 0;
	givescore = false;
	skill2 = false;
	hited_skill = false;
	damage = 10;
	m_def = 10;
	p_def = 10;
	scale = 0.0f;
	die = false;
	font = false;
	addscale = false;
	godtimer = 30;
	linked = false;
	ballangle = 0.0;
	frige = false;
	burned = false;
	toxic = false;
	reverse = false;
	sword_effect = false;
	alive = false;
	std_scale = 0.0;
}


BALLbase::~BALLbase()
{
}

void BALLbase::born()
{
	if (addscale == false)
	{
		this->alive = true;
		if (this->scale < 1.0)this->scale += 0.02;
		else
		{
			std_scale = 0.0;
			scale = 1.0;
			this->addscale = true;
			natked = false;
			dx = 30;
			dy = 30;
		}
	}
}

void BALLbase::godie(int mode)
{
	switch (mode)
	{
	case 0:
		if (std_scale == 0)std_scale = scale + 0.3;
		if (this->scale < std_scale){
			this->scale += 0.01; this->diealpha += 8;
		}
		else {
			this->die = true; this->scale = 0; this->alive = false; this->diealpha = 0;
			addscale = false;
		}
		break;
	case 1:
		this->die = true; 
		this->scale = 0; 
		this->alive = false;
		this->diealpha = 0;
		addscale = false;
		break;
	}
}

void BALLbase::move(float x1, float y1, float dt)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	if (reverse == true)
	{
		if (count_remove>0)count_remove--;
		if (x>x1 && y>y1){ x += cos(reangle)*(count_remove); y += sin(reangle)*(count_remove); }
		if (x<x1 && y>y1){ x -= sin(reangle)*(count_remove); y += cos(reangle)*(count_remove); }
		if (x>x1 && y<y1){ x += sin(reangle)*(count_remove); y -= cos(reangle)*(count_remove); }
		if (x<x1 && y<y1){ x -= cos(reangle)*(count_remove); y -= sin(reangle)*(count_remove); }

	}
	if (burned == true)
	{
		if (count_burned>0)count_burned--;
		x += hge->Random_Float(-5, 5);
		y += hge->Random_Float(-5, 5);
		if (godmode == false && alive == true)
		{
			font = true;
			//²âÊÔÉËº¦
			int def = hge->Random_Int(1, 10);
			HP -= def;
			dehealth = def;
		}
	}
	if (frige == true)count_frige--;
	if (toxic == true)
	{
		count_toxic--;
		if (godmode == false && alive == true)
		{
			font = true;
			//²âÊÔÉËº¦
			HP -= 10;
			dehealth = 10;
		}
		if (x>x1 && y>y1){ x -= dx*dt*cos(ballangle); y -= dy*dt*sin(ballangle); }
		if (x<x1 && y>y1){ x += dx*dt*sin(ballangle); y -= dy*dt*cos(ballangle); }
		if (x>x1 && y<y1){ x -= dx*dt*sin(ballangle); y += dy*dt*cos(ballangle); }
		if (x<x1 && y<y1){ x += dx*dt*cos(ballangle); y += dy*dt*sin(ballangle); }

	}
	if (reverse == false && burned == false && frige == false && toxic == false)
	{
		if (x>x1 && y>y1){ x -= dx*dt*cos(ballangle); y -= dy*dt*sin(ballangle); }
		if (x<x1 && y>y1){ x += dx*dt*sin(ballangle); y -= dy*dt*cos(ballangle); }
		if (x>x1 && y<y1){ x -= dx*dt*sin(ballangle); y += dy*dt*cos(ballangle); }
		if (x<x1 && y<y1){ x += dx*dt*cos(ballangle); y += dy*dt*sin(ballangle); }
	}
	if (count_remove == 0)reverse = false;
	if (count_burned == 0)burned = false;
	if (count_frige == 0)frige = false;
	if (count_toxic == 0)toxic = false;
		
		









}


void BALLbase::reborn_ball(int counter_time)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	HP = 100 + counter_time * 30;
	alive = false;
	givescore = false;
	scale = 0.0f;
	x = hge->Random_Float(12, SCREEN_WIDTH - 15);
	y = hge->Random_Float(70, SCREEN_HEIGHT - 20);
	dx = 0;
	dy = 0;
	die = false;
	damage = 10 + counter_time;
	m_def = 10 + counter_time * 10;
	p_def = 10 + counter_time * 10;
	addscale = false;
	linked = false;
	std_scale = 0.0;
}


float BALLbase::GetX()const
{
	return x;
}

float BALLbase::GetY()const
{
	return y;
}

bool BALLbase::GetGivescore()const
{
	return givescore;
}

void BALLbase::SetGivescore(bool set)
{
	givescore = set;
}

void BALLbase::SetX(float setx)
{
	x = setx;
}

void BALLbase::SetY(float sety)
{

	y = sety;
}

void BALLbase::diedboom(BALLbase *pball,int count)
{
	for (int i = 0; i < count; i++)
	{
		if (ballcrash(x, y, 50, pball[i].x, pball[i].y) && pball[i].alive)
		{
			pball[i].count_remove = 10;
			pball[i].reangle = atan2f(x-pball[i].x, y-pball[i].y);
			pball[i].reverse = true;
		}
	}
	
}

void BALLbase::reset()
{
	HGE *hge = hgeCreate(HGE_VERSION);
	x = hge->Random_Float(12, SCREEN_WIDTH - 15);
	y = hge->Random_Float(70, SCREEN_HEIGHT - 20);
	dx = 0;
	dy = 0;
	hited = false;
	HP = 100;
	godmode = false;
	reborn = 0;
	givescore = false;
	skill2 = false;
	hited_skill = false;
	damage = 10;
	m_def = 10;
	p_def = 10;
	scale = 0.0f;
	die = false;
	font = false;
	addscale = false;
	godtimer = 30;
	linked = false;
	ballangle = 0.0;
	frige = false;
	burned = false;
	toxic = false;
	reverse = false;
	sword_effect = false;
	alive = false;
	std_scale = 0.0;
}