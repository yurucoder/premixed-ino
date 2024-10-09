/* ButtonModule.ino: handle button module, by Hojun Kim. meringyee@gmail.com */
#include "ButtonModule.h"

ButtonModule::ButtonModule(int pin)
  : pin(pin) {
  // set pin of button module
  pinMode(pin, INPUT);
}
