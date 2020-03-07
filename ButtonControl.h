#ifndef BUTTONCONTROL_H
#define BUTTONCONTROL_H
class ButtonControl
{
  private: int waterButton_Pin = 9;
  public:
  ButtonControl();

  bool IsPressed();

  
};
#endif //BUTTONCONTROL_H

