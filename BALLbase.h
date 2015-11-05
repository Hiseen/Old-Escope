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
	bool reverse;//���ƻ��˵Ŀ���
	bool godmode;
	float reangle;//���˽Ƕ�
	void move(float x1, float y1, float dt);//���˺��ƶ�
	bool skill2;
	bool hited_skill;
	int count_remove;//����ʱ��
	void born();
	void godie(int mode=0);
	void reborn_ball(int counter_time);
	float scale;
	bool die;
	int alpha;
	bool font;//�費��Ҫnew�˺�����
	int dehealth;//�˺���
	int godtimer;//�޵е�ʱ�䣨30֡��
	bool linked;
	float ballangle;
	//�����Alpha
	int diealpha;
	//�쳣״̬
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

