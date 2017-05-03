/*
  Le coeur de chacun des personnages
*/
#include <IRremote.h>
#define RECV_PIN 8 // il faut vérifier que cette PIN permet la reception IR sur toutes les boards

/// la je définis les PIN digital qui vont commander les 3 leds sur les arduinos...
#define PIN_LED_YOUPI 9
#define PIN_LED_MOYEN 10
#define PIN_LED_NON 11

struct Per { //un personnage c'est:
  char name[10]; //un nom
  unsigned int config_pin; //une unique pin arduino qui est branchée sur 5V, 
  // en changeant la PIN branchée sur 5V on fait changer de personnage un arduino en particulier
  unsigned long ir_send; //un code envoyé a tout le monde
  unsigned long ir_expected_1; //un code expected pour etre youpi youpi
  unsigned long ir_expected_2; //un code expected pour etre moyen content  
};

//Creation des personnage et des regles du scenario
// les trucs entre les accolades, ce sont les valeurs que je décide de donner au 5 parametres de la structure Per (voir 5 lignes plus haut).
// donc le "5" du personnage "reine" ci-dessous correspond à sa "config_pin", le "Ox93" correspond à son ir_send, etc...
Per reine = {"reine", 5, 0x93, 0x92, 0x91}; //on crée le personnage "reine"
Per fou = {"fou", 6, 0x91, 0x93, 0x92}; //on crée le personnage "fou"
Per roi = {"roi", 7, 0x92, 0x91, 0x93}; //on crée le personnage "roi"
// Ici le scenario dit : roi -> reine -> fou -> roi pour que tout le monde soit "youpi youpi"
// personnage non defini ici lui parle dans les oreilles


Per l_pers[] = {reine, fou, roi}; // on crée une liste avec tous les personnage utile pour la suite

// Initialisations
IRsend irsend;
IRrecv irrecv(RECV_PIN);
int me = -1;
unsigned long to_send = 0x93;
decode_results results;

void setup() {
  Serial.begin(9600); //initialisation communication série.
  irrecv.enableIRIn(); // Start the receiver
  me = get_persona(l_pers); //cette fonction renvoie le personnage assignée à la carte arduino
  Serial.println(me);
  to_send = get_to_send(me, l_pers); //renvoie le code IR a envoyer
  Serial.println(to_send, HEX);
  /// Préparation des PIN pour la commande des LEDS
  pinMode(PIN_LED_YOUPI, OUTPUT);
  pinMode(PIN_LED_MOYEN, OUTPUT);
  pinMode(PIN_LED_NON, OUTPUT);
}

void loop() {
  sendIr(to_send); //envoie le code IR
  unsigned long received = receiveIr(); //écoute les code IR recus
  actions(me, received, l_pers); //réalise des actions en fonctions de ce qui est recu
  delay(me*10); // une bidouille pour eviter que les personnages se synchronise
  // et n'arrive plus à s'écouter.
}





