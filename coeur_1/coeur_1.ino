/*
  Le coeur de chacun des personnages
*/

#include "Servo.h" // on ajoute la bibliothèque Servo
#include <IRremote.h>

const byte PIN_BUZZER = 10;
int RECV_PIN = 8;
boolean sending;

IRsend irsend;
IRrecv irrecv(RECV_PIN);

decode_results results;


int tempsAct, tempsAct2;
int tempsPasse, tempsPasse2;
unsigned long tpsDep = millis(); // initialisation du temps

void setup() {
  Serial.begin(9600); //initialisation communication série.
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  
  sendIr();
  lecture();
}






