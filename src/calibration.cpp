#include <Arduino.h>

void
setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void
loop()
{
  int val;
  val = analogRead(0);
  Serial.println(val); // print the value to serial port
  delay(1000);         // wait for 100ms
}