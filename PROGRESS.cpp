#include "PROGRESS.h"


PROGRESS::PROGRESS(const char* texture, float w, float h, float center_x, float center_y)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	HTEXTURE tex=hge->Texture_Load(texture);
	spr = new hgeSprite(tex, 0, 0, w, h);
	spr->SetHotSpot(center_x, center_y);
}


void PROGRESS::render(float x, float y, float pro)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	
	float cx, cy;
	spr->GetHotSpot(&cx, &cy);
	if (pro > 0 && pro < 0.25)
	{
		/*
		Q1.v[0].z = 0.5;
		Q1.v[1].z = 0.5;
		Q1.v[2].z = 0.5;
		Q1.v[3].z = 0.5;
		Q1.v[0].x = 0 + x;
		Q1.v[0].y = 0 + y;
		Q1.v[1].x = cx + x;
		Q1.v[1].y = 0 + y;
		Q1.v[2].x = cx + x;
		Q1.v[2].y = cy * 2 + y;
		Q1.v[3].x = 0 + x;
		Q1.v[3].y = cy * 2 + y;
		Q1.tex = spr->GetTexture();
		Q2.v[0].z = 0.5;
		Q2.v[1].z = 0.5;
		Q2.v[2].z = 0.5;
		Q2.v[3].z = 0.5;
		Q2.v[0].x = cx + x;
		Q2.v[0].y = cy + y;
		Q2.v[1].x = cx + x;
		Q2.v[1].y = 10 + y;
		Q2.v[2].x = cx * 2 + x;
		Q2.v[2].y = cy * 2 + y;
		Q2.v[3].x = cx + x;
		Q2.v[3].y = cy * 2 + y;
		Q2.tex = spr->GetTexture();
		*/
		hgeSprite *spr2 = new hgeSprite(*spr);
		spr->SetTextureRect(0, 0, cx, cy * 2);
		
	}
	spr->Render(500, 500);
	hge->Gfx_RenderQuad(&Q1);
	hge->Gfx_RenderQuad(&Q2);
	//spr->RenderStretch(x, y, x + cx, y + cy);
	//spr->Render4V(x, y, x+ cx, y, x + cx, y + cy * 2, x, y + cy * 2);
}

PROGRESS::~PROGRESS()
{
}
