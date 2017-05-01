void actions(int me, unsigned long received, Per l[]){
  if(received == 0){
    return;
  }
  
  if(l[me].ir_expected_1 == received){
    Serial.println("youpi youpi");
  }
  else if(l[me].ir_expected_2 == received){
    Serial.println("peut mieux faire");
  }
  else{
    Serial.println("pas content");
  }
}

