#include "BOSSbase.h"


BOSSbase::BOSSbase()
{
	scale = 0.1;
	max = 4000;//累计吸收4000点HP
	natked = false;
//速度不受温度影响：
	dx = 30;
	dy = 30;
	move_delay = 0;
	max_sorb = 50;
	min_sorb = 10;
	masure = false;
}


void BOSSbase::move(float dt)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	if (move_delay == 0)
	{
		target_y = hge->Random_Int(70, SCREEN_HEIGHT - 20);
		target_x = hge->Random_Int(12, SCREEN_WIDTH - 15);
		move_delay = hge->Random_Int(100, 500);//1s~5s切换移动方向
	}
	else
	{
		move_delay--;
		BALLbase::move(target_x, target_y, dt);
	}
	if (HP >= max)
	{
		HP = max;
		masure = true;
	}
	if(HP<max)masure = false;

	float add = HP / (float)max;
	if (alive && HP>0)
	{
		scale = 0.1 + 0.9*add;
		damage = 5 + 0.01*HP;
	}
}


void BOSSbase::absorb(BALLbase &ball)
{
	if (masure == false)
	{
		HGE *hge = hgeCreate(HGE_VERSION);
		ball.dehealth = hge->Random_Int(min_sorb, max_sorb);
		ball.font = true;
		int copy = ball.HP;
		ball.HP -= ball.dehealth;
		if (ball.HP < 0)HP += copy;
		else HP += ball.dehealth;
	}
}

void BOSSbase::absorb(BLUEBALL &ball)
{
	if (masure == false)
	{
		HGE *hge = hgeCreate(HGE_VERSION);
		ball.dehealth = hge->Random_Int(min_sorb, max_sorb);
		ball.font = true;
		int copy = ball.HP;
		ball.HP -= ball.dehealth;
		if (ball.HP < 0)HP += copy;
		else HP += ball.dehealth;
	}
}


void BOSSbase::born()
{
	dx = 30;
	dy = 30;
	BALLbase::born();
}




BOSSbase::~BOSSbase()
{
}


bool BOSSbase::GetMasure()const
{
	return masure;
}

void BOSSbase::SetMasure(bool set)
{
	masure = set;
}


float BOSSbase::test()const
{
	return max;
}


void BOSSbase::reborn_ball(int counter_time)
{
	max += 200 * counter_time;
	BALLbase::reborn_ball(counter_time);

}

