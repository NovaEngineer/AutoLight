

#include "EEPROMex.h"

#include <Wire.h>
#include "LightLevel.h"
#include "Tune.h"
#define VIN 5.0
#define IOUT 0.04
#define calibration 1


const int sensorPin = 1;   //Обозначаем A0, как вход
const int ledPin = 9; //Обозначаем D9, как выход
const int voltpin = 1;
const int ledoPin = 13;
const int buttUp = 12;
const int buttDwn = 11;
const int setButt = 10;
const int modeButt = 8;
const int debugLight = 3;
int  lightLevel, high = 255, low = 0, lightlevel, lowDef = 0, upDef = 1023, lowThres, upThres;


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
    while (Serial.available() == 0);
    TuneLow();
    TuneUp();
    //Tune();
    TuneInform();
    lowThres = EEPROM.readInt(7);
    upThres = EEPROM.readInt(8);
    lowDef = lowThres;
    upDef = upThres;
  }
  digitalWrite (debugLight , LOW);
  Serial.write("WORKING");
  Serial.println();
  Serial.write("defThres:");
  Serial.println();
  Serial.println(lowDef);
  Serial.println();
  Serial.println(upDef);
  Serial.println();
  
  
  pinMode(ledPin, OUTPUT);
  pinMode(ledoPin, OUTPUT);
  pinMode(voltpin, INPUT);
  pinMode(buttUp, INPUT);
  pinMode(buttDwn, INPUT);
  pinMode(setButt, INPUT);
  pinMode(modeButt, INPUT);
  //lightMeter.begin();
  
}

void loop()
{
    lightLevel = analogRead(voltpin);
    Serial.println(lightLevel);
     manualTune(lightLevel, lowDef, upDef);
    
    analogWrite(ledPin, 255-lightLevel);
    analogWrite(ledoPin, 255-lightLevel);
  
  
  //boolean mode = digitalRead(setButt);
 // uint16_t lux = lightMeter.readLightLevel(); 
//  ;//считываем значение с фоторезистора
  //float volts = lightLevel / 204.6; //находим падение напряжения
  //float voltx = VIN - volts; //находим напряжение
  //int brightness = 255 - lightLevel / 4;//для вывода на serial port значение, отправляемое на D13 
  //Serial.println(); 
  //Serial.print(lux);
 // Serial.print(" lx");
 // Serial.print("\t");
  //Serial.print("ll = ");
  
  //Serial.print("\t");
  



    
  
  
  /*if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }*/    
}


