#pragma once
#include <Arduino.h>

namespace calibration {
void
print()
{
  const int val = analogRead(0);
  Serial.println(val); // print the value to serial port
  delay(1000);         // wait for 100ms
}
} // namespace calibration
