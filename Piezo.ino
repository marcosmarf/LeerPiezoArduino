
// Definicions
int nivSenal = 20;  // nivell llindar de que esta tocant
int duEscolta = 100;// durada del temps de escolta
// durant aquest temps el sistema escolta tota la senyal
int duEspera = 300; // Es el temps que espera a tornar a escoltar y no fa res
int nivFlux = 300; // Nivel maxim d'un cop flux
int nivFort = 800; // nivell maxim del cop mitjà
int tUltimaSenyal; // El moment en el que va comença a escoltar l'ultima vegada
int senyal ;
int intensitat;


void setup() {
  tUltimaSenyal = millis();
}

void loop() {
  senyal = analogRead(A0); // llegim el sensor
  if (senyal > nivSenal) { // hem escoltat algo
    if (millis() - tUltimaSenyal > duEscolta) {
      if (millis() - tUltimaSenyal > duEspera) {
        tUltimaSenyal = millis();

      } else {

      }
    } else {
      if (intensitat < senyal) {
        intensitat = senyal;
      }

    }
  } else {

    if (intensitat > 0) {
      if (intensitat > 300) {
        // enviar cop fort
        intensitat = -1;
      } else {
        // enviar cop flux
        intensitat = -1;
      }
    }

  }
}

