#include "ITEM.h"


float bounce(float start, float end, float step)
{
	static bool direction = false;
	static float set = start;
	if (direction == false)start += step;
	else start -= step;
	if (start >= end)direction = true;
	if (start <= set)direction = false;
	return start;
}



ITEM::ITEM
(
HGE *hge,
const char* filename_for_tex,
const char* filename_for_snd,
const char* filename_for_effect,
int nframes,
float w,
float h,
int mode_for_anim,
float center_x,
float center_y,
int max_time,
int min_time,
int effect1,
int last,
int nframes_for_effect,
float center_x_for_effect,
float center_y_for_effect,
float w2,
float h2
)
{
	tex = hge->Texture_Load(filename_for_tex);
	tex2 = hge->Texture_Load(filename_for_effect);
	sound = hge->Effect_Load(filename_for_snd);
	anim = new hgeAnimation(tex, nframes, 20, 0, 0, w, h);
	anim->SetZ(ITEM_LAYER);
	anim->SetMode(mode_for_anim);
	anim->SetBlendMode(BLEND_DEFAULT);
	anim->SetHotSpot(center_x, center_y);
	effect = new hgeAnimation(tex2, nframes_for_effect, 20, 0, 0, w2, h2);
	effect->SetZ(SKILL_LAYER);
	effect->SetBlendMode(BLEND_DEFAULT); 
	effect->SetMode(HGEANIM_NOLOOP);
	effect->SetHotSpot(center_x_for_effect, center_y_for_effect);
	MAX_TIME = max_time;
	MIN_TIME = min_time;
	STD_LAST_TIME = last;
	LAST_TIME = last;
	time = hge->Random_Int(MIN_TIME, MAX_TIME);
	EFFECT = effect1;
	scale = 0.0; 
	rot = 0.0;
	direction = false;
	rect = new hgeRect();
	reborn = false;
	ctrl = false;
	giveeffect = false;
}


void ITEM::create(HGE *hge)
{
	if (time <= 0)
	{
		LAST_TIME--;
		
	}
	else
	{
		if (time < 21)scale += 0.05;
		if (time == 21)
		{
			x = hge->Random_Float(12, SCREEN_WIDTH - 15);
			y = hge->Random_Float(70, SCREEN_HEIGHT - 20);
			ctrl = true;
		}
		time--;
		if (time == 1)alive = true;
	}

}


void ITEM::render(float x1, float y1)
{
	if (scale>=0.2)
	{
		if (scale < 1.1 && direction==false)scale += 0.005;
		else direction = true;
		if (direction == true && scale>1)scale -= 0.005;
		if (scale <= 1.0)direction = false;
		rect = anim->GetBoundingBoxEx(x, y, 0,scale,scale, rect);
		anim->RenderEx(x, y, rot, scale, scale);
	}
	if (giveeffect==true && effect->GetFrame()<effect->GetFrames()-1)
	{
		
		effect->Render(x1, y1);
	}

}

void  ITEM::die(HGE *hge,float dt)
{
	effect->Update(dt);
	if (LAST_TIME <= 0)
	{
		alive = false;
		reborn = false;
		ctrl = false;
		effect->SetFrame(0);
		giveeffect = false;
		
	}
	if (alive == false)
	{

		if (ctrl == false) scale -= 0.05;
		if (scale <= 0)
		{
			scale = 0;
			if (reborn == false)
			{
				LAST_TIME = STD_LAST_TIME;
				time = hge->Random_Int(MIN_TIME, MAX_TIME);
			}
			reborn = true;
		}
	}
}

void ITEM::SetAlive(bool alive1)
{
	alive = alive1;
}

bool ITEM::IsAlive()const
{

	return alive;
}

float ITEM::GetTime()const
{
	return scale;
}

void ITEM::SetCtrl(bool ctrl1)
{
	ctrl = ctrl1;
}

int ITEM::GetHeal()const
{
	return EFFECT;
}

void ITEM::SetHeal(int heal)
{
	EFFECT = heal;
}

void ITEM::PlayEffect()
{
	effect->Play();

}

void ITEM::setGive(bool isgive)
{
	giveeffect = isgive;

}

float ITEM::GetX()const
{
	return x;
}

float ITEM::GetY()const
{
	return y;
}


void ITEM::Playsound()
{
	HGE *hge = hgeCreate(HGE_VERSION);
	hge->Effect_Play(sound);
}