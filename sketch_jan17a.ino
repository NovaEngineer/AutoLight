#include "EEPROMex.h"
#include <Wire.h>
#include "LightLevel.h"
#include "Tune.h"


#define VIN 5.0
#define IOUT 0.04 
#define calibration 1   //Настройка


const int sensorPin = 1;   //Обозначаем A0, как вход
const int ledPin = 9; //Обозначаем D9, как выход
const int voltpin = 1;
const int ledoPin = 13;
const int buttUp = 12;
const int buttDwn = 11;
const int setButt = 10;
const int modeButt = 8;
const int debugLight = 3;
int  lightLevel, high = 255, low = 0, lightlevel;
uint32_t lowThres, upThres;


void setup()
{

  Serial.begin(9600);

 pinMode(debugLight, OUTPUT); 
  if (calibration)
  { 
    EEPROM_Res();
   
    digitalWrite (debugLight , HIGH);
    Serial.write("DEBUGGING");
    Serial.println();
    Serial.print("  Now LightLevel: "); 
    Serial.print(analogRead(voltpin)); 
    TuneLow();
    TuneUp();
    lowThres = EEPROM.readInt(7);
    upThres = EEPROM.readInt(8);
  }
  else
  {
    lowThres = 0;
    upThres = 1023;
  }
  digitalWrite (debugLight , LOW);
  Serial.write("WORKING");
  Serial.println();
  Serial.write("defThres:");
  Serial.println();
  Serial.println(lowThres);
  Serial.println();
  Serial.println(upThres);
  Serial.println();
  
  
  pinMode(ledPin, OUTPUT);
  pinMode(ledoPin, OUTPUT);
  pinMode(voltpin, INPUT);
}

void loop()
{
    lightLevel = analogRead(voltpin);
    Serial.println(lightLevel);
     manualTune(lightLevel, lowThres, upThres);
     autoTune(lightLevel, low, high);
    
    analogWrite(ledPin, 255-lightLevel);
    analogWrite(ledoPin, 255-lightLevel);
}


