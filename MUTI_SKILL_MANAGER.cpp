#include "MUTI_SKILL_MANAGER.h"


MUTI_SKILL_MANAGER::MUTI_SKILL_MANAGER(
	HGE *hge,
	const char* filename_for_tex,
	const char* filename_for_snd,
	const char* filename_for_boom,
	const char* filename_for_boomsnd,
	int nframes,
	int nframes2,
	float w,
	float w2,
	float h,
	float h2,
	int mode_for_anim,
	float center_x,
	float center_y,
	int CD,
	int lasttime 
	)
{
	HTEXTURE tex2=hge->Texture_Load(filename_for_boom);
	boom = new hgeAnimation(tex2, nframes2, 20, 0, 0, w2, h2);
	boom->SetZ(SKILL_LAYER);
	boom->SetHotSpot(w2/2, h2 / 2);
	boom->SetMode(HGEANIM_NOLOOP);
	SKILL = new SKILLBASE(hge, filename_for_tex, filename_for_snd, nframes, w, h, mode_for_anim, center_x, center_y, CD, lasttime);
	arrow_count = 0;
	SKILL->born(0, 0, 0,0);
	effect = hge->Effect_Load(filename_for_boomsnd);
}


MUTI_SKILL_MANAGER::~MUTI_SKILL_MANAGER()
{
}

bool MUTI_SKILL_MANAGER::GetCDAliveForSkill()const
{
	return SKILL->iscdalive();
}


void MUTI_SKILL_MANAGER::BornWithNumber(int number,float x,float y,float angle,int speed,bool lianfa, bool foe1,int damage1)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	SKILL->born(0, 0, 0, 0);
	if (lianfa)
	{
		SKILL->setCD(5);
		lianfale = true;
	}
	else lianfale = false;
	if (number > 1)
	{
		BASE_ARROW *arrow = new BASE_ARROW[number];
		for (int i = 0; i < number; i++)
		{
			arrow[i].Init(x, y, angle-(i-0.5*number)*0.314, speed, foe1,damage1);// need test
			arrows.push_back(arrow[i]);
		}
		arrow_count += number;
	}
	else
	{
		BASE_ARROW *arrow = new BASE_ARROW;
			arrow->Init(x, y, angle, speed,foe1,damage1);
			arrows.push_back(*arrow);
		arrow_count += 1;
	}
	hge->Effect_Play(SKILL->sound);
	arrows.shrink_to_fit();
	//arrows.resize(arrow_count);
}


void MUTI_SKILL_MANAGER::Run(float dt)
{
	
	for (int i = 0; i < boom_pool.size(); ++i)
	{
		boom_pool[i].anim->Update(dt);
		boom_pool[i].lifespan--;
	}
	SKILL->move(dt, 0);
	for (int i = 0; i != arrows.size(); ++i)
	{
		
		if (arrows[i].alive == false)
		{
		
			arrows[i].count3++;
			if (arrows[i].count3 == 50)arrows[i].die = true;
		}
		else
		{
			arrows[i].count2++;
			arrows[i].x -= arrows[i].speed*cos(arrows[i].angle);
			arrows[i].y -= arrows[i].speed*sin(arrows[i].angle);

		}
		if (arrows[i].x<0 || arrows[i].y<0 || arrows[i].x>SCREEN_WIDTH || arrows[i].y>SCREEN_HEIGHT)
		{
			arrows[i].alive = false;
		}
	}
	for (int i = 0; i < arrows.size();)
	{
		if (arrows[i].die)
		{
			arrows[i].alive = true;
			arrows.erase(arrows.begin() + i);
		}
		else
			i++;
	}
	
}

void MUTI_SKILL_MANAGER::DieWithNumber(BALLbase *BALL, int count, PUBLIC *pub, MOUSE *mouse, hgeAnimation *anim, bool leech,hgeAnimation *anim2)
//º¯ÊýÄÚ¼ì²âÅö×²
{
	HGE* hge = hgeCreate(HGE_VERSION);
	for (int j = 0; j != arrows.size(); ++j)
	{
		
	     for (int i = 0; i != count; ++i)
	{
			 if (BALL[i].alive == true && arrows[j].alive && BALL[i].natked == false && BALL[i].HP>0 && BALL[i].godmode == false && arrows[j].foe == false && Collision(pub->cskill1, arrows[j].angle, arrows[j].x, arrows[j].y, BALL[i].GetX(), BALL[i].GetY()))
			{
				BALL[i].HP -= damage((arrows[j].damage + 10)*(1 - arrows[j].count*0.125), BALL[i].m_def);
				BALL[i].natked = true;
				BALL[i].font = true;
				BALL[i].dehealth = damage((arrows[j].damage + 10)*(1 - arrows[j].count*0.125), BALL[i].m_def);
				arrows[j].count++;
				if (leech)
				{
					mouse->heal = true;
					anim2->Play();
					mouse->mouseHP += BALL[i].dehealth*0.25;
					
				}
				anim->Play();
				if (lianfale)
				{
					BALL[i].godtimer = 5;
					BALL[i].reverse = true;
					BALL[i].reangle = BALL[i].ballangle - 6.28;
					BALL[i].count_remove = 5;
					arrows[j].alive = false;
					break;
				}
				if (arrows[j].count == 8)
				{
					arrows[j].alive = false;
					break;
				}
			}
	 }
		 
		  
	}
	
}

void MUTI_SKILL_MANAGER::DieWithNumber(BLUEBALL *BALL, int count, PUBLIC *pub, MOUSE *mouse, hgeAnimation *anim, bool leech, hgeAnimation *anim2)
//º¯ÊýÄÚ¼ì²âÅö×²
{

	HGE* hge = hgeCreate(HGE_VERSION);
	for (int j = 0; j != arrows.size(); ++j)
	{
	
		for (int i = 0; i != count; ++i)
		{
			BALLbase *ball = new BALLbase(dynamic_cast<BALLbase&>(BALL[i]));
			
			if (ball->alive == true && arrows[j].alive && ball->natked == false && ball->HP>0 && ball->godmode == false && arrows[j].foe == false && Collision(pub->cskill1, arrows[j].angle, arrows[j].x, arrows[j].y, ball->GetX(), ball->GetY()))
			{
				BALL[i].HP -= damage((arrows[j].damage + 10)*(1 - arrows[j].count*0.125), BALL[i].m_def);
				BALL[i].natked = true;
				BALL[i].font = true;
				BALL[i].dehealth = damage((arrows[j].damage + 10)*(1 - arrows[j].count*0.125), BALL[i].m_def);
				arrows[j].count++;
				if (leech)
				{
					mouse->heal = true;
					anim2->Play();
					mouse->mouseHP += BALL[i].dehealth*0.3;
				}
				anim->Play();
				
				if (lianfale)
				{
					BALL[i].godtimer = 5;
					BALL[i].reverse = true;
					BALL[i].reangle = BALL[i].ballangle - 6.28;
					BALL[i].count_remove += 5;
					arrows[j].alive = false;
					break;
				}
				if (arrows[j].count == 8)
				{
					arrows[j].alive = false;
					break;
				}
			}
		}

		

	}

}
/*
void MUTI_SKILL_MANAGER::DieWithNumber(BOSSbase *BALL,  PUBLIC *pub, MOUSE *mouse, hgeAnimation *anim, bool leech, hgeAnimation *anim2)
//º¯ÊýÄÚ¼ì²âÅö×²
{
	HGE* hge = hgeCreate(HGE_VERSION);
	for (int j = 0; j != arrows.size(); ++j)
	{
		
			if (BALL->alive == true && arrows[j].alive && BALL->natked == false && BALL->HP>0 && BALL->godmode == false && arrows[j].foe == false && Collision(pub->cskill1, arrows[j].angle, arrows[j].x, arrows[j].y, BALL->GetX(), BALL->GetY()))
			{
				BALL->HP -= damage((arrows[j].damage + 10)*(1 - arrows[j].count*0.125), BALL->m_def);
				BALL->natked = true;
				BALL->font = true;
				BALL->dehealth = damage((arrows[j].damage + 10)*(1 - arrows[j].count*0.125), BALL->m_def);
				arrows[j].count++;
				if (leech)
				{
					mouse->heal = true;
					anim2->Play();
					mouse->mouseHP += BALL->dehealth*0.5;
				}
				anim->Play();
				
				if (lianfale)
				{
					BALL->godtimer = 5;
					BALL->reverse = true;
					BALL->reangle = BALL->ballangle-6.28;
					BALL->count_remove += 5;
					arrows[j].alive = false;
					break;
				}
				if (arrows[j].count == 8)
				{
					arrows[j].alive = false;
					break;
				}
			}
	}

}
*/








void MUTI_SKILL_MANAGER::CrashMouse(MOUSE *mouse, hgeAnimation *anim, PUBLIC *pub, BALLbase *ball)
{
	for (int j = 0; j != arrows.size(); ++j)
	{
		if (mouse->god == false && arrows[j].alive && arrows[j].foe && Collision(pub->cskill1, arrows[j].angle, arrows[j].x, arrows[j].y, mouse->x, mouse->y))
		{
			arrows[j].alive = false;
			mouse->mouseHP -= damage(arrows[j].damage, mouse->base_m_def);
			mouse->god = true;
			mouse->godcount = 20;
		}
	}

}




void MUTI_SKILL_MANAGER::Render_Alive()
{
	HGE* hge = hgeCreate(HGE_VERSION);
	
	for (int i = 0; i != arrows.size(); ++i)
	{
		
		
		if (arrows[i].alive == false)
		{
			if (arrows[i].boomed == false)
			{
				MUTIBOOM *boomfish = new MUTIBOOM(boom, arrows[i].x, arrows[i].y, arrows[i].delta);
				boomfish->Play();
				boom_pool.push_back(*boomfish);
				delete boomfish;
				boomfish = NULL;
				arrows[i].boomed = true;
				hge->Effect_Play(effect);
			}
		}
		else
			SKILL->render(arrows[i].x, arrows[i].y, arrows[i].angle);
	}

	for (int i = 0; i < boom_pool.size(); ++i)
	{
	
		   boom_pool[i].anim->RenderEx(boom_pool[i].GetX(), boom_pool[i].GetY(), 0, boom_pool[i].GetSize(), boom_pool[i].GetSize());
		if (boom_pool[i].lifespan<=0)
		{
			delete boom_pool.cbegin()->anim;
			boom_pool.erase(boom_pool.cbegin());
		}
	}
	boom_pool.shrink_to_fit();



}

int MUTI_SKILL_MANAGER::GetSize()const
{
	return boom_pool.size();
}

int MUTI_SKILL_MANAGER::GetSize2()const
{
	return arrows.size();
}

void MUTI_SKILL_MANAGER::Resist(SKILLBASE *skill, PUBLIC *pub, MOUSE *mouse, int range)
{
	if (range == 0)
	{
		for (int i = 0; i != arrows.size(); ++i)
		{
			if (skill->isalive() && arrows[i].alive && arrows[i].foe && Collision(pub->cskill1, arrows[i].angle, arrows[i].x, arrows[i].y, skill->GetX(), skill->GetY()))
			{
				arrows[i].alive = false;

			}
		}
	}
	else
	{
		for (int i = 0; i != arrows.size(); ++i)
		{
			if (ballcrash(mouse->x, mouse->y, 200, arrows[i].x, arrows[i].y))
			{
				arrows[i].alive = false;
			}
		}
	}
}

