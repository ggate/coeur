//fonction de lecture du code
void lecture() {




  
/*
  for (int t = 0; t < nbMax * 2; t += 2) { //boucle pour le nombre de lectures, progresse de 2 en 2
    while (PINB & B00000001) { // tant que état pulsé
      tableau[t] += temporisation; // on incrémente la valeur du tableau
     // delayMicroseconds(temporisation); //attente
    }
    while (!(PINB & B00000001)) { // puis tant que état non pulsé
      tableau[t + 1] += temporisation; // on incrémente l'autre valeur du tableau
     // delayMicroseconds(temporisation);
    }
  }
  delay(500); //délai pour ne plus rien recevoir
  compare(); // appel de la fonction de comparaison
  positionServo(); // appel de la fonction de positionnement du servomoteur
  */
if (!sending){
 if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume(); // Receive the next value

if (results.value == 4294967295){
  digitalWrite(LED_BUILTIN, HIGH); 
  Serial.println ("jour");
}

if (results.value == 658322 ){
  digitalWrite(LED_BUILTIN, LOW);
    Serial.println ("nuit");
}
    
  }
    delay(100);
}
  


  
}

