#include <IRremote.h>

int RECV_PIN = 9; // Pin para IR
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  irrecv.enableIRIn(); // Empezamos la recepción  por IR
  pinMode(13, OUTPUT); // Pin Led
}

boolean on = LOW;

void loop() {
  if (irrecv.decode(&results)) {
    // Dato recibido, conmutamos el LED
    on = !on;
    digitalWrite(13,  on? HIGH : LOW); 
    irrecv.resume(); // empezamos una nueva recepción
  }
  delay(300);
}
