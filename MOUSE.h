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
	int godcount;//�����޵�ʱ��
	bool heal;//��ѪЧ��
	void powerup();
	void powerdown();
	void setPower(int power);
	int getPower()const;
	bool font;
	int dehealth;
	float healthline;//�����ֵ
	void reset();
	~MOUSE();
private:
	int up_power;//������ǿ������

};

