#pragma once
#include "BOSS1.h"
#include "hgefont.h"
class HPBAR
{
public:
	HPBAR(const char* hp_tex, const char* shield_tex, const char* delay_tex);
	void init(BALLbase *ball);
	void render();
	void render_shield();
	void calculate(BALLbase *ball);
	void calculate(BOSS1 *boss);
	void GetShield(BOSS1 *boss);
	float test();
	~HPBAR();


private:
	float current_hp;
	float max_hp;
	float shield_hp;
	HTEXTURE tex1;
	HTEXTURE tex2;
	HTEXTURE tex3;
	hgeSprite *spr1;
	hgeSprite *spr2;
	hgeSprite *spr3;
	hgeFont *font;
	float delay;
	float delay2;

};

