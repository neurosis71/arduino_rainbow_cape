# Rainbow Cape :rainbow:
###### An Arduino project




### 1. What is it ?

This code comes from a personal project for building a rainbow cape like you can see here : [Living Rainbow- an Arduino Controlled Fiber Optic Cape](http://www.instructables.com/id/Living-Rainbow-an-Arduino-Controlled-Fiber-Optic-C/)

This code has been developed on an Arduino flora but can work on any Arduino as long as you have the correct libraries.

You have 5 effects available with this code :

 - theaterChase
 - theaterChaseRainbow
 - rainbow
 - rainbowCycle
 - rainbowCycleBackwards

You can specify the color displayed only with the theaterChase() function in the RGB format.

You can find color examples in the test function showAllColors() at the end of the file.

Feel free to create your own sequences in the loop function.

### 2. install required dependencies

For this code to compile you need to have the Adafruit NeoPixel Library installed on your system.

To do so in the Arduino IDE go to Sketch -> Include Library -> Manage Libraries

Now search for Adafruit NeoPixel and install the latest version of the library.

Your done everything should work fine.

### 3. warnings (full white on usb)

**IMPORTANT**: To reduce NeoPixel burnout risk, add 1000 uF capacitor across pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input and minimize distance between Arduino and first pixel.  Avoid connecting on a live circuit...if you must, connect GND first.


Be careful when you play around with colors. **The usb port** on the flora (it should be true for most of arduinos) **won't bring enough power to feed the whole LED strip**. My cape for example has 47 LEDs, each one of them will consume around 60 mA **at full brightness** (red, green and blue at maximum) which would require a power supply providing around 2,8A. An USB port would usually provide around 0,5A which is way lower than the power required by the strip. This situation forces the board to enter in some sort of security mode a second after powering it and the LED strip getting stuck on an orange color. To resolve this problem, if it happens to you, is to disconnect the power to the LED strip to be able to push the code on the board, and then reconnect the power to check if the result is what you want. 
