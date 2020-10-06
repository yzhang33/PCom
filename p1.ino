#include "pitches.h"

const int speakerPin = 8;
const int noteDuration = 20;

int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int notes1[] = {
  NOTE_A3, NOTE_C4, NOTE_E4, NOTE_A4
};

int notes2[] = {
  NOTE_C4, NOTE_A3, NOTE_F3, NOTE_E3
};

int notes1Durations[] = {
  4,4,4,4
};


void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  buttonState = digitalRead(2);
  while(playing){
      
  }
  for (int note = 0; note < 4; note++) {
     int notes1Duration = 1000/notes1Durations[note];
       if (buttonState == HIGH) {        
          tone(speakerPin, notes1[note], notes1Duration);
          delay(200);
    }
  lastButtonState = buttonState;
    

   }
  }
