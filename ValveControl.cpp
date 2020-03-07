#include "ValveControl.h"
#include "arduino.h"
#define UNSIGNED_LONG_MAX 4294967295
ValveControl::ValveControl()
  {
    pinMode(outputPin, OUTPUT);
    pinMode(13, OUTPUT);
    CloseValve();
  }
  void ValveControl :: ValveEvent()
  {
    if(startOpen)
    {
      if (!isOpenNow)
      {
        openStartTime = millis() / 1000.0;
        OpenValve();
      }
      else
      {
        openEndTime = millis() / 1000.0;
        unsigned long duration = 0;
        duration = openEndTime - openStartTime;
        if (openEndTime > openStartTime) // millis() hasn't overflow yet 
        {
          duration = openEndTime - openStartTime;
        }
        else if(openEndTime < openStartTime)
        {
          duration = openEndTime - (UNSIGNED_LONG_MAX / 1000.0 - openStartTime);
        }
        if (duration > openDuration) // time is up
        {
          CloseValve();
          startOpen = false;
        }
      }
    }
  }
void ValveControl:: StartOpen()
{
  startOpen = true;
}

  void ValveControl :: OpenValve()
  {
    digitalWrite(outputPin, HIGH);
    digitalWrite(13,HIGH);
    isOpenNow = true;
  }

  void ValveControl :: CloseValve()
  {
    digitalWrite(outputPin, LOW);
    digitalWrite(13,LOW);
    isOpenNow = false;
  }

 
