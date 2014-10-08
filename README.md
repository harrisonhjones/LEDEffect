LED-Effects
===========

A simple library for Arduino which allows for different LED effects

# Installation
## Arduino
* Copy the Library/LEDEffect into your Arduino libraries folder

## SparkCore

* Add Library/LEDEffect/LEDEffect.cpp and Library/LEDEffect/LEDEffect.h to your project

* Edit LEDEffect.cpp. Replace

    // Required for Arduino Library only
    #include "Arduino.h"

with

    // Required for Arduino Library only
    //#include "Arduino.h"

* Edit LEDEffect.h. Replace

    // Required for Arduino Library only
    #include "Arduino.h"
    // Required for SparkCore Library only
    //#include "application.h"

with

    // Required for Arduino Library only
    //#include "Arduino.h"
    // Required for SparkCore Library only
    #include "application.h"

# Usage

    #include <LEDEffect.h>

    LEDEffect led1(13); // Use onboard LED
    void setup()  {
        led1.blink(250);    // Set the LED to blink
    }
    void loop()  {
        led1.update();  // Call update as often as possible for smooth animation
    }

For more examples reference the "Library/LEDEffects/examples" folder

# Available LED Effects
* Off - Turns the LED off
* On - Turns the LED on
* Breath - Makes the LED "breath". The breathing rate can be specified for faster or slower breathing
* Fade Up - Makes the LED fade from dark to bright and then restart at dark. The speed of the animation can be controlled
* Fade Down - Makes the LED fade from bright to dark and then restart at bright. The speed of the animation can be controlled
* Blink - Makes the LED blink. The blinking rate can be controlled.
* Dim - Controls the LED's brightness