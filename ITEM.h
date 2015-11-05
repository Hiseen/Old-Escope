#pragma once
#include <hge.h>
#include <hgesprite.h>
#include <hgeanim.h>
#ifndef ITEM_LAYER
#define ITEM_LAYER 0.2
#endif
#ifndef FPS
#define FPS 100
#endif
#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 1280
#endif
#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 720
#endif
#ifndef SKILL_LAYER
#define SKILL_LAYER 0.0000001
#endif




class ITEM
{
public:
	ITEM(
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
		);
	void create(HGE *hge);
	void Playsound();
	void render(float x, float y);
	void die(HGE *hge, float dt);
	void SetAlive(bool alive1);
	void SetCtrl(bool ctrl1);
	bool IsAlive()const;
	float GetTime()const;
	bool GetEvent()const;
	float GetX()const;
	float GetY()const;
	int GetHeal()const;
	void setGive(bool isgive);
	void SetHeal(int heal);
	void PlayEffect();
	~ITEM();
	hgeRect *rect;
private:
	hgeAnimation *anim;
	hgeAnimation *effect;
	HTEXTURE tex;
	HTEXTURE tex2;
	HEFFECT sound;
	int MAX_TIME;
	int MIN_TIME;
	int time;
	float rot;
	float scale;
	float x, y;
	int EFFECT;
	int STD_LAST_TIME,LAST_TIME;
	bool alive;
	bool direction;
	bool reborn;
	bool ctrl;
	bool giveeffect;
};

