#include <STC89C5xRC.H>
#include "Delay.h"

sbit Buzzer = P2^5;   //位定义后面要加分号(否则会报错void语法错误)，define定义后面不用加分号

/**
  * @brief 蜂鸣器专用延迟函数，
  * @param 无
  * @retval 无
  */
//
void Delay500us()	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 227;
	while (--i);
}


/**
  * @brief 定制蜂鸣器发声时间，频率1000Hz
  * @param ms 毫秒
  * @retval 无
  */
//
void Buzzer_Time(unsigned int ms)       //1000
{
  unsigned int g_i;	
	for(g_i = 0;g_i < (ms*2);g_i++)         //程序进入死循环之后，执行完死循环之前不会再检测按键是否重新按下
	{                                    //同理后续的流程也不会被提前执行，这是死循环需要额外注意的部分
		Buzzer = !Buzzer;             //在这里使用逻辑关系符！和使用位运算符~是一样效果的，都可以反转0和1
		Delay500us();
	}		 
}