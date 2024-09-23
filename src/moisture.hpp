#pragma once
#include <Arduino.h>

/**
 * @file moisture.hpp
 * @brief Enthält Funktionen zur Bestimmung der Bodenfeuchtigkeit.
 */
namespace moisture {

/**
 * @brief Der Kalibrierungswert für Luft.
 *
 * Dieser Wert wird verwendet, um den Bereich der Bodenfeuchtigkeit zu
 * kalibrieren. Der Wert wird durch Messung der Bodenfeuchtigkeit in der Luft
 * bestimmt.
 *
 */
static inline int AirValue = 800;

/**
 * @brief Der Kalibrierungswert für Wasser.
 *
 * Dieser Wert wird verwendet, um den Bereich der Bodenfeuchtigkeit zu
 * kalibrieren. Der Wert wird durch Messung der Bodenfeuchtigkeit in Wasser
 * bestimmt.
 *
 */
static inline int WaterValue = 400;

/**
 * @brief Berechnet das Intervall der Bodenfeuchtigkeit basierend auf der
 * Kalibrierung.
 *
 * Diese Funktion liest den aktuellen Bodenfeuchtigkeitswert von einem analogen
 * Pin und berechnet das entsprechende Intervall basierend auf den
 * Kalibrierungswerten für Luft und Wasser. Die Intervalle werden gleichmäßig
 * zwischen den Kalibrierungswerten aufgeteilt.
 *
 * @param numIntervals Die Anzahl der Intervalle, in die der Bereich zwischen
 * den Kalibrierungswerten aufgeteilt werden soll.
 * @return Das Intervall, in dem der aktuelle Bodenfeuchtigkeitswert liegt. Wenn
 * der Wert außerhalb der Kalibrierungswerte liegt, wird das höchste Intervall
 * zurückgegeben.
 */
const int
getInterval(const int numIntervals)
{
  // Intervalle für die Ausgabe berechnen
  const int intervals = (AirValue - WaterValue) / numIntervals;

  // Sensorwert lesen
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
