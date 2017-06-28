int actions(int me, unsigned long received, Per l[], int latence){
  //if(me == "GARDE" and interrupteur = nok)
    //play("zerzer")
  
  //if(me == "fillette" and tiltdetector = nok)
    //return
  
  latence = latence - 1;

  if (latence < 1){
    latence = 0;
    set_led_reset();
    ishappy = false;
    isbof = false;
    iscolere = false;    
  }
  
  if(received == 0){
    return latence;
  }
  
  if(l[me].ir_expected_1 == received and !ishappy){
    set_led_youpi();
    Serial.println("youpi youpi");
    latence = latence_max;
    ishappy = true;
    isbof = false;
    iscolere = false;   
  }
  else if(l[me].ir_expected_2 == received and !isbof){
    set_led_moyen();
    Serial.println("bof");
    latence = latence_max;
    ishappy = false;
    isbof = true;
    iscolere = false; 
  }
//  else if(l[me].ir_expected_3 == received and !iscolere){
//    set_led_non();
//    Serial.println("colere");
//    latence = latence_max;
//    ishappy = false;
//    isbof = false;
//    iscolere = true;
//  }

  return latence;
}

void set_led_youpi(){
  myDFPlayer.play(1);
}

void set_led_moyen(){
  myDFPlayer.play(2);
}

void set_led_non(){
  myDFPlayer.play(3);
}

void set_led_reset(){
}
