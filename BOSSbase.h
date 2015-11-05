#pragma once
#include <hge.h>
#include "BLUEBALL.h"

//BOSS �� ����


class BOSSbase : public BALLbase
{
public:
	void born();
	void move(float dt);
	void absorb(BALLbase &ball);
	void absorb(BLUEBALL &ball);
	void avoid();
	bool GetMasure()const;
	void SetMasure(bool set);
	float test()const;
	void reborn_ball(int counter_time);
	void ResetAll();
	BOSSbase();
	~BOSSbase();
private:
	bool masure;
	int max;//ͻ���ٽ��
	int avoid_delay;//���ܵ�cd
	int move_delay;//�Ƕ��л�delay
	int target_x;
	int target_y;
	int min_sorb;//��С��Ѫ��
	int max_sorb;//�����Ѫ��
	
};

