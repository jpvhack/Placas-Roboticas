const int verm=8;
const int verd=7;
const int PIRPin= 6;
void setup(){
 pinMode(verm, OUTPUT);
 pinMode(verd, OUTPUT);
 pinMode(PIRPin, INPUT);
 digitalWrite(verm, LOW);
 digitalWrite(verd, LOW);
}
void loop(){
 int value= digitalRead(PIRPin);
 if (value == HIGH){
 digitalWrite(verm, HIGH);
 digitalWrite(verd, LOW);
 delay(1000);
 } else {
 digitalWrite(verm, LOW);
 digitalWrite(verd, HIGH);
 delay(1000);
 }
}
