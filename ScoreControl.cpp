#include "ScoreControl.h"
ScoreControl::ScoreControl()
{
  ResetScore();
  ShowScore();  
}
void ScoreControl::ShowScore()
{
    scoreLEDControl.SetNumber(Score);
}
int ScoreControl::AddScore(int count)
{
  Score +=count;
   if(Score >99)
  {
    Score = 99;
  }
  
}

int ScoreControl::MinusScore(int count)
{
  Score-=count;
  if(Score < 0)
  {
    Score = 0;
  }
 
}
  
int ScoreControl::GetScore()
{
  return Score;
}

void ScoreControl::SetScore(int count)
{
  Score = count;

}

void ScoreControl::ResetScore()
{
  Score = 5;

}

