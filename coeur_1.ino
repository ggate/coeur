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


const int pinServo = 9; // constante de pin pour le servomoteur
Servo monServo; // on définit l'objet Servo nommé monServo
//tableau qui stocke les codes : 5 codes de 65 valeurs
// /!\ Attention il correspond aux valeurs de ma télécommande
//Pour la vôtre, il faut utiliser le programme "Décodeur infrarouge"
//et créer ce tableau !
const unsigned int codes[5][65] = {
  0, 2500, 560, 660, 560, 640, 580, 640, 600, 620, 560, 640, 580, 640, 580, 640, 580, 640, 600, 1220, 580, 640, 580, 1240, 580, 1240, 580, 1240, 580, 660, 560, 660, 560, 1260, 560, 640, 580, 640, 580, 1240, 580, 640, 15180, 2500, 560, 640, 560, 660, 560, 660, 560, 640, 580, 640, 580, 640, 560, 660, 560, 640, 580, 1260, 560, 660, 0,
  0, 2500, 560, 1260, 560, 640, 580, 640, 580, 640, 580, 640, 580, 640, 600, 620, 560, 640, 580, 1260, 600, 600, 580, 1240, 580, 1260, 580, 1240, 580, 640, 580, 640, 560, 1260, 580, 640, 560, 660, 560, 1260, 560, 660, 14560, 2500, 560, 1240, 580, 640, 580, 640, 560, 660, 560, 640, 580, 660, 580, 620, 600, 620, 580, 1240, 580, 640, 0,
  0, 2520, 540, 640, 580, 1240, 580, 640, 580, 640, 580, 640, 580, 640, 560, 660, 580, 620, 600, 1220, 580, 640, 580, 1260, 560, 1260, 580, 1240, 580, 640, 600, 620, 560, 1260, 580, 640, 560, 660, 560, 1260, 560, 660, 14560, 2500, 560, 640, 560, 1260, 580, 640, 560, 640, 580, 660, 560, 640, 580, 640, 580, 640, 600, 1220, 580, 640, 0,
  0, 2520, 540, 1260, 560, 1260, 580, 620, 580, 660, 560, 660, 560, 640, 600, 620, 580, 640, 560, 1260, 580, 620, 600, 1240, 580, 1240, 580, 1240, 580, 640, 580, 640, 580, 1260, 560, 640, 600, 620, 580, 1240, 580, 640, 13960, 2500, 560, 1240, 580, 1240, 580, 640, 580, 640, 580, 640, 560, 660, 560, 640, 580, 640, 580, 1240, 580, 640, 0,
  0, 2500, 560, 640, 600, 620, 580, 1240, 580, 640, 580, 640, 580, 640, 560, 640, 580, 640, 600, 1240, 560, 660, 560, 1260, 560, 1260, 580, 1240, 580, 640, 580, 640, 560, 1260, 580, 640, 560, 660, 560, 1260, 580, 620, 14580, 2500, 560, 640, 560, 640, 580, 1260, 560, 660, 560, 640, 580, 640, 580, 640, 580, 640, 560, 1260, 580, 640, 0
};
//Tableau des noms pour chaque code
String noms[5] = {"90 deg", "179 deg", "0 deg", "Vers 179 deg", "Vers 0 deg"};
const int pin = 8; // pin de lecture du TSOP
const int nbMax = 32; // nombre maximum de lectures
const int temporisation = 20; // temporisation de lecture des signaux pulsés
unsigned int tableau[nbMax * 2] = {0}; // tableau pour stocker les temps lus
int posServo = 90; // variable de position du servomoteur
int ajServo = 0; // variable de déplacement du servomoteur
int nbCode = 0; // numéro de code en cours
unsigned long tpsDep = millis(); // initialisation du temps




void setup() {
  monServo.attach(pinServo); // attache l'objet monServo à pinServo
  pinMode(pin, INPUT); // mode INPUT pour le pin de lecture
  pinMode(PIN_BUZZER, OUTPUT);

  Serial.begin(9600); //initialisation communication série.

  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // while (PINB & B00000001) // tant que aucun signal
  // bougeServo(); // on gère le servomoteur
  //sinon
  sendIr();
  lecture();




}



//fonction de comparaison
int compare () {
  boolean trouve = 0; // drapeau de commande trouvée
  for (int c = 0; c < 5; c++) { //boucle sur les codes
    int nbCor = 0; // variable de validation de comparaison
    for (int t = 0; t < nbMax * 2; t++) { // on parcourt les résultats
      int tmoins = tableau[t] - tableau[t] * 20 / 100; // valeur-20%
      int tplus = tableau[t] + tableau[t] * 20 / 100; // valeur+20%
      if (codes[c][t] > tmoins && codes[c][t] < tplus && t > 0) { //si dans la fourchette (sauf première valeur)
        nbCor++; // on valide la comparaison
      }
    }
    if (nbCor == nbMax * 2 - 1) { //si tout est validé (sauf première valeur)
      // On affiche la touche correspondante
      Serial.print("Commande ");
      Serial.print(c);
      Serial.print(" => ");
      Serial.println(noms[c]);
      nbCode = c; // on indique le code en cours
      trouve = 1; // on indique que la commande a été trouvée
    }
  }
  if (!trouve) { //si commande non trouvée
    Serial.println("Commande inconnue...");
  }
  //on vide le tableau de lecture
  for (int t = 0; t < nbMax * 2; t++) {
    tableau[t] = 0;
  }
}
