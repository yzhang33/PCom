#include <FastLED.h>

#define LED_PIN 4
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
 FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH);
  for(int i=0;i<=60;i++){
    leds[i] = (0,0,255);
    FastLED.show();
    delay(40);
  }
  for(int i=60;i>=0;i--){
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(40);
  }
  
}