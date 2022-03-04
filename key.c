#include <reg52.h>

sbit ADDR0 = P1^0;
sbit ADDR1 = P1^1;
sbit ADDR2 = P1^2;
sbit ADDR3 = P1^3;
sbit ENLED = P1^4;

sbit KEY1 = P2^4;
sbit KEY2 = P2^5;
sbit KEY3 = P2^6;
sbit KEY4 = P2^7;

sbit LED9 = P0^7;
sbit LED8 = P0^6;
sbit LED7 = P0^5;
sbit LED6 = P0^4;

void delay();
unsigned char code LedChar[] = {
		0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,
    0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E
};
void main()
{
		bit backup = 1;
		bit KeyBuf = 1;
		unsigned char cnt = 0;
		ADDR0 = 0;
		ADDR1 = 0;
		ADDR2 = 0 ;
		ADDR3 = 1;
		ENLED = 0;
		P2 = 0xF7;
		P0 = LedChar[cnt];
		while(1)
		{
				if(KEY4 != backup)
				{
						if(0 == backup)
						{
								cnt++;
								if(cnt >= 10)
								{
										cnt = 0;
								}
								P0 = LedChar[cnt];
						}
						backup = KEY4;
				}
		}
}
void delay()
{
		unsigned char i = 1000;
}