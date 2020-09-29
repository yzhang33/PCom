int fsrAnalogPin = 0;
int fsrReading;
int ledbrightness;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading= ");
  Serial.println(fsrReading);

  ledbrightness = map(fsrReading, 0, 1023, 0,255);
  analogWrite(4,ledbrightness);
  
  delay(100);
  
}