#pragma once
#include <hge.h>
#include "BLUEBALL.h"

//BOSS の 种子


class BOSSbase : public BALLbase
{
public:
	void born();
	void move(float dt);
	void absorb(BALLbase &ball);
	void absorb(BLUEBALL &ball);
	void avoid();
	bool GetMasure()const;
	void SetMasure(bool set);
	float test()const;
	void reborn_ball(int counter_time);
	void ResetAll();
	BOSSbase();
	~BOSSbase();
private:
	bool masure;
	int max;//突变临界点
	int avoid_delay;//闪避的cd
	int move_delay;//角度切换delay
	int target_x;
	int target_y;
	int min_sorb;//最小吸血量
	int max_sorb;//最大吸血量
	
};

