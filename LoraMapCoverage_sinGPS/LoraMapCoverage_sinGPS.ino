#include <MKRWAN.h>

LoRaModem modem;

#include "arduino_secrets.h" 
// Please enter your sensitive data in the Secret tab or arduino_secrets.h
String devAddr="2601196C";
String nwkSKey="B33A9992CA8B07494C8D94638B0A3ABA";
String appSKey="15DDC1BEDA05F611A9E64F03560CF9D8";

//Green communication  confirmed, Red communication failed. Blue device as disconnected.
#define LBLUE 3
#define LGREEN 4
#define LRED 5
#define BOARDLED 6

bool connected;
int err_count;

void setColor(int r,int g,int b) {
  digitalWrite(LBLUE,b);
  digitalWrite(LGREEN,g);
  digitalWrite(LRED,r);
}

void setup() {
  //Serial.begin(115200);  
  modem.begin(EU868);
  delay(1000);      // apparently the murata dislike if this tempo is removed...
  connected=false;
  err_count=0;
  pinMode(LBLUE,OUTPUT);
  pinMode(LGREEN,OUTPUT);
  pinMode(LRED,OUTPUT);
  pinMode(BOARDLED,OUTPUT);
  setColor(HIGH,HIGH,LOW);
}

void loop() {
  char msg[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
  if ( !connected ) {
    int ret=modem.joinABP(devAddr, nwkSKey, appSKey);
    if ( ret ) {
      connected=true;
      modem.minPollInterval(60);
      modem.dataRate(5);
      delay(100);
      err_count=0;
    } else {
      setColor(LOW,HIGH,HIGH);
    }
  }
  if ( connected ) {
    int err=0;
    modem.beginPacket();
    modem.write(msg,12);
    err = modem.endPacket(true);
    if ( err <= 0 ) {
      setColor(LOW,HIGH,HIGH);
      err_count++;
      if ( err_count > 50 ) {
        connected = false;
        setColor(HIGH,HIGH,LOW);
      }
      for ( int i = 0 ; i < 1200 ; i++ ) {
        setColor(HIGH,HIGH,HIGH);
        delay(50);
        setColor(LOW,HIGH,HIGH);
        delay(50);
      }
    } else {
      setColor(HIGH,LOW,HIGH);
      err_count = 0;
      delay(10000);
    }
  }
  
}
