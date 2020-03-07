#include"ButtonControl.h"
#include "Connection.h"
#include "LightControl.h"
#include "ScoreControl.h"
#include "ValveControl.h"


ButtonControl buttonControl;
Connection connectionControl;
LightControl lightControl;
ValveControl valveControl;
ScoreControl scoreControl;


int loopTime = 5;
void setup() {
  // put your setup code here, to run once:

  lightControl.InitLight();
  
   Serial.begin(9600);

}
int stage = 0; // Control the lighting change //and machine status
void loop() {
  // put your main code here, to run repeatedly:\
  
  scoreControl.ShowScore();
  
  valveControl.ValveEvent();
  
  lightControl.LightEvent(stage);
  /// can press button 
  
  if(buttonControl.IsPressed() && !valveControl.isOpenNow)
  {
    if(scoreControl.GetScore()>0)
    {
      valveControl.StartOpen();
      scoreControl.MinusScore(1);
    }
  }
  if(valveControl.isOpenNow)
  {
    stage =1;
  }
  else
  {
    stage = 0;
  }

 // control the commu thru rs232
  if(Serial.available())
  {
    char c = '0';
    c = Serial.read();
    if(c=='1')
    {
     valveControl.StartOpen();
           
    }
    else if(c == '+')
    {
      scoreControl.AddScore(1);
    }
     else if(c == '-')
    {
      scoreControl.MinusScore(1);
    }
  }

  //delay(loopTime);
  
}
