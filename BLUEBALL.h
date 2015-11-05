#pragma once
#include "BALLbase.h"

#ifndef FPS
#define FPS 100
#endif
class BLUEBALL : public BALLbase
{
public:
	bool guard;
	void Attack();
	void Guard();
	void born();
	void reborn_ball(int counter_time);
	BLUEBALL();
	~BLUEBALL();

private:
	int attacknum;
	int Guard_time;
	int std_mdef;
	int std_pdef;


};

