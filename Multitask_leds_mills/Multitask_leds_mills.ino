int LED1 = 2;
int LED2 = 3;

unsigned long tempsAnterior1 = millis();
long interval1 = 100; // Blink con menos frecuencia
int estat1 = LOW;
unsigned long tempsAnterior2 = millis();
long interval2 = 100; // Blink con mas frecuencia
int estat2 = LOW;

void setup()
{
 Serial.begin(9600);
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
}

void loop(){
 unsigned long tempsAra = millis();
 if(tempsAra - tempsAnterior1 > interval1) {
tempsAnterior1 = tempsAra;
if (estat1 == HIGH) {
estat1 = LOW;
} else {
estat1 = HIGH;
}
digitalWrite(LED1, estat1);
}

 if(tempsAra - tempsAnterior2 > interval2) {
tempsAnterior2 = tempsAra;
if (estat2 == HIGH) {
estat2 = LOW;
} else {
estat2 = HIGH;
}
digitalWrite(LED2, estat2);
}

}
