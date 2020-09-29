const int triggerPin = 7;
const int echoPin = 4;
long duration = 0; 

void setup() {
  //put your setup code here, to run once:
    pinMode(triggerPin,OUTPUT);
    pinMode(echoPin, INPUT); 
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(triggerPin, LOW);
delayMicroseconds(2);
digitalWrite(triggerPin, HIGH);
delayMicroseconds(10);
digitalWrite(triggerPin, LOW);
  
duration = pulseIn(echoPin,HIGH);
long dist_cm = duration*0.034 / 2;
  
if(dist_cm < 10){
  digitalWrite(4,HIGH);
}else{
  digitalWrite(4,LOW);
}
  digitalWrite(4,HIGH);
    Serial.print("Distance = ");
    Serial.print(dist_cm);
    Serial.println(" cm");
    delay(1000);
}
