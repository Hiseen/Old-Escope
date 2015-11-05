#include "SKILLBASE.h"


SKILLBASE::SKILLBASE(const SKILLBASE &a)
	{
		anim=a.anim;
		rect=a.rect;
		setted = true;
		alive = a.alive;
		x = a.x;
		y = a.y;
		std_last_time = a.std_last_time;
		std_cd = a.std_cd;
		speed = a.speed;
		angle = a.angle;
		colddown = a.colddown;
		last_time = a.last_time;
		tex = a.tex;
		sound = a.sound;
		cdalive = a.cdalive;
	}

SKILLBASE::SKILLBASE(HGE *hge,const char* filename_for_tex,const char* filename_for_snd,int nframes,float w,float h,int mode_for_anim,float center_x,float center_y,int CD,int lasttime)
{
   alive=false;
   x=0;
   y=0;
   std_last_time=lasttime;
   last_time=lasttime;
   speed=10;
   angle=0.0;
   colddown=CD;
   std_cd=CD;
   rect=new hgeRect();
	tex=hge->Texture_Load(filename_for_tex);
	sound=hge->Effect_Load(filename_for_snd);
	anim= new hgeAnimation(tex,nframes,20,0,0,w,h);
	anim->SetZ(SKILL_LAYER);
	anim->SetMode(mode_for_anim);
	anim->SetBlendMode(BLEND_DEFAULT);
	anim->SetHotSpot(center_x,center_y);
	cdalive=false;
	setted = true;
}

void SKILLBASE::born(MOUSE *mouse)
{
	alive=true;
	cdalive=true;
	anim->Play();
	this->angle=mouse->angle-3.14;
	this->x=mouse->x;
    this->y=mouse->y;
	p_damage = mouse->base_p_damage;
	m_damage = mouse->base_m_damage;
	//HGE *hge = hgeCreate(HGE_VERSION);
	//hge->Effect_Play(sound);
}
 

void SKILLBASE::move(float dt,float x3, float y3)
{
	anim->Update(dt);
	if(cdalive==true)colddown--;
	if(colddown<=0)
	{
		cdalive=false;
	     die();
		 
	}
	if(x3!=0)x=x3;
	if(y3!=0)y=y3;
	if(angle!=0)
	rect=anim->GetBoundingBoxEx(x,y,angle,0.8,0.5,rect);
	else rect=anim->GetBoundingBox(x,y,rect);
}

void SKILLBASE::move(float dt, int speed)
{
	
	anim->Update(dt);
	if (cdalive == true)colddown--;
	if (colddown <= 0)
	{
		cdalive = false;
		die();
		
	}
	rect = anim->GetBoundingBoxEx(x, y,angle, 0.8, 0.5, rect);
	x -=speed*cos(angle);
	y -=speed*sin(angle);
}



void SKILLBASE::render()
{
	if(alive==true){
		if(last_time<=0)
	{
		if(anim->GetFrame()<anim->GetFrames()-1)
		{
			if (angle != 0)
			{
				if (angle>-4.71 && angle < -1.57)
				{
					float y1,s,std_x,std_y;
					anim->GetHotSpot(&std_x, &std_y);
					s = anim->GetHeight();
					y1 = s - std_y;
					anim->SetFlip(false, true);
					anim->SetHotSpot(std_x,y1);
					anim->RenderEx(x, y, angle);
					anim->SetHotSpot(std_x, std_y);
				
				}
				else
				{
					anim->SetFlip(false, false);
					anim->RenderEx(x, y, angle);
				}
			}
		else anim->Render(x,y);
		}
		else alive=false;
	}
		else
		{
			last_time--;
			if(last_time!=0)
			{
			if(angle!=0)
		    anim->RenderEx(x,y,angle);
		    else anim->Render(x,y);
			}
			else
			{
				last_time=std_last_time;
				alive=false;
			}
		}
	}	
}

void SKILLBASE::die()
{
	rect->Clear();
	anim->SetFrame(1);
	colddown = std_cd;
	cdalive = false;

}


bool SKILLBASE::isalive()const
{
	return alive;
 
}

bool SKILLBASE::iscdalive()const
{
	return cdalive;
 
}

float SKILLBASE::GetAngle()const
{
	return this->angle;

}

void SKILLBASE::setangle(float angle2)
{
	angle = angle2;
}

void SKILLBASE::setalive(bool alive1)
{
	alive = alive1;
}

int SKILLBASE::GetCD()const
{
	return colddown;
}

int SKILLBASE::GetLastTime()const
{
	return last_time;
}

void SKILLBASE::setCD(int cd)
{
	colddown = cd;
}  

float SKILLBASE::GetX()const
{
	
	return this->x;
}

float SKILLBASE::GetY()const
{
	return this->y;
}

int SKILLBASE::GetFrame()const
{
	return anim->GetFrame();
}

int SKILLBASE::GetFrames()const
{
	return anim->GetFrames();
}

void SKILLBASE::render(float x, float y, float angle)
{
	anim->RenderEx(x, y, angle);

}


void SKILLBASE::SetLastTime(int Last)
{
	last_time = Last;
}


int SKILLBASE::GetDamage(int type)const
{
	switch (type)
	{
	case PHYSICS:
		return p_damage;
		break;
	case MAGIC :
		return m_damage;
		break;
	default:
		return 0;
		break;
	}
}


void SKILLBASE::born(float angle1, float x1, float y1, int damage)
{
	alive = true;
	cdalive = true;
	anim->Play();
	this->angle = angle1;
	this->x = x1;
	this->y = y1;
	p_damage = damage;
	m_damage = damage;

}