#include <LiquidCrystal_I2C.h>

#include "Tune.h"
#include <Arduino.h>
#include "EEPROMex.h"
//Serial.begin(9600);



  
void EEPROM_Res(){
  for (byte i = 0; i < 7; i++) 
  EEPROM.writeInt(i, 0);
  
}
uint32_t TuneLow() {
  //--------калибровка----------

  //for (byte i = 0; i < 7; i++) EEPROM.writeInt(i, 0);// чистим EEPROM для своих нужд


  //lcd.print("Now light: "); lcd.println(lightMeter.readLightLevel());// общаемся с пользователем
  Serial.println();
  //while (Serial.available() == 0);
  Serial.write("ENTER LowThres");
  Serial.println(); 
  uint32_t lowDef = Serial.parseInt();
  EEPROM.writeInt(7,lowDef);// нижний порог значения фоторезистора при минимальной освещенности.
  } 
uint32_t TuneUp(){

  Serial.println();
  //while (Serial.available() == 0);
  Serial.write("ENTER UpThres");
  Serial.println();
  uint32_t upDef = Serial.parseInt();//Верхний порог значения фоторезистора при максимальной освещенности.
  EEPROM.writeInt(8, upDef);
  }
void TuneInform(){
  Serial.println();
  Serial.write("NEWDEFTHRES: ");
  Serial.println();
  Serial.print(TuneLow());
  Serial.println();
  Serial.print(TuneUp());
  Serial.println();
}
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
