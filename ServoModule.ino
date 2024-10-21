/* ServoModule.ino: handle servo module, by Hojun Kim. meringyee@gmail.com */
#include "ServoModule.h"

ServoModule::ServoModule(int pin)
  : servo(Servo()), start_time(0), wait_time(0) {
  // set pin of servo module
  servo.attach(pin);
}

void ServoModule::open() {
  start_time = millis();
  servo.write(0);
}

void ServoModule::close() {
  servo.write(90);
}
