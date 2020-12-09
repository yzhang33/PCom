#include <Wire.h>
#include <FastLED.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

#define LED_PIN 4
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];
// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(5,INPUT);
  pinMode(4,OUTPUT);
  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(10);
  }
  
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");
}

void loop() {
  // Get the currently touched pads
  currtouched = cap.touched();
  
  for (uint8_t i=0; i<12; i++) {
    // it if *is* touched and *wasnt* touched before, alert!
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
      Serial.write(i); 
      Serial.print(i); Serial.println(" touched");
      digitalWrite(2,HIGH);
      if(i == 0){
          //orange
        for(int i=0;i<=58;i++){
            leds[i] = CRGB::Orange;
            FastLED.show();
            //delay(40);
          }
      }
      //green apple
      if(i == 1){
        for(int i=0;i<=58;i++){
            leds[i] = CRGB::Green;
            FastLED.show();
            //delay(40);
          }
      }
      //banana
      if(i == 2){
        for(int i=0;i<=58;i++){
            leds[i] = CRGB::Yellow;
            FastLED.show();
            //delay(40);
          }
      }
      //red apple
      if(i == 3){
        for(int i=0;i<=58;i++){
            leds[i] = CRGB::Red;
            FastLED.show();
            //delay(40);
          }
      }
        
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      for(int i=0;i<=58;i++){
            leds[i] = CRGB::Black;
            FastLED.show();
            //delay(40);
      }
    }
  }

  // reset our state
  lasttouched = currtouched;

  // comment out this line for detailed data from the sensor!
  return;
}