int incommingByte;
int ledPin = 2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    if(Serial.available()>0){
      incommingByte = Serial.read();
      if(incommingByte == 1){
        digitalWrite(ledPin,HIGH);
      }
      if(incommingByte == 2){
        digitalWrite(ledPin,LOW);
      }
    } 

}

