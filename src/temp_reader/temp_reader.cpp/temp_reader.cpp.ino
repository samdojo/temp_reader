

int pins[] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

void setup() {
  Serial.begin(9600);

  for (int pin : pins) {
    pinMode(pin, OUTPUT);   
  }
  Serial.print("starting...");
}

void loop() {
  Serial.print("loop");
  digitalWrite(16, HIGH);
  delay(2000);
  digitalWrite(16, LOW);
  delay(2000);
}
