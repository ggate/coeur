/*
  Le coeur de chacun des personnages
*/
#include <IRremote.h>
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

#define RECV_PIN 8 // il faut vérifier que cette PIN permet la reception IR sur toutes les boards

struct Per { //un personnage c'est:
  char name[10]; //un nom
  unsigned int config_pin; //une unique pin arduino qui est branchée sur 5V,
  // en changeant la PIN branchée sur 5V on fait changer de personnage un arduino en particulier
  unsigned long ir_send; //un code envoyé a tout le monde
  unsigned long ir_expected_1; //un code expected pour etre youpi youpi
  unsigned long ir_expected_2; //un code expected pour etre pas content  
};

//Creation des personnage et des regles du scenario
// les trucs entre les accolades, ce sont les valeurs que je décide de donner au 5 parametres de la structure Per (voir 5 lignes plus haut).
// donc le "5" du personnage "reine" ci-dessous correspond à sa "config_pin", le "Ox93" correspond à son ir_send, etc...
Per garde = {"garde", 5, 0x10, 0x810, 0x410}; //on crée le personnage "garde" //emetrre
Per fillette = {"fillette", 6, 0x810, 0x10, 0x410}; //on crée le personnage "fillette"
Per viellard = {"viellard", 7, 0x410, 0x410, 0x10}; //on crée le personnage "viellard"
// Ici le scenario dit : acrobate -> fillette -> garde -> acrobate pour que tout le monde soit "youpi youpi"
// personnage non defini ici lui parle dans les oreilles


Per l_pers[] = {garde, fillette, viellard}; // on crée une liste avec tous les personnage utile pour la suite

// Initialisations
IRrecv irrecv(RECV_PIN);
int me = 1; // Fillette

decode_results results;
int latence_max = 300;
int latence = latence_max;

bool ishappy = false;
bool isbof = false;
bool iscolere = false;

SoftwareSerial mySoftwareSerial(10, 11); // TX, RX (1K resistor on RX (11))
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(19200); //initialisation communication série.

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  
  irrecv.enableIRIn(); // Start the receiver  
}

void loop() {  
  unsigned long received = receiveIr(); //écoute les code IR recus
  latence = actions(me, received, l_pers, latence); //réalise des actions en fonctions de ce qui est recu  
  //delay(abs(me)*300); // une bidouille pour eviter que les personnages se synchronise
  delay(5);
  //Serial.println(l_pers[me].name);
}





