#pragma once
#include "moisture.hpp"
#include <Arduino.h>

/**
 * @file watering.hpp
 * @brief Enthält Funktionen zur Bewässerung der Pflanzen.
 */
namespace watering {

/**
 * @brief Die Dauer der Bewässerung in Millisekunden.
 *
 * Diese Variable wird verwendet, um die Zeit zu bestimmen, die die Pumpe
 * aktiviert wird.
 *
 * Default: 5 Sekunden
 */
static inline int wateringDuration = 5000;

/**
 * @brief Die Dauer des Wartens nach der Bewässerung in Millisekunden.
 *
 * Diese Variable wird verwendet, um die Zeit zu bestimmen, die gewartet wird,
 * bevor die nächste Pflanze bewässert wird.
 *
 * Default: 3 Minuten
 */
static inline int wateringWaitDuration = 300000;

/**
 * @brief Das Intervall, in dem die Pflanzen bewässert werden.
 *
 * Diese Variable wird verwendet, um die Zeit zu bestimmen, die zwischen den
 * Bewässerungen gewartet wird.
 *
 * Default: 1 tag = 86400000
 */
static inline int wateringInterval = 86400000;

/**
 * @brief Startet die Sequenz zum Gießen der Pflanze und wartet damit das
 * Wasser versickern kann.
 *
 * Diese Funktion aktiviert den DigitalPin und wartet 5 Sekunden, bevor sie
 * ihn wieder deaktiviert. Danach wird 3 Minuten gewartet, bevor die Funktion
 * beendet wird.
 *
 * @param pinIndex Der Index des DigitalPins, der aktiviert werden soll.
 */
void
waterPlant(const int pinIndex)
{
  Serial.println(">> Bewässerung von Pflanze " + String(pinIndex - 1));
  Serial.println(">> Aktiviere Pumpe");
  digitalWrite(pinIndex, LOW);
  Serial.println(">> Wasser aktiviert...");
  delay(wateringDuration);
  digitalWrite(pinIndex, HIGH);
  Serial.println(">> Wasser deaktiviert");
  delay(wateringWaitDuration);
  Serial.println(">> Warte 3 Minuten...");
}

/** @brief Testst Feuchtigkeit und triggert die Bewässerungssequenz.
 *
 * Diese Funktion liest die Feuchtigkeitswerte von den analogen Pins und
 * schaltet die Bewässerung ein, wenn der Wert über dem Schwellwert liegt.
 * Die Funktion wird in der Hauptschleife aufgerufen.
 *
 * @param numLevels Die Anzahl der Feuchtigkeitsstufen.
 */
void
run(const int* values, const int numLevels)
{
  // Loop über alle Werte
  Serial.println("Kontrolliere Feuchtigkeitswerte...");
  for (int i = 2; i < 6; i++) {
    Serial.print("\nAnalogPin " + String(i) + ": Stufe " +
                 String(values[i - 2]) + " von " + numLevels + "\n");
    // Feuchtigkeitswert die kleiner 2 sind, schalte den Pin ein
    if (values[i - 2] <= moisture::waterThreshold) {
      waterPlant(i);
    } else {
      Serial.println(">> Keine Bewässerung notwendig");
    }
  }
}
} // namespace watering