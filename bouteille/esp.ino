#include<SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//initalise communication esp-arduino
SoftwareSerial s(3,1);

//co internet
const char * SSID = "WIFI-ETUDIANT";
const char * PASSWORD = "NextUstud3nt";

//appel server
String url_webhook_objRequestBottle = "https://la-forge-des-enigmes.capucinemad.com/api/wine_games/1/objRequestBottle";
String url_webhook_connexion = "https://la-forge-des-enigmes.capucinemad.com/api/login";
String url_webhook_infoBottle = "https://la-forge-des-enigmes.capucinemad.com/api/wine_games/1";
const char empreinte[] PROGMEM = "B3 99 B3 59 19 03 7A 31 34 BD 8F CF 45 E4 2C 43 C6 14 B4 FD";

//fonction admin active bottle
void adminActiveBottle(){
  WiFiClientSecure client_https;
  client_https.setFingerprint(empreinte);

  HTTPClient requete;
  requete.begin(client_https, url_webhook_objRequestBottle);
  requete.addHeader("Content-Type", "application/json");
  
  int httpCode = requete.GET();
  if(httpCode > 0) {
    if (httpCode == HTTP_CODE_OK){
      String response = requete.getString();

      // Extract the value of "isBottleRing" from the JSON response
      int startIndex = response.indexOf("isBottleRing") + 14;
      int endIndex = response.indexOf("}", startIndex);
      String isBottleRing = response.substring(startIndex, endIndex);
      s.print((isBottleRing == "true"));
    }
  }
}

//fonction démarrage
void startInitialisation(){
  WiFiClientSecure client_https;
  client_https.setFingerprint(empreinte);

  HTTPClient requete;
  requete.begin(client_https, url_webhook_connexion);
  requete.addHeader("Content-Type", "application/json");
  String payload = "{\"username\": \"machine1@mail.com\", \"password\": \"A@vF7%LW5N&sfo\"}";  

  int httpCode = requete.POST(payload);
  if(httpCode > 0) {
    if (httpCode == HTTP_CODE_OK){
      String response = requete.getString();

      // Extract the value of "Token" from the JSON response
      int startIndex = response.indexOf(":\"") + 2;
      int endIndex = response.lastIndexOf("\"");
      String myToken = response.substring(startIndex, endIndex);

      requete.begin(client_https, url_webhook_infoBottle);
      requete.addHeader("Authorization", "Bearer " + myToken);

      int httpCode = requete.GET();
      if(httpCode > 0) {
        if (httpCode == HTTP_CODE_OK){
          String response = requete.getString();
          s.println(response);
        }
      }
    }
  }
}

void setup() {
  s.begin(9600);

  // mode de co wifi
  WiFi.mode(WIFI_STA);

  // démarer la co
  WiFi.begin(SSID, PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
  }

  //initialisation données
  startInitialisation();
}

void loop() {
  if(WiFi.isConnected()){
    adminActiveBottle();
    delay(5000);
  }
  else {
    delay(5000);
  }
}
