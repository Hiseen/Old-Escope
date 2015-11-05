#include "MUTI_POOL.h"


MUTI_POOL::MUTI_POOL(const char *flie,int nframes, float w, float h, float centerx, float centery)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	HTEXTURE pic = hge->Texture_Load(flie);
	boom = new hgeAnimation(pic, nframes, 30, 0, 0, w, h);
	boom->SetZ(SKILL_LAYER);
	boom->SetHotSpot(centerx, centery);
}


MUTI_POOL::~MUTI_POOL()
{
}


void MUTI_POOL::insert(float x, float y, float size)
{
	MUTIBOOM *mutiboom = new MUTIBOOM(boom,x,y,size);
	mutiboom->Play();
	pool.push_back(*mutiboom);
	delete mutiboom;
	mutiboom = NULL;

}

void MUTI_POOL::render()
{
	HGE *hge = hgeCreate(HGE_VERSION);
	float dt = hge->Timer_GetDelta();
	for (int i = 0; i < pool.size(); i++)
	{
		pool[i].anim->Update(dt);
		pool[i].anim->RenderEx(pool[i].GetX(), pool[i].GetY(), 0, pool[i].GetSize(), pool[i].GetSize());
		pool[i].lifespan--;
		if (pool[i].lifespan <= 0)
		{
			delete pool.cbegin()->anim;
			pool.erase(pool.cbegin());
		}

	}


}