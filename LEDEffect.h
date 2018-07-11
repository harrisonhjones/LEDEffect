/*
	LEDEffect.h - Library for LED Effecs.
	Created by Harrison H. Jones, October 3, 2014.
*/

#ifndef LEDEffect_h
#define LEDEffect_h

#if defined (SPARK)
#include "application.h"
#else
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#endif

class LEDEffect
{
  public:
	LEDEffect(int pin);
	void update();
	void off();
	void on();
	void breath(int ledDelay);
	void fadeDown(int ledDelay);
	void fadeUp(int ledDelay);
	void blink(int ledDelay);
	void dim(unsigned char brightness);
  private:
	int _pin;
	unsigned char _brightness;
	unsigned char _fadeAmount;    // how many points to fade the LED by
	unsigned char _fadeDirection; 
	unsigned char _ledState;     // 0 = off, 1 = on, 2 = breath, 3 = fade down, 4 = fade up, 5 = blink
	int _ledDelay; // in ms
	unsigned long _time;
};

#endif
