/* ServoModule.h: handle servo module, by Hojun Kim. meringyee@gmail.com */
#ifndef PUMP_MODULE_H
#define PUMP_MODULE_H

class PumpModule {
private:
  int pinP;
  int pinN;
  unsigned long startTime;
  unsigned long waitTime;
public:
  PumpModule(int pin1, int pin2);
  void run();
  void stop();
  unsigned long getStartTime() const {
    return startTime;
  };
  void setWaitTime(unsigned long time) {
    waitTime = time;
  };
  unsigned long getWaitTime() const {
    return waitTime;
  };
};

#endif  // PUMP_MODULE_H
