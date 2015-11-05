#pragma once
#include <hge.h>
#include <math.h>
#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 1280
#endif
#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 720
#endif
extern bool ballcrash(float center_x, float center_y, int r, float px, float py);
#pragma pack(4)
class BALLbase
{
public:
	void reset();
	bool hited;
	bool alive;
	bool reverse;//控制击退的开关
	bool godmode;
	float reangle;//击退角度
	void move(float x1, float y1, float dt);//击退和移动
	bool skill2;
	bool hited_skill;
	int count_remove;//击退时间
	void born();
	void godie(int mode=0);
	void reborn_ball(int counter_time);
	float scale;
	bool die;
	int alpha;
	bool font;//需不需要new伤害数字
	int dehealth;//伤害量
	int godtimer;//无敌的时间（30帧）
	bool linked;
	float ballangle;
	//死球的Alpha
	int diealpha;
	//异常状态
	bool burned;
	bool frige;
	bool toxic;
	int count_burned;
	int count_frige;
	int count_toxic;
	bool sword_effect;
	bool natked;
	float HP;
	void SetX(float setx);
	void SetY(float sety);
	float GetX()const;
	float GetY()const;
	bool GetGivescore()const;
	void SetGivescore(bool set);
	float dx, dy;
	float damage;
	int p_def;
	int m_def;
	void diedboom(BALLbase *pball,int count);
	BALLbase();
	~BALLbase();
private:
	float x, y;
	bool addscale;
	int reborn;
	bool givescore;
	float std_scale;




	
};
#pragma pack()

