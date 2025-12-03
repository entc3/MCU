#include <STC89C5xRC.H>
#include "Delay.H"

unsigned int NixieTable[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void Nixie (unsigned int Location,Number)
{
	switch (Location)
	{
		case 1:
			P22 = 1;P23 = 1;P24 = 1;break;
		case 2:
			P22 = 0;P23 = 1;P24 = 1;break;
		case 3:
			P22 = 1;P23 = 0;P24 = 1;break;
		case 4:
			P22 = 0;P23 = 0;P24 = 1;break;
		case 5:
			P22 = 1;P23 = 1;P24 = 0;break;
		case 6:
			P22 = 0;P23 = 1;P24 = 0;break;
		case 7:
			P22 = 1;P23 = 0;P24 = 0;break;
		case 8:
			P22 = 0;P23 = 0;P24 = 0;break;  
	}
	P0 = NixieTable[Number];
	Delay(1);
//	P0 = 0x00;     //为防止位选段选混乱而设置的清零，如果在主程序调用时需将该函数设置在循环内使用，如果不在循环内使用需要将该行注释掉
}