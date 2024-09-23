#pragma once
#include <Arduino.h>

/**
 * @file calibration.hpp
 * @brief Enthält Funktionen zur Kalibrierung des Bodenfeuchtigkeitssensors.
 */
namespace calibration {

/**
 * @brief Liest den aktuellen Sensorwert des analogen Pins 0 und gibt ihn über
 * USB aus. Diese Funktion wird verwendet, um die Kalibrierungswerte für Luft
 * und Wasser zu bestimmen. Die Funktion wartet 1000ms zwischen den Messungen.
 */
void
print()
{
  const int val = analogRead(0);
  Serial.println(val);
}
} // namespace calibration
