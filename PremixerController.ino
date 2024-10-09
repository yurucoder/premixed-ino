/* PremixerController.ino: control premixer machine, by Hojun Kim. meringyee@gmail.com */
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define LCD_ADDRESS 0x27
#define SERVO_PIN_1 9
#define SERVO_PIN_2 10
#define BUTTON_PIN_1 3
#define BUTTON_PIN_2 4

class ServoModule {
private:
  Servo servo;
  unsigned long start_time;
  unsigned long wait_time;
public:
  ServoModule(int pin);
  // declared as inline method for performance.
  unsigned long getStartTime() const {
    return start_time;
  };
  // declared as inline method for performance.
  void setWaitTime(unsigned long time) {
    wait_time = time;
  };
  // declared as inline method for performance.
  unsigned long getWaitTime() const {
    return wait_time;
  };
  void open();
  void close();
};

class ButtonModule {
private:
  int pin;
public:
  ButtonModule(int pin);
  // declared as inline method for performance.
  int getState() const {
    return digitalRead(pin);
  };
};

// Modules
LiquidCrystal_I2C lcd(LCD_ADDRESS, 20, 4);
ServoModule s1(SERVO_PIN_1), s2(SERVO_PIN_2);
ButtonModule b1(BUTTON_PIN_1), b2(BUTTON_PIN_2);

// Global variable
unsigned long current_time = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  // set wait time 1000ms for testing
  // note: add bluetooth module for set presets.
  s1.setWaitTime(1000);
  s2.setWaitTime(1000);
}

void loop() {
  // check time per 0.1s
  current_time = millis();

  // #@@range_begin(module_1)
  if (b1.getState() == HIGH) s1.open();
  if (current_time - s1.getStartTime() >= s1.getWaitTime()) s1.close();
  // #@@range_end(module_1)

  // #@@range_begin(module_2)
  if (b2.getState() == HIGH) s2.open();
  if (current_time - s2.getStartTime() >= s2.getWaitTime()) s2.close();
  // #@@range_end(module_2)

  // delay of loop
  delay(100);
}

ServoModule::ServoModule(int pin)
  : servo(Servo()), start_time(0), wait_time(0) {
  // set pin of servo module
  servo.attach(pin);
}

void ServoModule::open() {
  start_time = millis();
  servo.write(0);
  lcd.setCursor(0, 0);
  lcd.print("Open!");
}

void ServoModule::close() {
  servo.write(90);
  lcd.setCursor(0, 0);
  lcd.print("Close!");
}

ButtonModule::ButtonModule(int pin)
  : pin(pin) {
  // set pin of button module
  pinMode(pin, INPUT);
}
