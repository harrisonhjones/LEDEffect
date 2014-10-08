/*
	basic.ino - Library for LED Effecs.
	Created by Harrison H. Jones, October 3, 2014.

	Basic LEDEffect Example
	Cycles two LEDs through multiple effects
	PIN 13 is connected to the onboard LED for most Arduinos
	PIN 7 is connected to an external LED's positive lead. The negative lead is connected to GND
*/

#include <LEDEffect.h>
LEDEffect led2(13);	// Use onboard LED
unsigned long time = 0;
int ledState = 0;
void setup()  {}

void loop()  {
	if(millis() > time + 5000)	// Every 5 seconds change between states
	{    
		time = millis();
		if(ledState == 0)
		{
			led1.on();
			led2.breath(15);
			ledState = 1;
		}
		else if(ledState == 1)
		{
			led1.breath(30);
			led2.fadeDown(15);
			ledState = 2;
		}
		else if(ledState == 2)
		{
			led1.fadeDown(30);
			led2.fadeUp(30);
			ledState = 3;
		}
		else if(ledState == 3)
		{
			led1.fadeUp(10);
			led2.blink(125);
			ledState = 4;
		}
		else if(ledState == 4)
		{
			led1.blink(250);
			led2.off();
			ledState = 5;
		}
		else if(ledState == 5)
		{
			led1.off();
			led2.on();
			ledState = 6;
		}
		else
		{
			led2.on();
			led1.off();
			ledState = 0;
		}
	}
	led1.update();
	led2.update();
}