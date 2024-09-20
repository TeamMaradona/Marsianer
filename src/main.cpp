#include <Arduino.h>

void
setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(5, INPUT);
}

void
loop()
{
  bool isOn = digitalRead(5);

  if (isOn) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}