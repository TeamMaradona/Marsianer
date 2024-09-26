#pragma once
#include <Arduino.h>

/**
 * @file watering.hpp
 * @brief Enthält Funktionen zur Bewässerung der Pflanzen.
 */
namespace watering {

/**
 * @brief Startet die Sequenz zum Gießen der Pflanze und wartet damit das Wasser
 * versickern kann.
 *
 * Diese Funktion aktiviert den DigitalPin und wartet 5 Sekunden, bevor sie ihn
 * wieder deaktiviert. Danach wird 3 Minuten gewartet, bevor die Funktion
 * beendet wird.
 *
 * @param pinIndex Der Index des DigitalPins, der aktiviert werden soll.
 */
void
waterPlant(const int pinIndex)
{
  Serial.println("----------------------------------------------");
  Serial.println(">> Aktiviere DigitalPin " + String(pinIndex));
  Serial.println(">> Wasser aktiviert...");
  digitalWrite(pinIndex, HIGH);
  delay(5000);
  digitalWrite(pinIndex, LOW);
  Serial.println(">> Wasser deaktiviert");
  delay(300000);
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
  Serial.println("Feuchtigkeitswerte:");
  for (int i = 2; i < 6; i++) {
    Serial.print("AnalogPin " + String(i) + ": Stufe " + String(values[i - 2]) +
                 " von " + numLevels + "\n");
    // Feuchtigkeitswert die kleiner 2 sind, schalte den Pin ein
    if (values[i - 2] >= 4) {
      waterPlant(i);
    }
  }
}
} // namespace watering