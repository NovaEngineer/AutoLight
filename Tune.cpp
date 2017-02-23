

#include "Tune.h"
#include <Arduino.h>
#include "EEPROMex.h"
#include <HardwareSerial.h>


  
void EEPROM_Res(){
  for (byte i = 0; i < 7; i++) 
  EEPROM.writeInt(i, 0);
  
}
void TuneLow() {
  //--------калибровка----------
  Serial.println();

  Serial.write("ENTER LowThres");
  Serial.println(); 
  while (Serial.available() == 0);
  unsigned int lowDef = Serial.parseInt();
  EEPROM.writeInt(7,lowDef);// нижний порог значения фоторезистора при минимальной освещенности.
  } 
void TuneUp(){

  Serial.println();
  
  Serial.write("ENTER UpThres");
  Serial.println();
  while (Serial.available() == 0);
  unsigned int upDef = Serial.parseInt();//Верхний порог значения фоторезистора при максимальной освещенности.
  EEPROM.writeInt(8, upDef);
  }
/*void TuneInform(){
  Serial.println();
  Serial.write("NEWDEFTHRES: ");
  Serial.println();
  Serial.print(TuneLow());
  Serial.println();
  Serial.print(TuneUp());
  Serial.println();
}*/
//void Tune(){
  //Serial.begin(9600);
  //TuneLow();
  //TuneUp();
 // uint32_t low = TuneLow();
//  uint32_t up = TuneUp();
  
//  EEPROM.writeInt(8, up);// запись в EEPROM
//} 
 // if (up != 0)
 // {
//    loop();// уйти в бесконечный цикл
//  }
  //------конец калибровки-------
//  }
