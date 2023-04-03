// ecran
#include "Wire.h"
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C LCD(0x27,16,2);

//music
const int buzzer = 3;

#define NOTE_AS3 233
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_A5  880
#define REST     0

//music 0 : pirate
int notesM0[] = {
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
  NOTE_A4, NOTE_G4, NOTE_A4, 0,
  
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
  NOTE_A4, NOTE_G4, NOTE_A4, 0,
  
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
  NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
  NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
  
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
  NOTE_D5, NOTE_E5, NOTE_A4, 0, 
  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
  NOTE_C5, NOTE_A4, NOTE_B4, 0
};

int durationM0[] = 
{
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  4, 8, 4, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 4
};

//music 1 : harry potter
int notesM1[] = {
  
  REST, NOTE_D4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5,
  NOTE_C5, 
  NOTE_A4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_F4, NOTE_GS4,
  NOTE_D4, 
  NOTE_D4,
  
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5,
  NOTE_F5, NOTE_E5,
  NOTE_DS5, NOTE_B4,
  NOTE_DS5, NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_B4,
  NOTE_G4
};

int durationM1[] = {
  2, 4,
  4, 8, 4,
  2, 4,
  2, 
  2,
  4, 8, 4,
  2, 4,
  1, 
  4,
  
  4, 8, 4,
  2, 4,
  2, 4,
  2, 4,
  4, 8, 4,
  2, 4,
  1
};

//music 2 : mario
int notesM2[] = {
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST, 
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,
  
  REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,
  REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
  REST, NOTE_DS5, REST, NOTE_D5,
  NOTE_C5, REST
};

int durationM2[] = {
  8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 4, 
  4, 8, 4, 4,
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4,8, 8, 4,
  4, 8, 4, 4,
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4, 8, 8, 4,
  
  
  4, 8, 8, 8, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 4,
  2, 2
};

//music 3 : happy_birthday
int notesM3[] = {
  NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_F4,
  NOTE_E4, NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_G4,
  NOTE_F4, NOTE_C4, NOTE_C4,
  
  NOTE_C5, NOTE_A4, NOTE_F4, 
  NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4,
  NOTE_A4, NOTE_F4, NOTE_G4,
  NOTE_F4
};

int durationM3[] = {
  4, 8, 
  4, 4, 4,
  2, 4, 8, 
  4, 4, 4,
  2, 4, 8,
  
  4, 4, 4, 
  4, 4, 4, 8,
  4, 4, 4,
  2
};

// Varibles
String data;
bool receivedJson = false;
float temperature;
int music;
String bottleCode;
int countNbTemperature = 0;

// function vérifier temperature
void checkT(){
  // Convert analog value of A0 port into digital value
  int adcVal = analogRead(A0);
  // Calculate voltage
  float v = adcVal * 3.3 / 1024;
  // Calculate resistance value of thermistor
  float Rt = 10 * v / (3.3 - v);
  // Calculate temperature (Kelvin)
  float tempK = 1 / (log(Rt / 10) / 3950 + 1 / (273.15 + 25));
  // Calculate temperature (Celsius)
  float tempC = tempK - 273.15;

  Serial.println(tempC);
  if (tempC < temperature){
    countNbTemperature++;
    if(countNbTemperature == 4){
      activeBottle();
      countNbTemperature = 0;
    }
  }else{
    countNbTemperature = 0;
  }
  delay(1000);
}

// function active bottle
void activeBottle(){
  //ecran
  LCD.setCursor(0,0);
  LCD.print("CODE, NOTEZ-LE !");
  LCD.setCursor(6,1);
  LCD.print(bottleCode);

  //musique
  int size;
  if(music == 0){
    size = sizeof(durationM0) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
      int duration = 1000 / durationM0[i];
      tone(buzzer,notesM0[i],duration);
      delay(duration * 1.3);
    }
  } else if (music == 1) {
    size = sizeof(durationM1) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
      int duration = 1000 / durationM1[i];
      tone(buzzer,notesM1[i],duration);
      delay(duration * 1.3);
    }
  } else if (music == 2) {
    size = sizeof(durationM2) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
      int duration = 1000 / durationM2[i];
      tone(buzzer,notesM2[i],duration);
      delay(duration * 1.3);
    }
  } else if (music == 3) {
    size = sizeof(durationM3) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
      int duration = 1000 / durationM3[i];
      tone(buzzer,notesM3[i],duration);
      delay(duration * 1.3);
    }
  }

  delay(20000); // fait une pause de 20 secondes
  LCD.clear();
}

void setup() {
  Serial.begin(9600);

  //musique
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  //ecran
  LCD.init();
  LCD.backlight();

  // setup mes values
  while(!receivedJson) {
    if (Serial.available()) {
      data = Serial.readString();
      // Serial.println(data);
      if (data.indexOf("{") != -1) { // Vérifier si le JSON est reçu
        receivedJson = true;

        int musicPos = data.indexOf("\"music\":");
        int musicEndPos = data.indexOf(",", musicPos);
        String musicStr = data.substring(musicPos + strlen("\"music\":"), musicEndPos);
        music = musicStr.toInt();

        int temperaturePos = data.indexOf("\"temperature\":");
        int temperatureEndPos = data.indexOf(",", temperaturePos);
        String temperatu0r = data.substring(temperaturePos + strlen("\"temperature\":"), temperatureEndPos);
        temperature = temperatu0r.toFloat();

        int bottleCodePos = data.indexOf("\"bottleCode\":");
        int bottleCodeEndPos = data.indexOf(",", bottleCodePos);
        bottleCode = data.substring(bottleCodePos + strlen("\"bottleCode\":") + 1, bottleCodeEndPos - 1);
        
        // Afficher les valeurs extraites
        Serial.print("music: ");
        Serial.println(music);
        Serial.print("temperature: ");
        Serial.println(temperature);
        Serial.print("bottleCode: ");
        Serial.println(bottleCode);
      }
    }
  }
}

void loop() {
  if (Serial.available()) {
    data = Serial.readString();
    Serial.println(data);
    if (data == "1") {
      activeBottle();
    }
  }
  checkT();
}
