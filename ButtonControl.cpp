#include "ButtonControl.h"
#include "arduino.h"
ButtonControl::ButtonControl()
{
  waterButton_Pin = 9;
  pinMode(waterButton_Pin,INPUT_PULLUP);
  pinMode(3,OUTPUT);
}
bool ButtonControl::IsPressed()
{
  if(digitalRead(waterButton_Pin) == LOW)
  {
    pinMode(3,HIGH);
    return true;
  }
  else
  {
    pinMode(3,LOW);
  return false;
  }
}

