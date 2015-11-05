#pragma once
#include <hge.h>
#include <hgesprite.h>
#include <hgeanim.h>
#include "SKILLBASE.h"
#include <map>
using namespace std;
#define SOCKET_1  0.759315
#define SOCKET_2  1.515101
#define SOCKET_3  2.276062
#define SOCKET_4  3.116902
#define SOCKET_5  0
#define SOCKET_6 -0.785
#define SOCKET_7 -1.57
#define SOCKET_8 -2.364725





class SKILLCIRCLE
{
public:
	friend class SKILLBASE;
	/*
	static SKILLCIRCLE* GetInstance
		(
		HGE *hge=0,
		const char* fliename1=0,
		const char* fliename2=0,
		float w=0,
		float h=0,
		float center_x=0,
		float center_y=0,
		const char* filename3=0
		)
	{
		if (CIRCLE == NULL)
			CIRCLE = new SKILLCIRCLE(hge, fliename1, fliename2, w, h, center_x, center_y, filename3);
			return CIRCLE;
	};
	*/
	int GetSkill()const;
	void PutSkill(int skillkey, float position);
	void Start(float x1, float y1, float x2, float y2,bool CD,int &choose);
	void Render(HGE *hge, float x2, float y2);
	void over(float &x1, float &y1,int &choose);
	bool GetCTRL();
	bool GetAlive();
	float getAngle();
	float GetSize();
	SKILLCIRCLE(
		HGE *hge,
		const char* fliename1,
		const char* fliename2,
		float w,
		float h,
		float center_x,
		float center_y,
		const char* filename3
		);
	~SKILLCIRCLE();

private:
	
	map<float, int>map1;
	HTEXTURE tex;
	HTEXTURE tex2;
	hgeSprite *spr2;
	HEFFECT sound;
	hgeSprite *spr;
	float x, y;
	float angle;
	void *p;
	int alpha;
	float scale;
	bool alive;
	bool CTRL;
	float angle2;
	//static SKILLCIRCLE* CIRCLE;
};

