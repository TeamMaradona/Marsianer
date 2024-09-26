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
 * kalibrieren.
 *
 * Der Wert wird durch Messung der Bodenfeuchtigkeit in der Luft
 * bestimmt.
 *
 */
static inline int airValue = 800;

/**
 * @brief Der Kalibrierungswert für Wasser.
 *
 * Dieser Wert wird verwendet, um den Bereich der Bodenfeuchtigkeit zu
 * kalibrieren.
 *
 * Der Wert wird durch Messung der Bodenfeuchtigkeit in Wasser
 * bestimmt.
 *
 */
static inline int waterValue = 400;

/**
 * @brief Ab dieser Feuchtigkeitsstufe soll gegossen werden.
 *
 * Dieser Wert gibt an, ab welcher Feuchtigkeitsstufe gegossen werden soll.
 *
 * Der Wert wird durch testen bestimmt.
 */
static inline int waterThreshold = 4;

/**
 * @brief Liest den Wert von einem analogen Pin.
 *
 * Diese Funktion liest den aktuellen Wert von einem analogen Pin und gibt ihn
 * zurück.
 *
 * @param channel Der Kanal, von dem der Wert gelesen werden soll.
 * @return Der gelesene Wert.
 */
const int
readFromChannel(const int channel)
{
  switch (channel) {
    case 0:
      return analogRead(A0);
    case 1:
      return analogRead(A1);
    case 2:
      return analogRead(A2);
    case 3:
      return analogRead(A3);
      // Default return value if no case matches
      return -1;
  }
}

/**
 * @brief Gibt den Feuchtigkeitswert zurück.
 *
 * Diese Funktion gibt den Feuchtigkeitswert zurück, der aufgrund des
 * Sensorwertes berechnet wird.
 * Je höher der Wert, desto trockener ist der Boden.
 *
 * @param numIntervals Die Anzahl der Intervalle, in die der Bereich
 *                     der Bodenfeuchtigkeit unterteilt werden soll.
 * @param channel Der Kanal, von dem der Sensorwert gelesen werden soll.
 * @return Der berechnete Feuchtigkeitswert.
 */
const int
getValue(const int numIntervals, const int channel)
{
  // Intervalle für die Ausgabe berechnen
  const int intervals = (airValue - waterValue) / numIntervals;

  // Sensorwert lesen
  const int soilMoistureValue = readFromChannel(channel);

  // Wenn der Sensorwert über den Messwerten liegt kehre direkt zurück
  if (soilMoistureValue > airValue) {
    return 0;
  }
  if (soilMoistureValue < waterValue) {
    return numIntervals;
  }

  // Berechnung des Feuchtigkeitswertes
  for (int i = 0; i < numIntervals; i++) {
    if (soilMoistureValue > (airValue - i * intervals)) {
      return i;
    }
  }
  return numIntervals;
}
} // namespace moisture