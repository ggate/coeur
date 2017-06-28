void get_persona(Per l[], int * res){
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println(sizeof(l)); 
  
  for(int i; i < 3; i++)
  {
    Serial.println(i);
    Serial.println(*res);
    if(is_this(l[i].config_pin))
    {
      Serial.println(l[i].name);
      Serial.println(i);
      *res = i; 
    }
  }  
}

boolean is_this(unsigned int pin){
  Serial.println(pin);
  pinMode(pin, INPUT);
  delay(100);
  if(digitalRead(pin) == HIGH){
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("True");  
    return true;    
  }
  else{
    Serial.println("False");
    return false;
  }
}

int get_to_send(int me, Per l[]){  
  return l[me].ir_send;
  Serial.print(l[me].ir_send, HEX);
}

