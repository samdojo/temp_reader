#include "display.h"

#define SERVO_CTRL 0

#define THERMO_SCL 9
#define THERMO_SDA 10

int pins[] = { SERVO_CTRL,
               THERMO_SCL, THERMO_SDA
             };


void setup() {
  Serial.begin(9600);
  Display::init();

  for (int pin : pins) {
    pinMode(pin, OUTPUT);
  }
  Serial.print("starting...");



}
int i = 0;
int j = 0;
void loop() {
  Display::print_digit(j / 10, Display::Digit::DIGIT_10s);
  Display::print_digit(j % 10, Display::Digit::DIGIT_1s);
  if (i > 100) {
    j++;
    i = 0;
  }
  if (j > 99) {
    j = 0;
  }
  i++;
}
