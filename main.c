#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"
#include "Key.h"

uint8_t KeyNum;			//定义用于接收键码的变量
uint16_t Angle;			//定义角度变量
uint16_t d=0;

int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	Servo_Init();		//舵机初始化
	Key_Init();			//按键初始化
	
	/*显示静态字符串*/
	OLED_ShowString(1, 1, "Angle:");	//1行1列显示字符串Angle:
	
	while (1)
	{
		/*KeyNum = Key_GetNum();			//获取按键键码
		 if (KeyNum == 1) {
            while (Key_GetNum() == 1) 
                Angle++;}
                if (Angle > 180) {
                    Angle = 0;
                }
		Servo_SetAngle(Angle);			//设置舵机的角度为角度变量
		OLED_ShowNum(1, 7, Angle, 3);	//OLED显示角度变量
		*/
		
		if(d ==0) Angle++;
		if(d ==1) Angle--;
		if( Angle>=180)
		{
			d=1;
		}
		if(Angle == 0)
		{
			d=0;
		}
		Servo_SetAngle(Angle);
		OLED_ShowNum(1, 7, Angle, 3);
		Delay_ms(10);
		
		
	}
}
		 

