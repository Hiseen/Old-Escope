#pragma once
#include "hge.h"
#include "MUTIBOOM.h"
#include<vector>
using namespace std;
class MUTI_POOL
{
public:
	MUTI_POOL(const char *flie,int nframes, float w, float h, float centerx, float centery);
	~MUTI_POOL();
	void render();
	void insert(float x,float y,float size=1.0);
	hgeAnimation *boom;
private:
	vector<MUTIBOOM> pool;



};

