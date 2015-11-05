#pragma once
#include"BALLbase.h"

#define PHYSICS 1
#define MAGIC 2


class MOUSE
{
public:
	MOUSE();
	float MAX_HP ;
	float MAX_MP ;
	float MAX_EXP;
	int LV ;
	float x, y;
	float dx, dy;
	float angle;
	float speed;
	float mouseHP, mouseMP, mouseEXP;
	bool god;
	int luk;
	float base_p_damage;
	float base_m_damage;
	int base_p_def;
	int base_m_def;
	int godcount;//鼠标的无敌时间
	bool heal;//吸血效果
	void powerup();
	void powerdown();
	void setPower(int power);
	int getPower()const;
	bool font;
	int dehealth;
	float healthline;//计算差值
	void reset();
	~MOUSE();
private:
	int up_power;//技能增强！！！

};

