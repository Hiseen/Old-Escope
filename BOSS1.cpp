#include "BOSS1.h"


BOSS1::BOSS1()
{
	move_delay = 0;
	test1 = 0;
}

void BOSS1::init(BOSSbase *bossbase)
{
	HP = bossbase->HP;
	max_hp = bossbase->HP;
	SetX(bossbase->GetX());
	SetY(bossbase->GetY());
	dx = 40;
	dy = 40;
	p_def = 100;
	m_def = 80;
	damage = 30;
	rate = 300;
	raged = false;
	alive = true;
	shield_last = 200;
	shield_counter = 500;
	guarded = false;
	bossbase->HP = 0;
	present_hp = 0;
	raged = false;
	natked = false;
	test1++;
}

void BOSS1::move(float dt)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	if (move_delay == 0)
	{
		target_y = hge->Random_Int(70, SCREEN_HEIGHT - 20);
		target_x = hge->Random_Int(12, SCREEN_WIDTH - 15);
		if (raged)
			move_delay = hge->Random_Int(100, 200);
		else move_delay = hge->Random_Int(200, 400);//2s~8sÇÐ»»ÒÆ¶¯·½Ïò
	}
	else
	{
		move_delay--;
		BALLbase::move(target_x, target_y, dt);
	}
	if (guarded)
	{
		
		if (shield_last == 199)
		{
			present_hp = HP;
			HP += shield_hp;
		}
		shield_last--;
		if (present_hp > HP)
		{
			present_hp = 0;
			guarded = false;
			shield_last = 200;
		}
		if (shield_last == 0)
		{
			HP = present_hp;
			shield_hp = 0;
			present_hp = 0;
			guarded = false;
			shield_last = 200;
		}
	}



}

void BOSS1::rage()
{
	if (HP < max_hp*0.2 && raged == false)
	{
		godmode = true;
		godtimer = 500;
		raged = true;
		dx = 70;
		dy = 70;
	}
}

void BOSS1::shoot( MUTI_SKILL_MANAGER *m1, MOUSE *mouse)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	if (rate == 0)
	{
		float angle = atan2f(GetY() -mouse->y , GetX() - mouse->x);
		if (raged)
		{
			m1->BornWithNumber(20, GetX(), GetY(), angle, 4, false,true,damage);
			rate = hge->Random_Int(100, 150);
		
		}
		else
		{
			m1->BornWithNumber(1, GetX(), GetY(), angle, 10, false,true,damage);
			rate = hge->Random_Int(50, 250);
		}
	  }
	else
	{
		rate--;
	}



}


void BOSS1::shield()
{
	HGE *hge = hgeCreate(HGE_VERSION);
	if(shield_counter == 0)
	{
		guarded = true;
		if (raged)
		{
			shield_hp = hge->Random_Int(300, 400);
			shield_counter = hge->Random_Int(301, 500);
			if (HP + shield_hp > max_hp) shield_hp = max_hp - HP;
		}
		else
		{
			shield_hp = hge->Random_Int(100, 200);
			shield_counter = hge->Random_Int(500, 700);
			if (HP + shield_hp > max_hp) shield_hp = max_hp - HP;
		}
	}
	else
	{
		shield_counter--;
	}




}



int BOSS1::GetShieldHP()const
{
	if (guarded)
		return HP - present_hp;
	else
		return 0;
}

float BOSS1::GetPresentHP()const
{
	if (present_hp == 0)
		return HP;
	else
	    return present_hp;
}

float BOSS1::test()const
{
	return HP;
}


int BOSS1::GetMaxHp()const
{
	return test1;
}


bool BOSS1::GetRaged()const
{
	return raged;
}

BOSS1::~BOSS1()
{
}
