
void sendIr() {


  tempsAct = millis(); //temps actuel
  if (tempsAct - tempsPasse > 500) { //si 50ms passées
    sending = true;
    irsend.sendSony(0xa90, 12);
    irrecv.enableIRIn();
    tempsPasse = tempsAct; //on réinitialise le temps
    sending = false;
  }





}

