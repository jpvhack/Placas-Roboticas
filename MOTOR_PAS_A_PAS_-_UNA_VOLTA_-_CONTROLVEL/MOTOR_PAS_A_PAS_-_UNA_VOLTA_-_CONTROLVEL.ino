/*################## Test motor 28BYJ-48 #####################
* Filename: motorPP_Ej1.ino
* Descripción: Prueba motor 28BYJ-48
* Autor: Jose Mª Morales
* Revisión: 31-03-2017
* Probado: ARDUINO UNO r3 - IDE 1.8.2 (Windows7)
* Web: www.playbyte.es/electronica/
* Licencia: Creative Commons Share-Alike 3.0
* http://creativecommons.org/licenses/by-sa/3.0/deed.es_ES
* ############################################################
* 
* Motor paso a paso uniopolar de 4 bobinas
* Alimentado mediante driver ULN2003 a 5v
* Paso = 0,088º
* Velocidad máxima: 14 rpm
* ========================================================
*/

// Pines donde tenemos conectadas las bobinas
const int motor_IN1 = 8;
const int motor_IN2 = 9;
const int motor_IN3 = 10;
const int motor_IN4 = 11;

// Maxima frecuencia excitacion bobinas, 100Hz => t=10 ms
int t = 10; // Tiempo de retardo ajustable (ms)
boolean giro = false; // Sentido de giro horario

const int halfpass[8] = // Secuencia de pasos "medio paso"
{
 B1000, 
 B1100,
 B0100,
 B0110,
 B0010,
 B0011,
 B0001,
 B1001 };

void setup() {
 pinMode(motor_IN1, OUTPUT);
 pinMode(motor_IN2, OUTPUT);
 pinMode(motor_IN3, OUTPUT);
 pinMode(motor_IN4, OUTPUT);

 Serial.begin(9600);
 Serial.println("Introduce retardo (1-200ms)");
}

void loop() { 

 if(Serial.available()>0) input_serial(); // devuelve numero introducido
 if (t!=0) motor_on();

}
// =================================================

void input_serial() { 

 delay(5); // favorece la lectura de caracteres pero ralentiza el motor
 String bufferString = ""; // variable que sirve como buffer
 
 while (Serial.available() > 0) {
 bufferString += (char)Serial.read();
 }
 t = bufferString.toInt(); // Lo convierte en entero

 if (t>=-200 && t<=200) {

 Serial.print(" Retardo: ");
 Serial.print(t); 
 
 if (t==0) motor_off(); // Apaga motor!
 
 else { // Motor ON
 if (t<0) { // Direccion antihoraria
 t = abs(t); 
 giro = true;
 }
 
 else giro = false;
 if (giro) Serial.println(", Giro horario");
 if (!giro) Serial.println(", Giro antihorario"); 
 
 }
 }
 
 else {
 Serial.println("Valor no valido");
 t=0;
 }
 
}

void motor_off() {

 digitalWrite(motor_IN1, 0);
 digitalWrite(motor_IN2, 0);
 digitalWrite(motor_IN3, 0);
 digitalWrite(motor_IN4, 0);
 Serial.println(", Motor parado");
}

void motor_on() {

 // Secuencia de encendido de la bobinas (8 pasos por vuelta)
 for (int i=0; i<8; i++) {

 int step = i; // paso en sentido horario
 if (giro) step = 8-i; // paso en sentido antihorario 

 digitalWrite(motor_IN1, bitRead(halfpass[step], 0));
 digitalWrite(motor_IN2, bitRead(halfpass[step], 1));
 digitalWrite(motor_IN3, bitRead(halfpass[step], 2));
 digitalWrite(motor_IN4, bitRead(halfpass[step], 3));
 delay(t); // Limita la velocidad de giro
 } 
}
