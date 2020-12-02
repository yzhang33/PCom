#include <FastLED.h>

#define LED_PIN 4
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
 FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
 pinMode(5,INPUT);
 pinMode(4,OUTPUT);
}

void loop() {
  int keypressed = 0;
  //read sensor value
  int sensorVal = digitalRead(5);
  Serial.println(sensorVal);
  //if touched 
  if(sensorVal == LOW){
    digitalWrite(2,HIGH);
    //one fruit pressed
    ++keypressed;
    Serial.print("pressed: ");
    Serial.println(sensorVal);
    //trun on leds
    for(int i=0;i<=60;i++){
        leds[i] = CRGB::Orange;
        FastLED.show();
        delay(40);
    }
  }
  //Serial.println(keypressed);
  //no fruit pressed
  if(keypressed == 0){
    digitalWrite(4,LOW);
  }
  
  delay(250);
  
}