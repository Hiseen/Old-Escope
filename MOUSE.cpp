#include "MOUSE.h"


MOUSE::MOUSE()
{
	god = false;
	MAX_HP = 300;
	MAX_MP = 150;
	MAX_EXP= 20;
	LV = 0;
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;
	angle = 0.0f;
	speed = 80;
	mouseHP = 300;
	mouseMP = 150;
	mouseEXP = 0;
	luk = 500;
	base_m_damage = 50;
	base_m_def = 20;
	base_p_damage = 30;
	base_p_def = 25;
	godcount = 20;
	heal = false;
	up_power = 10;
	font = false;
	dehealth = 0;
	healthline = mouseHP;
}


void MOUSE::powerup()
{
	base_m_damage *= up_power;
	base_p_damage *= up_power;
}

void MOUSE::powerdown()
{
	base_m_damage /= up_power;
	base_p_damage /= up_power;
	up_power = 1;

}

void MOUSE::setPower(int power)
{
	if (power > 1)
		up_power = power;
	else
		up_power = 1;
}

MOUSE::~MOUSE()
{
}

int MOUSE::getPower()const
{
	return up_power;

}

void MOUSE::reset()
{
	god = false;
	MAX_HP = 300;
	MAX_MP = 150;
	MAX_EXP = 20;
	LV = 0;
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;
	angle = 0.0f;
	speed = 80;
	mouseHP = 300;
	mouseMP = 150;
	mouseEXP = 0;
	luk = 500;
	base_m_damage = 50;
	base_m_def = 20;
	base_p_damage = 30;
	base_p_def = 25;
	godcount = 20;
	heal = false;
	up_power = 10;
	font = false;
	dehealth = 0;
	healthline = mouseHP;
}