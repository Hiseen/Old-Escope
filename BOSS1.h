#pragma once
#include"BOSSbase.h"

#include "MUTI_SKILL_MANAGER.h"

class BOSS1 : public BALLbase
{
public:
	BOSS1();
	void init(BOSSbase *bossbase);
	void move(float dt);
	void shoot( MUTI_SKILL_MANAGER *m1, MOUSE *mouse);
	void rage();
	void death();
	void shield();
	float test()const;
	int GetShieldHP()const;
	float GetPresentHP()const;
	~BOSS1();
	bool GetRaged()const;
	int GetMaxHp()const;
private:
	bool raged;
	int max_hp;
	int rate;//瞄准时间。。减少到0之后瞄准发射
	int bullet_scale;//子弹个数
	int move_delay;
	int target_x, target_y;
	bool guarded;
	int shield_hp;
	int shield_counter;
	int shield_last;
	float present_hp;
	float delta;
	int test1;
};

