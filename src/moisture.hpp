#pragma once
#include <Arduino.h>
namespace moisture {
// Werte aus der Kalibrierung
const int AirValue = 824;
const int WaterValue = 477;

const int
getInterval(const int numIntervals)
{
  // Intervalle für die Ausgabe berechnen
  const int intervals = (AirValue - WaterValue) / numIntervals;
  const int soilMoistureValue = analogRead(A0);

  // Berechnung des Feuchtigkeitswertes
  for (int i = 0; i < numIntervals; i++) {
    if (soilMoistureValue > (AirValue - i * intervals)) {
      return i;
    }
  }

  return numIntervals;
}
} // namespace moisture
