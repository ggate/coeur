//fonction de lecture du code
void lecture() {
if (!sending){
 if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume(); // Receive the next value

if (results.value == 4294967295){
  digitalWrite(LED_BUILTIN, HIGH); 
  Serial.println ("jour");
}

if (results.value == 902510849 ){
  digitalWrite(LED_BUILTIN, LOW);
    Serial.println ("nuit");
}
    
  }
    delay(100);
}
  


  
}

