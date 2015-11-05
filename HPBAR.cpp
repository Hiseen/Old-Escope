#include "HPBAR.h"


float addorminus1(float start, float end, float delta)
{

	if ((int)start>(int)end)
	{
		start -= delta;
	}
	if ((int)start<(int)end)
	{
		start += delta;
	}
	return start;

}


HPBAR::HPBAR(const char* hp_tex, const char* shield_tex, const char* delay_tex)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	tex1 = hge->Texture_Load(hp_tex);
	tex2 = hge->Texture_Load(shield_tex);
	tex3 = hge->Texture_Load(delay_tex);
	spr1 = new hgeSprite(tex1, 0, 0, 100, 17);
	spr2 = new hgeSprite(tex2, 0, 0, 100, 17);
	spr3 = new hgeSprite(tex3, 0, 0, 100, 17);
	spr3->SetColor(ARGB(255, 255, 0, 0));
	spr1->SetColor(ARGB(255, 0, 255, 0));
	spr2->SetColor(ARGB(255, 200, 200, 200));
	font = new hgeFont("font1.fnt");
	font->SetZ(SKILL_LAYER);
	font->SetScale(0.75);

}

void HPBAR::init(BALLbase *ball)
{
	
	current_hp = ball->HP;
	max_hp = ball->HP; 
	shield_hp = 0;
	delay = current_hp;
	


}

void HPBAR::render()
{
	float f1 = current_hp / max_hp;
	float f2 = delay / max_hp;
	spr1->SetTextureRect(0, 0, 1250 *f1, 17);
	spr3->SetTextureRect(0, 0, 1250 * f2, 17);
	//宽度为17 长度为1250
	spr1->SetZ(0.2);
	spr3->SetZ(0.1);
	spr3->Render(15, 73);
	spr1->Render(15, 73);
	font->printf(640, 73, HGETEXT_CENTER,"%d/%d", (int)delay, (int)max_hp);
	
}

void HPBAR::render_shield()
{
	float f1 = current_hp / max_hp;
	float f2 = shield_hp / max_hp;
	spr2->SetTextureRect(0, 0, 1250 * f2, 17);
	//护盾render
	spr2->SetZ(0.1);
	spr2->Render(1250 * f1 + 15, 73);
	
}



void HPBAR::calculate(BALLbase *ball)
{
	current_hp = ball->HP-shield_hp;
	delay = addorminus1(delay, current_hp, max_hp / 1000);
}

void HPBAR::calculate(BOSS1 *boss)
{
	current_hp = boss->GetPresentHP();
	delay = addorminus1(delay, current_hp, max_hp/1000);
}


void HPBAR::GetShield(BOSS1 *boss)
{
	shield_hp = boss->GetShieldHP();
	
}


float HPBAR::test()
{
	return current_hp;
}


HPBAR::~HPBAR()
{
}
