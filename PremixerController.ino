#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define LCD_ADDRESS 0x27
#define SERVO_PIN_1 9
#define SERVO_PIN_2 10
#define BUTTON_PIN_1 3
#define BUTTON_PIN_2 4

// Constants
const char DATA_ON = '1';
const char DATA_OFF = '0';
const int CHANGE_ANGLE = 90;

// Modules
LiquidCrystal_I2C lcd(LCD_ADDRESS, 20, 4);
Servo servo1, servo2;

// Interfaces
void handleOpen(Servo* servo, unsigned long* start_time);
void closeServo(Servo* servo);

// Global variables
int current_angle = 0;
unsigned long open_start_time_1 = 0;
unsigned long open_start_time_2 = 0;

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  // Initialize serial monitor
  Serial.begin(9600);
  // Innitialize servo
  servo1.attach(SERVO_PIN_1);
  servo2.attach(SERVO_PIN_2);
  // Initialize button
  pinMode(BUTTON_PIN_1, INPUT);
  pinMode(BUTTON_PIN_2, INPUT);
}

void loop() {
  int button_state_1 = digitalRead(BUTTON_PIN_1);
  int button_state_2 = digitalRead(BUTTON_PIN_2);

  // Check button 1
  if (button_state_1 == HIGH) {
    handleOpen(&servo1, &open_start_time_1);
  }

  // Check button 2
  if (button_state_2 == HIGH) {
    handleOpen(&servo2, &open_start_time_2);
  }

  // Check if open time has passed for servo1
  if (millis() - open_start_time_1 >= 1000) {
    closeServo(&servo1);
  }

  // Check if open time has passed for servo2
  if (millis() - open_start_time_2 >= 1000) {
    closeServo(&servo2);
  }

  // Loop delay
  delay(100);
}

void handleOpen(Servo* servo, unsigned long* start_time) {
  *start_time = millis();
  servo->write(0);
  lcd.setCursor(0, 0);
  lcd.print("Open!");
}

void closeServo(Servo* servo) {
  servo->write(90);
  lcd.setCursor(0, 0);
  lcd.print("Close!");
}
