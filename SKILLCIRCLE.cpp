#include "SKILLCIRCLE.h"
#include "new.h"



SKILLCIRCLE::SKILLCIRCLE(
	HGE *hge,
	const char* fliename1,
	const char* fliename2, 
	float w, 
	float h, 
	float center_x, 
	float center_y,
	const char* filename3
	)
{
	
	tex = hge->Texture_Load(fliename1);
	spr = new hgeSprite(tex, 0, 0, w, h);
	spr->SetHotSpot(center_x, center_y);
	tex2 = hge->Texture_Load(filename3);
	spr2 = new hgeSprite(tex2, 0, 0, w, h);
	spr2->SetHotSpot(center_x, center_y);
    //分配内存
	alpha = 0;
	alive = false;
	CTRL = false;
	angle2 = 0.759315;
	map1.insert(pair<float, int>(SOCKET_1, 1));	
	map1.insert(pair<float, int>(SOCKET_2, 2));
	map1.insert(pair<float, int>(SOCKET_3, 3));
	map1.insert(pair<float, int>(SOCKET_4, 4));
	map1.insert(pair<float, int>(SOCKET_5, 5));
	map1.insert(pair<float, int>(SOCKET_6, 6));
	map1.insert(pair<float, int>(SOCKET_7, 7));
	map1.insert(pair<float, int>(SOCKET_8, 0));

}

SKILLCIRCLE::~SKILLCIRCLE()
{

}

void SKILLCIRCLE::PutSkill(int skillkey, float position)
{


}


void SKILLCIRCLE::Start(float x1,float y1,float x3,float y3,bool CD,int &choose)
{
	//总共17帧
	alive = true;
	if (alpha != 255)
	{   
		if (alpha == 0)scale = 0.666;
		alpha += 15; 
		spr->SetColor(ARGB(alpha, 255, 255, 255));
		angle += (1.57 / 17);//need test
		scale += (0.333 / 17);
	}
	else
	{
		choose = map1.find(angle2)->second;
		CTRL = true;
	}
	x = x1;
	y = y1;
	
	if (CD)spr2->SetColor(ARGB(255, 11, 23, 31));
	else spr2->SetColor(ARGB(255, 255, 255, 255));

    float angle3 = atan2f(y1 - y3, x1 - x3);
	if (angle3 < -1.9 && angle3 >= -2.81)angle2 = -2.364725;
	if (angle3 > 0.43 && angle3 < 1.10)angle2 = 0.759315;
	if (angle3 >= 1.10 && angle3 < 1.83)angle2 = 1.515101;
	if (angle3 >= 1.83 && angle < 2.64)angle2 = 2.276062;
	if (angle3 >= 2.64 || angle3 < -2.81)angle2 = 3.116902;
	if (angle3 < 0.43 && angle3 >= -0.23)angle2 = 0;
	if (angle3 < -0.23 &&angle3 >= -1)angle2 = -0.785;
	if (angle3 < -1 && angle3 >= -1.90)angle2 = -1.57;
	







	
}


void SKILLCIRCLE::Render(HGE *hge,float x2,float y2)
{
	
	if (alive)
	{
		spr->RenderEx(x, y, angle, scale, scale);
		hge->Gfx_RenderLine(x, y, x2+25, y2+25, ARGB(255, 255, 255, 255), 0.00000001);
		spr2->RenderEx(x, y, angle2, scale, scale);
	}

}


void SKILLCIRCLE::over(float &x1,float &y1,int &choose)
{
	
	if (alpha != 0)
	{
		alpha -= 15;
		spr->SetColor(ARGB(alpha, 255, 255, 255));
		angle -= (1.57 / 17);//need test
		scale -= (0.333 / 17);//need test
	}
	else
	{
		x1 = 0;
		y1 = 0;
		choose=map1.find(angle2)->second;
		angle = 0;
		scale = 0;
		alive = false;
		CTRL = false;
	}
	x = x1;
	y = y1;









}

bool SKILLCIRCLE::GetCTRL()
{
	return CTRL;
}

bool SKILLCIRCLE::GetAlive()
{
	return alive;
}

float SKILLCIRCLE::getAngle()
{
	return angle2;
}

float SKILLCIRCLE::GetSize()
{
	return scale;
}

