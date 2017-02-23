#include "LightLevel.h"
#include <Arduino.h>

void manualTune(int lightLevel, int lowThres, int upThres)
{     
      lightLevel = map(lightLevel, lowThres , upThres, 0, 255);
      lightLevel = constrain(lightLevel, 0, 255);
}

void autoTune(int lightLevel, int high, int low)
{
  if  (lightLevel < high)
  {
    high = lightLevel;

  }
  if (lightLevel > low)
  {
    low = lightLevel;
  }
  lightLevel = map(lightLevel, low, high, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
}

  
