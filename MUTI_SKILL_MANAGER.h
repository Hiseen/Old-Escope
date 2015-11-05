#pragma once
#include <hge.h>
#include "SKILLBASE.h"
#include "BASE_ARROW.h"
#include <vector>
#include "PUBLIC.h"
#include "BLUEBALL.h"
#include "hgeanim.h"
#include "BOSSbase.h"
#include "MOUSE.h"
#include "MUTIBOOM.h"

extern void getRange(int *arr, int size, int *max, int *min);
extern bool Collision(Point *mPoint, const float angle5, float center_x, float center_y, float px, float py);
extern float damage(float damage1, float def);
extern bool ballcrash(float center_x, float center_y, int r, float px, float py);

class MUTI_SKILL_MANAGER
{
public:
	MUTI_SKILL_MANAGER
		(
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
		int lasttime = 0
		);
	~MUTI_SKILL_MANAGER();
	void BornWithNumber(int number,float x,float y,float angle,int speed,bool lianfa, bool foe1,int damage1);
	void DieWithNumber(BALLbase *BALL, int count, PUBLIC *pub, MOUSE *mouse, hgeAnimation *anim, bool leech, hgeAnimation *anim2);
	void DieWithNumber(BLUEBALL *BALL, int count, PUBLIC *pub, MOUSE *mouse, hgeAnimation *anim, bool leech, hgeAnimation *anim2);
	//void DieWithNumber(BOSSbase *BALL, PUBLIC *pub, MOUSE *mouse, hgeAnimation *anim, bool leech, hgeAnimation *anim2);
	void CrashMouse(MOUSE *mouse, hgeAnimation *anim, PUBLIC *pub, BALLbase *ball);
	void Resist(SKILLBASE *skill, PUBLIC *pub, MOUSE *mouse, int range = 0);
	void Run(float dt);
	void Render_Alive();
	bool GetCDAliveForSkill()const;
	int GetSize()const;
	int GetSize2()const;
private:
	SKILLBASE *SKILL;
	hgeAnimation *boom;
	vector<BASE_ARROW> arrows;
	vector<MUTIBOOM> boom_pool;
	int arrow_count;
	bool lianfale;
	HEFFECT effect;
};

