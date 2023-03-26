#include <Servo.h>
#define button 4
#define led 17
#define buzz 6
#define mosfet 2
Servo arms;
boolean button_state = 0;
void setup() {
  pinMode(mosfet, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  arms.write(90);
  int i = 0;
  while (i < 5) {
    i++;
    digitalWrite(led, 1);
    digitalWrite(buzz, 1);
    delay(100);
    digitalWrite(led, 0);
    digitalWrite(buzz, 0);
    delay(900);
  }
}

void loop() {
  button_state = (!digitalRead(4));
  digitalWrite(led, 1);
  delay(100);
  digitalWrite(led, 0);
  delay(900);
  if (button_state == 1) {
    int l = 0;
    while(l < 10) {
      l++;
      digitalWrite(led, 1);
      digitalWrite(buzz, 1);
      delay(100);
      digitalWrite(led, 0);
      digitalWrite(buzz, 0);
      delay(900);
    }
    digitalWrite(led, 1);
    digitalWrite(buzz, 1);
    arms.write(0);
    delay(1000);
    digitalWrite(buzz, 0);
    digitalWrite(mosfet, 1);
    delay(1000);
    digitalWrite(mosfet, 0);
    digitalWrite(13, 1);
    digitalWrite(led, 0);
    arms.write(90);
  }
}
