#include <Adafruit_NeoPixel.h>



// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

#define LED_COUNT 47
#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_RGB + NEO_KHZ800);


/**
 * 
 * You have 5 effects available with this code : 
 * 
 * - theaterChase
 * - theaterChaseRainbow
 * - rainbow
 * - rainbowCycle
 * - rainbowCycleBackwards
 * 
 * 
 * You can specify the color displayed only with the theaterChase() function in the RGB format.
 * 
 * You can find color exemples in the test function showAllColors() at the end of the file.
 * 
 * Feel free to create your own sequences in the loop function.
 */




void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}


void loop() {
  strip.show(); // Initialize all pixels to 'off'
  delay(25);


  /*
   * Phase 1
   */

  //TURQUOISE
  theaterChase(153, 0, 51, 80);
  //PURPLE
  theaterChase(0, 153, 51, 80);
  //TURQUOISE
  theaterChase(153, 0, 51, 80);
  //PURPLE
  theaterChase(0, 153, 51, 80);

  /**
  * Phase 2
  */

  for (int i = 0 ; i < 4 ; ++ i)
  {
    rainbow(30);
  }


  /**
  * Phase 3
  */

  //ORANGE
  theaterChase(51, 255,  0, 80);
  //YELLOW
  theaterChase(102, 204,  0, 80);
  //ORANGE
  theaterChase(51, 255,  0, 80);
  //YELLOW
  theaterChase(102, 204,  0, 80);

  /**
  * Phase 4
  */

  rainbowCycle(30);
  rainbowCycleBackwards(1);
  rainbowCycle(30);
  rainbowCycleBackwards(1);
  rainbowCycle(30);

  /**
  * Phase 5
  */
  
  theaterChaseRainbow(20);
  theaterChaseRainbow(100);
  theaterChaseRainbow(20);

  /**
  * Phase 6
  */

  for (int i = 0 ; i < 4 ; ++ i)
  {
    rainbow(30);
    theaterChaseRainbow(30);
  }

  strip.show(); // Initialize all pixels to 'off'
}



void rainbowCycleBackwards(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = strip.numPixels() - 1; i > 0 ; i--) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}



void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}


//Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}


//Theatre-style crawling lights.
void theaterChase(uint32_t r, uint32_t g, uint32_t b, uint8_t wait) {

  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 4; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, r, g, b);  //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}


//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j = j + 16) { // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, Wheel( (i + j) % 255)); //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}


//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


/**
      TEST FUNCTIONS

*/

/**
 * display all available colors one after the other
 */
 void showAllColors() {

  int colors[][3] = {
    {255, 0, 0},//GREEN
    {153, 0,  51},// TURQUOISE 
    {204,102,  255},// LIGHT_BLUE 
    {102, 0,  255},// BLUE 
    {0, 0, 204},// DARK_BLUE 
    {102, 255,  102},// LIGHT_RED 
    {0, 255,  0},// RED
    {102, 255,  0},// ORANGE 
    {51, 255,  0},// DARK_ORANGE 
    {102, 204,  0},// YELLOW 
    {255, 255, 0},// YELLOW #2
    {51, 204,  255},// PURPLE 
    {0, 204,  204},// DARK_PURPLE 
    {102, 255,  204},// PINK 
  };

  int numRows = sizeof(colors)/sizeof(colors[0]);
  
  for (int y = 0; y <= numRows; y++) {
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, colors[y][0], colors[y][1], colors[y][2]);
    }
    strip.show();
    delay(10000);
  }



}
