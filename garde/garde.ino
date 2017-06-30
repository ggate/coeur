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
  unsigned long ir_expected_2; //un code expected pour etre bof  
};

//Creation des personnage et des regles du scenario
// les trucs entre les accolades, ce sont les valeurs que je décide de donner au 5 parametres de la structure Per (voir 5 lignes plus haut).
// donc le "5" du personnage "reine" ci-dessous correspond à sa "config_pin", le "Ox93" correspond à son ir_send, etc...
Per garde = {"garde", 5, 0x10, 0x810, 0x410}; //on crée le personnage "garde"
Per fillette = {"fillette", 6, 0x810, 0x410, 0x10}; //on crée le personnage "fillette"
Per acrobate = {"acrobate", 7, 0x410, 0x10, 0x810}; //on crée le personnage "acrobate"
// Ici le scenario dit : acrobate -> fillette -> garde -> acrobate pour que tout le monde soit "youpi youpi"
// personnage non defini ici lui parle dans les oreilles


Per l_pers[] = {garde, fillette, acrobate}; // on crée une liste avec tous les personnage utile pour la suite

// Initialisations
IRsend irsend;
int me = 0; //Garde
unsigned long to_send = 0x10;

decode_results results;
int latence_max = 300;
int latence = latence_max;

void setup() {  
  Serial.begin(19200); //initialisation communication série.        
}

void loop() {
  sendIr(to_send); //envoie le code IR      
}





