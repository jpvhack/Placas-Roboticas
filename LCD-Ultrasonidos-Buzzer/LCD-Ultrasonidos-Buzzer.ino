#include <LiquidCrystal.h>
const int trig_pin = 3;
const int echo_pin = 2;
const int buzzer_pin = 4;

int distance_cm;
long duration;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // configuramos nuestro lcd de 16x2

void setup()
{
lcd.begin(16, 2);
lcd.setCursor(0, 0);
pinMode(trig_pin, OUTPUT);
pinMode(echo_pin, INPUT);
pinMode(buzzer_pin, OUTPUT);
}

void loop()
{  
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  duration = pulseIn(echo_pin, HIGH);
  distance_cm = (duration*0.034)/2.0;

  if (distance_cm >= 10 || distance_cm <= 0)
  {
  digitalWrite(buzzer_pin, LOW); 
  lcd.setCursor(0, 0);
  lcd.print("NO OBJETO[>10cm]");
  lcd.setCursor(0, 1);
  lcd.print("DETECTADO!");
  delay(1000);
  lcd.clear();
  }
  else
  {
  digitalWrite(buzzer_pin, HIGH); 
  lcd.setCursor(0, 0);
  lcd.print("DISTANCIA(cm):");
  lcd.print(distance_cm);
  lcd.setCursor(0, 1);
  lcd.print("OBJETO DETECTADO!");
  delay(1000);
  lcd.clear();
  }
}
