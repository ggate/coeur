int get_persona(Per l[]){
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println(sizeof(l));
  int res;
  
  for(int i; i < sizeof(l); i++)
  {
    Serial.println(i);
    Serial.println(res);
    if(is_this(l[i].config_pin))
    {
      Serial.println(l[i].name);
      Serial.println(i);
      res = i;
      Serial.println(res);
    }
  }
  
  Serial.println(res);
  return res;
}

boolean is_this(unsigned int pin){
  Serial.println(pin);
  pinMode(pin, INPUT);
  delay(100);
  if(digitalRead(pin) == HIGH){
    digitalWrite(LED_BUILTIN, HIGH);
    return true;
  }
  else{
    return false;
  }
}

int get_to_send(int me, Per l[]){  
  return l[me].ir_send;
  Serial.print(l[me].ir_send, HEX);
}

