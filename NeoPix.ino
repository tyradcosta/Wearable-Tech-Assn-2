#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
const int numPixels = 12; //Number of pixels on neopixel
const int pixelPin = 6; // pin connected to neopixels
const int led = 0;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5; // how many points to fade the led by 
bool slideSwitch; // switch on cpx
int state = 1; // inital state

Adafruit_NeoPixel pixels(numPixels, pixelPin, NEO_GRB + NEO_KHZ800); // neopixel ring 


void setup() {

  Serial.begin(9600);
  CircuitPlayground.begin();

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

}

void loop() {

  // if switch is on then set state to 2 and play day light pattern on the cpx and neopixels
 
  slideSwitch = CircuitPlayground.slideSwitch();
  if (slideSwitch) {
    state = 2;
    Day();
RingTwo();

// if switch is off then set state to 1 and play night pattern on the cpx and neopixels 

//    Serial.print("state 2");
  } else {
    state = 1;
    Night();
    RingOne();

  }
  Serial.println();
  

}

// function for night light pattern

void Night() {


  if (state == 1) {
//fades leds in and out 
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }

// sets pixel colors
    CircuitPlayground.setPixelColor(0, 5,   0,   150);
    CircuitPlayground.setPixelColor(1, 5,   0,   150);
    CircuitPlayground.setPixelColor(2, 5,   0,   150);
    CircuitPlayground.setPixelColor(3, 25,   25,   112);
    CircuitPlayground.setPixelColor(4, 25,   25,   112);
    CircuitPlayground.setPixelColor(5, 25,   25,   112);
    CircuitPlayground.setPixelColor(6, 30,   0,   159);
    CircuitPlayground.setPixelColor(7, 30,   0,   159);
    CircuitPlayground.setPixelColor(8, 30,   0,   159);
    CircuitPlayground.setPixelColor(9, 30,   0,   159);
    CircuitPlayground.setBrightness(brightness);
    
// delay in between loop to create slow glowing 
    delay(20);

    //twinkle twinle song tones 

    // CircuitPlayground.playTone(196,100 );
    //CircuitPlayground.playTone(294,100 );
    //CircuitPlayground.playTone(294,100 );
    //CircuitPlayground.playTone(330,100 );
    //CircuitPlayground.playTone(330,100 );
    //CircuitPlayground.playTone(294,100);
    //CircuitPlayground.playTone(262,100 );
    //CircuitPlayground.playTone(262,100 );
    //CircuitPlayground.playTone(247,100 );
    //CircuitPlayground.playTone(247,100 );
    //CircuitPlayground.playTone(220,100 );
    //CircuitPlayground.playTone(220,100 );
    //CircuitPlayground.playTone(196,100);
    //CircuitPlayground.playTone(294,100 );
    //CircuitPlayground.playTone(294,100 );
    //CircuitPlayground.playTone(262,100 );
    //CircuitPlayground.playTone(262,100 );
    //CircuitPlayground.playTone(247,100 );
    //CircuitPlayground.playTone(247,100 );
    //CircuitPlayground.playTone(220,100 );
    //CircuitPlayground.playTone(294,100 );
    //CircuitPlayground.playTone(294,100 );
    //CircuitPlayground.playTone(262,100 );
    //CircuitPlayground.playTone(262,100 );
    //CircuitPlayground.playTone(247,100 );

  }

}

// function for day light pattern
void Day() {

  if (state == 2) {
//fades leds in and out 
    brightness = brightness + fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
// sets pixel colors
    CircuitPlayground.setPixelColor(0, 168, 60,   0);
    CircuitPlayground.setPixelColor(1, 168,   60,   0);
    CircuitPlayground.setPixelColor(2, 168,   60,   0);
    CircuitPlayground.setPixelColor(3, 168,   60,   0);
    CircuitPlayground.setPixelColor(4, 200,   0,   0);
    CircuitPlayground.setPixelColor(5, 200,   0,   0);
    CircuitPlayground.setPixelColor(6, 190,   24,   0);
    CircuitPlayground.setPixelColor(7, 190,   24,   0);
    CircuitPlayground.setPixelColor(8, 190,   24,   0);
    CircuitPlayground.setPixelColor(9, 200,   20,   0);
    CircuitPlayground.setBrightness(brightness);
// delay in between loop to create slow glowing 
    delay(20);


  }
}


// fucntion to play night light pattern on neopixels
void RingOne() {

  brightness = brightness + fadeAmount;
  ////
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  pixels.setPixelColor(0, pixels.Color (5,   0,   150));
  pixels.setPixelColor (1, pixels.Color(5,   0,   150));
  pixels.setPixelColor(2, pixels.Color( 5,   0,   150));
  pixels.setPixelColor(3, pixels.Color(3, 25,   25,   1120));
  pixels.setPixelColor(4, pixels.Color( 25,   25,   112));
  pixels.setPixelColor(5, pixels.Color( 25,   25,   112));
  pixels.setPixelColor (6, pixels.Color (30,   0,   159));
  pixels.setPixelColor(7, pixels.Color (30,   0,   159));
  pixels.setPixelColor(8, pixels.Color (30,   0,   159));
  pixels.setPixelColor(9, pixels.Color (30,   0,   159));
  pixels.setPixelColor(10, pixels.Color (30,   0,   159));
  pixels.setPixelColor(11, pixels.Color (30,   0,   159));
  pixels.setBrightness(brightness);

pixels.show();   // Send the updated pixel colors to the hardware.
}

// fucntion to play day light pattern on neopixels
void RingTwo() {

  brightness = brightness + fadeAmount;
  ////
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

    pixels.setPixelColor( 0, pixels.Color( 168, 60,   0));
    pixels.setPixelColor(1, pixels.Color(168, 60,   0));
    pixels.setPixelColor(2, pixels.Color(168,   60,   0));
    pixels.setPixelColor(3, pixels.Color(168,   60,   0));
    pixels.setPixelColor(4, pixels.Color(200,   0,   0));
    pixels.setPixelColor(5, pixels.Color(200,   0,   0));
    pixels.setPixelColor(6, pixels.Color(190,   24,   0));
    pixels.setPixelColor(7, pixels.Color (190,   24,   0));
    pixels.setPixelColor(8, pixels.Color ( 190,   24,   0));
    pixels.setPixelColor(9, pixels.Color (200,   20,   0));
       pixels.setPixelColor(10, pixels.Color ( 190,   24,   0));
    pixels.setPixelColor(11, pixels.Color (200,   20,   0));
    pixels.setBrightness(brightness);

pixels.show();   // Send the updated pixel colors to the hardware.
}
