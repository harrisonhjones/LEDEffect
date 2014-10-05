/*
	button.ino - Library for LED Effecs.
	Created by Harrison H. Jones, October 3, 2014.

	LEDEffect Example with button press
	Cycles an LEDs through multiple effects. Changes on button press
	PIN 3 is connected to the a normally open switch. The common of the switch is connected to ground
	PIN 7 is connected to an external LED's positive lead. The negative lead is connected to GND
*/

#include "ClickButton.h"
#include <LEDEffect.h>

// the LED
LEDEffect led1(7);
int ledState = 0;

// the Button
const int buttonPin1 = 3;
ClickButton button1(buttonPin1, LOW, CLICKBTN_PULLUP);

void setup()
{
	// Setup button timers (all in milliseconds / ms)
	// (These are default if not set, but changeable for convenience)
	button1.debounceTime   = 20;   // Debounce timer in ms
	button1.multiclickTime = 250;  // Time limit for multi clicks
	button1.longClickTime  = 1000; // time until "held-down clicks" register

	led1.on();
	ledState = 1;
}


void loop()
{
	// Update button state
	button1.Update();

	if(button1.clicks == 1)
	{
		if(ledState == 0)
		{
			led1.on();
			ledState = 1;
		}
		else if(ledState == 1)
		{
			led1.breath(30);
			ledState = 2;
		}
		else if(ledState == 2)
		{
			led1.fadeDown(30);
			ledState = 3;
		}
		else if(ledState == 3)
		{
			led1.fadeUp(10);
			ledState = 4;
		}
		else if(ledState == 4)
		{
			led1.blink(250);
			ledState = 5;
		}
		else
		{
			led1.off();
			ledState = 0;
		}
	}
	led1.update();  
}