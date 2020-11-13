int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int demora = 10; //demora entre pasos minim 10 ms
String entrada;
boolean ingreseAngulo;

void setup() {
 Serial.begin(9600);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 entrada = "0";
 ingreseAngulo = true;
}

void loop() {
  if(ingreseAngulo == true){
    Serial.print("Ingresa el angulo: ");
    ingreseAngulo = false;
  }
  
  if (Serial.available() > 0){
   entrada=Serial.readString();
   Serial.print(entrada);
   girar(entrada.toInt());
  }
}


 void girar(int entrada){
  float iteraciones = abs(entrada)*512./360;

  Serial.print("sentido: ");
  
  if(entrada>0){ 
    Serial.print("horario");
    Serial.println("");
    for (int i = 0; i < iteraciones; i++) {
       digitalWrite(IN1,HIGH); //pas 1
       digitalWrite(IN2,LOW);
       digitalWrite(IN3,LOW);
       digitalWrite(IN4,LOW);
       delay(demora);
      
       digitalWrite(IN1,LOW); //pas 2
       digitalWrite(IN2,HIGH);
       digitalWrite(IN3,LOW);
       digitalWrite(IN4,LOW);
       delay(demora);
      
       digitalWrite(IN1,LOW); //pas 3
       digitalWrite(IN2,LOW);
       digitalWrite(IN3,HIGH);
       digitalWrite(IN4,LOW);
       delay(demora);
      
       digitalWrite(IN1,LOW); //pas 4
       digitalWrite(IN2,LOW);
       digitalWrite(IN3,LOW);
       digitalWrite(IN4,HIGH);
       delay(demora);
       }
       digitalWrite(IN1,LOW); //aturada
       digitalWrite(IN2,LOW);
       digitalWrite(IN3,LOW);
       digitalWrite(IN4,LOW);
       delay(5000);
    }else{
      Serial.print("antihorario");
      Serial.println();
      for (int i = 0; i < iteraciones; i++) {
         digitalWrite(IN1,LOW); //pas 1
         digitalWrite(IN2,LOW);
         digitalWrite(IN3,LOW);
         digitalWrite(IN4,HIGH);
         delay(demora);
        
         digitalWrite(IN1,LOW); //pas 2
         digitalWrite(IN2,LOW);
         digitalWrite(IN3,HIGH);
         digitalWrite(IN4,LOW);
         delay(demora);
        
         digitalWrite(IN1,LOW); //pas 3
         digitalWrite(IN2,HIGH);
         digitalWrite(IN3,LOW);
         digitalWrite(IN4,LOW);
         delay(demora);
        
         digitalWrite(IN1,HIGH); //pas 4
         digitalWrite(IN2,LOW);
         digitalWrite(IN3,LOW);
         digitalWrite(IN4,LOW);
         delay(demora);
         }
         digitalWrite(IN1,LOW); //aturada
         digitalWrite(IN2,LOW);
         digitalWrite(IN3,LOW);
         digitalWrite(IN4,LOW);
         delay(5000);
       }
 
      Serial.println("-------------------------------------------------");
    ingreseAngulo = true;
 }
 
