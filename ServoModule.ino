#include "ServoModule.h"

ServoModule::ServoModule(int pin)
  : servo(Servo()), start_time(0), wait_time(0) {
  // set pin of servo module
  servo.attach(pin);
}

void ServoModule::open() {
  start_time = millis();
  servo.write(0);
  // lcd.setCursor(0, 0);
  // lcd.print("Open!");
}

void ServoModule::close() {
  servo.write(90);
  // lcd.setCursor(0, 0);
  // lcd.print("Close!");
}
