#pragma once
#include "BOSS1.h"
#include "SKILLBASE.h"
class BOSS2 : public BALLbase
{
public:
	BOSS2(HGE *hge, const char* filename_for_tex1, const char* filename_for_snd1, int nframes1, float w1, float h1, int mode_for_anim1, float center_x1, float center_y1, int CD1, int lasttime1
		, const char* filename_for_tex2, const char* filename_for_snd2, int nframes2, float w2, float h2, int mode_for_anim2, float center_x2, float center_y2, int CD2, int lasttime2);
	BOSS2(const BOSS2 &a);
	void init(BOSSbase *bossbase);
	void move(float dt);
	void rage();
	void death();
	void frost_ray(float x1, float y1);
	void frost_impect();
	void render();
	~BOSS2();
	SKILLBASE *ray;
	SKILLBASE *impect;
private:
	
	int skill1_delay;
	int skill2_delay;
	int max_hp;
	int move_delay;
	int target_x, target_y;
	bool raged;
	int direction;
};

