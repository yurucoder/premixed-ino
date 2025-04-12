/* ButtonModule.h: handle button module, by Hojun Kim. meringyee@gmail.com */
#ifndef BUTTON_MODULE_H
#define BUTTON_MODULE_H

class ButtonModule {
private:
  int pin;
public:
  ButtonModule(int pin);
  int getState() const {
    return digitalRead(pin);
  };
};

#endif  // BUTTON_MODULE_H
