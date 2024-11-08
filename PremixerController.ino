/* PremixerController.ino: handle premixer machine, by Hojun Kim. meringyee@gmail.com */
// #include <LiquidCrystal_I2C.h>
// #include <Arduino_JSON.h>
// #include <ArduinoBlue.h>
#include "ButtonModule.h"
#include "PumpModule.h"

// #define LCD_ADDRESS 0x27
#define BUTTON_PIN_1 3
// #define BUTTON_PIN_2 4
#define PUMP_PIN_P 6
#define PUMP_PIN_N 7

// Modules
// LiquidCrystal_I2C lcd(LCD_ADDRESS, 20, 4);
ButtonModule b1(BUTTON_PIN_1);
PumpModule p1(PUMP_PIN_P, PUMP_PIN_N);

// Global variable
unsigned long currentTime = 0;

// Sample json data
// const char input[] = "{\"result\":true,\"count\":42,\"foo\":\"bar\"}";

void setup() {
  // lcd.init();
  // lcd.backlight();
  // lcd.println("Hello");
  // Serial.begin(9600);

  // set speed of pump module
  p1.setWaitTime(3000);
  pinMode(PUMP_PIN_P, OUTPUT);
  pinMode(PUMP_PIN_N, OUTPUT);

  // JSON object
  // JSONVar myObject = JSON.parse(input);
}

void loop() {
  // check time per 0.1s
  currentTime = millis();

  // #@@range_begin(pump_module)
  if (b1.getState() == HIGH) {
    p1.run();
  }
  if (currentTime - p1.getStartTime() >= p1.getWaitTime()) {
    p1.stop();
  }
  // #@@range_end(pump_module)

  // delay of loop
  delay(100);
}
