#ifndef __MOTOR_CONTROL_H__
#define __MOTOR_CONTROL_H__

/**************************************
******     GLOBAL VARIABLES     ******
**************************************/

float ShaftLength = 0.15;
float EncoderResolution = 800;

float posCNT_interrupt = 0;
int pwmOUTPUT = 255;              // depend on motor input voltage

struct encoderPin {
  int channel_a;
  int channel_b;
};

struct motorPin {
  int motorctrl_R;
  int motorctrl_L;
  int pwm;
};

/***************************************
***   CLASS DECLARATION: EncoderFB   ***
***************************************/

class EncoderFB {
private:
public:
  float posCNT;
  float MotorPositionFB;  
  encoderPin inChannel;
  EncoderFB(int pin_a, int pin_b);
};

/****************************************
***  CLASS DECLARATION: MotorInorder  ***
****************************************/

class MotorInorder {
private:
  static float PosDeadZone;
public:
  bool motorState;
  float MotorPositionINPUT;
  motorPin outputPin;
  MotorInorder(int pin_r, int pin_l, int pin_p);
  bool setDirection(float posin, float posfb);
  void changeState(bool state);
};

float MotorInorder::PosDeadZone = 0.45;
bool motorState = false;

/******************************************
***  CLASS DECLARATION: IncomingString  ***
******************************************/

class IncomingString {
private:
  static boolean hasPayload;
public:
  static String str;
  static String payload;
  static bool isReady;
  IncomingString();
  static void reset();
  static bool append(char c);
};

bool IncomingString::isReady = false;
bool IncomingString::hasPayload = false;
String IncomingString::str = "";
String IncomingString::payload = "";

/*******************************************
***  CLASS DECLARATION: IncomingCommand  ***
*******************************************/

class IncomingCommand {
private:
  static bool decPt;
public:
  static float commandF;
  IncomingCommand();
  static bool isValidNumber(String str);
  static float toFloatInput(String str);
};

float IncomingCommand::commandF = 0;
bool IncomingCommand::decPt = false;

#endif

