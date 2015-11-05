#include "PUBLIC.h"


PUBLIC::PUBLIC()
{

	cskill1 = new Point[4];
	cskill2 = new Point[4];
	cskill3 = new Point[4];
	cskill4 = new Point[7];
	cskill5 = new Point[4];
	cskill6 = new Point[6];
	//技能1的碰撞结构
	cskill1[0].x = 0;
	cskill1[0].y = 0;
	cskill1[1].x = 42-20;
	cskill1[1].y = 46-95;
	cskill1[2].x = 151-20;
	cskill1[2].y = 97-95;
	cskill1[3].x = 42-20;
	cskill1[3].y = 144-95;
	//技能2的碰撞结构
	cskill2[0].x = 0;
	cskill2[0].y = 0;
	cskill2[1].x = 156-397;
	cskill2[1].y = 28-90;
	cskill2[2].x = 359-397;
	cskill2[2].y = 90-90;
	cskill2[3].x = 156-397;
	cskill2[3].y = 147-90;
	//技能sword的combo1的碰撞结构
	cskill3[0].x = 0;
	cskill3[0].y = 0;
	cskill3[1].x = 79-26;
	cskill3[1].y = 56-82;
	cskill3[2].x = 153-26;
	cskill3[2].y = 82-82;
	cskill3[3].x = 55-26;
	cskill3[3].y = 134-82;
	//技能sword的combo2的碰撞结构1
	cskill4[0].x = 0;
	cskill4[0].y = 0;
	cskill4[1].x = 162 - 40;
	cskill4[1].y = 67 - 208;
	cskill4[2].x = 392 - 40;
	cskill4[2].y = 47 - 208;
	cskill4[3].x = 516- 40;
	cskill4[3].y = 85 - 208;
	cskill4[4].x = 230 - 40;
	cskill4[4].y = 171 - 208;
	cskill4[5].x = 180 - 40;
	cskill4[5].y = 264 - 208;
	cskill4[6].x = 129 - 40;
	cskill4[6].y = 274 - 208;
	//技能sword的combo2的碰撞结构2
	cskill5[0].x = 0;
	cskill5[0].y = 0;
	cskill5[1].x = 150 - 27;
	cskill5[1].y = 150 - 202;
	cskill5[2].x = 313 - 27;
	cskill5[2].y = 202 - 202;
	cskill5[3].x = 167 - 27;
	cskill5[3].y = 248 - 202;
	//技能sword的combo3的碰撞结构
	cskill6[0].x = 0;
	cskill6[0].y = 0;
	cskill6[1].x = 102 - 16;
	cskill6[1].y = 38 - 118;
	cskill6[2].x = 403 - 16;
	cskill6[2].y = 28 - 118;
	cskill6[3].x = 443 - 16;
	cskill6[3].y = 106 - 118;
	cskill6[4].x = 374 - 16;
	cskill6[4].y = 150 - 118;
	cskill6[5].x = 183 - 16;
	cskill6[5].y = 151 - 118;

















}


PUBLIC::~PUBLIC()
{
}
