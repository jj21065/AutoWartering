#ifndef VALVECONTROL_H
#define VALVECONTROL_H

class ValveControl
{
  int outputPin = 2;
  int openDuration = 10; //sec

  public : 
ValveControl();
  bool isOpenNow = false;
  bool startOpen = false;
  unsigned long openStartTime ; // sec
  unsigned long openEndTime ; //sec

void StartOpen();
  
void ValveEvent();

void OpenValve();

void CloseValve();

};
#endif //VALVECONTROL_H
