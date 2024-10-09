#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#define LCD_ADDRESS 0x27
#define SERVO_PIN 9
#define BUTTON_PIN 3

// Constants
const char DATA_ON = '1';
const char DATA_OFF = '0';
const int CHANGE_ANGLE = 90;

// Modules
LiquidCrystal_I2C lcd(LCD_ADDRESS, 20, 4);
Servo servo;

// Interfaces
// void handleServo();

void setup() {
  // Initialize the LCD
  /*
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
  lcd.setCursor(0, 1);
  lcd.print("LCD2004A I2C Test");
  lcd.setCursor(0, 2);
  lcd.print("20 chars");
  lcd.setCursor(0, 3);
  lcd.print("4 lines");
  */

  // Initialize serial monitor
  Serial.begin(9600);
  // Innitialize servo
  servo.attach(SERVO_PIN);
  // Initialize button
  pinMode(BUTTON_PIN, INPUT);
}

// Global variables
int current_angle = 0;
bool is_open = false;

void loop() {
  int button_state = digitalRead(BUTTON_PIN);

  if (button_state == HIGH) {
    Serial.println("pushed!");
    current_angle = 0;
    servo.write(current_angle);
    delay(3000);
    Serial.println("meet!");
    current_angle = 90;
    servo.write(current_angle);
  }

  delay(100);

  /*
  if (Serial.available()) {
    handleServo();
  }
  */
}

/*
void handleServo() {
  char input_data = Serial.read();

  switch (input_data) {
    case DATA_ON:
      current_angle += CHANGE_ANGLE;
      break;
    case DATA_OFF:
      current_angle -= CHANGE_ANGLE;
      break;
    default:
      break;
  }

  servo.write(current_angle);
}
*/
