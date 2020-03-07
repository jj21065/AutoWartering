#ifndef CONNECTION_H
#define CONNECTION_H
// connect to centeral connection
class Connection
{
  public :
  int AddPoint(int count);

  int MinusPoint(int count);

  void SendCommand(byte b);

  void SendCommand(char*cmd);

  void ReadCommand(byte b);
  
  void ReadComand(char* s);
  
};
#endif CONNECTION_H
