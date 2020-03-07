#ifndef SCORECONTROL_H
#define SCORECONTROL_H
#include "ScoreLEDControl.h"
class ScoreControl
{
  private :
  int Score = 0;
  ScoreLEDControl scoreLEDControl;
  public :
  ScoreControl();
  int AddScore(int count);
  
  void ShowScore();
  
  int MinusScore(int count);
  
  int GetScore();

  void SetScore(int count);

  void ResetScore();
  
};
#endif
