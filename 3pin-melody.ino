#include "pitches.h"

const int speakerPin = 8;
const int noteDuration = 20;

int button1State = 0;
int lastButton1State = 0; 
int button2State = 0; 
int lastButton2State = 0; 
int button3State = 0; 
int lastButton3State = 0; 

bool outPin[] ={false,false,false};

int notes1[] = {
  NOTE_F3, NOTE_A3, NOTE_C4, NOTE_DS4, NOTE_F4,  
};

int notes2[] = {
  NOTE_A3, NOTE_C4, NOTE_E4, NOTE_F4
};

int notes3[] = {
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_G4, NOTE_E4 
};

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop() {
  button1State = digitalRead(2);
  if (button1State != lastButton1State) {
    if (button1State == HIGH){
      outPin[0] = true;
    }
  }
  lastButton1State = button1State;

  button2State = digitalRead(3);
  if (button2State != lastButton2State) {
    if (button2State == HIGH){
      outPin[2] = true;
    }
  }
  lastButton2State = button2State;

    button3State = digitalRead(4);
  if (button3State != lastButton3State) {
    if (button3State == HIGH){
      outPin[3] = true;
    }
  }
  lastButton3State = button3State;

  if(outPin[0]){
    playMusic(0, notes1,5, 200,[3,4]);
  }
  
  if(outPin[1]){
    playMusic(1, notes2,4, 200,[2,4]);
  }
  if(outPin[2]){
     playMusic(2, notes3,8, 100,[2,3]);
  }

}

void playMusic(int playingPin, int mynotes[],int len, int tempo,int readpin[]){
   for (int note = 0; note < len; note++) {             
        tone(speakerPin, notes1[note],tempo);
        delay(tempo);
      if (digitalRead(readpin[0]) == HIGH || digitalRead(readpin[1]) == HIGH){
        outPin[playingPin] = false;
        break;
      }
    }
}
