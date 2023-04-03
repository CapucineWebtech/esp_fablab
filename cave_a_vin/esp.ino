#include <ESP8266WiFi.h>
#include <Servo.h>
#include <ESP8266HTTPClient.h>

//servo moteur
Servo monServo;
int positionDuServo = 0;

// Entrée analogique
int entreeAnalogique = A0;

// Valeur de la résistance de mesure R1 en ohms
#define R1 1000.0F

//variables
int adminMode = 0;

//co internet
const char * SSID = "WIFI-ETUDIANT";
const char * PASSWORD = "NextUstud3nt";
// const char * SSID = "Bbox-12DB1BE2";
// const char * PASSWORD = "WWCVi7esaNM26a591c";

//appel server
String url_webhook = "https://la-forge-des-enigmes.capucinemad.com/api/wine_games/1/objRequest";
const char empreinte[] PROGMEM = "B3 99 B3 59 19 03 7A 31 34 BD 8F CF 45 E4 2C 43 C6 14 B4 FD";

//fonction cadenas test
void cadenasTest(){
  if(adminMode == 0){
    // Lecture de l'entrée analogique
    float valeurLue = (float)analogRead(entreeAnalogique);
    
    // calcul de la valeur de la résistance en ohms
    float resistanceLue = (valeurLue * (R1)) / (1023.0F - valeurLue);

    if(resistanceLue > 550 && resistanceLue < 900){
      monServo.write(180);
    }else{
      monServo.write(0);
    }
  }else{
    monServo.write(180);
  }
  // attendre 1 seconde avant la prochaine mesure
  delay(1000);
}

//fonction cadena is admin mode
void cadenasIsAdminMode(){
  WiFiClientSecure client_https;
  client_https.setFingerprint(empreinte);

  HTTPClient requete;
  requete.begin(client_https, url_webhook);
  requete.addHeader("Content-Type", "application/json");
  
  int httpCode = requete.GET();
  if(httpCode > 0) {
    if (httpCode == HTTP_CODE_OK){
      String response = requete.getString();

      // Extract the value of "isPadlockIsOpen" from the JSON response
      int startIndex = response.indexOf("isPadlockIsOpen") + 17;
      int endIndex = response.indexOf(",", startIndex);
      String isPadlockOpenString = response.substring(startIndex, endIndex);
Serial.println(isPadlockOpenString);      
      adminMode = (isPadlockOpenString == "true" || isPadlockOpenString == "true}");
    }
  }
}

void setup() {
Serial.begin(9600);
  
  //define motor
  monServo.attach(2);
  monServo.write(positionDuServo);
  
  // mode de co wifi
  WiFi.mode(WIFI_STA);

  // démarer la co
  WiFi.begin(SSID, PASSWORD);
}

void loop() {  
  if(WiFi.isConnected()){
    Serial.println("wifi");
    cadenasTest();
    cadenasIsAdminMode();
  }
  else {
    adminMode = 0;
    cadenasTest();
  }
}

