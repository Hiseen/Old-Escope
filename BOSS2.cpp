#include "BOSS2.h"


BOSS2::BOSS2(
	HGE *hge, const char* filename_for_tex1, const char* filename_for_snd1, int nframes1, float w1, float h1, int mode_for_anim1, float center_x1, float center_y1, int CD1, int lasttime1
	,const char* filename_for_tex2, const char* filename_for_snd2, int nframes2, float w2, float h2, int mode_for_anim2, float center_x2, float center_y2, int CD2, int lasttime2
	)
{
	
	ray = new SKILLBASE(hge, filename_for_tex1, filename_for_snd1, nframes1, w1, h1, mode_for_anim1, center_x1, center_y1, CD1, lasttime1);
	impect = new SKILLBASE(hge, filename_for_tex2, filename_for_snd2, nframes2, w2, h2, mode_for_anim2, center_x2, center_y2, CD2, lasttime2);
}





BOSS2::BOSS2(const BOSS2 &a)
{
	ray = a.ray;
	impect = a.impect;


}

BOSS2::~BOSS2()
{


}


void BOSS2::init(BOSSbase *bossbase)
{
	HP = bossbase->HP;
	max_hp = bossbase->HP;
	SetX(bossbase->GetX());
	SetY(bossbase->GetY());
	dx = 50;
	dy = 50;
	p_def = 80;
	m_def = 100;
	damage = 20;
	skill1_delay = 300;
	alive = true;
	skill2_delay = 600;
	bossbase->HP = 0;
}

void BOSS2::move(float dt)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	if (move_delay == 0)
	{
		target_y = hge->Random_Int(70, SCREEN_HEIGHT - 20);
		target_x = hge->Random_Int(12, SCREEN_WIDTH - 15);
		if (raged)
			move_delay = hge->Random_Int(100, 200);
		else move_delay = hge->Random_Int(200, 400);//2s~8s切换移动方向
	}
	else
	{
		move_delay--;
		BALLbase::move(target_x, target_y, dt);
	}
	ray->move(dt);
	ray->setangle(ray->GetAngle() + 0.01*direction);
	impect->move(dt);


}

void BOSS2::rage()
{

	damage *= 4;
	p_def *= 2;
	m_def *= 5;
}


void BOSS2::frost_ray(float x1,float y1)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	if (skill1_delay == 0)
	{
		ray->born(atan2f(GetX() - x1, GetY() - y1),GetX(), GetY(),damage);
		direction=hge->Random_Int(-1, 1);//有可能会取不到-1；

	}
	else
	{
		skill1_delay--;
	}

}


void BOSS2::frost_impect()
{
	HGE *hge = hgeCreate(HGE_VERSION);
	if (skill2_delay == 0)
	{
		impect->born(0,GetX(), GetY(),damage);
	}
	else
	{
		skill2_delay--;
	}


}


void BOSS2::render()
{
	impect->render();
	ray->render();
}