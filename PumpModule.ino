#include "PumpModule.h"

PumpModule::PumpModule(int pinP, int pinN)
  : pinP(pinP), pinN(pinN), startTime(0), waitTime(0) {
  pinMode(pinP, OUTPUT);
  pinMode(pinN, OUTPUT);
}

void PumpModule::run() {
  digitalWrite(pinP, HIGH);
  digitalWrite(pinN, LOW);
}

void PumpModule::stop() {
  digitalWrite(pinP, LOW);
  digitalWrite(pinN, LOW);
}
