#include <Servo.h>

class Arm {
public:
  Arm() {
    servo.attach(9); // PIN 9
    servo.write(90);
  }

  bool isDown() { return down; }

  void goDown() {
      servo.write(90);
      down = true;
  }

  void goUp() {
      servo.write(0);
      down = false;
  }

private:
  Servo servo;
  bool down = true;
};