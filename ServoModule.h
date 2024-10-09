#ifndef SERVO_MODULE_H
#define SERVO_MODULE_H

class ServoModule {
private:
  Servo servo;
  unsigned long start_time;
  unsigned long wait_time;
public:
  ServoModule(int pin);
  unsigned long getStartTime() const {
    return start_time;
  };
  void setWaitTime(unsigned long time) {
    wait_time = time;
  };
  unsigned long getWaitTime() const {
    return wait_time;
  };
  void open();
  void close();
};

#endif  // SERVO_MODULE_H
