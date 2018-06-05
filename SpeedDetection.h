#ifndef __SPEED_DETECTION_H__
#define __SPEED_DETECTION_H__

/***************************************
**  CLASS DECLARATION: SpeedDetector  **
***************************************/

class SpeedDetector {
private:

public:
  static unsigned long startTime;
  static float RPM;
  static float LinearSpeed;
  static float degPrev;
  SpeedDetector();
  static void getStartTime();
  static bool getSpeed(float degFB, bool state);
  static void printSpeed();
};

float SpeedDetector::RPM = 0;
float SpeedDetector::LinearSpeed = 0;
unsigned long SpeedDetector::startTime = 0;
float SpeedDetector::degPrev = 0;

#endif
