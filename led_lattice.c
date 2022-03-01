#include <reg52.h>

sbit ADDR0 = P1^0;
sbit ADDR1 = P1^1;
sbit ADDR2 = P1^2;
sbit ADDR3 = P1^3;
sbit ENLED = P1^4;

unsigned char code LedLove[]={
		0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xC3,0xE7,0xE7,0xE7,0xE7,0xE7,0xC3,0xFF,
    0x99,0x00,0x00,0x00,0x81,0xC3,0xE7,0xFF,
    0x99,0x99,0x99,0x99,0x99,0x81,0xC3,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};
void main()
{
		EA = 1;      //中断总使能
		ENLED = 0;
		ADDR3 = 0;   //U4使能
		TH0 = 0xFC;
		TL0 = 0x67;
		TMOD = 0x01;  //T0定时器模式1
		ET0 = 1;
		TR0 = 1;     //T0定时器使能
		

		while(1);
}
void interruptTime0() interrupt 1  //T0定时器中断
{ 
    static unsigned char j = 0;
		static unsigned char tmr = 0;
		static unsigned char index = 0;
		TH0 = 0xFC;
		TL0 = 0x67;
		P0 = 0xFF;
		switch(j)
		{	
		case 0: ADDR2=0; ADDR1=0; ADDR0=0; j++ ; P0 = LedLove[index+0]; break;	
		case 1: ADDR2=0; ADDR1=0; ADDR0=1; j++ ; P0 = LedLove[index+1]; break;
		case 2: ADDR2=0; ADDR1=1; ADDR0=0; j++ ; P0 = LedLove[index+2]; break;
		case 3: ADDR2=0; ADDR1=1; ADDR0=1; j++ ; P0 = LedLove[index+3]; break;
		case 4: ADDR2=1; ADDR1=0; ADDR0=0; j++ ; P0 = LedLove[index+4]; break;
		case 5: ADDR2=1; ADDR1=0; ADDR0=1; j++ ; P0 = LedLove[index+5]; break;
		case 6: ADDR2=1; ADDR1=1; ADDR0=0; j++ ; P0 = LedLove[index+6]; break;
		case 7: ADDR2=1; ADDR1=1; ADDR0=1; j=0 ; P0 = LedLove[index+7]; break;
		default:break;		
		}
		tmr++;
		if(tmr >= 250)
		{
				tmr = 0;
				index++;
				if(index >= 32)
				{
					index = 0;
				}
		}
		
		


}