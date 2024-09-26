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
print(const int pin)
{
  const int val = analogRead(pin);
  Serial.println("AnalogPin " + String(pin) + ": " + String(val));
}

/**
 * @brief Liest den aktuellen Sensorwert der analogen Pins 0 bis 3 und gibt ihn
 * über USB aus. Diese Funktion wird verwendet, um die Kalibrierungswerte für
 * Luft und Wasser zu bestimmen. Die Funktion wartet 1000ms zwischen den
 * Messungen.
 */
void
printAll()
{
  Serial.println("----------------------------------------------");
  Serial.println("Kalibrierungswerte:");
  print(A0);
  print(A1);
  print(A2);
  print(A3);
  Serial.println("----------------------------------------------");
}
} // namespace calibration