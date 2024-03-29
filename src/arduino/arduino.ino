#include "display.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"
#include "arm.h"

Arm arm;
Adafruit_AM2320 tempSensor = Adafruit_AM2320();

int tempBy10;
int tick = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10); // wait for serial port to open
  }
  Serial.println("starting...");

  Display::init();
  tempSensor.begin();
}

double inline celsius_to_farenheit(double celsius) {
  return (celsius * 1.8) + 32;
}

void loop() {
  if (tick > 99) {
    tick = 0;
    // round 100ths place and save 10ths place
    tempBy10 = (10.0 * celsius_to_farenheit(tempSensor.readTemperature()) + 0.5);
    Serial.print("Temp: ");
    Serial.println(float(tempBy10) / 10.0);

    if (tempBy10 < 740 && arm.isDown()) {
      arm.goUp();
    }
    else if (tempBy10 > 740 && !arm.isDown()) {
      arm.goDown();
    }
  }

  Display::print_digit(tempBy10 / 100, Display::Digit::DIGIT_10s);
  Display::print_digit((tempBy10 / 10) % 10, Display::Digit::DIGIT_1s);
  Display::print_digit(tempBy10 % 10, Display::Digit::DIGIT_10ths);

  tick++;
}
