#include "pitches.h"

const int speakerPin = 4;

int preState = LOW; //previous state
int speakerState = LOW; //speaker state
int debounce = 150;
long time = 0;

int notes[] = {
   NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_G3, NOTE_C4,
  NOTE_C3, NOTE_D3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_A3,
  NOTE_B3, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_B3,
  NOTE_C4, NOTE_D4, NOTE_G3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_C4, NOTE_E4, NOTE_D4
};
int notesDurations[] = {
  2, 4, 4, 4, 4, 4, 2, 2,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 2, 2, 2, 4, 4, 4, 4,
  4, 2, 2, 4, 4, 4, 4, 4,
  4, 4, 4, 2, 2
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12,INPUT);
}

void loop() {
  if(checkState() == HIGH){
    delay(20);
    for(int note=0;note<37;note++){
      if(digitalRead(12) == HIGH){
        Serial.println("in here");
        speakerState = LOW;
        noTone(speakerPin);
        break;
      }
      int noteDuration = 1000/notesDurations[note];
      tone(speakerPin,notes[note],noteDuration);
      int pause = noteDuration*1.30;
      delay(pause);
      noTone(speakerPin);  
    }
  }
}

bool checkState(){
  int buttonState = digitalRead(12);
   delay(200);
  if(buttonState == HIGH && preState == LOW && millis() - time > debounce){
    if(speakerState == LOW){
       speakerState = HIGH;   
    }else{
      speakerState = LOW;
    }
    time = millis();
  }
  preState = buttonState;
  return speakerState;
}
