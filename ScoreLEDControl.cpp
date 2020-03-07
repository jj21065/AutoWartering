  #include "ScoreLEDControl.h"
  
  void ScoreLEDControl::InitLEDMatrix()
  { 
    for(int i = 0;i<MatrixNum;i++)
    {
      lc.shutdown(i,false);
      /* Set the brightness to a medium values */
      lc.setIntensity(i,2);
      /* and clear the display */
      lc.clearDisplay(i);
    }
  }
  void ScoreLEDControl::SetNumber(int v)
  {
    if(v <= 99)
    {
      int ones = v%10;
      v = v /10;
      int tens = v%10;

      for(int i = 0;i<8;i++)
      {
        lc.setRow(3,i,patterns[0][i]);
      }
      for(int i = 0;i<8;i++)
      {
        lc.setRow(2,i,patterns[1][i]);
      }
      for(int i = 0;i<8;i++)
      {
        lc.setRow(0,i,codeDisp[ones][i]);
      }
      for(int i = 0;i<8;i++)
      {
        lc.setRow(1,i,codeDisp[tens][i]);
      }
    }
  }
