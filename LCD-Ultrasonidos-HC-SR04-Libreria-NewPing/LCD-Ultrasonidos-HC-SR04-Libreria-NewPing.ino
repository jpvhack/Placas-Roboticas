#include <LiquidCrystal.h>
#include <NewPing.h>

#define TRIGGER_PIN  3  // Aqui conectaremos el pin trigger del sensor ultrasonico
#define ECHO_PIN     2  // Aqui conectaremos el pin echo de nuestro sensor
#define MAX_DISTANCE 300 // Maxima distacia a medir en cm . Maximo que permite el sensor 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Configuramos nuestro sensor.


LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // configuramos nuestro lcd de 16x2

int distancia= 0;

void setup(){
Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
lcd.begin(16,2);

}

void loop(){

  delay(50);  // delay para darle tiempo al sensor entre pings
  distancia = sonar.ping_cm(); // guardamos la distancia medida en la variable
  Serial.print("Ping: ");
  Serial.print(distancia); // imprimimos la distancia a travez del puerto serie (arroja 0 cuando se supera la distancia maxima 
  Serial.println("cm");
  lcd.setCursor(0,0);
  lcd.print("Distancia: ");
  lcd.print(distancia);   // imprimimos la distancia a travez del display lcd (arroja 0 cuando se supera la distancia maxima)
  lcd.print(" cm");

}
