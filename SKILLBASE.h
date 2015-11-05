#pragma once
#include <hge.h>
#include <hgesprite.h>
#include <hgeanim.h>
#include <math.h>
#include <hgerect.h>
#include "SKILLCIRCLE.h"
#include "MOUSE.h"
#ifndef SKILL_LAYER
#define SKILL_LAYER 0.0000001
#endif
#ifndef FPS
#define FPS 100
#endif

class SKILLBASE
{
public:
	friend class SKILLCIRCLE;
	SKILLBASE
		(
		HGE *hge,
		const char* filename_for_tex,
		const char* filename_for_snd,
		int nframes,
		float w,
		float h,
		int mode_for_anim,
		float center_x,
		float center_y,
		int CD,
		int lasttime = 0
		);
	void born(MOUSE *mouse);
	void born(float angle1, float x1, float y1, int damage);
	void move(float dt, float x3 = 0, float y3 = 0);
	void move(float dt, int speed);
	void render();
	void render(float x, float y, float angle);
	void die();
	void setangle(float angle2);
	void setalive(bool alive1);
	void setCD(int cd);
	bool isalive()const;
	bool iscdalive()const;
	float GetAngle()const;
	int GetFrames()const;
	int GetFrame()const;
	int GetCD()const;
	int GetLastTime()const;
	float GetX()const;
	float GetY()const;
	int GetDamage(int type)const;
	void SetLastTime(int Last);
	SKILLBASE(const SKILLBASE &x);
	bool setted;
	~SKILLBASE();
		hgeRect *rect;
		HEFFECT sound;
private:
	bool cdalive;
	float speed;
	bool alive;
	int base_damage;
	HTEXTURE tex;
	int m_damage;
	int p_damage;
	float x, y;
	float angle;
	hgeAnimation *anim;
	int colddown,std_cd;
	int last_time,std_last_time;
	
	
};

