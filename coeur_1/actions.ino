void actions(int me, unsigned long received, Per l[]){
  if(received == 0){
    return;
  }
  
  if(l[me].ir_expected_1 == received){
    set_led_youpi();
    Serial.println("youpi youpi");
  }
  else if(l[me].ir_expected_2 == received){
    set_led_moyen();
    Serial.println("peut mieux faire");
  }
  else{
    set_led_non();
    Serial.println("pas content");
  }
}

void set_led_youpi(){
  digitalWrite(PIN_LED_YOUPI, HIGH);
  digitalWrite(PIN_LED_MOYEN, HIGH);
  digitalWrite(PIN_LED_NON, HIGH);
}

void set_led_moyen(){
  digitalWrite(PIN_LED_YOUPI, LOW);
  digitalWrite(PIN_LED_MOYEN, HIGH);
  digitalWrite(PIN_LED_NON, HIGH);
}

void set_led_non(){
  digitalWrite(PIN_LED_YOUPI, LOW);
  digitalWrite(PIN_LED_MOYEN, LOW);
  digitalWrite(PIN_LED_NON, HIGH);
}
