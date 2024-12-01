/* PremixerController.ino: handle premixer machine, by Hojun Kim. meringyee@gmail.com */
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include "ButtonModule.h"
#include "PumpModule.h"
#define LCD_ADDRESS 0x27
#define BT_RX 1
#define BT_TX 2
#define BUTTON_PIN_1 3
#define BUTTON_PIN_2 4
#define PUMP_PIN_P 5
#define PUMP_PIN_N 6

/* Modules */
LiquidCrystal_I2C lcd(LCD_ADDRESS, 20, 4);
SoftwareSerial bluetooth(BT_RX, BT_TX);
ButtonModule b1(BUTTON_PIN_1);
PumpModule p1(PUMP_PIN_P, PUMP_PIN_N);

/* Global variable */
unsigned long currentTime = 0;

void setup() {
  // set bluetooth module
  Serial.begin(9600);
  bluetooth.begin(9600);

  // set speed of pump module
  p1.setWaitTime(3000);
  pinMode(PUMP_PIN_P, OUTPUT);
  pinMode(PUMP_PIN_N, OUTPUT);

  // set lcd module
  lcd.init();
  lcd.backlight();
  lcd.println("Premixer");
}

void loop() {
  // check time per 0.1s
  currentTime = millis();

  // get data from android
  if (bluetooth.available()) {
    char data = bluetooth.read();
  }

  // send data through bt06
  if (Serial.available()) {
    char data = Serial.read();
    bluetooth.write(data);
  }

  // delay of loop
  delay(100);
}
