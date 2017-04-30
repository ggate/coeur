
//Fonction de positionnement du servomoteur
void positionServo() {
  switch (nbCode) { //en fonction du code
    case 0: // on place le servo à 90°
      ajServo = 0;
      posServo = 90;
      break;
    case 1: // on place le servo à 179°
      ajServo = 0;
      posServo = 179;
      break;
    case 2: // on place le servo à 0°
      ajServo = 0;
      posServo = 0;
      break;
    case 3: // on met la variable de déplacement à 1°
      ajServo = +1;
      break;
    case 4: // on met la variable de déplacement à -1°
      ajServo = -1;
      break;
  }
}

//fonction de déplacement du servomoteur
void bougeServo() {
  unsigned long tpsAct = millis(); //temps actuel
  if (tpsAct - tpsDep > 50) { //si 50ms passées
    posServo += ajServo; // on déplace le servo
    tpsDep = tpsAct; //on réinitialise le temps
  }
  if (posServo <= 0 || posServo >= 179) // si servo hors limite
    ajServo = 0; // on stoppe le déplacement
  monServo.write(posServo); // on envoie la position du servomoteur

}

//Joue la musique de tetris
/*
void Tetris() {
  tone(PIN_BUZZER, 2637, 200);
  delay(400);
  tone(PIN_BUZZER, 1975, 200);
  delay(200);
  tone(PIN_BUZZER, 2093, 200);
  delay(200);
  tone(PIN_BUZZER, 2349, 200);
  delay(400);
  tone(PIN_BUZZER, 2093, 200);
  delay(200);
  tone(PIN_BUZZER, 1975, 200);
  delay(200);
  tone(PIN_BUZZER, 1760, 200);
  delay(400);
  tone(PIN_BUZZER, 1760, 200);
  delay(200);
  tone(PIN_BUZZER, 2093, 200);
  delay(200);
  tone(PIN_BUZZER, 2637, 200);
  delay(400);
  tone(PIN_BUZZER, 2349, 200);
  delay(200);
  tone(PIN_BUZZER, 2093, 200);
  delay(200);
  tone(PIN_BUZZER, 1975, 200);
  delay(400);
  tone(PIN_BUZZER, 1975, 200);
  delay(200);
  tone(PIN_BUZZER, 2093, 200);
  delay(200);
  tone(PIN_BUZZER, 2349, 200);
  delay(400);
  tone(PIN_BUZZER, 2637, 200);
  delay(400);
  tone(PIN_BUZZER, 2093, 200);
  delay(400);
  tone(PIN_BUZZER, 1760, 200);
  delay(400);
  tone(PIN_BUZZER, 1760, 200);
  delay(800);
  tone(PIN_BUZZER, 1760, 200);
  delay(400);
  tone(PIN_BUZZER, 2349, 200);
  delay(200);
  tone(PIN_BUZZER, 2794, 200);
  delay(200);
  tone(PIN_BUZZER, 3520, 200);
  delay(400);
  tone(PIN_BUZZER, 3136, 200);
  delay(200);
  tone(PIN_BUZZER, 2794, 200);
  delay(200);
  tone(PIN_BUZZER, 2637, 200);
  delay(600);
  tone(PIN_BUZZER, 2093, 200);
  delay(200);
  tone(PIN_BUZZER, 2637, 200);
  delay(400);
  tone(PIN_BUZZER, 2349, 200);
  delay(200);
  tone(PIN_BUZZER, 2093, 200);
  delay(200);
  tone(PIN_BUZZER, 1975, 200);
  delay(400);
  tone(PIN_BUZZER, 1975, 200);
  delay(200);
  tone(PIN_BUZZER, 2093, 200);
  delay(200);
  tone(PIN_BUZZER, 2349, 200);
  delay(400);
  tone(PIN_BUZZER, 2637, 200);
  delay(400);
  tone(PIN_BUZZER, 2093, 200);
  delay(400);
  tone(PIN_BUZZER, 1760, 200);
  delay(400);
  tone(PIN_BUZZER, 1760, 200);
  delay(800);
}
*/
//Allume une Med sur la ligne 11

