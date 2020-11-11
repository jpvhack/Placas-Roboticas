/********************************************************
Exercici 1. Motor continua + xip L293D. CANVI DE VELOCITAT I SENTIT
********************************************************/
#define ENABLE 6
#define DIRA 5
#define DIRB 4

void setup() {
 pinMode(ENABLE,OUTPUT);
 pinMode(DIRA,OUTPUT);
 pinMode(DIRB,OUTPUT);
}

void loop() {
 digitalWrite(DIRA,HIGH); // un sentit
 digitalWrite(DIRB, LOW); 
 analogWrite (ENABLE, 240); //velocitat 240
 delay(10000);
 
 digitalWrite(DIRA, LOW); //altre sentit
 digitalWrite(DIRB, HIGH);
 analogWrite (ENABLE, 240); //velocitat 240
 delay(10000);
}
