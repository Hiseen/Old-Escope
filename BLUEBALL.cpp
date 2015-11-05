#include "BLUEBALL.h"


BLUEBALL::BLUEBALL()
{

	dx =10;
	dy =10;
	m_def *= 2;
	p_def *= 2;
	std_pdef = p_def;
	std_mdef = m_def;
	Guard_time = 10 * FPS;
	attacknum = 10;
	guard = false;
	HP *= 4;
	natked = false;
}


void BLUEBALL::Guard()
{
	if (guard)
	{
		Guard_time--;
		p_def = 2 * std_pdef;
		m_def = 2 * std_mdef;
	}
	else
	{
		Guard_time = 10 * FPS;
		p_def = std_pdef;
		m_def = std_mdef;
	}
}


void BLUEBALL::reborn_ball(int counter_time)
{
	BALLbase::reborn_ball(counter_time);
	HP *= 4;
	m_def *= 2;
	p_def *= 2;
	std_pdef = p_def;
	std_mdef = m_def;
	natked = false;
	dx = 10;
	dy = 10;
}




BLUEBALL::~BLUEBALL()
{
}

void BLUEBALL::born()
{
	BALLbase::born();
	
	

}